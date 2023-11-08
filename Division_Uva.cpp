#include <iostream>


using namespace std;


/*int division(int a, int b, int c){

    for(int b = 1234; b <= 98765 / c ; b++){
        a = b *c;

        int tmp, used =(b < 10000);
        tmp = a; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
        tmp = b; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }

        if(used == (1<<10) - 1){
            printf("%0.5d / %0.5d = %d\n", a, b, c);
        }

    }

}*/

int main(){

    int a = 10 ;
    long int b = 20 ;
    int c = 5;


    //if((fghij / 10000) % 10 == 0) abcde = ;

    //printf("%0.5d / %0.5d = %d\n", a, b, c);
    for( c = 0; c <= 72; c++){
        for(int b = 1234; b <= 98765 / c ; b++){
            a = b *c;

            int tmp, used =(b < 10000);
            tmp = a; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
            tmp = b; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }

            if(used == (1<<10) - 1){
                printf("%0.5d / %0.5d = %d\n", a, b, c);
            }
        }
    }


    
        

    return 0;

}