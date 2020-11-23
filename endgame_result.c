#define N 6
int gameboard[N][N];

//게임 종료 조건
int end_game(void) 
{
	int row;
	int col;
	int space = 0;	//빈칸 
	int white = 0;
	int black = 0;
	int white_possible = 0;
	int black_possible = 0;

	//칸이 모두 찼을 때 => space = 0
	for (row=0; row<N; row++)
	{
		for (col=0; col<N; col++)
		{
			if (gameboard[row][col] == ' ')
				space++;
		}
	}
	if (space == 0)
		return 1; //end game

	// 모든 알이 한 색일 때 = 한 색 개수가 0일 떄 
	for (row=0; row<N; row++)
	{
		for (col=0; col<N; col++)
		{
			if (gameboard[row][col] == 'O')
				white++;
			if (gameboard[row][col] == 'X')
				black++;
		}
	}

	if (white == 0)
		return 1;	//end game
	if (black == 0)
		return 1;	//end game

	for (row=0; row<N; row++)
	{
		for (col=0; col<N; col++)
		{
			white_possible += white_flip_possible(row, col);
			black_possible += black_flip_possible(row, col);
		}
	}
	if ((white_possible == 0) || (black_possible == 0))	//뒤집을 수 있는 돌이 없을 때 
		return 1; //end game
	else
		return 0;
}

int check_result(void)
{
	int row, col;
	int white = 0; 
	int black = 0;
	
	printf("\n::game result::\n");
	print_board();
	
	for (row=0; row<N; row++)
	{
		for (col=0; col<N; col++)
		{
			if (gameboard[row][col] == 'O')
				white++;
			if (gameboard[row][col] == 'X')
				black++;
		}
	}
	//돌 개수 비교, 결과 출력 
	if (white > black)
		printf("White win!\n");
	else if (black > white)
		printf("Black win!\n");
	else
		printf("Draw!\n");	
}

