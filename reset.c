#define N 6
int gameboard[N][N];

void reset_game(void)
{
	//reset game => board �߾� �� ĭ�� �밢������ �� ��, ���� �� ��ġ 
	gameboard[N / 2-1][N / 2-1]	= 'O'	;
	gameboard[N / 2][N / 2]		= 'O'	;
	gameboard[N / 2][N / 2-1]	= 'X'	;
	gameboard[N / 2-1][N / 2]	= 'X'	;	
	
}
