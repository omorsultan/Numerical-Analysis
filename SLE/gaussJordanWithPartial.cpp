#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the order of matrix: ";
    cin >> n;

    double a[20][40]; // Augmented matrix [A | I]

    cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Augment A with Identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            a[i][j] = (i == (j - n)) ? 1 : 0;
        }
    }

    // Gauss–Jordan with partial pivoting
    for (int i = 0; i < n; i++) {
        // Step 1: Find pivot row (partial pivoting)
        int pivotRow = i;
        double maxVal = fabs(a[i][i]);
        for (int k = i + 1; k < n; k++) {
            if (fabs(a[k][i]) > maxVal) {
                maxVal = fabs(a[k][i]);
                pivotRow = k;
            }
        }

        // If pivot row is not current row, swap
        if (pivotRow != i) {
            for (int j = 0; j < 2 * n; j++) {
                swap(a[i][j], a[pivotRow][j]);
            }
        }

        // Step 2: Check if pivot is zero after swapping
        if (fabs(a[i][i]) < 1e-9) {
            cout << "Matrix is singular or nearly singular. No inverse exists.\n";
            return 1;
        }

        // Step 3: Make pivot element = 1
        double pivot = a[i][i];
        for (int j = 0; j < 2 * n; j++) {
            a[i][j] /= pivot;
        }

        // Step 4: Make all other elements in pivot column = 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double ratio = a[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    a[k][j] -= ratio * a[i][j];
                }
            }
        }
    }

    // Display inverse
    cout << "\nInverse Matrix (A^-1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            cout << fixed << setprecision(4) << setw(10) << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
