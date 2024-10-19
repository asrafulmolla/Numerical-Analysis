#include <bits/stdc++.h>
using namespace std;
double f(double x)
{
    return (2 * (pow(x, 3))) - 3;
}
double df(double x)
{
    return 6 * x * x;
}
int main()
{
    double a, b;
    cin >> a >> b;
    int n = 0;
    if (a < b and f(a) * f(b) < 0)
    {
        double x0 = (a + b) / 2;
        cout << "n" << setw(20) << "x0" << setw(20) << "f(x0)" << setw(20) << "f'(x0)" << setw(20) << "x1" << setw(20) << "f(x1)" << setw(20) << "Update" << endl;
        while (true)
        {
            double x1 = x0 - ((f(x0) / df(x0)));
            if (f(x1) == 0 || abs(f(x1) <= 0.00005))
            {
                cout << ++n << setw(20) << x0 << setw(20) << f(x0) << setw(20) << df(x0) << setw(20) << x1 << setw(20) << f(x1) << setw(20) << "This is Root" << endl;
                cout << "Root is : " << x1 << endl;
                return 0;
            }
            else
            {
                cout << ++n << setw(20) << x0 << setw(20) << f(x0) << setw(20) << df(x0) << setw(20) << x1 << setw(20) << f(x1) << setw(20) << "x0=x1" << endl;
                x0 = x1;
            }
        }
    }
    else
        cout << "Invalid Choice";
}