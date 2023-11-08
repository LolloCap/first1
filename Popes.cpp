#include <iostream>
#include <vector>

using namespace std;

int number_popes = 0; 
int first_elected = 0;
int last_elected = 0;

void number(int years, vector<int> popes){
    
    int i = 0;
    int j = 0;
    int temp;

    while(i < popes.size() && j < popes.size() ){
        if(popes[i] - popes[j] < years){
            number_popes++;
            i++;
            temp = number_popes;
            if(temp > number_popes){
                number_popes = temp;
            }else{
                number_popes = number_popes;
            }
        }else{
            j++;
        }
    }
    
    first_elected = popes[j];
    last_elected = popes[i];
    
}




int main(){
    vector<int> popes;

    int years;
    
    cin >> years;
    int t = 0;

    cin >>t;
    while(t--){

        int election = 0;
        cin >> election;
        popes.push_back(election);

    }

    cout << number_popes << " " << first_elected <<" "<< last_elected<<endl;

    return 0;
}