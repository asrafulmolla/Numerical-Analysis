#include <bits/stdc++.h>
#define sp fixed << setprecision(5)
using namespace std;

double f(double x)
{
    return x * x - 3;
}
void Bisection(double a, double b, double Accuracy)
{
    if (a > b || f(a) * f(b) >= 0)
    {
        cout << "Invalid interval [a, b]. Ensure f(a) * f(b) < 0." << endl;
        return;
    }

    double c;
    int i = 1;
    cout << " n " << setw(15) << "a" << setw(15) << "f(a)" << setw(15) << "b" << setw(15) << "f(b)" << setw(15) << "c=(a+b)/2" << setw(15) << "f(c)" << setw(20) << "Update" << endl;

    while ((b - a) >= Accuracy)
    {
        c = (a + b) / 2;
        if (f(c) == 0.0)
        {
            break;
        }
        if (f(a) * f(c) < 0)
        {
            b = c;
            cout << setw(3) << i
                 << setw(15) << sp << a
                 << setw(15) << sp << f(a)
                 << setw(15) << sp << b
                 << setw(15) << sp << f(b)
                 << setw(15) << sp << (a + b) / 2
                 << setw(15) << sp << f(c)
                 << setw(20) << "b = c" << endl;
        }
        else
        {
            a = c;
            cout << setw(3) << i
                 << setw(15) << sp << a
                 << setw(15) << sp << f(a)
                 << setw(15) << sp << b
                 << setw(15) << sp << f(b)
                 << setw(15) << sp << (a + b) / 2
                 << setw(15) << sp << f(c)
                 << setw(20) << "a = c" << endl;
        }
        i++;
    }
    cout << "The root is: " << fixed << setprecision(5) << c << endl;
}
int main()
{
    double a = 1;
    double b = 2;
    double Accuracy = 0.00001;
    Bisection(a, b, Accuracy);
    return 0;
}
