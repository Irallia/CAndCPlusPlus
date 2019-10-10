# pragma once
#include <iostream>

template <typename T>
struct Complex
{
    T re{};
    T im{};

    void print()
    {
        std::cout << "(" <<  re << ", " <<  im << ")\n";
    }

    void operator += (Complex const & other)
    {
        re += other.re;
        im += other.im;
    }
    void operator -= (Complex const & other)
    {
        re -= other.re;
        im -= other.im;
    }
    void operator *= (Complex const & other)
    {
        re *= other.re;
        im *= other.im;
    }
    void operator /= (Complex const & other)
    {
        re /= other.re;
        im /= other.im;
    }

    Complex operator + (Complex const & other) const
    {
        // return (c += *this)
        Complex tmp = *this;
        tmp += other;
        return tmp;
    }
    Complex operator - (Complex const & other) const
    {
        Complex tmp = *this;
        tmp -= other;
        return tmp;
    }
    Complex operator * (Complex const & other) const
    {
        Complex tmp = *this;
        tmp *= other;
        return tmp;
    }
    Complex operator / (Complex const & other) const
    {
        Complex tmp = *this;
        tmp /= other;
        return tmp;
    }

    bool operator == (Complex const & other) const
    {
        return (re == other.re) && (im == other.im);
    }

    bool operator != (Complex const & other) const
    {
        return !(*this == other);
    }

};