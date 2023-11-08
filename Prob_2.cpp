#include <iostream>
#include <vector>

using namespace std;


vector<int> Sequence(vector<vector<int>> A){
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[i].size(); i++){
            
        }
    }
}

int main(){

    int t;   //numero casi di test
    int n;   //numero numero di lavori
    cin >> t;

    while (t--){

        vector<vector<int>> lavoro;
        vector<int> l;
        cin >> n; 

        int time;       //tempo impiegato
        int penale;     //Penale da pagare

       for(int i = 0; i < n ; i++){ 
            cin >> time >> penale;
            l.push_back(time);
            l.push_back(penale);
            lavoro.push_back(l);
       }

       /*for(int j = 0; j < lavoro.size(); j++ ){
        for(int k = 0; k < lavoro[j].size(); k++){
            cout << lavoro[j][k] <<" " ;
        }
        cout << endl;
       }*/

    }
    

    return 0;
}