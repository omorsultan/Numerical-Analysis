#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter number of data points :";
    int n;cin>>n;

    double x[n],y[n][n];
    cout<<"Enter data points: "<<endl;
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i][0];
    
    
    for(int j=1; j<n ; j++ )
    {
        for( int i=0 ; i<n-j ; i++)
            y[i][j]= (y[i+1][j-1]-y[i][j-1])/(x[i+j]-x[i]);
    }

    cout<<"Divided difference table:"<<endl;
    for(int i=0 ; i<n ; i++)
    {
        cout<<setw(5)<<x[i];
        for(int j=0;j<n-i;j++)
            cout<<setw(8)<<y[i][j];
        cout<<endl;
    }

    cout<<"Enter value of x for interpolation : ";
    double value ; cin>>value ;

    double sum = y[0][0];
    double term ;

    for(int i=1; i<n ; i++ )
    {
        term = y[0][i];
        for(int j= 0 ; j<i ; j++)
            term *= (value-x[j]);
        sum+=term;
    }
    cout<<"value of f("<<value<<")="<<sum<<endl;
}