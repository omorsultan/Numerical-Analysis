#include <iostream>
#include <iomanip>
using namespace std;

// Define the differential equation dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;  // Example: dy/dx = x + y
}

int main() {
    double x0, y0, xn, h, k1, k2, k3, k4, yn;
    int n;

    cout << "Enter initial value of x (x0): ";
    cin >> x0;
    cout << "Enter initial value of y (y0): ";
    cin >> y0;
    cout << "Enter final value of x (xn): ";
    cin >> xn;
    cout << "Enter step size (h): ";
    cin >> h;

    n = (int)((xn - x0) / h);

    cout << fixed << setprecision(6);
    cout << "\nStep\tx\t\ty\t\tk1\t\tk2\t\tk3\t\tk4\t\ty(next)\n";

    for (int i = 0; i < n; i++) {
        k1 = f(x0, y0);
        k2 = f(x0 + h/2, y0 + (h/2)*k1);
        k3 = f(x0 + h/2, y0 + (h/2)*k2);
        k4 = f(x0 + h, y0 + h*k3);

        yn = y0 + (h/6)*(k1 + 2*k2 + 2*k3 + k4);

        cout << i+1 << "\t" << x0 << "\t" << y0 << "\t"
             << k1 << "\t" << k2 << "\t" << k3 << "\t" << k4 << "\t" << yn << endl;

        x0 += h;
        y0 = yn;
    }

    cout << "\nApproximate value of y at x = " << xn << " is " << y0 << endl;

    return 0;
}
