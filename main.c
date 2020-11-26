#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 6
int gameboard[N][N];

void main (){
	int player = 0;
	int input_row, input_col;
	
	reset_game();

	while (end_game() == 1)
	{
		print_board();
		//배치할 좌표 입력 받기
		if ((player % 2) == 0)
			printf("put a new white othello : ");
		else 
			printf("put a new black othello : ");
					
		scanf("%d %d", &input_row, &input_col);
		
		if ((player % 2) == 0)	//white turn
		{
			if(main_white_possible() == 1)
			{

				while (white_flip_possible(input_row, input_col) != 1)	//flip 불가능한 자리면 반복 
				{	
					printf("invalid input! (no flip happens)");
					scanf("%d %d", &input_row, &input_col);
				}
				if (white_flip_possible(input_row, input_col) == 1)
				{
					flip_white_turn(input_row, input_col);
				
				}
			}
			else
			{
				printf("turn pass!");
			}
				
			player++;
		}
		else				//black turn
		{
			if(main_black_possible() == 1)
			{
				while (black_flip_possible(input_row, input_col) != 1)
				{	
					printf("invalid input! (no flip happens)");
					scanf("%d %d", &input_row, &input_col);
				}
				if (black_flip_possible(input_row, input_col) == 1)
				{
					flip_black_turn(input_row, input_col);
				
				}
			}
			else
			{
				printf("turn pass!");
			}
			player++;
		}
	}
	
	
	check_result(); 
}
