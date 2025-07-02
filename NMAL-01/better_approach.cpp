#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return 3*x*x+41*x+2 ;
}

pair<double, int> bisection(double a, double b, double tolerance) {
    int iter = 0;
    while (fabs(b - a) > tolerance) {
        double c = (a + b) / 2.0;
        if (f(c) == 0.0) break;
        else if (f(a) * f(c) < 0) b = c;
        else a = c;
        iter++;
    }
    return {(a + b) / 2.0, iter};
}

pair<double, double> find_range(double start, double end, double step) {
    for (double x = start; x < end; x += step) {
        if (f(x) * f(x + step) < 0)  return {x, x + step};
    }
    return {0, 0}; 
}

int main() {
    double tolerance = 1e-6;

    auto result1 = bisection(-2, 2, tolerance);
    cout << fixed << setprecision(6);
    cout << "Traditional Range [-2, 2]:\n";
    cout << "Root = " << result1.first << ", Iterations = " << result1.second << "\n\n";

    auto range = find_range(-10, 10, 0.1);
    if (range.first == 0 && range.second == 0)
        cout << "No valid range found.\n";
    else {
        auto result2 = bisection(range.first, range.second, tolerance);
        cout << " Better Auto Range [" << range.first << ", " << range.second << "]:\n";
        cout << "Root = " << result2.first << ", Iterations = " << result2.second << "\n";
    }

    return 0;
}