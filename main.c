#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h" 

#define MAX_CHARNAME    200 
#define N_BOARD    15 //board ĭ 

#define N_PLAYER   3   
#define MAX_DIE    6
//PLAYER ���� 
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];//PLAYER�� ���¸� PLAYER�� ����ŭ 
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"};//0~2�� �ǹ��ϴ� ��
 

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
              printf("%c", player_name[player][0]);//�÷��̾��� ù��° ���ڸ� ��� 
          }
          else
          {
              if(board_getBoardStatus(i) == BOARDSTATUS_NOK)//NOK�� ��� 
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
//2-1 end -> ȣ�� �Ǵ� �Լ� 

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
  // rand �ʱ�ȭ �Լ�
  srand((unsigned)time(NULL));
  // 0. opening 
  opening();
  //1. �ʱ�ȭ �� �÷��̾� �̸� ����
  board_initboard();
  //1-2.
  for (i=0;i<N_PLAYER;i++)
  {
      player_position[i] = 0;
      player_coin[i] = 0;
      player_status[i] = PLAYERSTATUS_LIVE;
      printf("Player %i's name : ", i);
      scanf("%s", player_name[i]); //player_name ��ü�� �����Ϳ� �ش��ϱ� ������ &�ʿ�X
         
  }
  
  //2. �ݺ��� (�÷��̾� ��)
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
       
       //2-1. ����, �÷��̾��� ���� ���(�Լ� ȣ��)
       board_printBoardStatus();// ���� ���� ��� 
       for(i=0;i<N_PLAYER;i++)// �÷��̾� ���� ��� 
             printPlayerPosition(i);
       printPlayerStatus(); 
       //
       
       //2-2. �ֻ��� ������
       printf("%s turn!! ", player_name[turn]); 
       printf("press any key to roll a die!\n");
       scanf("%d", &c);
       fflush(stdin);  
       step = rolldie();
       //
       
       //2-3. �̵�
       
       player_position[turn] += step; //�̵�
       if(player_position[turn] >= N_BOARD) //ĭ�� �Ѿ ������ ��Ȳ 
       {
             player_position[turn] = N_BOARD - 1;                       
       }
       if(player_status[turn] = N_BOARD-1)
       {       player_status[turn] = PLAYERSTATUS_END;    }
       //printf(); 
       //            
       
       //2-4. ���� �ݱ� 
       coinResult = board_getBoardCoin(pos) ; 
       player_coin[turn] += coinResult;
       //printf();
       //
       
       //2-5. ���� ��
       turn =( turn + 1 )%N_PLAYER;
       //
       
       //2-6. ��� ����(���� : ��� �÷��̾ �ѹ��� ���� ��)
       // |-> if(���� : ��� �÷��̾ �ѹ��� ���� ��) {��� ����}
       if (turn == 0)
       {
          //��� ���� 
          int shark_pos = board_stepShark();
          printf("Shark moved to %i\n", shark_pos);
          checkDie();        
       }
  } 
  while(1);//game end �Լ� �̿��Ͽ� ���ǹ� �ۼ� 
  //3. ���� (���ڰ�� , ��� ��)   
  
  system("PAUSE");	
  return 0;
}
