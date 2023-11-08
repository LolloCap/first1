/*PROBLEMA 1

Il signor Rossi si trasferisce a Napoli. Ha una famiglia molto numerosa a Napoli, e tutti vivono a via Roma. 
Dal momento che intende visitare spesso tutti i suoi parenti, sta cercando di trovare casa vicino a loro. 
Il signor Rossi vuole ridurre al minimo la distanza totale da tutti loro (ossia, vuole determinare la 
posizione ottimale della casa che minimizza la somma delle distanze dalle case dei suoi parenti), e ti ha 
ingaggiato per scrivere un programma che risolva il problema.


INPUT
L'input è costituito da diversi casi di test. La prima riga contiene il numero di casi di test. 
Per ogni test case è fornito un numero intero che indica il numero dei parenti r (0 < r < 500), 
ed i numeri civici (anche essi interi) s1, s2,…, si,…, sr dove vivono (0 < si < 30000 ). 
Nota che diversi parenti potrebbero vivere allo stesso civico.

OUTPUT
Per ogni test case, il programma riporti in output la somma minima delle distanze dalla casa del signor Rossi
alle case di ciascuno dei suoi parenti. La distanza tra due numeri civici si ed sj è 
dij = |si − sj|.
 

Sample Input
2
2 2 4
3 2 4 6

Sample Output
2
4*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int merge(vector<int>& A, int p, int r, int q)
{
    int i, j ,k;
    static vector<int> c(A.size());
    i = p;
    k = p;
    j = q + 1;
    while (i <= q && j <= r) {  
        if (A[i] < A[j]) {
            c[k] = A[i];
            k++;
            i++;
        }
        else  {
            c[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= q)  {
        c[k] = A[i];
        k++;
        i++;
        
    }
    while (j <= r) {
        c[k] = A[j];
        k++;
        j++;
    }
    for (i =p; i < k; i++)  {
        A[i] = c[i];
    }


}



void mergeSort(vector<int>& A, int p, int r){
    int q;
    if (p < r){
        //divide the array at id and sort independetly using merge sort
        q=(p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        //merge or conquer sorted arrays
        merge(A,p,r,q);
        
    }
}

int main() {
    int numTest;
    vector<int> Input;
    //cout <<"Quanti casi di test vuoi eseguire ? "<< endl;
    //cin >> numTest;   

    /*for(int i = 0; i < numTest; i++){
        vector<int> Input;
    }*/

    cout << "Quanti parenti vuoi analizzare " << endl;
    cin >> Input[0];

    for(int i = 1; i <= Input[0]; i++){
        int n ;
        cin >> n;
        Input[i] = n;
    }

    mergeSort(Input,1,Input.size());

    int distanza = 0;

    if(Input.size() % 2 == 0)
        distanza = Input[Input.size()/2];
    else
        distanza = Input[] ;

    return 0;
}




