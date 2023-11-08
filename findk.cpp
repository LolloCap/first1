#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cmath>


using namespace std;
int merge(vector<int> nums,int k,int begin,int end){
    if(end - begin < 0){
        return 0;
    }
    
    if (end - begin == 0){
        if(nums[begin] == k){
            return 1;
        }
        else return 0;
    }

    int mid = begin + ((end - begin) / 2);
    int left = merge(nums,k,begin,mid);
    int right = merge(nums,k,mid + 1,end);
    return right + left;
}




int main(){
    ifstream input_file("findk.txt");

    if (!input_file.is_open() ) {
        cerr << "Impossibile aprire i file." << endl;
        return 1;
    }

    int n_test;
    input_file >> n_test;
    int k;
    int n;
    for (int i = 0; i < n_test; i++)
    {
        input_file >> k;
        input_file >> n;
        vector<int> nums(n);
        for (int j = 0; j < n; j++)
        {
            input_file >> nums[j];
        }
        cout<<merge(nums,k,0,nums.size() - 1)<<endl; 
    }
    input_file.close();
    return 0;
}
