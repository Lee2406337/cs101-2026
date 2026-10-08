#include <stdio.h>
void print_sp(int i, int n){
    for (int s = 0; s < n - i; s++) {
        printf(" ");
    }
}

void print_num(int n){
    for (int j = 0; j < n; j++) {
        printf("%d ", n);
    }
    printf("\n");
}

int main() {
    int n = 6;

    for (int i = 1; i <= n; i++) {
        print_sp(i, n);
        print_num(i);
    }

    return 0;
}