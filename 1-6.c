#include <stdio.h>

int main() {
  int i, n, s = 1;
  printf("구하고 싶은 팩토리얼 값을 입력하시오 : ");
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    s *= i;
  printf("%d! = %d\n", n, s);
  return 0;
}