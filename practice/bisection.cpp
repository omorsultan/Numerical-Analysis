#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return 3*x*x+41*x-2;;
}
int main()
{
    double a=0 , b = 4 ; 
    if(f(a)*f(b)>0){
        cout<<"No answer "<<endl;
        return 0;
    }
    double tol =  0.01 ;
    double c = (a+b)/2;
    while(fabs(a-b)>tol)
    {
        c = (a+b)/2;
        if(f(a)*f(c)<0)b=c;
        else a=c;
        // if(f(c)<1e-5)break;
    }
    cout<<setprecision(3)<<c<<endl;
}