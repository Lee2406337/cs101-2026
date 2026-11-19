#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SETS 5
#define NUMS     7
#define MAX_NUM  69

void gen_lotto(int nums[]) {
    int used[MAX_NUM + 1] = {0};
    for (int i = 0; i < NUMS; i++) {
        int r;
        do {
            r = rand() % MAX_NUM + 1;
        } while (used[r]);
        used[r] = 1;
        nums[i] = r;
    }

    for (int i = 0; i < NUMS - 2; i++)
        for (int j = 0; j < NUMS - 2 - i; j++)
            if (nums[j] > nums[j + 1]) {
                int t = nums[j]; nums[j] = nums[j + 1]; nums[j + 1] = t;
            }
}

int main(void) {
    int n;
    int nums[NUMS];

    srand((unsigned)time(NULL));

    printf("歡迎光臨長庚樂透彩購買機台\n");
    do {
        printf("請問您要買幾組樂透彩：");
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n');
            n = 0;
        }
        if (n < 1 || n > MAX_SETS)
            printf("請輸入 1 ~ %d 之間的數字！\n", MAX_SETS);
    } while (n < 1 || n > MAX_SETS);

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟 lotto.txt\n");
        return 1;
    }

    time_t now = time(NULL);
    char date[32];
    strftime(date, sizeof(date), "%a %b %d %H:%M:%S %Y", localtime(&now));

    fprintf(fp, "======== lotto649 ========\n");
    fprintf(fp, "= %s =\n", date);
    for (int i = 1; i <= MAX_SETS; i++) {
        fprintf(fp, "[%d]:", i);
        if (i <= n) {
            gen_lotto(nums);
            for (int j = 0; j < NUMS; j++)
                fprintf(fp, " %02d", nums[j]);
        } else {
            for (int j = 0; j < NUMS; j++)
                fprintf(fp, " --");
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "======== csie@CGU ========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
