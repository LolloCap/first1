#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool is_valid_move(int x, int y, vector<vector<int>>& lab, vector<vector<int>>& solution) {
    int N = lab.size();
    
    if(x >= 0 && x < N && y >= 0 && y < N && lab[x][y] == 1 && solution[x][y] == 0) return true;
    else return false;
}

bool find_path(vector<vector<int>>& lab, vector<vector<int>>& solution, int x, int y) {
    int N = lab.size();
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }

    if (is_valid_move(x, y, lab, solution)) {
        solution[x][y] = 1;

        if (find_path(lab, solution, x + 1, y) || find_path(lab, solution, x, y + 1)) {
            return true;
        }

        solution[x][y] = 0;
    }

    return false;
}

int main() {
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
        
        vector<vector<int>> lab(nrow, vector<int>(ncol));
        vector<vector<int>> solution(nrow, vector<int>(ncol, 0));

        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                input_file >> lab[i][j];
            }
        }

    
        if (find_path(lab, solution, 0, 0)) {
            for (int i = 0; i < nrow; i++) {
                for (int j = 0; j < ncol; j++) {
                    cout << solution[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "Nessun percorso trovato." << endl;
        }
    }

    input_file.close();
    

    return 0;
}
