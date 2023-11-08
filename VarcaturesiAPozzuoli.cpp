#include <stdlib.h>
#include<iostream>
#include <vector>
#include <fstream>
using namespace std;



vector<vector<int>> Soluzione(vector<vector<int>>& matrice, vector<vector<int>>& appoggio, int x, int y){
    if(x == matrice.size()-1 && y == matrice.size()-1) return appoggio;

    if(matrice[x][y+1] == 1 && y+1 < matrice.size()){
        appoggio[x][y+1] = 1;
        return Soluzione(matrice,appoggio,x,y+1);
    }else if(matrice[x+1][y] == 1 && x+1 < matrice.size()){
        appoggio[x+1][y] = 1;
        return Soluzione(matrice,appoggio,x+1,y);
    }

    if(matrice[x][y+1] == 0 && matrice[x+1][y] == 0){
        appoggio[x][y] = 0;
        matrice[x][y] = 0;
        if(x !=0){
            if(matrice[x-1][y] == 1){
            return Soluzione(matrice,appoggio,x-1,y);
        }
    }
    if(y != 0){
        if(matrice[x][y-1] == 1){
            return Soluzione(matrice,appoggio,x,y-1);
        }
    }
    }
}

int main(){
    ifstream input_file("labirinto.txt");

    if (!input_file.is_open() ) {
        cerr << "Impossibile aprire i file." << endl;
        return 1;
    }
    int n;
    input_file >> n; 
    while(n--){
        int nrow;
        int ncol;
        input_file >> nrow;
        input_file >> ncol;

    vector<vector<int>> lab(nrow,vector<int> (ncol));
    vector<vector<int>> solution(nrow,vector<int> (ncol));

    for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                input_file >> lab[i][j];
            }
        }

    solution = Soluzione(lab, solution, 0, 0);
    solution[0][0] = 1;
    for(int j = 0; j<nrow; j++){
        for(int k = 0; k<ncol; k++){
        cout<<solution[j][k]<<" ";
    }
    cout<<endl;
    }
    }

    input_file.close();
    return 0;
}

