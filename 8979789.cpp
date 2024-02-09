#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    Fraction operator+(const Fraction& other) const {
        int num = (numerator * other.denominator) + (other.numerator * denominator);
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator-(const Fraction& other) const {
        int num = (numerator * other.denominator) - (other.numerator * denominator);
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator/(const Fraction& other) const {
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }

    int gcd(int a, int b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

    void simplify() {
        int gcdVal = gcd(numerator, denominator);
        numerator /= gcdVal;
        denominator /= gcdVal;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

