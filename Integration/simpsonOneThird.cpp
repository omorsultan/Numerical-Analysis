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

    if (n % 2 != 0) {
        cout << "Number of intervals must be even!" << endl;
        return 1;
    }

    h = (b - a) / n;
    double x[n + 1], y[n + 1];

    // Calculate x and y values
    for (int i = 0; i <= n; i++) {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }

    // Apply Simpson's 1/3 Rule
    double integral = y[0] + y[n];

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)
            integral += 2 * y[i];
        else
            integral += 4 * y[i];
    }

    integral = (h / 3) * integral;

    cout << fixed << setprecision(6);
    cout << "\nApproximate value of the integral = " << integral << endl;

    return 0;
}
