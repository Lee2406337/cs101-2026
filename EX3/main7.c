#include <stdio.h>

int main(){
    int i = 1610;
    if (i <=1500 ){
        printf("70元");
    }else{
        int n = i -1500;
        if (n % 100){
            int price = ((n / 100) +1) * 10;
            printf("%d元", price + 70);
        }else{
            printf("%d元", (n / 100) * 10 + 70);
        }
    }
    return 0;
}