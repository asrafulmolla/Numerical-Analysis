#include <bits/stdc++.h>
using namespace std;
double f(double x)
{
    return (2 * pow(x, 3)) - (2 * x) - 5;
}
int main()
{
    double x0, x1, x2;
    cin >> x0 >> x1;
    if (x0 < x1)
    {
        if (f(x0) * f(x1) < 0)
        {
            int n = 0;
            cout << "n" << setw(20) << "x0" << setw(20) << "f(x0)" << setw(20) << "x1" << setw(20) << "f(x1)" << setw(20) << "x2" << setw(20) << "f(x2)" << setw(20) << "Update" << endl;
            while (1)
            {
                x2 = x0 - (f(x0) * (x1 - x0)) / (f(x1) - f(x0));
                if (f(x2) == 0.0 || abs(f(x2)) <= 0.00005)
                {
                    cout << ++n << setw(20) << x0 << setw(20) << f(x0) << setw(20) << x1 << setw(20) << f(x1) << setw(20) << x2 << setw(20) << f(x2) << setw(20) << "Exact Root" << endl;
                    cout << "Root is " << x2 << endl;
                    return 0;
                }
                if (f(x0) * f(x2) < 0.0)
                {
                    cout << ++n << setw(20) << x0 << setw(20) << f(x0) << setw(20) << x1 << setw(20) << f(x1) << setw(20) << x2 << setw(20) << f(x2) << setw(20) << "x1 = x2" << endl;
                    x1 = x2;
                }
                else if (f(x2) * f(x1) < 0.0)
                {
                    cout << ++n << setw(20) << x0 << setw(20) << f(x0) << setw(20) << x1 << setw(20) << f(x1) << setw(20) << x2 << setw(20) << f(x2) << setw(20) << "x0 = x2" << endl;
                    x0 = x2;
                }
            }
        }
        else
        {
            cout << "Invalid a and b" << endl;
        }
    }
    else
    {
        cout << "Invalid a and b" << endl;
    }
}