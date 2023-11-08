#include <iostream>

using namespace std;

int count(uint32_t a){

    if(a == 0) return 0;
    else  return (a&1)+count(a >> 1);

}

int main(){

    uint32_t a = 00000000000000000000000000001011;
    
    cout << count(a)<<endl;

    return 0;
}