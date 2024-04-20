#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 45
#define MIN_NUM 1
#define NUMBERS 6

void input_nums(int nums[]);               // 로또 번호 입력
int duplicate(int num, int numd[], int a); // 중복 확인
void print_nums(int inputN[][NUMBERS],
                int count); // 사용자가 입력한 로또 번호 확인
void make_goalNums(int Goal_nums[]); // 로또 당첨 번호 생성
void check_result(int player_nums[], int Goal_nums[],
                  int count); // 로또 당첨 여부 확인

// 선택창 & 메인
int main() {
  char op;
  int count, i;
  int inputN[100][NUMBERS]; // 100회 까지의 로또 번호를 저장할 수 있게 함

start:
  printf("로또를 몇 회 뽑으시겠습니까? : ");
  scanf("%d", &count);

  // input_nums()을 count만큼 반복
  for (i = 0; i < count; i++) {
    printf("\n-----%d번째 로또 번호 입력\n", i + 1);
    input_nums(inputN[i]);
    printf("로또 번호 입력이 완료되었습니다.\n");
  }

  //선택창
  printf("\n\n 게임을 시작합니다.\n\n");
  printf("---------선택---------\n");
  printf("l : 입력하신 로또 번호를 확인하실 수 있습니다.\nf : 로또 당첨 "
         "번호와 당첨 여부를 확인하실 수 있습니다\n");

menu:
  printf("원하는 작업을 선택하여 주십시오 : ");
  scanf(" %c", &op);

  //옵션 실행창
  switch (op) {
  case 'l':
  case 'L':
    print_nums(inputN, count);
    goto menu;

  case 'f':
  case 'F': {
    int goal_nums[NUMBERS]; //당첨 번호에 사용할 배열, 당첨 번호 저장
    make_goalNums(goal_nums);
    printf("\n당첨 번호입니다 : ");
    for (i = 0; i < NUMBERS; i++) {
      printf(" %d", goal_nums[i]);
    }
    printf("\n\n");

    //입력 번호 당첨 번호 비교
    for (i = 0; i < count; i++) {
      check_result(inputN[i], goal_nums, count);
    }
    break;
  }
  default:
    printf("\n잘못된 입력입니다. 올바른 선택을 해주십시오.\n\n");
    goto menu;
  }

  printf("\n게임이 끝났습니다.\n");
  printf("r : 재시작\nx : 종료\n");

end:
  printf("원하는 작업을 선택하여 주십시오 : ");
  scanf(" %c", &op);

  switch (op) {
  case 'r':
  case 'R':
    printf("\n");
    goto start;

  case 'x':
  case 'X':
    printf("\n게임을 종료합니다.\n");
    return 0;

  default:
    printf("올바른 선택을 해주십시오.\n");
    goto end;
  }
  return 0;
}

// 사용자의 로또 번호 입력
void input_nums(int nums[]) {
  int i;
  for (i = 0; i < NUMBERS; i++) {
    printf("%d번째 번호 입력 : ", i + 1);
    scanf("%d", &nums[i]);

    //범위를 벗어나는 번호인지 확인
    if (nums[i] < MIN_NUM || nums[i] > MAX_NUM) {
      printf(
          "\n1부터 45까지의 번호만 입력이 가능합니다. 다시 입력해 주십시오.\n");
      i--; // 범위를 벗어나는 번호를 다시 입력받기 위해 i 감소
      continue;
    }

    //중복되는 번호인지 확인
    if (duplicate(nums[i], nums, i)) {
      printf("\n중복된 번호입니다. 중복되는 번호를 입력할 수 없습니다. "
             "다시입력해 주십시오\n");
      i--; //중복되는 번호를 다시 받기 위해 i 감소
    }
  }
}

//중복 확인
int duplicate(int nums, int numd[], int a) {
  int i;
  for (i = 0; i < a; i++) {
    if (nums == numd[i]) {
      return 1; //중복 숫자가 있을 시
    }
  }
  return 0; // 중복 숫자가 없을 시
}

//입력한 로또 번호 확인
void print_nums(int inputN[][NUMBERS], int count) {
  printf("\n 입력한 로또 번호\n");
  for (int i = 0; i < count; i++) {
    printf("%d번째 : ", i + 1);
    for (int j = 0; j < NUMBERS; j++) {
      printf("%d ", inputN[i][j]);
    }
    printf("\n");
  }
}

//로또 당첨 번호 생성
void make_goalNums(int goal_nums[]) {
  srand(time(NULL));
  for (int i = 0; i < NUMBERS; i++) {
    goal_nums[i] = rand() % MAX_NUM + 1;
  }
}

// 로또 당첨 여부 출력
void check_result(int player_nums[], int goal_nums[], int count) {
  int point = 0;
  for (int c = 0; c < count; c++) {
    for (int i = 0; i < NUMBERS; i++) {
      for (int j = 0; j < NUMBERS; j++) {
        if (player_nums[i] == goal_nums[j]) {
          point++;
          break; //여러번 비교 될 수 있어 포인트 올린 후 탈출
        }
      }
    }
    printf("%d회차 당첨 확인\n", c + 1);
    if (point == NUMBERS) {
      printf("축하합니다! 모든 번호를 맞춰 당첨되셨습니다!\n\n");
    } else {
      printf("아쉽네요. 번호가 일치하지 않아 당첨되지 않았습니다.\n맞힌 개수 : "
             "%d개 \n\n",
             point);
    }
    printf("\n");
  }
}