#include <iostream>
#include <string>

using namespace std;

string Nice(string s,int start, int end ){
    if(s.length() == 0) return "";

    string left;
    string right;

    if(start < end){
        int mid = start + end /2;
        left = Nice(s,start,mid);
        right = Nice(s,mid+1,end);
    }

    for(int i = 0; i < left.length(); i++ ){
        if(left[i] == right[i]) return left;
        else return "";
    }
}

int main(){

    string s; 

    s = "WWaw";

    cout << Nice(s,0,s.length());

    return 0;
}