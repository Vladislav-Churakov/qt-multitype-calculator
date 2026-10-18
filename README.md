# Multi-Type Calculator — C++20 / Qt

A desktop calculator application developed independently using **C++20**, **Qt Widgets**, and the **Model–View–Controller (MVC)** architectural pattern.

The project demonstrates modern C++ techniques, generic programming, custom numeric types, and separation of application logic from the graphical user interface.

## Features

- Graphical user interface built with Qt Widgets
- Support for multiple numeric types
- Basic arithmetic operations: addition, subtraction, multiplication, and division
- Exponentiation
- Calculator memory functionality
- Error handling for invalid mathematical operations
- Custom `Rational` number implementation
- Reusable calculation logic using C++ templates

## Supported Numeric Types

The calculator supports:

- `int`
- `int64_t`
- `uint8_t`
- `size_t`
- `float`
- `double`
- `Rational` — custom fraction type

## Architecture

The application follows the **Model–View–Controller (MVC)** pattern.

**Model — `Calculator<T>`**

Responsible for mathematical operations, calculation state, memory operations, and error handling.

**View — `MainWindow`**

Provides the graphical interface using Qt Widgets and displays user input and calculation results.

**Controller — `Controller<T>`**

Connects the user interface with the calculation model and handles user commands.

This separation makes the application easier to maintain, test, and extend.

## Modern C++ Features

The project demonstrates:

- **Templates** — generic calculator implementation
- **`if constexpr`** — compile-time branching
- **Type traits** — type-dependent calculation logic
- **Operator overloading** — arithmetic and comparison operations for rational numbers
- **`std::optional`** — error reporting
- **C++20 three-way comparison (`<=>`)** — comparison support for custom numeric types
- **Object-oriented programming** — modular application architecture

## Project Structure

The project consists of components responsible for:

- Calculation logic
- MVC controller
- Qt-based graphical interface
- Custom rational number implementation
- Automated tests using Qt Test

## Testing

The project includes tests built with the Qt Test framework.

These tests are intended to validate calculator behavior and mathematical operations.

## Technologies

- C++20
- Qt Widgets
- Qt Test
- C++ Standard Library
- MVC Architecture
- Generic Programming

## Purpose

This project was developed independently to strengthen practical skills in:

- Modern C++ development
- Template programming
- Software architecture and design patterns
- GUI application development
- Error handling and application testing

## Author

**Vladislav Churakov**

GitHub: https://github.com/Vladislav-Churakov
