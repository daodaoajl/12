#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define N_BOARD    15 //board ĭ 
#define N_COIN     12
#define MAX_COIN   4

// �� ���� ������ �ļ� ���� 
int board_status[N_BOARD];

//i��° ĭ�� ���� coin �� 
int board_coin[N_BOARD];

//��� ��ġ
static int board_sharkPosition; 

// �ʱ�ȭ board 
int board_intboard(void)
{
    int i;
    for(i=0;i<N_BOARD;i++)
    {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0;                       
    }    
    
    for(i=0;i<N_COINPOS;i++)
    {
        int flag = 0;
        while(flag == 0)
        {
            int allocpos = rand()%N_BOARD;
            
            if(board_coin[allocPos] == 0)
            {
                 board_coin[allocPos] == rand()%MAX_COIN+1;     
                 flag = 1;                   
            }       
        }                        
    }
    return 0;
}

// print board status
int board_printBoardStatus(void)
{
    int i;
    
    printf("-------------------- BOARD STATUS --------------------\n");
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
           printf("X");
        else 
           printf("O");    
    }    
    printf("|\n");
    printf("------------------------------------------------------\n");
    return 0;
}

//board get coin
int board_getBoardCoin(int pos)
{
    int coin = board_coin[pos];
    board_coin[pos] = 0; 
    return coin;    
}

//get shark position
int board_getSharkPosition(void);

//step shark
int board_stepShark(void);

//���� �ļ� ���� 
int board_getBoardStatus(int pos) 
{
    return board_status[pos];    
}

//-> �̸� ���ϼ� �߿� 
