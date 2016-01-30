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

    void binaryRandArgs(std::function<double(double,double)> func) {
        QTest::addColumn<double>("a");
        QTest::addColumn<double>("b");
        QTest::addColumn<double>("expect");
        for (int i = 0; i < 10; i++)
        {
            double a = getRandDouble();
            double b = getRandDouble();
            QTest::newRow("random") << a << b << func(a,b);
        }
    }

    double getRandDouble() {
        return ((0xFFFFFF / 2) - (qrand() % 0xFFFFFF)) * 0.001;
    }

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

private slots:

    void initTestCase() {
        qsrand(QTime().msec());
    }

    //Plus
    void plus_data() {binaryRandArgs([](double a, double b) {return a + b;});}
    void plus() {testBinaryOperation(Func__Plus_());}
    //Minus
    void minus_data() {binaryRandArgs([](double a, double b) {return a - b;});}
    void minus() {testBinaryOperation(Func__Minus_());}
    //Mul
    void mul_data() {binaryRandArgs([](double a, double b) {return a * b;});}
    void mul() {testBinaryOperation(Func__Mul_());}
    //Div
    void div_data() {binaryRandArgs([](double a, double b) {return a / b;});}
    void div() {testBinaryOperation(Func__Div_());}
    //Run test
    void execStr() {
        QCOMPARE(LispExecuter::execStr("+ 5 5"),std::string("10\n"));
    }
};

#endif // TESTFUNCTIONS_H
