#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return log(3 * x) - 3; 
}

pair<double, int> falsePosition(double a, double b, double tol) {
    int iteration = 0;
    double c;

    if (f(a) * f(b) > 0) {
        cout << "Invalid interval: f(a) and f(b) must have opposite signs.\n";
        return {-1, 0};
    }

    cout << "Iter\t a \t\t b \t\t c \t\t f(c) \n";
    while (true) {
        c = b - (f(b) * (a - b)) / (f(a) - f(b));
        double fc = f(c);
        iteration++;

        cout << iteration << "\t" << fixed << setprecision(6) << a << "\t" << b << "\t" << c << "\t" << fc << "\n";

        if (fabs(fc) < tol)
            break;

        if (f(a) * fc < 0)
            b = c;
        else
            a = c;
    }

    return {c, iteration};
}

int main() {
    double a = 0.1, b = 10 , tolerance = 1e-4;       

    auto result = falsePosition(a, b, tolerance);

    cout << "\nApproximate Root = " << result.first << endl;
    cout << "Total Iterations = " << result.second << endl;

    return 0;
}
