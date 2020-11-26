#define N 6
int gameboard[N][N];

//�� flip ���ɼ� Ȯ���ϱ� 
int east_white(int row, int col);		//�� 
int west_white(int row, int col);		//�� 
int south_white(int row, int col);		//�� 
int north_white(int row, int col);		//�� 
int southeast_white(int row, int col);	//���� 
int southwest_white(int row, int col);	//����
int northeast_white(int row, int col);	//�ϵ�
int northwest_white(int row, int col);	//�ϼ�

//������ flip ���ɼ� Ȯ���ϱ� 
int east_black(int row, int col);		//�� 
int west_black(int row, int col);		//�� 
int south_black(int row, int col);		//�� 
int north_black(int row, int col);		//�� 
int southeast_black(int row, int col);	//���� 
int southwest_black(int row, int col);	//����
int northeast_black(int row, int col);	//�ϵ�
int northwest_black(int row, int col);	//�ϼ�

/*
�� �Ʒ�...8����. . . . <<����!! 
�����ڸ��϶� �� ����(���⺰�� ���� ���ϱ� �� �������� ������ �� ���� �Ұ���) 
	�ڸ� �ִµ� �ش� �������� ���� ���϶� �� ����
	�����϶� �� ����
		��������ĭ�� ������ �� ����
			�ٸ� �� �ƴҶ�����..
*/	

