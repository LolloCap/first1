#include <iostream>
#include <string>

using namespace std;

string Brocot(int m, int n, int a=0, int b=1, int c=1, int d=0){
    int x=a+c;
    int y=b+d;
    if(m==x && n==y){
        return "";
    }

    if(m*y<n*x){
        return 'L' + Brocot(m, n, a, b, x, y);
    }else{
        return 'R' + Brocot(m, n, x, y, c, d);
    }
    
}

int main(){
    int m , n ; 

    m = 878;
    n = 323;
    string nbr;

    nbr = Brocot(m,n);
    if(m == 1 && n == 1)nbr ="I";
    cout << nbr << endl;


    return 0;
}