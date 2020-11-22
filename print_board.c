
#define N 6
int gameboard[N][N];

int print_board(void) {
	int col, row; //row=가로, col=세로줄
	int i;

	//print board
	printf("---------------------\n");
	for (i = 0; i < N; i++)
	{
		printf("  %d", i);
	}
	printf("\n");
	printf("---------------------\n");

	for (row = 0; row < N; row++)
	{
		printf("%d|", row);
		for (col = 0; col < N; col++)
		{
			printf("%c |", gameboard[row][col]); // 배열 안의 돌 출력
		}
		printf("\n");
		printf("---------------------\n");
	}

	print_state();

	return 0;
}

int print_state(void){
	int white = 0	; //흰돌 
	int black = 0	; //검은돌 //두 돌 모두 개수 초기화 
	int col, row	;
	
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == 'O')
				white++;	//흰돌 개수 세기 
		}
	}

	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == 'X')
				black++;	//검은돌 개수 세기 
		}
	}

	//두 돌 개수 상태 print 
	printf(" STATUS - WHITE : %d, BLACK : %d\n", white, black );
	
	
}