//��
int east_white(int row, int col){
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
int west_white(int row, int col){
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
			 	if ((row+2+i) > N)	//������ ������ 
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
			 	if ((row-2-i) > N)	//������ ������ 
				 	return 0; 
			}
				
			if (gameboard[row-2-i][col] == 'O')
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

//���� 
int southeast_white(int row, int col){
	int i = 0; 
	if ((row+1) >= N || (col+1) >= N )	
		return 0; //���������� 		
	else
	{
		if (gameboard[row+1][col+1] == 'X')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row+2+i][col+2+i] == 'X')
			{ 
			 	i++;
			 	if ((row+2+i) > N || ((col+2+i) > N))	//������ ������ 
				 	return 0; 
			}
				
			if (gameboard[row+2+i][col+2+i] == 'O')
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
//���� 
int southwest_white(int row, int col){
	int i = 0; 
	if ((row+1) >= N || (col-1) <= N )	
		return 0; //���������� 		
	else
	{
		if (gameboard[row+1][col-1] == 'X')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row+2+i][col-2-i] == 'X')
			{ 
			 	i++;
			 	if ((row+2+i) > N || ((col-2-i) < N))	//������ ������ 
				 	return 0; 
			}
				
			if (gameboard[row+2+i][col-2-i] == 'O')
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
//�ϵ� 
int northeast_white(int row, int col){

	int i = 0; 
	if ((row-1) <= N || (col+1) >= N )	
		return 0; //���������� 		
	else
	{
		if (gameboard[row-1][col+1] == 'X')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row-2-i][col+2+i] == 'X')
			{ 
			 	i++;
			 	if ((row-2-i) < N || ((col+2+i) > N))	//������ ������ 
				 	return 0; 
			}
				
			if (gameboard[row-2-i][col+2+i] == 'O')
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
//�ϼ� 
int northwest_white(int row, int col){

	int i = 0; 
	if ((row-1) <= N || (col-1) <= N )	
		return 0; //���������� 		
	else
	{
		if (gameboard[row-1][col-1] == 'X')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row-2-i][col-2-i] == 'X')
			{ 
			 	i++;
			 	if ((row-2-i) < N || ((col-2-i) < N))	//������ ������ 
				 	return 0; 
			}
				
			if (gameboard[row-2-i][col-2-i] == 'O')
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

int white_flip_possible (int x, int y)
{
	int east_w, west_w, south_w, north_w;
	int southeast_w, southwest_w, northeast_w, northwest_w;
	int output;
			
	east_w = east_white(x, y);		
	west_w = west_white(x, y);	
	south_w = south_white(x, y);		
	north_w = north_white(x, y);
	southeast_w = southeast_white(x, y);
	southwest_w = southwest_white(x, y);
	northeast_w = northeast_white(x, y);
	northwest_w = northwest_white(x, y);
	
	if(gameboard[x][y] = ' ')	//�����϶��� ���� �� ���� 
	{
	
		output = (east_w || west_w || south_w || north_w
				|| southeast_w || southwest_w || northeast_w || northwest_w);	//�ϳ��� �Ǹ� ������ ���� 
		
		return output;	
	}							//output = 1 => ������ ����
}	 

int flip_white_turn(int row, int col){
	int i = 0;
	int east = 0; 
	int west = 0; 
	int south = 0;
	int north = 0;
	int southeast = 0;	
	int southwest = 0;
	int northeast = 0;
	int northwest = 0;
	
		//put stone 
	gameboard[row][col] = 'O';

	if (east_white(row, col) == 1)
	{
		while (gameboard[row][col + 1 + east] == 'X')
		{
			east++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<east; i++)
			gameboard[row][col + 1 + i] = 'O';
	}
	
	if (west_white(row, col) == 1)
	{
		while (gameboard[row][col - 1 - west] == 'X')
		{
			west++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<west; i++)
			gameboard[row][col - 1 - i] = 'O';
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
	
	if (southeast_white(row, col) == 1)
	{
		while (gameboard[row + 1 + southeast][col + 1 + southeast] == 'X')
		{
			southeast++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<southeast; i++)
			gameboard[row + 1 + i][col + 1 + i] = 'O';
	}
	
	if (southwest_white(row, col) == 1)
	{
		while (gameboard[row + 1 + southeast][col - 1 - southeast] == 'X')
		{
			southwest++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<southwest; i++)
			gameboard[row + 1 + i][col - 1 - i] = 'O';
	}
	
	if (northeast_white(row, col) == 1)
	{
		while (gameboard[row - 1 - northeast][col + 1 + northeast] == 'X')
		{
			northeast++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<northeast; i++)
			gameboard[row - 1 - i][col + 1 + i] = 'O';
	}
	
	if (northwest_white(row, col) == 1)
	{
		while (gameboard[row - 1 - southeast][col - 1 - southeast] == 'X')
		{
			southeast++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<northwest; i++)
			gameboard[row - 1 - i][col - 1 - i] = 'O';
	}
	
	//������ 
	printf("flip result : E-%d, E-%d, S-%d, N-%d, NW-%d, NE-%d, SW-%d SE-%d\n", east, west, south, north, northwest, northeast, southwest, southeast);
	printf("White has flipped %d othellos!\n", east+west+south+north+northwest+northeast+southeast+southwest); 
} 
 //south �̻��� 
 
 //===================black============================================================================

//flip ���ɼ� Ȯ���ϱ� 
int east_black(int row, int col);		//�� 
int west_black(int row, int col);		//�� 
int south_black(int row, int col);		//�� 
int north_black(int row, int col);		//�� 
int southeast_black(int row, int col);	//���� 
int southwest_black(int row, int col);	//����
int northeast_black(int row, int col);	//�ϵ�
int northwest_black(int row, int col);	//�ϼ�

//��
int east_black(int row, int col){
	int i = 0; 
	if ((col+1) < 0)	
		return 0; //���������� 		
	else
	{
		if (gameboard[row][col+1] == 'O')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row][col+2+i] == 'O')
			{ 
			 	i++;
			 	if ((col+2+i) < 0)	//������ ���϶� 
				 	return 0; 
			}
				
			if (gameboard[row][col+2+i] == 'X')
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
int west_black(int row, int col){
	int i = 0; 
	if ((col-1) < 0)	
		return 0; //���������� 		
	else
	{
		if (gameboard[row][col-1] == 'O')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row][col-2-i] == 'O')
			{ 
			 	i++;
			 	if ((col-2-i) < 0)	//������ ���϶� 
				 	return 0; 
			}
				
			if (gameboard[row][col-2-i] == 'X')
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
int south_black(int row, int col){
	int i = 0; 
	if ((row+1) >= N )	
		return 0; //���������� 		
	else
	{
		if (gameboard[row+1][col] == 'O')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row+2+i][col] == 'O')
			{ 
			 	i++;
			 	if ((row+2+i) > N)	//������ ���϶� 
				 	return 0; 
			}
				
			if (gameboard[row+2+i][col] == 'X')
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
int north_black(int row, int col){
	int i = 0; 
	if ((row-1) >= N )	
		return 0; //���������� 		
	else
	{
		if (gameboard[row-1][col] == 'O')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row-2-i][col] == 'O')
			{ 
			 	i++;
			 	if ((row-2-i) > N)	//������ ���϶� 
				 	return 0; 
			}
				
			if (gameboard[row-2-i][col] == 'X')
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

//���� 
int southeast_black(int row, int col){
	int i = 0; 
	if ((row+1) >= N || (col+1) >= N )	
		return 0; //���������� 		
	else
	{
		if (gameboard[row+1][col+1] == 'O')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row+2+i][col+2+i] == 'O')
			{ 
			 	i++;
			 	if ((row+2+i) > N || ((col+2+i) > N))	//������ ���϶� 
				 	return 0; 
			}
				
			if (gameboard[row+2+i][col+2+i] == 'X')
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
//���� 
int southwest_black(int row, int col){
	int i = 0; 
	if ((row+1) >= N || (col-1) <= N )	
		return 0; //���������� 		
	else
	{
		if (gameboard[row+1][col-1] == 'O')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row+2+i][col-2-i] == 'O')
			{ 
			 	i++;
			 	if ((row+2+i) > N || ((col-2-i) < N))	//������ ���϶� 
				 	return 0; 
			}
				
			if (gameboard[row+2+i][col-2-i] == 'X')
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
//�ϵ� 
int northeast_black(int row, int col){
	int i = 0; 
	if ((row-1) <= N || (col+1) >= N )	
		return 0; //���������� 		
	else
	{
		if (gameboard[row-1][col+1] == 'O')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row-2-i][col+2+i] == 'O')
			{ 
			 	i++;
			 	if ((row-2-i) < N || ((col+2+i) > N))	//������ ���϶� 
				 	return 0; 
			}
				
			if (gameboard[row-2-i][col+2+i] == 'X')
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
//�ϼ� 
int northwest_black(int row, int col){
	int i = 0; 
	if ((row-1) <= N || (col-1) <= N )	
		return 0; //���������� 		
	else
	{
		if (gameboard[row-1][col-1] == 'O')//�ش� �������� �ٸ� ���϶�
		{
			while (gameboard[row-2-i][col-2-i] == 'O')
			{ 
			 	i++;
			 	if ((row-2-i) < N || ((col-2-i) < N))	//������ ���϶� 
				 	return 0; 
			}
				
			if (gameboard[row-2-i][col-2-i] == 'X')
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

 

int black_flip_possible (int x, int y)
{
	int east_b, west_b, south_b, north_b;
	int southeast_b, southwest_b, northeast_b, northwest_b;
	int output;
			
	east_b = east_black(x, y);		
	west_b = west_black(x, y);	
	south_b = south_black(x, y);		
	north_b = north_black(x, y);
	southeast_b = southeast_black(x, y);
	southwest_b = southwest_black(x, y);
	northeast_b = northeast_black(x, y);
	northwest_b = northwest_black(x, y);
	if(gameboard[x][y] = ' ')	//�����϶��� ���� �� ���� 
	{
	
		output = (east_b || west_b || south_b || north_b
				|| southeast_b || southwest_b || northeast_b || northwest_b);	//�ϳ��� �Ǹ� ������ ���� 
		
		return output;	
	}												//output = 1 => ������ ����
}	 


/*
int end_game(int row, int col)
{ 
�� player ��� ��ġ�� �� �ִ� ĭ�� ������ ���� ����
ĭ�� ��� ���ų� ��� ���� �Ѱ��� ����
	
}
*/

int flip_black_turn(int row, int col){
	int i = 0;
	int east = 0; 
	int west = 0; 
	int south = 0;
	int north = 0;	
	int southeast = 0;
	int southwest = 0;
	int northeast = 0;
	int northwest = 0;
		//put stone 
	gameboard[row][col] = 'X';

	if (east_black(row, col) == 1)
	{
		while (gameboard[row][col + 1 + east] == 'O')
		{
			east++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<east; i++)
			gameboard[row][col + 1 + i] = 'X';
	}
	
	if (west_black(row, col) == 1)
	{
		while (gameboard[row][col - 1 - west] == 'O')
		{
			west++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<west; i++)
			gameboard[row][col - 1 - i] = 'X';
	}
	
	if (south_black(row, col) == 1)
	{
		while (gameboard[row + 1 + south][col] == 'O')
		{
			south++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<south; i++)
			gameboard[row + 1 + i][col] = 'X';
	}
	
	if (north_black(row, col) == 1)
	{
		while (gameboard[row - 1 - north][col] == 'O')
		{
			north++;	//�ش� �������� flip�� ���� ���� 
		}
		//flip
		for (i=0; i<north; i++)
			gameboard[row - 1 - i][col] = 'X';
	}
	if (southeast_black(row, col) == 1)
	{
		while (gameboard[row + 1 + southeast][col + 1 + southeast] == 'O')
		{
			southeast++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<southeast; i++)
			gameboard[row + 1 + i][col + 1 + i] = 'X';
	}
	
	if (southwest_black(row, col) == 1)
	{
		while (gameboard[row + 1 + southeast][col - 1 - southeast] == 'O')
		{
			southwest++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<southwest; i++)
			gameboard[row + 1 + i][col - 1 - i] = 'X';
	}
	
	if (northeast_black(row, col) == 1)
	{
		while (gameboard[row - 1 - northeast][col + 1 + northeast] == 'O')
		{
			northeast++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<northeast; i++)
			gameboard[row - 1 - i][col + 1 + i] = 'X';
	}
	
	if (northwest_black(row, col) == 1)
	{
		while (gameboard[row - 1 - southeast][col - 1 - southeast] == 'O')
		{
			southeast++;	//�ش� �������� flip�� ���� ����
		}
		//flip
		for (i=0; i<northwest; i++)
			gameboard[row - 1 - i][col - 1 - i] = 'X';
	}
	
	//������ 
	printf("flip result : E-%d, E-%d, S-%d, N-%d, NW-%d, NE-%d, SW-%d SE-%d\n", east, west, south, north, northwest, northeast, southwest, southeast);
	printf("Black has flipped %d othellos!\n", east+west+south+north+northwest+northeast+southeast+southwest); 

} 

 
