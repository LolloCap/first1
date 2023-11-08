#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int Distance(vector<int> A ){
    if(A.size() == 0) return 0;
    int d; 
    int x ,y;
    x = pow(A.back(),2);
    A.pop_back();
    y = pow(A.front(),2);
    d = sqrt(x+y);
    return d;
}

int dist = 0; 


vector<vector<int>> Closest(vector<vector<int>> A, int k){
    
    vector<vector<int>> copy;
    copy.resize(k);

    if(A.size() == 1) return copy;
      
    //int temp = 0 ; 
    //if(dist > Distance(A.front())) temp = Distance(A.front());
    //dist = Distance(A.front());     
    //cout << dist << Distance(A.front())<< endl;
    //cout << temp << endl;
    if(dist <= Distance(A.front())){
        dist = Distance(A.front());
        copy.push_back(A.front()); 
        //cout << dist << Distance(A.front())<< endl;
        //if(Distance(copy) < dist) copy.front() = A.front(); 
    }else  copy.push_back(A.front()); 

    A.erase(A.begin());
    
    Closest(A,k);
    
    return copy;

}

int main(){

    vector<vector<int>> points{{3,3},{5,-1},{-2,4}};

    /*for(int i = 0; i < points.size();i++)
    cout << Distance(points[i]) << endl;
    */
    int k = 2;

    vector<vector<int>> kclos = Closest(points,k);
    
    for(int i = 0; i < kclos.size(); i++){
        for(int j = 0; j < kclos[i].size(); j++){
            cout << kclos[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}