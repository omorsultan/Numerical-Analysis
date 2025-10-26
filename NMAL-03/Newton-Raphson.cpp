#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return log(3 * x) - 3;
}

double df(double x) {
    return 1 / x;
}

int main() {
    double x0 = 6.0;        // initial guess
    double x1;
    double tol = 1e-4;      // tolerance
    int maxIter = 100;
    int iter = 0;

    cout << fixed << setprecision(6);
    cout << "Iter\tx_n\t\tf(x_n)\t\tError\n";

    while (iter < maxIter) {
        double fx = f(x0);
        double dfx = df(x0);

        // Prevent division by zero
        if (dfx == 0) {
            cout << "Derivative is zero. Method fails." << endl;
            return -1;
        }

        x1 = x0 - fx / dfx;
        double error = fabs((x1 - x0) / x1);

        cout << iter+1 << "\t" << x0 << "\t" << fx << "\t" << error << endl;

        if (error < tol) break;

        x0 = x1;
        iter++;
    }

    cout << "\nApproximate Root: " << x1 << endl;
    return 0;
}
