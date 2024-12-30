#include <bits/stdc++.h>
using namespace std;

// Define the function to integrate
double f(double x)
{
    return log(x); // Natural logarithm function
}

int main()
{
    int n;         // Number of subintervals (must be even)
    double a, b;   // Lower and upper limits of the integral
    
    // Prompt the user to enter the number of subintervals
    cout << "Enter number of interval parts (must be even): ";
    cin >> n;

    // Ensure the number of subintervals is even
    if (n % 2 != 0)
    {
        cout << "Error: Number of interval parts must be even. Please restart the program and try again.\n";
        return 1; // Exit the program if the condition is not met
    }

    // Prompt the user to enter the lower and upper limits of integration
    cout << "\nEnter Lower limit and Upper limit: ";
    cin >> a >> b;

    // Calculate the width of each subinterval
    double h = (b - a) / n;

    // Vectors to store the x and y values
    vector<double> x(n + 1), y(n + 1);

    // Generate the x values based on the subinterval width
    x[0] = a;
    for (int i = 1; i <= n; i++)
    {
        x[i] = x[i - 1] + h;
    }

    // Compute the corresponding y values using the function f(x)
    for (int i = 0; i <= n; i++)
    {
        y[i] = f(x[i]);
    }

    // Variables to accumulate the summation for even and odd indices
    double y4 = 0, y2 = 0;

    // Compute the summation terms for Simpson's Rule
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            y2 += y[i]; // Add y values for even indices
        }
        else
        {
            y4 += y[i]; // Add y values for odd indices
        }
    }

    // Calculate the final result using Simpson's 1/3 Rule
    double result = (h / 3) * (y[0] + y[n] + 4 * y4 + 2 * y2);

    // Output the result with 4 decimal precision
    cout << fixed << setprecision(4);
    cout << "\nThe result of the integration is: " << result << endl;

    return 0;
}
