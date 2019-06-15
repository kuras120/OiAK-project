#include <iostream>
#include <climits>

#include "src/include/library.h"

int main() {
    FloatingPoint floatingPoint({1}, {1});
    FloatingPoint floatingPoint1({1}, {1});

    std::cout << "FP + FP1" << std::endl;
    std::cout << floatingPoint;
    std::cout << floatingPoint1 << std::endl;

    FloatingPoint fp = floatingPoint + floatingPoint1;

    std::cout << fp;

    FloatingPoint floatingPoint2({5}, {-1});
    FloatingPoint floatingPoint3({3}, {-1});

    std::cout << "FP2 + FP3" << std::endl;
    std::cout << floatingPoint2;
    std::cout << floatingPoint3 << std::endl;

    FloatingPoint fp1 = floatingPoint2 + floatingPoint3;

    std::cout << fp1;

    FloatingPoint floatingPoint4({10}, {INT_MAX});
    FloatingPoint floatingPoint5({12}, {INT_MAX});

    std::cout << "FP4 + FP5" << std::endl;
    std::cout << floatingPoint4;
    std::cout << floatingPoint5 << std::endl;

    FloatingPoint fp2 = floatingPoint4 + floatingPoint5;

    std::cout << fp2;

    return 0;
}

void equalsOperator() {
    std::cout << "\n\n**** OPERATOR '==' ****\n" << std::endl;
    FloatingPoint floatingPoint({-2},{5, 4});
    FloatingPoint floatingPoint1({-2},{5, 4});

    std::string boolean = floatingPoint == floatingPoint1 ? "true" : "false";
    std::cout << "FP1 == FP2 -> " << boolean << std::endl;

    std::cout << floatingPoint;
    std::cout << floatingPoint1 << std::endl;
}

void notEqualsOperator() {
    std::cout << "\n\n**** OPERATOR '!=' ****\n" << std::endl;
    FloatingPoint floatingPoint({-2},{5, 4});
    FloatingPoint floatingPoint1({-2},{-5, 4});

    std::string boolean = floatingPoint != floatingPoint1 ? "true" : "false";
    std::cout << "FP1 != FP2 -> " << boolean << std::endl;

    std::cout << floatingPoint;
    std::cout << floatingPoint1 << std::endl;
}

void getSign() {
    std::cout << "\n\n**** ZNAK ****\n" << std::endl;
    FloatingPoint floatingPoint({-2},{5, 4});
    FloatingPoint floatingPoint1({4, -2},{-5, 4});

    std::string boolean = floatingPoint.GetSign() ? "Ujemna" : "Dodatnia";
    std::cout << "FP znak -> " << boolean << std::endl;
    std::cout << floatingPoint << std::endl;

    boolean = floatingPoint1.GetSign() ? "Ujemna" : "Dodatnia";
    std::cout << "FP znak -> " << boolean << std::endl;
    std::cout << floatingPoint1 << std::endl;
}

