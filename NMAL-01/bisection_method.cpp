#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return 3*x*x+41*x-2;
}

int main() {
    double a = 0, b = 4, mid ,tolerance = 0.01;
    int  iter = 1;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. f(a) and f(b) must have opposite signs." << endl;
        return 0;
    }

    cout << "Iter\t" << "a\t\t" << "b\t\t" << "mid\t\t" << "f(mid)" << endl;

    while ((b - a) > tolerance ) {
        mid = (a + b) / 2.0;
        cout << iter << "\t" << fixed << setprecision(4) << a << "\t" << b << "\t" << mid << "\t" << f(mid) << endl;

        if (f(mid) == 0.0)   break;
        else if (f(mid) * f(a) < 0)   b = mid;
        else   a = mid;
        iter++;
    }

    cout << "\nApproximate root = " << fixed << setprecision(4) << mid << endl;
    return 0;
}
