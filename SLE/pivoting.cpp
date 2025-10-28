#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter number of equations: ";
     int n; cin >> n;

    double a[20][21]; // augmented matrix [A|b]

    cout << "Enter coefficients of augmented matrix (A|b):\n";
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n + 1; j++) 
            cin >> a[i][j];
    
      // Forward Elimination with Partial Pivoting
    for (int i = 0; i < n - 1; i++) {
        // Find pivot row (largest absolute value in column i)
        int pivot = i;
        for (int j = i + 1; j < n; j++) 
            if (fabs(a[j][i]) > fabs(a[pivot][i])) 
                pivot = j;

        // Swap rows if needed
        if (pivot != i) 
            for (int k = 0; k < n + 1; k++) 
                swap(a[i][k], a[pivot][k]);

        if (fabs(a[i][i]) < 1e-9) {
            cout << "No unique solution (zero pivot at row " << i << ")\n";
            return 0;
        }
        // Eliminate entries below pivot
        for (int j = i + 1; j < n; j++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = i; k < n + 1; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    double x[20];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Output results
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x[i] << endl;
    }

    return 0;
}
