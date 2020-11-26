#define N 6
int gameboard[N][N];

//흰돌 flip 가능성 확인하기 
int east_white(int row, int col);		//동 
int west_white(int row, int col);		//서 
int south_white(int row, int col);		//남 
int north_white(int row, int col);		//북 
int southeast_white(int row, int col);	//남동 
int southwest_white(int row, int col);	//남서
int northeast_white(int row, int col);	//북동
int northwest_white(int row, int col);	//북서

//검은돌 flip 가능성 확인하기 
int east_black(int row, int col);		//동 
int west_black(int row, int col);		//서 
int south_black(int row, int col);		//남 
int north_black(int row, int col);		//북 
int southeast_black(int row, int col);	//남동 
int southwest_black(int row, int col);	//남서
int northeast_black(int row, int col);	//북동
int northwest_black(int row, int col);	//북서

/*
위 아래...8방향. . . . <<따로!! 
가장자리일때 못 놓음(방향별로 따로 보니까 이 방향으론 뒤집을 돌 존재 불가능) 
	자리 있는데 해당 방향으로 같은 돌일때 못 놓음
	공백일때 못 놓음
		다음다음칸이 없을때 못 놓음
			다른 돌 아닐때까지..
*/	

//동
int east_white(int row, int col){
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

//서
int west_white(int row, int col){
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
			 	if ((row+2+i) > N)	//끝까지 검은돌 
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
			 	if ((row-2-i) > N)	//끝까지 검은돌 
				 	return 0; 
			}
				
			if (gameboard[row-2-i][col] == 'O')
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

//남동 
int southeast_white(int row, int col){
	int i = 0; 
	if ((row+1) >= N || (col+1) >= N )	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row+1][col+1] == 'X')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row+2+i][col+2+i] == 'X')
			{ 
			 	i++;
			 	if ((row+2+i) > N || ((col+2+i) > N))	//끝까지 검은돌 
				 	return 0; 
			}
				
			if (gameboard[row+2+i][col+2+i] == 'O')
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
//남서 
int southwest_white(int row, int col){
	int i = 0; 
	if ((row+1) >= N || (col-1) <= N )	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row+1][col-1] == 'X')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row+2+i][col-2-i] == 'X')
			{ 
			 	i++;
			 	if ((row+2+i) > N || ((col-2-i) < N))	//끝까지 검은돌 
				 	return 0; 
			}
				
			if (gameboard[row+2+i][col-2-i] == 'O')
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
//북동 
int northeast_white(int row, int col){

	int i = 0; 
	if ((row-1) <= N || (col+1) >= N )	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row-1][col+1] == 'X')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row-2-i][col+2+i] == 'X')
			{ 
			 	i++;
			 	if ((row-2-i) < N || ((col+2+i) > N))	//끝까지 검은돌 
				 	return 0; 
			}
				
			if (gameboard[row-2-i][col+2+i] == 'O')
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
//북서 
int northwest_white(int row, int col){

	int i = 0; 
	if ((row-1) <= N || (col-1) <= N )	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row-1][col-1] == 'X')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row-2-i][col-2-i] == 'X')
			{ 
			 	i++;
			 	if ((row-2-i) < N || ((col-2-i) < N))	//끝까지 검은돌 
				 	return 0; 
			}
				
			if (gameboard[row-2-i][col-2-i] == 'O')
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
	
	if(gameboard[x][y] = ' ')	//공백일때만 놓을 수 있음 
	{
	
		output = (east_w || west_w || south_w || north_w
				|| southeast_w || southwest_w || northeast_w || northwest_w);	//하나라도 되면 돌놓기 가능 
		
		return output;	
	}							//output = 1 => 돌놓기 가능
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
			east++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<east; i++)
			gameboard[row][col + 1 + i] = 'O';
	}
	
	if (west_white(row, col) == 1)
	{
		while (gameboard[row][col - 1 - west] == 'X')
		{
			west++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<west; i++)
			gameboard[row][col - 1 - i] = 'O';
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
	
	if (southeast_white(row, col) == 1)
	{
		while (gameboard[row + 1 + southeast][col + 1 + southeast] == 'X')
		{
			southeast++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<southeast; i++)
			gameboard[row + 1 + i][col + 1 + i] = 'O';
	}
	
	if (southwest_white(row, col) == 1)
	{
		while (gameboard[row + 1 + southeast][col - 1 - southeast] == 'X')
		{
			southwest++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<southwest; i++)
			gameboard[row + 1 + i][col - 1 - i] = 'O';
	}
	
	if (northeast_white(row, col) == 1)
	{
		while (gameboard[row - 1 - northeast][col + 1 + northeast] == 'X')
		{
			northeast++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<northeast; i++)
			gameboard[row - 1 - i][col + 1 + i] = 'O';
	}
	
	if (northwest_white(row, col) == 1)
	{
		while (gameboard[row - 1 - southeast][col - 1 - southeast] == 'X')
		{
			southeast++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<northwest; i++)
			gameboard[row - 1 - i][col - 1 - i] = 'O';
	}
	
	//결과출력 
	printf("flip result : E-%d, E-%d, S-%d, N-%d, NW-%d, NE-%d, SW-%d SE-%d\n", east, west, south, north, northwest, northeast, southwest, southeast);
	printf("White has flipped %d othellos!\n", east+west+south+north+northwest+northeast+southeast+southwest); 
} 
 //south 이상해 
 
 //===================black============================================================================

