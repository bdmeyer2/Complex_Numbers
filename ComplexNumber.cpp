//
//  ComplexNumber.cpp
//  Complex_Numbers
//
//  Created by Brett Meyer on 4/21/16.
//  Copyright © 2016 Brett Meyer. All rights reserved.
//
#include <string>
#include <stdlib.h> //atof()
#include "ComplexNumber.h"

// constructors
ComplexNumber::ComplexNumber()
{
    real = 0;
    imag = 0;
}

ComplexNumber::ComplexNumber(double real_part, double imaginary_part)
{
    real = real_part;
    imag = imaginary_part;
}

ComplexNumber::ComplexNumber(const ComplexNumber & rhs)
{
    real = rhs.real;
    imag = rhs.imag;
}

// named member functions
void ComplexNumber::print(ostream & out) const
{
    out << real << ' ';
    if (imag > 0)
    {
        out << "+ " << imag << "i";
    }
    else if (imag < 0)
    {
        out <<"- " << imag*-1 << "i";
    }
    else
    {
        out << "+ 0i";
    }
}

bool ComplexNumber::equals(const ComplexNumber & rhs) const
{
    if (this->real == rhs.real && this->imag == rhs.imag) {
        return true;
    }
    return false;
}

// assignment operators
const ComplexNumber & ComplexNumber::operator=(const ComplexNumber & rhs)
{
    if (this != &rhs) {
        real = rhs.real;
        imag = rhs.imag;
    }
    return *this;
}

const ComplexNumber & ComplexNumber::operator+=(const ComplexNumber & rhs)
{
    real = real + rhs.real;
    imag = imag + rhs.imag;
    return *this;
}

const ComplexNumber & ComplexNumber::operator-=(const ComplexNumber & rhs)
{
    real = real - rhs.real;
    imag = imag - rhs.imag;
    return *this;
}

const ComplexNumber & ComplexNumber::operator*=(const ComplexNumber & rhs)
{
    double temp = (real * rhs.real) - (imag * rhs.imag);
    imag = (real * rhs.imag) + (imag * rhs.real);
    real = temp;
    return *this;
}
// arithmetic operators
ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs)
{
    ComplexNumber answer(lhs);
    answer += rhs;
    return answer;
}

ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs)
{
    ComplexNumber answer(lhs);
    answer -= rhs;
    return answer;
}

ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs)
{
    ComplexNumber answer(lhs);
    answer *= rhs;
    return answer;
}

// relational operators
bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs)
{
    return lhs.equals(rhs);
}

bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs)
{
    return !lhs.equals(rhs);
}

// I/O operators
ostream & operator<<(ostream & out, const ComplexNumber & n)
{
    n.print(out);
    return out;
}

istream & operator>>(istream & in, ComplexNumber & n)
{
    double r,i;
    char c;
    std::string before,after;
    in >> r;
    in >> c;
    in >> before;
    //get rid of i character
    after = before.substr(0,before.size()-1);
    i = atof(after.c_str());
    if (c == '-') {
        i = i * -1;
    }
    
    n = ComplexNumber(r,i);
    return in;
}