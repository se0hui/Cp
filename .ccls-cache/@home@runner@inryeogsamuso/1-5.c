#include <stdio.h>

int main(){
  int n, i, j, k;
  printf("검을 몇 회 강화하시겠습니까? : ");
  scanf("%d", &n);
  for (i = 1; i <= n * 3 + 1; i++){
    if (i < n*2+1){
      for (k = 0; k < n; k++)
        printf(" ");
      for (j = n; j >= 1; j--){
        if (j <= i)
          printf("*");
        else
          printf(" ");
      } //검의 날 부분
      printf("\n");
    }
    else if ( i > n * 2+1){
      for (k = 0; k < n; k++)
        printf(" ");
      for (j = n; j >= 1; j--){
        printf("*");
      } //검 손잡이 부분
      printf("\n");
    }
    else {
      for (j = n*3; j > 0; j--){
        printf("*");
      }//가드 부분
      printf("\n");
    }
    
  }
  return 0;
}
