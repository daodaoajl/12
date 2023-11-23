#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h" 

#define MAX_CHARNAME    200 
#define N_BOARD    15 //board 칸 

#define N_PLAYER   3   
#define MAX_DIE    6
//PLAYER 상태 
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];//PLAYER의 상태를 PLAYER의 수만큼 
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"};//0~2가 의미하는 것
 

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
// 2-1 start
void printPlayerPosition(int player) 
{
     int i;
     for(i=0;i<N_BOARD;i++)
     {
          printf("|");
          if(i == player_position[player])
          {
              printf("%c", player_name[player][0]);//플레이어의 첫번째 글자를 출력 
          }
          else
          {
              if(board_getBoardStatus(i) == BOARDSTATUS_NOK)//NOK의 경우 
                  printf("X");
              else
                  printf(" ");    
          }                         
     }  
     printf("|\n");  
} 

void printPlayerStatus(void)
{
     int i;
     for(i=0;i<N_PLAYER;i++)
     {
          printf("%s : pos %i, coin %i, status : %s\n", player_name[i], player_position[i], player_statusString[player_status[i]]);                       
     }
     printf("-------------------------\n");
}
//2-1 end -> 호출 되는 함수 

void checkDie(void)
{
     int i;
     for(i=0; i<N_PLAYER; i++)
     {
         if(board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
              player_status[i] = PLAYERSTATUS_DIE;         
     }    
}

int main(int argc, char *argv[])
{
  int pos = 0;
  int i;  
  int turn = 0; 
  // rand 초기화 함수
  srand((unsigned)time(NULL));
  // 0. opening 
  opening();
  //1. 초기화 및 플레이어 이름 설정
  board_initboard();
  //1-2.
  for (i=0;i<N_PLAYER;i++)
  {
      player_position[i] = 0;
      player_coin[i] = 0;
      player_status[i] = PLAYERSTATUS_LIVE;
      printf("Player %i's name : ", i);
      scanf("%s", player_name[i]); //player_name 자체가 포인터에 해당하기 때문에 &필요X
         
  }
  
  //2. 반복문 (플레이어 턴)
  do
  {
       int step;
       int coinResult;
       char c;
       
       if(player_status[turn] != PLAYERSTATUS_LIVE)
        {
            turn == (turn + 1)%N_PLAYER;    
            continue;
        }
       
       //2-1. 보드, 플레이어의 상태 출력(함수 호출)
       board_printBoardStatus();// 보드 상태 출력 
       for(i=0;i<N_PLAYER;i++)// 플레이어 상태 출력 
             printPlayerPosition(i);
       printPlayerStatus(); 
       //
       
       //2-2. 주사위 던지기
       printf("%s turn!! ", player_name[turn]); 
       printf("press any key to roll a die!\n");
       scanf("%d", &c);
       fflush(stdin);  
       step = rolldie();
       //
       
       //2-3. 이동
       
       player_position[turn] += step; //이동
       if(player_position[turn] >= N_BOARD) //칸을 넘어간 예외적 상황 
       {
             player_position[turn] = N_BOARD - 1;                       
       }
       if(player_status[turn] = N_BOARD-1)
       {       player_status[turn] = PLAYERSTATUS_END;    }
       //printf(); 
       //            
       
       //2-4. 동전 줍기 
       coinResult = board_getBoardCoin(pos) ; 
       player_coin[turn] += coinResult;
       //printf();
       //
       
       //2-5. 다음 턴
       turn =( turn + 1 )%N_PLAYER;
       //
       
       //2-6. 상어 동작(조건 : 모든 플레이어가 한번씩 턴을 돔)
       // |-> if(조건 : 모든 플레이어가 한번씩 턴을 돔) {상어 동작}
       if (turn == 0)
       {
          //상어 동작 
          int shark_pos = board_stepShark();
          printf("Shark moved to %i\n", shark_pos);
          checkDie();        
       }
  } 
  while(1);//game end 함수 이용하여 조건문 작성 
  //3. 정리 (승자계산 , 출력 등)   
  
  system("PAUSE");	
  return 0;
}
