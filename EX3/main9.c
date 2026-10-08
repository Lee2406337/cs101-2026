#include <stdio.h>

int main(){
    int x = 9;
    int y = 9;
    int z = 9;
    if (x < 0){
        printf("%d",((x * -1) * 100 + y * 10 + z) * -1);
    }else{
        printf("%d", x * 100 + y * 10 + z);
    }
    return 0;
}