void lessOperator() {
    std::cout << "\n\n**** OPERATOR '<' ****\n" << std::endl;

    //PIERWSZA WIEKSZA (ZNAK) -> FALSE
    FloatingPoint floatingPoint({-2, 4},{5, 4});
    FloatingPoint floatingPoint1({4, -2},{-5, 4});
    std::string boolean = floatingPoint < floatingPoint1 ? "True" : "False";
    std::cout << "FP < FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint;
    std::cout << floatingPoint1 << std::endl;

    //PIERWSZA MNIEJSZA (ZNAK) -> TRUE
    FloatingPoint floatingPoint2({4, -2},{-5, 4});
    FloatingPoint floatingPoint3({4, -2},{5, 4});
    boolean = floatingPoint2 < floatingPoint3 ? "True" : "False";
    std::cout << "FP < FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint2;
    std::cout << floatingPoint3 << std::endl;

    //TAKIE SAME -> FALSE
    FloatingPoint floatingPoint4({4, -2},{5, 4});
    FloatingPoint floatingPoint5({4, -2},{5, 4});
    boolean = floatingPoint4 < floatingPoint5 ? "True" : "False";
    std::cout << "FP < FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint4;
    std::cout << floatingPoint5 << std::endl;

    //PIERWSZA WIEKSZA (NIE ZNAK) - DODATNIE -> FALSE
    FloatingPoint floatingPoint6({4, -2},{6, 4});
    FloatingPoint floatingPoint7({4, -2},{5, 4});
    boolean = floatingPoint6 < floatingPoint7 ? "True" : "False";
    std::cout << "FP < FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint6;
    std::cout << floatingPoint7 << std::endl;

    //PIERWSZA MNIEJSZA (NIE ZNAK) - DODATNIE -> TRUE
    FloatingPoint floatingPoint8({4, -2},{4, 4});
    FloatingPoint floatingPoint9({4, -2},{5, 4});
    boolean = floatingPoint8 < floatingPoint9 ? "True" : "False";
    std::cout << "FP < FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint8;
    std::cout << floatingPoint9 << std::endl;

    //PIERWSZA WIEKSZA (NIE ZNAK) - UJEMNE -> FALSE
    FloatingPoint floatingPoint10({4, -2},{-4, 4});
    FloatingPoint floatingPoint11({4, -2},{-5, 4});
    boolean = floatingPoint10 < floatingPoint11 ? "True" : "False";
    std::cout << "FP < FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint10;
    std::cout << floatingPoint11 << std::endl;

    //PIERWSZA MNIEJSZA (NIE ZNAK) - UJEMNE -> TRUE
    FloatingPoint floatingPoint12({4, -2},{-5, 4});
    FloatingPoint floatingPoint13({4, -2},{-4, 4});
    boolean = floatingPoint12 < floatingPoint13 ? "True" : "False";
    std::cout << "FP < FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint12;
    std::cout << floatingPoint13 << std::endl;

    //PIERWSZA WIEKSZA (DODATNI WYKLADNIK) -> FALSE
    FloatingPoint floatingPoint14({5, -2},{-4, 4});
    FloatingPoint floatingPoint15({4, -2},{-5, 4});
    boolean = floatingPoint14 < floatingPoint15 ? "True" : "False";
    std::cout << "FP < FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint14;
    std::cout << floatingPoint15 << std::endl;

    //PIERWSZA MNIEJSZA (DODATNI WYKLADNIK) -> TRUE
    FloatingPoint floatingPoint16({3, -2},{-5, 4});
    FloatingPoint floatingPoint17({4, -2},{-4, 4});
    boolean = floatingPoint16 < floatingPoint17 ? "True" : "False";
    std::cout << "FP < FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint16;
    std::cout << floatingPoint17 << std::endl;

    //PIERWSZA WIEKSZA (UJEMNY WYKLADNIK) -> FALSE
    FloatingPoint floatingPoint18({-3, -2},{-4, 4});
    FloatingPoint floatingPoint19({-4, -2},{-5, 4});
    boolean = floatingPoint18 < floatingPoint19 ? "True" : "False";
    std::cout << "FP < FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint18;
    std::cout << floatingPoint19 << std::endl;

    //PIERWSZA MNIEJSZA (UJEMNY WYKLADNIK) - UJEMNE -> TRUE
    FloatingPoint floatingPoint20({-5, -2},{-5, 4});
    FloatingPoint floatingPoint21({-4, -2},{-4, 4});
    boolean = floatingPoint20 < floatingPoint21 ? "True" : "False";
    std::cout << "FP < FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint20;
    std::cout << floatingPoint21 << std::endl;
}

void moreOperator() {
    std::cout << "\n\n**** OPERATOR '>' ****\n" << std::endl;
    FloatingPoint floatingPoint({4},{-4, -1});
    FloatingPoint floatingPoint1({4},{-5, 1});

    std::string boolean = floatingPoint > floatingPoint1 ? "True" : "False";
    std::cout << "FP > FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint;
    std::cout << floatingPoint1 << std::endl;

    FloatingPoint floatingPoint2({2},{-5, 1});
    FloatingPoint floatingPoint3({-3},{5, 3});
    boolean = floatingPoint2 > floatingPoint3 ? "True" : "False";
    std::cout << "FP > FP1 -> " << boolean << std::endl;
    std::cout << floatingPoint2;
    std::cout << floatingPoint3 << std::endl;
}

void add() {
    std::cout << "\n\n**** DODAWANIE ****\n" << std::endl;
    FloatingPoint floatingPoint({4},{-4, -1});
    FloatingPoint floatingPoint1({4},{-5, 1});

    std::cout << floatingPoint;
    std::cout << floatingPoint1 << std::endl;

    std::cout << "FP + FP1" << std::endl;

    FloatingPoint floatingPoint2 = floatingPoint + floatingPoint1;
    std::cout << floatingPoint2 << std::endl;
}