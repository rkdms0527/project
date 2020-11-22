
#define N 6
int gameboard[N][N];

int print_board(void) {
	int col, row; //row=����, col=������
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
			printf("%c |", gameboard[row][col]); // �迭 ���� �� ���
		}
		printf("\n");
		printf("---------------------\n");
	}

	print_state();

	return 0;
}

int print_state(void){
	int white = 0	; //�� 
	int black = 0	; //������ //�� �� ��� ���� �ʱ�ȭ 
	int col, row	;
	
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == 'O')
				white++;	//�� ���� ���� 
		}
	}

	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gameboard[row][col] == 'X')
				black++;	//������ ���� ���� 
		}
	}

	//�� �� ���� ���� print 
	printf(" STATUS - WHITE : %d, BLACK : %d\n", white, black );
	
	
}

