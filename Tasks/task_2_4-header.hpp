# pragma once
#include <iostream>

template <typename T>
struct Complex
{
    T re{};
    T im{};

    void print()
    {
        std::cout << "(" << this->re << ", " << this->im << ")\n";
    }

    void operator += (Complex const & c)
    {
        re += c.re;
        im += c.im;
    }
    void operator -= (Complex const & c)
    {
        re -= c.re;
        im -= c.im;
    }
    void operator *= (Complex const & c)
    {
        re *= c.re;
        im *= c.im;
    }
    void operator /= (Complex const & c)
    {
        re /= c.re;
        im /= c.im;
    }

    Complex operator + (Complex const & c) const
    {
        // return (c += *this)
        Complex tmp = *this;
        tmp += c;
        return tmp;
    }
    Complex operator - (Complex const & c) const
    {
        Complex tmp = *this;
        tmp -= c;
        return tmp;
    }
    Complex operator * (Complex const & c) const
    {
        Complex tmp = *this;
        tmp *= c;
        return tmp;
    }
    Complex operator / (Complex const & c) const
    {
        Complex tmp = *this;
        tmp /= c;
        return tmp;
    }

    bool operator == (Complex const & c) const
    {
        return (re == c.re) && (im == c.im);
    }

    bool operator != (Complex const & c) const
    {
        return !(*this == c);
    }

};