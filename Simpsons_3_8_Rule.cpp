#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return 1 / (1 + x);
}

int main()
{
    int n;
    double a, b;
    cout << "Enter the number of interval parts (must be a multiple of 3): ";
    cin >> n;
    if (n % 3 != 0)
    {
        cout << "Error: Number of interval parts must be a multiple of 3. Please restart the program and try again.\n";
        return 1;
    }
    cout << "\nEnter Lower limit and Upper limit: ";
    cin >> a >> b;
    double h = (b - a) / n;
    vector<double> x(n + 1), y(n + 1);
    x[0] = a;
    for (int i = 1; i <= n; i++)
    {
        x[i] = x[i - 1] + h;
    }
    for (int i = 0; i <= n; i++)
    {
        y[i] = f(x[i]);
    }
    double y3 = 0, y2 = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
        {
            y2 += y[i];
        }
        else
        {
            y3 += y[i];
        }
    }

    double result = (3 * h / 8) * (y[0] + y[n] + 3 * y3 + 2 * y2);
    cout << fixed << setprecision(4);
    cout << "\nThe result of the integration is: " << result << endl;
}
