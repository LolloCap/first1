#include <iostream> 
#include <vector> 
/*
PROBLEMA 2

Si consideri un albero binario completamente pieno, con i nodi numerati con numeri crescenti procedendo dall’alto al basso e
da sinistra a destra. Un certo numero di palline vengono lasciate cadere una alla volta dalla radice finché giungono ad un 
nodo foglia. Ad ogni nodo non terminale, la pallina va a sinistra se trova il valore del flag X associato al nodo non 
terminale pari a falso (X = F), oppure a destra se trova tale flag settato a vero (X = V). 
Inizialmente tutti flag sono falsi; quando una pallina visita un nodo non terminale cambia il valore corrente del flag, 
settandolo a VERO se era FALSO (proseguendo poi la sua discesa verso sinistra), ed a FALSO se invece era VERO 
(proseguendo verso destra). 
Nell'esempio, quindi, la prima pallina cadrà in posizione 8, la seconda in posizione 12, la terza in posizione 10 e così via. 

Si scriva un programma per determinare la posizione finale di arresto P per ogni test case. 
Per ogni test case l'intervallo di due parametri D e I è il seguente:

Si consideri una serie di casi di test, per ciascuno dei quali sono forniti due valori interi: un valore Depth, 
che è la profondità massima dell’albero (ad es. Depth = 4 in figura), ed un secondo valore N che indica l’N-esima palla che 
viene lasciata cadere. (si assume ance N non superi il numero di nodi foglia (2(Depth-1)). Si scriva un programma per 
determinare la posizione finale della N-esima palla nell’albero di profondità Depth. (si assuma  2 ≤ Depth≤ 10)

INPUT
La prima linea dell’input indica il numero di casi di test T. A seguire, ogni linea inidca la coppia Depth N.

OUTPUT
Ogni linea dovrà riportare la posizione finale della pallina

Sample Input
5
4 2
2 2
8 128
3 4
10 1

Sample Output
12
3
255
7
512
*/
#include <iostream>
#include <vector>

using namespace std;

vector<bool> Tree;

int FinalPos (int x, int D, int n){
    if(x==D){
        return n;
    }

    if(!Tree[n]){
        Tree[n]=true;
        return FinalPos(x+1, D, 2*n+1);
    }else{
        Tree[n]=false;
        return FinalPos(x+1, D, 2*n+2);
    }
}

int main(){
    int Depth, N, sol;

    cin>>Depth>>N;

    int size=1;

    for(int i=0; i<Depth; i++){
        size*=2;
    }

    Tree.resize(size);

    for(int i=0; i<N; i++){
        sol=FinalPos(1, Depth, 0)+1;
    }

    cout<<sol<<endl;
    
}