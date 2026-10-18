#pragma once
#include <string>
#include <optional>
#include <type_traits>
#include <cmath>
#include "rational.h"
#include "pow.h"

using Error = std::string;

template <typename Number>
class Calculator {
public:
    void Set(Number n) {
        number_ = n;
    }

    Number GetNumber() const {
        return number_;
    }

    std::optional<Error> Add(Number n) {
        number_ += n;
        return std::nullopt;
    }

    std::optional<Error> Sub(Number n) {
        number_ -= n;
        return std::nullopt;
    }

    std::optional<Error> Div(Number n) {
        if constexpr(std::is_integral_v<Number> || std::is_same_v<Number, Rational>) {
            if(n == Number{}) {
                return std::optional<Error>{"Division by zero"};
            }
        }
        number_ /= n;
        return std::nullopt;
    }

    std::optional<Error> Mul(Number n) {
        number_ *= n;
        return std::nullopt;
    }

    std::optional<Error> Pow(Number n) {
        if constexpr(std::is_same_v<Number, Rational>) {
            if(n.GetDenominator() != 1) {
                return std::optional<Error>{"Fractional power is not supported"};
            }

            if(number_ == Rational{0} && n.GetNumerator() == 0) {
                return std::optional<Error>{"Zero power to zero"};
            }

            number_ = ::Pow(number_, n);
            return std::nullopt;
        } else {
            if constexpr (std::is_integral_v<Number>) {
                if(n == 0 && number_ == 0) {
                    return std::optional<Error>{"Zero power to zero"};
                }

                if(n < 0) {
                    return std::optional<Error>{"Integer negative power"};
                }

                number_ = IntegerPow(number_, n);
                return std::nullopt;
            }

            number_ = std::pow(number_, n);
            return std::nullopt;
        }
    }

    void Save() {
        mem_ = number_;
    }

    void Load() {
        if(mem_.has_value()) {
            number_ = mem_.value();
        }
    }

    bool GetHasMem() const {
        return mem_.has_value();
    }

    Error GetNumberRepr() const {
        if constexpr (std::is_same_v<Number, Rational>) {
            return number_.ToString();
        } else {
            return std::to_string(number_);
        }
    }


    void Negate() {
        number_ = -number_;
    }

private:
    Number number_ {};
    std::optional<Number> mem_;
};
