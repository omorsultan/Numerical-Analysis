#include <iostream>
#include <iomanip>
using namespace std;

// Define the differential equation dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;  // Example: dy/dx = x + y
}

int main() {
    double x0, y0, xn, h, yp, yc;
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
    cout << "\nStep\tx\t\ty\t\tPredictor(y_p)\tCorrector(y_c)\n";

    for (int i = 0; i < n; i++) {
        double slope1 = f(x0, y0);            // f(x_n, y_n)
        yp = y0 + h * slope1;                 // Predictor (Euler's method)
        double slope2 = f(x0 + h, yp);        // f(x_{n+1}, y_p)
        yc = y0 + (h / 2.0) * (slope1 + slope2);  // Corrector (Heun's)

        cout << i + 1 << "\t" << x0 << "\t" << y0 << "\t" << yp << "\t" << yc << endl;

        // Update for next iteration
        x0 += h;
        y0 = yc;
    }

    cout << "\nApproximate value of y at x = " << xn << " is " << y0 << endl;

    return 0;
}
