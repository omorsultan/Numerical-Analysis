#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[20], y[20];

    cout << "Enter data points (x, y):\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double value;
    cout << "Enter value of x for interpolation: ";
    cin >> value;

    double result = 0.0;

    // Apply Lagrange interpolation formula
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (value - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    cout << "\nEstimated value of f(" << value << ") = " << result << endl;

    return 0;
}
