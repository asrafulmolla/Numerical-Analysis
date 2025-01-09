def f(x):
    """
    Function: f(x) = x^3 - x - 1
    Returns the value of f(x) for a given x.
    """
    return pow(x, 3) - x - 1

def df(x):
    """
    First derivative: f'(x) = 3x^2 - 1
    Returns the value of f'(x) for a given x.
    """
    return 3 * x**2 - 1

def ddf(x):
    """
    Second derivative: f''(x) = 6x
    Returns the value of f''(x) for a given x.
    """
    return 6 * x

# Input interval [a, b]
a = float(input("Enter Point a: "))
b = float(input("Enter Point b: "))

# Initial guess (midpoint of [a, b])
x0 = (a + b) / 2

# Tolerance for approximation
accuracy = 0.00005

# Print table header
print(f"{'N':<12}{'x0':<15}{'f(x0)':<15}{'x1':<15}{'f(x1)':<15}")

# Iterative process using Halley's Method
n = 1
while True:
    # Halley's formula
    xx = 2 * f(x0) * df(x0)
    xxx = 2 * pow(df(x0), 2) - f(x0) * ddf(x0)
    x1 = x0 - (xx / xxx)

    # Print current iteration details
    print(f"{n:<12}{x0:<15.6f}{f(x0):<15.6f}{x1:<15.6f}{f(x1):<15.6f}")

    # Check for convergence
    if abs(f(x1)) <= accuracy:
        print(f"\nApproximate root of the equation: {x1}")
        break
    else:
        # Update the guess for the next iteration
        x0 = x1
        n += 1
