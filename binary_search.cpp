#include <iostream>
#include <vector>

using namespace std;
    
int binary_search(vector<int> A, int start, int end, int k ){

    if(start <=  end){
        int mid = start + end / 2;

        if(A[mid] == k) return mid;
        
        if(A[mid] > k) return binary_search(A,start,mid-1,k);
        
        return binary_search(A,mid+1,end,k);
    }

    //return -1;
}

int main(){

    vector<int> A{1,2,3,4,5};
    int k = 5;

    int index = binary_search(A,0,A.size()-1,k);

    cout << index;
    return 0;
}