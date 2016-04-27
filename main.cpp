//
//  main.cpp
//  Complex_Numbers
//
//  Created by Brett Meyer on 4/21/16.
//  Copyright © 2016 Brett Meyer. All rights reserved.
//
#include <iostream>
#include "ComplexNumber.h"

int main(int argc, const char * argv[]) {
    //variables
    ComplexNumber C1,C2;
    
    //Enter complex numbers
    std::cout << "Enter a complex number C1:\n";
    cin >> C1;
    std::cout << "Enter a complex number C2:\n";
    cin >> C2;
    std::cout << "For C1 = " << C1 << " and C2 = " << C2 << " :\n";
    
    //test arithmetic operators
    std::cout << "C1 + C2 = " << C1 + C2 << "\n";
    std::cout << "C1 - C2 = " << C1 - C2 << "\n";
    std::cout << "C1 * C2 = " << C1 * C2 << "\n";
    
    //test relational operators
    std::cout << "C1 == C2 is ";
    if (C1 == C2)
        std::cout << "true\n";
    else
        std::cout << "false\n";
    std::cout << "C1 != C2 is ";
    if (C1 != C2)
        std::cout << "true\n";
    else
        std::cout << "false\n";
    
    //test assignment operators
    ComplexNumber temp = C1;
    C1 += C2;
    std::cout << "After C1 += C2, C1 = " << C1 << "\n";
    C1 = temp;
    
    C1 -= C2;
    std::cout << "After C1 -= C2, C1 = " << C1 << "\n";
    C1 = temp;
    
    C1 *= C2;
    std::cout << "After C1 *= C2, C1 = " << C1 << "\n";
    
    return 0;
}
