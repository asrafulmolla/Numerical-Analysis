#include <bits/stdc++.h>
using namespace std;

// Define the function to integrate
double f(double x)
{
    return 1 / (1 + x); // Function 1 / (1 + x)
}

int main()
{
    int n;         // Number of subintervals (must be a multiple of 3)
    double a, b;   // Lower and upper limits of the integral

    // Prompt the user to enter the number of subintervals
    cout << "Enter the number of interval parts (must be a multiple of 3): ";
    cin >> n;

    // Validate that the number of subintervals is a multiple of 3
    if (n % 3 != 0)
    {
        cout << "Error: Number of interval parts must be a multiple of 3. Please restart the program and try again.\n";
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

    // Variables to accumulate the summation for 3h/8 Rule
    double y3 = 0, y2 = 0;

    // Compute the summation terms for 3h/8 Rule
    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
        {
            y2 += y[i]; // Add y values for indices that are multiples of 3
        }
        else
        {
            y3 += y[i]; // Add y values for other indices
        }
    }

    // Calculate the final result using Simpson's 3/8 Rule
    double result = (3 * h / 8) * (y[0] + y[n] + 3 * y3 + 2 * y2);

    // Output the result with 4 decimal precision
    cout << fixed << setprecision(4);
    cout << "\nThe result of the integration is: " << result << endl;

    return 0;
}