//flip 가능성 확인하기 
int east_black(int row, int col);		//동 
int west_black(int row, int col);		//서 
int south_black(int row, int col);		//남 
int north_black(int row, int col);		//북 
int southeast_black(int row, int col);	//남동 
int southwest_black(int row, int col);	//남서
int northeast_black(int row, int col);	//북동
int northwest_black(int row, int col);	//북서

//동
int east_black(int row, int col){
	int i = 0; 
	if ((col+1) < 0)	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row][col+1] == 'O')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row][col+2+i] == 'O')
			{ 
			 	i++;
			 	if ((col+2+i) < 0)	//끝까지 흰돌일때 
				 	return 0; 
			}
				
			if (gameboard[row][col+2+i] == 'X')
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
int west_black(int row, int col){
	int i = 0; 
	if ((col-1) < 0)	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row][col-1] == 'O')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row][col-2-i] == 'O')
			{ 
			 	i++;
			 	if ((col-2-i) < 0)	//끝까지 흰돌일때 
				 	return 0; 
			}
				
			if (gameboard[row][col-2-i] == 'X')
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
int south_black(int row, int col){
	int i = 0; 
	if ((row+1) >= N )	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row+1][col] == 'O')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row+2+i][col] == 'O')
			{ 
			 	i++;
			 	if ((row+2+i) > N)	//끝까지 흰돌일때 
				 	return 0; 
			}
				
			if (gameboard[row+2+i][col] == 'X')
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
int north_black(int row, int col){
	int i = 0; 
	if ((row-1) >= N )	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row-1][col] == 'O')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row-2-i][col] == 'O')
			{ 
			 	i++;
			 	if ((row-2-i) > N)	//끝까지 흰돌일때 
				 	return 0; 
			}
				
			if (gameboard[row-2-i][col] == 'X')
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

