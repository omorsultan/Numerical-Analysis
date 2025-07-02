#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

// Traditional fixed range
pair<double, int> bisection(double a, double b, double tol) {
    int iter = 0;
    while (fabs(b - a) > tol) {
        double c = (a + b) / 2.0;
        if (f(c) == 0.0) break;
        else if (f(a) * f(c) < 0) b = c;
        else a = c;
        iter++;
    }
    return {(a + b) / 2.0, iter};
}

// Auto range finder
pair<double, double> find_range(double start, double end, double step) {
    for (double x = start; x < end; x += step) {
        if (f(x) * f(x + step) < 0)
            return {x, x + step};
    }
    return {0, 0}; // Not found
}

int main() {
    double tol = 1e-6;

    // Traditional method: fixed range
    auto result1 = bisection(1, 2, tol);
    cout << fixed << setprecision(6);
    cout << "Traditional Range [1, 2]:\n";
    cout << "Root = " << result1.first << ", Iterations = " << result1.second << "\n\n";

    // Better: auto detect range
    auto range = find_range(-10, 10, 0.1);
    if (range.first == 0 && range.second == 0)
        cout << "No valid range found.\n";
    else {
        auto result2 = bisection(range.first, range.second, tol);
        cout << " Better Auto Range [" << range.first << ", " << range.second << "]:\n";
        cout << "Root = " << result2.first << ", Iterations = " << result2.second << "\n";
    }

    return 0;
}
