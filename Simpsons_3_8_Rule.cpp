#include <bits/stdc++.h>
using namespace std;

// Define multiple functions
double f1(double x) {
    return 1 / (1 + x); // Function: 1 / (1 + x)
}

double f2(double x) {
    return sin(x); // Function: sin(x)
}

double f3(double x) {
    return cos(x); // Function: cos(x)
}

double f4(double x) {
    return exp(x); // Function: e^x
}

int main() {
    int n;         // Number of subintervals (must be a multiple of 3)
    double a, b;   // Lower and upper limits of the integral

    // Prompt the user to select the function
    cout << "Select the function to integrate:\n";
    cout << "1. 1 / (1 + x)\n";
    cout << "2. sin(x)\n";
    cout << "3. cos(x)\n";
    cout << "4. e^x\n";
    int choice;
    cin >> choice;

    // Assign the selected function
    double (*f)(double); // Pointer to the chosen function
    switch (choice) {
        case 1: f = f1; break;
        case 2: f = f2; break;
        case 3: f = f3; break;
        case 4: f = f4; break;
        default:
            cout << "Invalid choice! Please restart the program.\n";
            return 1;
    }

    // Prompt the user to enter the number of subintervals
    cout << "Enter the number of interval parts (must be a multiple of 3): ";
    cin >> n;

    // Validate that the number of subintervals is a multiple of 3
    if (n % 3 != 0) {
        cout << "Error: Number of interval parts must be a multiple of 3. Please restart the program and try again.\n";
        return 1;
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
    for (int i = 1; i <= n; i++) {
        x[i] = x[i - 1] + h;
    }

    // Compute the corresponding y values using the selected function
    for (int i = 0; i <= n; i++) {
        y[i] = f(x[i]);
    }

    // Variables to accumulate the summation for 3h/8 Rule
    double y3 = 0, y2 = 0;

    // Compute the summation terms for 3h/8 Rule
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) {
            y2 += y[i]; // Add y values for indices that are multiples of 3
        } else {
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
