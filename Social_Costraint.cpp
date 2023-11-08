#include <iostream>

using namespace std;

int factorial(int a){
    if(a == 0) return 1;

    return a * factorial(a-1);

}

int main(){

    int n,m;
    cin >> n >> m;
    int a, b , c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
    } 

    if(m == 0){
        cout <<factorial(n);
    }
    if(m != 0){
        for(int i = 0; i < n; i++){
            
        }
    }

    return 0;
}