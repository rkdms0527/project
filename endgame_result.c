#define N 6
int gameboard[N][N];

//���� ���� ����
int end_game(void) 
{
	int row;
	int col;
	int space = 0;	//��ĭ 
	int white = 0;
	int black = 0;
	int white_possible = 0;
	int black_possible = 0;

	//ĭ�� ��� á�� �� => space = 0
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

	// ��� ���� �� ���� �� = �� �� ������ 0�� �� 
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
	if ((white_possible == 0) || (black_possible == 0))	//������ �� �ִ� ���� ���� �� 
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
	//�� ���� ��, ��� ��� 
	if (white > black)
		printf("White win!\n");
	else if (black > white)
		printf("Black win!\n");
	else
		printf("Draw!\n");	
}

