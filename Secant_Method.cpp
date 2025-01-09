#include <bits/stdc++.h>
using namespace std;

// Function for equation 1: f(x) = x^3 - x - 1
double equation1(double x)
{
    return pow(x, 3) - x - 1; // Equation: f(x) = x^3 - x - 1
}

// Function for equation 2: f(x) = x^2 - 4
double equation2(double x)
{
    return pow(x, 2) - 4; // Equation: f(x) = x^2 - 4
}

// Function for equation 3: f(x) = sin(x) - 0.5
double equation3(double x)
{
    return sin(x) - 0.5; // Equation: f(x) = sin(x) - 0.5
}

// Function for the Secant Method
void secantMethod(double (*f)(double))
{
    double a, b, c;
    cout << "Enter two points: ";
    cin >> a >> b;

    int n = 0; // Counter for iterations
    if (a < b)
    {
        double fa = f(a), fb = f(b);

        // Check if the root lies between a and b
        if (fa * fb < 0)
        {
            // Table header for displaying iterations
            cout << "n" << setw(15) << "x0" << setw(15) << "f(x0)" << setw(15) << "x1" 
                 << setw(15) << "f(x1)" << setw(15) << "x2" << setw(15) << "f(x2)" << endl;

            // Secant Method Iterations
            while (true)
            {
                // Secant formula: c = a - f(a) * (b - a) / (f(b) - f(a))
                c = a - f(a) * (b - a) / (f(b) - f(a));
                cout << ++n << setw(15) << a << setw(15) << f(a) << setw(15) << b << setw(15) 
                     << f(b) << setw(15) << c << setw(15) << f(c) << endl;

                // Check if f(c) is zero or within tolerance
                if (abs(f(c)) <= 0.00005)
                {
                    cout << "The root is approximately = " << c << endl;
                    break;
                }

                // Update points
                a = b;
                b = c;
            }
        }
        else
        {
            cout << "Invalid input: Root does not lie between the given points." << endl;
        }
    }
    else
    {
        cout << "Invalid input: Ensure the first point is less than the second." << endl;
    }
}

int main()
{
    while (true)
    {
        // Display menu options
        cout << "\nChoose an equation to solve using the Secant Method:" << endl;
        cout << "1. f(x) = x^3 - x - 1" << endl;
        cout << "2. f(x) = x^2 - 4" << endl;
        cout << "3. f(x) = sin(x) - 0.5" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nSolving equation: f(x) = x^3 - x - 1" << endl;
                secantMethod(equation1);
                break;
            case 2:
                cout << "\nSolving equation: f(x) = x^2 - 4" << endl;
                secantMethod(equation2);
                break;
            case 3:
                cout << "\nSolving equation: f(x) = sin(x) - 0.5" << endl;
                secantMethod(equation3);
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
