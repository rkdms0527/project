#define N 6
int gameboard[N][N];

//flip ���ɼ� Ȯ���ϱ� 
int east_white(int row, int col);		//�� 
int west_white(int row, int col);		//�� 
int south_white(int row, int col);		//�� 
int north_white(int row, int col);	//�� 
int southeast_white(int row, int col);	//���� 
int southwest_white(int row, int col);//����
int northeast_white(int row, int col);	//�ϵ�
int northwest_white(int row, int col);	//�ϼ�


/*
�� �Ʒ�...8����. . . . <<����!! 
�����ڸ��϶� �� ����(���⺰�� ���� ���ϱ� �� �������� ������ �� ���� �Ұ���) 
	�ڸ� �ִµ� �ش� �������� ���� ���϶� �� ����
	�����϶� �� ����
		��������ĭ�� ������ �� ����
			�ٸ� �� �ƴҶ�����..
				
�̹� �ִ� �ڸ� <<<<where..?T.T 
*/	

//��
int east_white(int row, int col){
	int i = 0; 
	if ((col-1) < 0)	
		return 0; //���������� 		
	else
	{
		if (gameboard[row][col-1] == 'X')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row][col-2-i] == 'X')
			{ 
			 	i++;
			 	if ((col-2-i) < 0)	//������ ������ 
				 	return 0; 
			}
				
			if (gameboard[row][col-2-i] == 'O')
			{
				return 1;	//flip ���� 
			}
			else
				return 0; 
		}
		else
			return 0;
	}
}

//��
int west_white(int row, int col){
	int i = 0; 
	if ((col+1) < 0)	
		return 0; //���������� 		
	else
	{
		if (gameboard[row][col+1] == 'X')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row][col+2+i] == 'X')
			{ 
			 	i++;
			 	if ((col+2+i) < 0)	//������ ������ 
				 	return 0; 
			}
				
			if (gameboard[row][col+2+i] == 'O')
			{
				return 1;	//flip ���� 
			}
			else
				return 0; 
		}
		else
			return 0;
	}
} 
//��	
int south_white(int row, int col){
	int i = 0; 
	if ((row+1) >= N )	
		return 0; //���������� 		
	else
	{
		if (gameboard[row+1][col] == 'X')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row+2+i][col] == 'X')
			{ 
			 	i++;
			 	if ((row+1+i) > N)	//������ ������ 
				 	return 0; 
			}
				
			if (gameboard[row+2+i][col] == 'O')
			{
				return 1;	//flip ���� 
			}
			else
				return 0; 
		}
		else
			return 0;
	}
}
//��
int north_white(int row, int col){
	int i = 0; 
	if ((row-1) >= N )	
		return 0; //���������� 		
	else
	{
		if (gameboard[row-1][col] == 'X')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row-2-i][col] == 'X')
			{ 
			 	i++;
			 	if ((row-1-i) > N)	//������ ������ 
				 	return 0; 
			}
				
			if (gameboard[row-1-i][col] == 'O')
			{
				return 1;	//flip ���� 
			}
			else
				return 0; 
		}
		else
			return 0;
	}
} 


//������ 4��. . .&������ 

int white_flip_possible (int x, int y)
{
	int east_w, west_w, south_w, north_w;
	int output;
	
	east_w = east_white(x, y);		
	west_w = west_white(x, y);	
	south_w = south_white(x, y);		
	north_w = north_white(x, y);
	
	output = (east_w || west_w || south_w || north_w);	//�ϳ��� �Ǹ� ������ ���� 
	
	
	return output;										//output = 1 => ������ ����
}	 


/*
int end_game(int row, int col)
{ 
�� player ��� ��ġ�� �� �ִ� ĭ�� ������ ���� ����
ĭ�� ��� ���ų� ��� ���� �Ѱ��� ����
	
}
*/

int flip_white_turn(int row, int col){
	int i = 0;
	int east = 0; 
	int west = 0; 
	int south = 0;
	int north = 0;
	
	if (east_white(row, col) == 1)
	{
		while (gameboard[row][col - 1 - east] == 'X')
		{
			east++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<east; i++)
			gameboard[row][col - 1 - i] = 'O';
	}
	
	if (west_white(row, col) == 1)
	{
		while (gameboard[row][col + 1 + west] == 'X')
		{
			west++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<west; i++)
			gameboard[row][col + 1 + i] = 'O';
	}
	
	if (south_white(row, col) == 1)
	{
		while (gameboard[row + 1 + south][col] == 'X')
		{
			south++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<south; i++)
			gameboard[row + 1 + i][col] = 'O';
	}
	
	if (north_white(row, col) == 1)
	{
		while (gameboard[row - 1 - north][col] == 'X')
		{
			north++;	//�ش� �������� flip�� ���� ���� 
		}
		//flip
		for (i=0; i<north; i++)
			gameboard[row - 1 - i][col] = 'O';
	}
	//������ 
	printf("flip result : east-%d, west-%d, south-%d, north-%d, \n", east, west, south, north);
	printf("White has flipped %d othellos!\n", east+west+south+north); 
} 
