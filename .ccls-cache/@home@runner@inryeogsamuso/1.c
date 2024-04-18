#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // 상단 부분
    for (int i = 1; i <= n; i++) {
        // 왼쪽 공백
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // 별 출력
        printf("*");
        // 오른쪽 공백
        for (int k = 1; k < 2 * i - 1; k++) {
            printf(" ");
        }
        // 두 번째 별 출력 (가운데 열)
        if (i != 1) {
            printf("*");
        }
        printf("\n");
    }

    // 하단 부분
    for (int i = n - 1; i >= 1; i--) {
        // 왼쪽 공백
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // 별 출력
        printf("*");
        // 오른쪽 공백
        for (int k = 1; k < 2 * i - 1; k++) {
            printf(" ");
        }
        // 두 번째 별 출력 (가운데 열)
        if (i != 1) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
