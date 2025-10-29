#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Define the function f(x)
double f(double x) {
    return 1 / (1 + x * x);  // Example: f(x) = 1 / (1 + x^2)
}

int main() {
    double a, b, h, sum = 0.0;
    int n;

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (n): ";
    cin >> n;

    h = (b - a) / n;
    double x[n + 1], y[n + 1];

    // Calculate x and y values
    for (int i = 0; i <= n; i++) {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }

    // Apply Trapezoidal Rule
    double integral = y[0] + y[n];

    for (int i = 1; i < n; i++) {
        integral += 2 * y[i];
    }

    integral = (h / 2) * integral;

    cout << fixed << setprecision(6);
    cout << "\nApproximate value of the integral = " << integral << endl;

    return 0;
}
