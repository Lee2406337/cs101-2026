#include <stdio.h>

int multi (int i, int j){
    if(j == 1){
        printf("%d*%d=%d ", i, j, i * j);
        return 0;
    }else{
        multi(i, j - 1);
        printf("%d*%d=%d ", i, j, i * j);
    }
}

int printable (int k){
    if (k  == 9){
        multi(k, 9);
        printf("\n");
        return 0;
    }else{
        multi(k, 9);
        printf("\n");
        k++;
        printable(k);
    }
}

int main (){
    printable(1);
    return 0;
}