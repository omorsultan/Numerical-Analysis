#include <iostream>
using namespace std;

int main() {
    double x0, y0, x1, y1, x, y;

    cout << "Enter x0, y0: ";
    cin >> x0 >> y0;
    cout << "Enter x1, y1: ";
    cin >> x1 >> y1;
    cout << "Enter value of x for which y is to be estimated: ";
    cin >> x;

    // Linear Interpolation Formula
    y = y0 + ((x - x0) / (x1 - x0)) * (y1 - y0);

    cout << "\nEstimated value of y at x = " << x << " is " << y << endl;

    return 0;
}
