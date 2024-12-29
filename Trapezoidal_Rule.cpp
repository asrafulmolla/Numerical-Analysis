#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return sqrt(1 + (x * x));
}

int main()
{
    int n;
    double a, b;
    cout << "Enter the number of interval parts: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Invalid input. The number of intervals must be greater than 0.\n";
        return 1;
    }
    cout << "\nEnter Lower limit and Upper limit: ";
    cin >> a >> b;
    if (a >= b)
    {
        cout << "Invalid input. Lower limit must be less than upper limit.\n";
        return 1;
    }
    double h = (b - a) / n;
    double result = 0.0;
    double x = a;
    result += f(x) + f(b);
    for (int i = 1; i < n; i++)
    {
        x += h;
        result += 2 * f(x);
    }
    result *= h / 2;
    cout << fixed << setprecision(4);
    cout << "\nThe result of the integration is: " << result << endl;

    return 0;
}
