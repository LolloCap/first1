#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> A,int r, int c){
    if(A[r][c] == 0 || r > A.size() || c > A[r].size()) return false;
    if(A[r][c] == 1 && r <= A.size() && c < A[r].size()) return true;
}

vector<vector<int>> Path(vector<vector<int>> A, vector<vector<int>> p,int r, int c){
 
        if(A[r][c] == 1 ){
                p[r][c] = 1;
                //cout << "sono qui" <<endl; 
                if(A[r+1][c] == 0 && A[r][c+1] == 0 ){
                    p[r][c] = 0; 
                    Path(A,p,r,c);
                }   
                if(A[r+1][c] == 1) p[r+1][c] == 1;
                if(A[r][c+1] == 1) p[r][c+1] == 1;
                //if(A[r][c+1] == 0){
                //    Path(A,p,r,c+1);
                //}
            }else if(A[r][c] == 0){
                p[r][c] = 0;
            }    

    for(int k = 0; k < r; k++){
        for(int h = 0; h < c; h++){
            cout << p[k][h] << " ";
        }
        cout << "\n";
    }

    return p;
}

int main(){

    int t;

    cin >> t;

    vector<vector<int>> L;
    vector<vector<int>> S;
    while (t--)
    {
        
        int nrow, ncol;

        cin >> nrow >> ncol;
        L.resize(nrow,vector<int>(ncol));
        S.resize(nrow,vector<int>(ncol));

        for(int i = 0; i < nrow; i++){
            for(int j = 0; j < ncol; j++){
                cin >> L[i][j];
            }    
        }

        Path(L,S,nrow,ncol);
        
    }

 
    return 0;
}