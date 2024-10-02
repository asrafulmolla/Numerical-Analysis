#include <bits/stdc++.h>
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
        }
        else
        {
            a = c;
        }
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
