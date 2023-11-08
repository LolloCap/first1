#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cmath>

using namespace std;
void Perma(vector<int>& nums, vector<int>& app, vector<int>& usato) {
    if (app.size() == nums.size()) {
        for (int i = 0;i < nums.size();i++) {
            cout << app[i]<< " ";
        }
        cout <<endl;
    }

    for (int j = 0; j < nums.size(); j++) {
        if (usato[j] == 0) {
            usato[j] = 1;
            app.push_back(nums[j]);
            Perma(nums, app, usato);
            app.pop_back();
            usato[j] = 0;
        }
    }
}
int main(){
    std::ifstream inputFile("Perma.txt");
    if (!inputFile) {
        std::cerr << "Impossibile aprire il file." << std::endl;
        return 1;
    }

    int n_test;
    inputFile >> n_test;
    int num;

    while (n_test)
    {
        int z = 1;
        vector<int> nums;
        vector<int> app;
        vector<int> used(nums.size(),0);
        while (z){
            inputFile >> num;
            nums.push_back(num);

            char c;
            if (inputFile.get(c) && c == '\n')z = 0;
        }
        Perma(nums,app,used);
        n_test--;
    }

    inputFile.close();
    return 0;
}




/*
        if(index != i){
            res.push_back(nums[i]);
            perma(nums,index + 1,res);
        }
        if(index + 1 == nums.size()){
            for (int j = 0; j < nums.size(); j++)
            {
                cout<<res[j];
            }
            cout<<endl;            
        }*/