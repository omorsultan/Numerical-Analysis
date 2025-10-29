#include <iostream>
#include <iomanip>
using namespace std;

// Define the differential equation dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;  // Example: dy/dx = x + y
}

int main() {
    double x0, y0, xn, h, yn;
    int n;

    cout << "Enter initial value of x (x0): ";
    cin >> x0;
    cout << "Enter initial value of y (y0): ";
    cin >> y0;
    cout << "Enter final value of x (xn): ";
    cin >> xn;
    cout << "Enter step size (h): ";
    cin >> h;

    // Number of steps
    n = (int)((xn - x0) / h);

    cout << "\nStep\tx\t\ty\t\tf(x,y)\t\ty(next)\n";
    cout << fixed << setprecision(6);

    for (int i = 0; i < n; i++) {
        double fx = f(x0, y0);
        yn = y0 + h * fx;  // Euler formula
        cout << i + 1 << "\t" << x0 << "\t" << y0 << "\t" << fx << "\t" << yn << endl;

        // Update values for next iteration
        x0 += h;
        y0 = yn;
    }

    cout << "\nApproximate value of y at x = " << xn << " is " << yn << endl;

    return 0;
}
