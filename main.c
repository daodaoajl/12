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
  // rand �ʱ�ȭ �Լ�
  srand((unsigned)time(NULL));
  // 0. opening 
  opening();
  //1. �ʱ�ȭ �� �÷��̾� �̸� ����
  board_initboard();
  
  //2. �ݺ��� (�÷��̾� ��)
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
       //2-1. �÷��̾��� ���� ���
       //2-2. �ֻ��� ������
       //2-3. �̵�
       //2-4. ���� �ݱ� 
       //2-5. ���� ��
       //2-6. ��� ����(���� : ��� �÷��̾ �ѹ��� ���� ��)
       // |-> if(���� : ��� �÷��̾ �ѹ��� ���� ��) {��� ����} 
  while(1);
  //3. ���� (���ڰ�� , ��� ��)   
  
  system("PAUSE");	
  return 0;
}
