#include <bits/stdc++.h>
using namespace std;

// Define the function to integrate
double f(double x)
{
    return sqrt(1 + (x * x)); // Function: sqrt(1 + x^2)
}

int main()
{
    int n;         // Number of subintervals
    double a, b;   // Lower and upper limits of the integral

    // Prompt the user to enter the number of subintervals
    cout << "Enter the number of interval parts: ";
    cin >> n;

    // Validate the number of subintervals
    if (n <= 0)
    {
        cout << "Invalid input. The number of intervals must be greater than 0.\n";
        return 1; // Exit if the input is invalid
    }

    // Prompt the user to enter the lower and upper limits of integration
    cout << "\nEnter Lower limit and Upper limit: ";
    cin >> a >> b;

    // Validate the range of integration
    if (a >= b)
    {
        cout << "Invalid input. Lower limit must be less than upper limit.\n";
        return 1; // Exit if the input is invalid
    }

    // Calculate the width of each subinterval
    double h = (b - a) / n;

    // Initialize the result for the trapezoidal rule
    double result = 0.0;

    // Start at the lower limit
    double x = a;

    // Add the first and last terms to the result
    result += f(x) + f(b);

    // Loop through the remaining subintervals and add intermediate terms
    for (int i = 1; i < n; i++)
    {
        x += h;                // Move to the next x value
        result += 2 * f(x);    // Multiply f(x) by 2 for intermediate terms
    }

    // Multiply the result by h/2 (Trapezoidal Rule formula)
    result *= h / 2;

    // Output the result with 4 decimal precision
    cout << fixed << setprecision(4);
    cout << "\nThe result of the integration is: " << result << endl;

    return 0;
}
