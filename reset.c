#define N 6
int gameboard[N][N];

void reset_game(void)
{
	//reset game => board 중앙 네 칸에 대각선으로 흰 돌, 검은 돌 배치 
	gameboard[N / 2-1][N / 2-1]	= 'O'	;
	gameboard[N / 2][N / 2]		= 'O'	;
	gameboard[N / 2][N / 2-1]	= 'X'	;
	gameboard[N / 2-1][N / 2]	= 'X'	;	
	
}
