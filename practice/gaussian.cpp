#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter number of equeation: ";
    int n;cin>>n;
    double a[n][n+1];
    for(int i=0; i<n; i++ )
        for( int j=0 ; j<n+1 ; j++ )
            cin>>a[i][j];

    for(int i=0; i<n ; i++ )
    {
        if(abs(a[i][i])<1e-9)
        {
            cout<<"pivot cannot be 0"; return 0;
        }
        for(int j=i+1 ; j<n ; j++ )
        {
            double mark = a[j][i]/a[i][i];
            for(int k=0 ; k<n+1; k++ )
            {
                a[j][k] -= mark * a[i][k];
            }
        }
    }
    double x[n];
    for(int i=n-1;i>=0;i--)
    {
        x[i]=a[i][n];
        for(int j=i+1 ; j<n ; j++ )
            x[i] -= a[i][j]*x[j];
        x[i]/= a[i][i];
    }
    for(int i=0 ; i<n ; i++ )
        cout<<x[i]<<endl;
}