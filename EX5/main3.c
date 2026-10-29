#include <stdio.h>

int moves = 0;

int ta (int n, char from, char goal, char sup){
    if (n == 1) {
        printf("移動 1號 從 %c 到 %c\n", from, goal);
        moves++;
    } else {
        ta(n - 1, from, sup, goal);
        printf("移動 %d號 從 %c 到 %c\n", n, from, goal);
        moves++;
        ta(n - 1, sup, goal, from);
    }
}

int main (){
    int n = 3;
    ta(n, 'A', 'B', 'C');
    printf("%d moves\n", moves);
    return 0;
}