//남동 
int southeast_black(int row, int col){
	int i = 0; 
	if ((row+1) >= N || (col+1) >= N )	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row+1][col+1] == 'O')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row+2+i][col+2+i] == 'O')
			{ 
			 	i++;
			 	if ((row+2+i) > N || ((col+2+i) > N))	//끝까지 흰돌일때 
				 	return 0; 
			}
				
			if (gameboard[row+2+i][col+2+i] == 'X')
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
//남서 
int southwest_black(int row, int col){
	int i = 0; 
	if ((row+1) >= N || (col-1) <= N )	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row+1][col-1] == 'O')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row+2+i][col-2-i] == 'O')
			{ 
			 	i++;
			 	if ((row+2+i) > N || ((col-2-i) < N))	//끝까지 흰돌일때 
				 	return 0; 
			}
				
			if (gameboard[row+2+i][col-2-i] == 'X')
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
//북동 
int northeast_black(int row, int col){
	int i = 0; 
	if ((row-1) <= N || (col+1) >= N )	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row-1][col+1] == 'O')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row-2-i][col+2+i] == 'O')
			{ 
			 	i++;
			 	if ((row-2-i) < N || ((col+2+i) > N))	//끝까지 흰돌일때 
				 	return 0; 
			}
				
			if (gameboard[row-2-i][col+2+i] == 'X')
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
//북서 
int northwest_black(int row, int col){
	int i = 0; 
	if ((row-1) <= N || (col-1) <= N )	
		return 0; //빠져나가기 		
	else
	{
		if (gameboard[row-1][col-1] == 'O')//해당 방향으로 다른 돌일때
		{
			while (gameboard[row-2-i][col-2-i] == 'O')
			{ 
			 	i++;
			 	if ((row-2-i) < N || ((col-2-i) < N))	//끝까지 흰돌일때 
				 	return 0; 
			}
				
			if (gameboard[row-2-i][col-2-i] == 'X')
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
	if(gameboard[x][y] = ' ')	//공백일때만 놓을 수 있음 
	{
	
		output = (east_b || west_b || south_b || north_b
				|| southeast_b || southwest_b || northeast_b || northwest_b);	//하나라도 되면 돌놓기 가능 
		
		return output;	
	}												//output = 1 => 돌놓기 가능
}	 


/*
int end_game(int row, int col)
{ 
두 player 모두 배치할 수 있는 칸이 없으면 게임 종료
칸이 모두 차거나 모든 알이 한가지 색깔
	
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
			east++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<east; i++)
			gameboard[row][col + 1 + i] = 'X';
	}
	
	if (west_black(row, col) == 1)
	{
		while (gameboard[row][col - 1 - west] == 'O')
		{
			west++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<west; i++)
			gameboard[row][col - 1 - i] = 'X';
	}
	
	if (south_black(row, col) == 1)
	{
		while (gameboard[row + 1 + south][col] == 'O')
		{
			south++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<south; i++)
			gameboard[row + 1 + i][col] = 'X';
	}
	
	if (north_black(row, col) == 1)
	{
		while (gameboard[row - 1 - north][col] == 'O')
		{
			north++;	//해당 방향으로 flip된 돌의 개수 
		}
		//flip
		for (i=0; i<north; i++)
			gameboard[row - 1 - i][col] = 'X';
	}
	if (southeast_black(row, col) == 1)
	{
		while (gameboard[row + 1 + southeast][col + 1 + southeast] == 'O')
		{
			southeast++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<southeast; i++)
			gameboard[row + 1 + i][col + 1 + i] = 'X';
	}
	
	if (southwest_black(row, col) == 1)
	{
		while (gameboard[row + 1 + southeast][col - 1 - southeast] == 'O')
		{
			southwest++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<southwest; i++)
			gameboard[row + 1 + i][col - 1 - i] = 'X';
	}
	
	if (northeast_black(row, col) == 1)
	{
		while (gameboard[row - 1 - northeast][col + 1 + northeast] == 'O')
		{
			northeast++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<northeast; i++)
			gameboard[row - 1 - i][col + 1 + i] = 'X';
	}
	
	if (northwest_black(row, col) == 1)
	{
		while (gameboard[row - 1 - southeast][col - 1 - southeast] == 'O')
		{
			southeast++;	//해당 방향으로 flip된 돌의 개수
		}
		//flip
		for (i=0; i<northwest; i++)
			gameboard[row - 1 - i][col - 1 - i] = 'X';
	}
	
	//결과출력 
	printf("flip result : E-%d, E-%d, S-%d, N-%d, NW-%d, NE-%d, SW-%d SE-%d\n", east, west, south, north, northwest, northeast, southwest, southeast);
	printf("Black has flipped %d othellos!\n", east+west+south+north+northwest+northeast+southeast+southwest); 

} 

 
