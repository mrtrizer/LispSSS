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

class TestFunctions : public QObject
{
    Q_OBJECT

    void binaryRandArgs(QString operation, std::function<double(double,double)> func,int n = 10) {
        QTest::addColumn<QString>("expression");
        QTest::addColumn<QString>("expect");

        auto addRow = [operation,func](double a, double b) {
            QString expression;
            QTextStream expressionStream(&expression);
            expressionStream << operation << ' ' << a << ' ' << b;
            double expect = func(QString::number(a).toDouble(),QString::number(b).toDouble());
            qDebug() << QString::fromStdString(std::to_string(expect));
            QTest::newRow(expression.toLocal8Bit()) << expression << QString::fromStdString(std::to_string(expect)) + '\n';
        };

        for (int i = 0; i < n; i++)
            addRow(getRandDouble(), getRandDouble());
        addRow(0,0);
        addRow(0.0, 10.0 / 3.0);
        addRow(10.0 / 3.0, 0.0);
    }


    double getRandDouble() {
        return ((0xFFFFFF / 2) - (qrand() % 0xFFFFFF)) * 0.001;
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
        qDebug() << QString::fromStdString(LispExecuter::execStr(expression.toStdString()));
        qDebug() << expect;
        QCOMPARE(LispExecuter::execStr(expression.toStdString()),std::string(expect.toStdString()));
    }

private slots:

    void initTestCase() {
        qsrand(QTime().msec());
    }

    //Plus
    void plus_data() {binaryRandArgs("+",[](double a, double b) {return a + b;});}
    void plus() {testOperation();}
    //Minus
    void minus_data() {binaryRandArgs("-",[](double a, double b) {return a - b;});}
    void minus() {testOperation();}
    //Mul
    void mul_data() {binaryRandArgs("*",[](double a, double b) {return a * b;});}
    void mul() {testOperation();}
    //Div
    void div_data() {binaryRandArgs("/",[](double a, double b) {return a / b;});}
    void div() {testOperation();}
    //Run test
    void execStr() {
        QCOMPARE(LispExecuter::execStr("+ 5 5"),std::string("10\n"));
    }
};

#endif // TESTFUNCTIONS_H
