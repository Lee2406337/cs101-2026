#include <stdio.h>
int main() {
    int n = 32;

    if (n > 0){
        while(n % 2 == 0){
            n = n / 2;
        }
        if (n == 1){
            printf("¬O");
        }else{
            printf("§_");
        }
    }else{
        printf("§_");
    }

    return 0;
}