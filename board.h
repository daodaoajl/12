#include <stdio.h>
#include <stdlib.h>

#define BOARDSTATUS_OK        1 // if 1, OK
#define BOARDSTATUS_NOK        0 // if 0, NOK

//prototype ����

 
// �ʱ�ȭ board 
int board_intboard(void);

// print board status
int board_printBoardStatus(void);

//board get coin
int board_getBoardCoin(int pos);

//get shark position
int board_getSharkPosition(void);

//step shark
int board_stepShark(void);

//���� �ļ� ����
int board_getBoardStatus(int pos); 
