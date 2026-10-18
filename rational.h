#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <numeric>

class Rational {
public:

    Rational() : numerator_(0), denominator_(1) {};
    Rational(int numerator, int denominator)
        : numerator_(numerator)
        , denominator_(denominator) {
        if (denominator_ == 0) {
            std::abort();
        }
        Reduction();
    }

    Rational(int value) : numerator_(value), denominator_(1) {};


    Rational Inv() const {
        return Rational{ denominator_, numerator_ };
    }


    int GetNumerator() const {
        return numerator_;
    }

    int GetDenominator() const {
        return denominator_;
    }

    Rational& operator=(const Rational& obj) = default;

    friend std::istream& operator>>(std::istream& is, Rational& r);
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);

    auto operator<=>(const Rational& other) const {
        int64_t a = static_cast<int64_t>(numerator_) * other.denominator_;
        int64_t b = static_cast<int64_t>(denominator_) * other.numerator_;
        return a <=> b;
    }


    bool operator==(const Rational& other) const {
        int64_t a = static_cast<int64_t>(numerator_) * other.denominator_;
        int64_t b = static_cast<int64_t>(denominator_) * other.numerator_;

        return a == b;
    }


    Rational& operator+=(const Rational& obj) {
        numerator_ = (numerator_ * obj.denominator_) + (denominator_ * obj.numerator_);
        denominator_ = denominator_ * obj.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator-=(const Rational& obj) {
        numerator_ = (numerator_ * obj.denominator_) - (denominator_ * obj.numerator_);
        denominator_ = denominator_ * obj.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator*=(const Rational& obj) {
        numerator_ *= obj.numerator_;
        denominator_ *= obj.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator/=(const Rational& obj) {
        numerator_ *= obj.denominator_;
        denominator_ *= obj.numerator_;
        Reduction();
        return *this;
    }

    Rational operator+(const Rational& r2) const {
        Rational other{ *this };
        other += r2;

        return other;
    }

    Rational operator-(const Rational& r2) const {
        Rational other{ *this };
        other -= r2;

        return other;
    }

    Rational operator*(const Rational& r2) const {
        Rational other{ *this };
        other *= r2;

        return other;
    }

    Rational operator/(const Rational& r2) const {
        Rational other{ *this };
        other /= r2;

        return other;
    }

    Rational operator+() const {
        return *this;
    }

    Rational operator-() const {
        return Rational(-numerator_, denominator_);
    }

    std::string ToString() const {
        if (denominator_ == 1) {
            return std::to_string(numerator_);
        } else {
            return std::to_string(numerator_) + "/" + std::to_string(denominator_);
        }
    }



private:
    void Reduction() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }


    int numerator_ = 0;
    int denominator_ = 1;
};

inline std::ostream& operator<<(std::ostream& os, const Rational& r) {
    using namespace std::literals;
    if (r.denominator_ == 1) {
        os << r.numerator_;
        return os;
    }
    os << r.numerator_ << " / "s << r.denominator_;
    return os;
}

inline std::istream& operator>>(std::istream& is, Rational& r) {
    int n, d;
    char div;

    if (!(is >> n)) {
        return is;
    }

    if (!(is >> std::ws >> div)) {
        r = Rational(n, 1);
        is.clear();
        return is;
    }

    if (div != '/') {
        r = Rational(n, 1);
        is.unget();
        return is;
    }

    if (!(is >> d) || (d == 0)) {
        is.setstate(std::ios::failbit);
        return is;
    }

    r = Rational(n, d);

    return is;
}
