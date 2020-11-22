#define N 6
int gameboard[N][N];

//flip 가능성 확인하기 
int east_white(int row, int col);		//동 
int west_white(int row, int col);		//서 
int south_white(int row, int col);		//남 
int north_white(int row, int col);	//북 
int southeast_white(int row, int col);	//남동 
int southwest_white(int row, int col);//남서
int northeast_white(int row, int col);	//북동
int northwest_white(int row, int col);	//북서


/*
위 아래...8방향. . . . <<따로!! 
가장자리일때 못 놓음(방향별로 따로 보니까 이 방향으론 뒤집을 돌 존재 불가능) 
	자리 있는데 해당 방향으로 같은 돌일때 못 놓음
	공백일때 못 놓음
		다음다음칸이 없을때 못 놓음
			다른 돌 아닐때까지..
				
이미 있는 자리 <<<<where..?T.T 
*/	

//동
int east_white(int row, int col){
	int i = 0; 
	if ((col-1) < 0)	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row][col-1] == 'X')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row][col-2-i] == 'X')
			{ 
			 	i++;
			 	if ((col-2-i) < 0)	//끝까지 검은돌 
				 	return 0; 
			}
				
			if (gameboard[row][col-2-i] == 'O')
			{
				return 1;	//flip 가능 
			}
			else
				return 0; 
		}
		else
			return 0;
	}
}

//서
int west_white(int row, int col){
	int i = 0; 
	if ((col+1) < 0)	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row][col+1] == 'X')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row][col+2+i] == 'X')
			{ 
			 	i++;
			 	if ((col+2+i) < 0)	//끝까지 검은돌 
				 	return 0; 
			}
				
			if (gameboard[row][col+2+i] == 'O')
			{
				return 1;	//flip 가능 
			}
			else
				return 0; 
		}
		else
			return 0;
	}
} 
//남	
int south_white(int row, int col){
	int i = 0; 
	if ((row+1) >= N )	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row+1][col] == 'X')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row+2+i][col] == 'X')
			{ 
			 	i++;
			 	if ((row+1+i) > N)	//끝까지 검은돌 
				 	return 0; 
			}
				
			if (gameboard[row+2+i][col] == 'O')
			{
				return 1;	//flip 가능 
			}
			else
				return 0; 
		}
		else
			return 0;
	}
}
//북
int north_white(int row, int col){
	int i = 0; 
	if ((row-1) >= N )	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row-1][col] == 'X')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row-2-i][col] == 'X')
			{ 
			 	i++;
			 	if ((row-1-i) > N)	//끝까지 검은돌 
				 	return 0; 
			}
				
			if (gameboard[row-1-i][col] == 'O')
			{
				return 1;	//flip 가능 
			}
			else
				return 0; 
		}
		else
			return 0;
	}
} 


//나머지 4방. . .&검은돌 

int white_flip_possible (int x, int y)
{
	int east_w, west_w, south_w, north_w;
	int output;
	
	east_w = east_white(x, y);		
	west_w = west_white(x, y);	
	south_w = south_white(x, y);		
	north_w = north_white(x, y);
	
	output = (east_w || west_w || south_w || north_w);	//하나라도 되면 돌놓기 가능 
	
	
	return output;										//output = 1 => 돌놓기 가능
}	 


/*
int end_game(int row, int col)
{ 
두 player 모두 배치할 수 있는 칸이 없으면 게임 종료
칸이 모두 차거나 모든 알이 한가지 색깔
	
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
			east++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<east; i++)
			gameboard[row][col - 1 - i] = 'O';
	}
	
	if (west_white(row, col) == 1)
	{
		while (gameboard[row][col + 1 + west] == 'X')
		{
			west++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<west; i++)
			gameboard[row][col + 1 + i] = 'O';
	}
	
	if (south_white(row, col) == 1)
	{
		while (gameboard[row + 1 + south][col] == 'X')
		{
			south++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<south; i++)
			gameboard[row + 1 + i][col] = 'O';
	}
	
	if (north_white(row, col) == 1)
	{
		while (gameboard[row - 1 - north][col] == 'X')
		{
			north++;	//해당 방향으로 flip된 돌의 개수 
		}
		//flip
		for (i=0; i<north; i++)
			gameboard[row - 1 - i][col] = 'O';
	}
	//결과출력 
	printf("flip result : east-%d, west-%d, south-%d, north-%d, \n", east, west, south, north);
	printf("White has flipped %d othellos!\n", east+west+south+north); 
} 
