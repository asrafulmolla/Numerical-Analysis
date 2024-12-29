#include <bits/stdc++.h>
using namespace std;
double f(double x)
{
    return log(x);
}

int main()
{
    int n;
    double a, b;
    cout << "Enter number of interval parts (must be even): ";
    cin >> n;
    if (n % 2 != 0)
    {
        cout << "Error: Number of interval parts must be even. Please restart the program and try again.\n";
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
    double y4 = 0, y2 = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            y2 += y[i];
        }
        else
        {
            y4 += y[i];
        }
    }
    double result = (h / 3) * (y[0] + y[n] + 4 * y4 + 2 * y2);
    cout << fixed << setprecision(4);
    cout << "\nThe result of the integration is: " << result << endl;
}
