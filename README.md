# Numerical Analysis

This repository contains various numerical analysis algorithms implemented in C++ and Python. These methods are widely used for solving mathematical problems such as root finding, numerical integration, interpolation, and linear algebra.

## Table of Contents

- [Introduction](#introduction)
- [Implemented Algorithms](#implemented-algorithms)
- [Usage](#usage)
- [Compilation and Execution](#compilation-and-execution)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Numerical analysis is a field of mathematics that deals with designing efficient algorithms for solving mathematical problems computationally. This repository includes implementations of fundamental numerical methods in C++ and Python.

## Implemented Algorithms

### Root-Finding Methods
- **Bisection Method** (`Algorithm_of_Bisection_Method.cpp`, `bisection.cpp`)
- **Secant Method** (`Secant_Method.cpp`)
- **Halley's Method** (`Halleys_Method.py`)
- **Newton's Method** (`newton.cpp`)
- **Regular Falsi Method** (`regular_falsi_methods.cpp`)

### Linear Algebra
- **Gaussian Elimination** (`Gauss_Elimination.cpp`)

### Numerical Integration
- **Simpson’s 1/3 Rule** (`Simpsons_1_3_Rule.cpp`)
- **Simpson’s 3/8 Rule** (`Simpsons_3_8_Rule.cpp`)
- **Trapezoidal Rule** (`Trapezoidal_Rule.cpp`)

### Interpolation
- **Lagrange Interpolation** (`lagrange_interpolation.cpp`)

## Usage

To use any of these methods, clone the repository and navigate to the desired algorithm’s directory.

```sh
# Clone the repository
git clone https://github.com/asrafulmolla/Numerical-Analysis.git
cd Numerical-Analysis
```

## Compilation and Execution

Since most implementations are in C++, you need a C++ compiler (e.g., `g++`).

```sh
# Compile a C++ program
g++ Algorithm_of_Bisection_Method.cpp -o bisection
# Run the compiled executable
./bisection
```

For Python scripts, simply run:

```sh
python Halleys_Method.py
```

## Contributing

Contributions are welcome! If you find any issues or want to add new algorithms, feel free to fork the repository, make changes, and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
