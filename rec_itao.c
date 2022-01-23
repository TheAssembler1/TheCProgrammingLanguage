#include <stdio.h>

//printd: print n in decimal
void printed(int n){
    if(n < ){
        putchar('-');
        n = -n;
    }
    if(n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}
