#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h" 

#define MAX_DIE    6

//0. opening function
void opening(void)
{
     printf("===========\n");
     printf("===========\n");
     printf("   shark   \n");
     printf("===========\n");
     printf("===========\n");
}

int rolldie(void)
{
    return rand()%MAX_DIE;
}

int main(int argc, char *argv[])
{
  // rand 초기화 함수
  srand((unsigned)time(NULL));
  // 0. opening 
  opening();
  //1. 초기화 및 플레이어 이름 설정
  board_initboard();
  
  //2. 반복문 (플레이어 턴)
  do
  {
       int step = rolldie();
       int coinResult;
       int pos;
       
       board_printBoardStatus();
       
       pos += step;
       printf();
       coinResult = board_getCoardCoin(pos)   
       printf("press any key to continue:")
       scanf("%d", $c);
       fflush(stdin);  
  }
       //2-1. 플레이어의 상태 출력
       //2-2. 주사위 던지기
       //2-3. 이동
       //2-4. 동전 줍기 
       //2-5. 다음 턴
       //2-6. 상어 동작(조건 : 모든 플레이어가 한번씩 턴을 돔)
       // |-> if(조건 : 모든 플레이어가 한번씩 턴을 돔) {상어 동작} 
  while(1);
  //3. 정리 (승자계산 , 출력 등)   
  
  system("PAUSE");	
  return 0;
}
