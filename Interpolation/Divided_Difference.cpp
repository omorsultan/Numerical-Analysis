#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[20], y[20][20];  // y[i][j] will store divided differences

    cout << "Enter data points (x, y):\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i][0];
    }

    // Calculate divided difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Display divided difference table
    cout << "\nDivided Difference Table:\n";
    for (int i = 0; i < n; i++) {
        cout << setw(8) << x[i];
        for (int j = 0; j < n - i; j++) {
            cout << setw(12) << y[i][j];
        }
        cout << endl;
    }

    double value;
    cout << "\nEnter value of x for interpolation: ";
    cin >> value;

    // Apply Newton’s formula
    double sum = y[0][0];
    double term;
    for (int i = 1; i < n; i++) {
        term = y[0][i];
        for (int j = 0; j < i; j++) {
            term *= (value - x[j]);
        }
        sum += term;
    }

    cout << "\nValue of f(" << value << ") = " << sum << endl;

    return 0;
}
