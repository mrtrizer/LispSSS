#ifndef TESTFUNCTIONS_H
#define TESTFUNCTIONS_H

#include <functional>
#include <QObject>
#include <QTest>
#include <QTime>
#include "func__plus_.h"
#include "func__mul_.h"
#include "func__minus_.h"
#include "func__div_.h"
#include "atomfloatdata.h"
#include "lispexecuter.h"

namespace {

template<typename T>
T getRand() {
    Q_ASSERT(false);
}

template<>
double getRand<double>() {
    return ((0xFFFFFF / 2) - (qrand() % 0xFFFFFF)) * 0.001;
}

template<typename T>
QString toString( T) {
    Q_ASSERT(false);
}

template<>
QString toString<bool>(bool value) {
    return value? "T":"nil";
}

template<>
QString toString<double>(double value) {
    std::string str;
    double test = 0.0;
    if (modf(value, &test) == 0.0)
        str = std::to_string((int) test);
    else
        str = std::to_string(value);
    return QString::fromStdString(str);
}

}

class TestFunctions : public QObject
{
    Q_OBJECT

    template <typename Arg, typename Result>
    void addRow(QString operation, std::function<Result(Arg,Arg)> func, Arg a, Arg b) {
        Arg expect = func(a,b);
        qDebug() << QString::fromStdString(std::to_string(expect));
        QString expression;
        QTextStream expressionStream(&expression);
        expressionStream << operation << ' ' << toString<Arg>(a) << ' ' << toString<Arg>(b);
        QTest::newRow(expression.toLocal8Bit()) << expression << toString<Result>(expect) + '\n';
    }

    template <typename Arg, typename Result>
    void binaryRandArgs(QString operation, std::function<Result(Arg,Arg)> func, int n = 10) {
        QTest::addColumn<QString>("expression");
        QTest::addColumn<QString>("expect");

        for (int i = 0; i < n; i++)
            addRow(operation, func, getRand<Arg>(), getRand<Arg>());
    }

    void binaryNumArgs(QString operation, std::function<double(double,double)> func, int n = 10) {
        binaryRandArgs(operation, func, n);
        addRow(operation, func, 0.0, 0.0);
        addRow(operation, func, 0.0, 10.0 / 3.0);
        addRow(operation, func, 10.0 / 3.0, 0.0);
    }

    void binaryBoolArgs(QString operation, std::function<bool(bool,bool)> func) {
        binaryRandArgs(operation, func, 0);
        addRow(operation, func, true,true);
        addRow(operation, func, true, false);
        addRow(operation, func, false, true);
        addRow(operation, func, false, false);
    }

    void binaryNumCompArgs(QString operation, std::function<bool(double,double)> func) {
        binaryRandArgs(operation, func, 0);
        //equal
        addRow(operation, func, 1.0, 1.0);
        addRow(operation, func, 10.0 / 3.0, 10.0 / 3.0);
        addRow(operation, func, 0.0, 0.0);
        //not equal
        addRow(operation, func, 1.0, 2.0);
        addRow(operation, func, 10.0 / 3.0, 10.0 / 3.1);
        addRow(operation, func, 0.0, 1.0 / 100000.0);
        //less
        addRow(operation, func, 1.0, 2.0);
        addRow(operation, func, 10.0 / 3.0, 10.0 / 3.1);
        addRow(operation, func, 0.0, 1.0 / 100000.0);
        //greater
        addRow(operation, func, 2.0, 1.0);
        addRow(operation, func, 10.0 / 3.1, 10.0 / 3.0);
        addRow(operation, func, 1.0 / 100000.0, 0.0);
    }

    ///Used to test arithmetic operations.
    /// @details Method fetches data from qt test data
    void testBinaryOperation(const Function & func) {
        QFETCH(double, a);
        QFETCH(double, b);
        QFETCH(double, expect);
        Arguments args;
        AtomFloatData argA(a);
        AtomFloatData argB(b);
        args.push_back(Value(&argA));
        args.push_back(Value(&argB));
        Memory stack(nullptr);
        Value resultValue = func.run(args, &stack);
        const Data * data =  resultValue.getData();
        double result = dynamic_cast<const AtomFloatData*>(data)->getNum();
        QCOMPARE(result, expect);
    }

    void testOperation() {
        QFETCH(QString, expression);
        QFETCH(QString, expect);
        QString result = QString::fromStdString(LispExecuter::execStr(expression.toStdString()));
        QCOMPARE(result, expect);
    }

private slots:

    void initTestCase() {
        qsrand(QTime().msec());
    }

    //Plus
    void func__plus_data() {binaryNumArgs("+",[](double a, double b) {return a + b;});}
    void func__plus() {testOperation();}
    //Minus
    void func__minus_data() {binaryNumArgs("-",[](double a, double b) {return a - b;});}
    void func__minus() {testOperation();}
    //Mul
    void func__mul_data() {binaryNumArgs("*",[](double a, double b) {return a * b;});}
    void func__mul() {testOperation();}
    //Div
    void func__div_data() {binaryNumArgs("/",[](double a, double b) {return a / b;});}
    void func__div() {testOperation();}
    //And
    void func__and_data() {binaryBoolArgs("&&",[](bool a, bool b) {return a && b;});}
    void func__and() {testOperation();}
    //Or
    void func__or_data() {binaryBoolArgs("||",[](bool a, bool b) {return a || b;});}
    void func__or() {testOperation();}
    //Equ
    void func__equ_data() {binaryNumCompArgs("==",[](double a, double b) {return a == b;});}
    void func__equ() {testOperation();}
    //NotEqu
    void func__notequ_data() {binaryNumCompArgs("!=",[](double a, double b) {return a != b;});}
    void func__notequ() {testOperation();}
    //Less
    void func__less_data() {binaryNumCompArgs("<",[](double a, double b) {return a < b;});}
    void func__less() {testOperation();}
    //Greater
    void func__greater_data() {binaryNumCompArgs(">",[](double a, double b) {return a > b;});}
    void func__greater() {testOperation();}
    //Less
    void func__lessequ_data() {binaryNumCompArgs("<=",[](double a, double b) {return a <= b;});}
    void func__lessequ() {testOperation();}
    //GreaterEqu
    void func__greaterequ_data() {binaryNumCompArgs(">=",[](double a, double b) {return a >= b;});}
    void func__greaterequ() {testOperation();}
    //Not
    void func_not() {
        QCOMPARE(QString::fromStdString(LispExecuter::execStr("! nil")), QString("T\n"));
        QCOMPARE(QString::fromStdString(LispExecuter::execStr("! T")), QString("nil\n"));
    }

    //Run test
    void execStr() {
        QCOMPARE(LispExecuter::execStr("+ 5 5"),std::string("10\n"));
    }
};

#endif // TESTFUNCTIONS_H
