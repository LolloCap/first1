#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;  // I numeri minori o uguali a 1 non sono primi
    }
    
    if (num <= 3) {
        return true;   // 2 e 3 sono primi
    }

    if (num % 2 == 0 || num % 3 == 0) {
        return false;  // I multipli di 2 e 3 non sono primi
    }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;  // Se è divisibile per i o i + 2, non è primo
        }
    }

    return true;  // Se non è divisibile per nessun numero precedente, è primo
}

void prime(int s,int n,int p,int index,vector<int>& nums){
    for (int i = p; i < s; i++)
    {
        if(isPrime(i)){
            nums[index] = i;            
            if(index + 1 == n){
                int sum = 0;
                for (int j = 0; j < n; j++)
                {
                    sum += nums[j];
                }
                
                if (sum == s){
                    for (int k = 0; k < n; k++)
                    {
                        cout<<nums[k]<<" ";
                    }
                    cout<<endl;                    
                }
            }
            else prime(s,n,i + 1,index + 1,nums);
        }
    }
    
}

int main(){
    int n_test = 1;
    int s,n,p;
    for (int i = 0; i < n_test; i++)
    {
        s = 23;
        n = 3;
        p = 2;
        vector<int> nums(n);
        prime(s,n,p,0,nums);       
    }
    return 0;
}
