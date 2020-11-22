#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 6
int gameboard[N][N];

/*
//main
void main (��) {
�ʿ��� ������ ����;
init_othello(); //���� �ʱ�ȭ										=>OK
while (isGameEnd() == 0) { //game ���� ���� Ȯ��
	 	 print_othello(); //��ġ ���� ��� ��						=>OK
	 	 if (��ġ�� ������ ĭ�� �ִ��� Ȯ��)
	 	 	 continue; //�� player ��� ��ġ�� �Ұ����ϸ� �ݺ����� ������������
	 	 ��ġ�� ��ǥ �Է� �ޱ�;
	 	 if (�Է� ��ǥ�� �������� üũ)								=>
	 	 	 if (������ �õ�) {
				 � ���������� ���;
				 �� �ٲ�;
	 	 	 }
	 	 else
			 �������� �Է����� ���;
}
check_result(); //��� ���											=>?
}
*/
void main (){
	int player = 0;
	int input_row, input_col;
	
	reset_game();

	while (end_game() == 0)
	{
		print_board();
		if (��ġ������ ĭ �ִ��� Ȯ���ϱ�)
			continue;  //�� player ��� ��ġ�� �Ұ����ϸ� �ݺ����� ������������
		//��ġ�� ��ǥ �Է� �ޱ�;
		if ((player % 2) == 0)
			printf("put a new white othello : ");
		else 
			printf("put a new black othello : ");
					
		scanf("%d %d", &input_row, &input_col);
		
		if ((player % 2) == 0)	//white turn
		{

			while (white_flip_possible(input_row, input_col) != 1)	//flip �Ұ����� �ڸ��� �ݺ� 
			{	
				printf("invalid input! (no flip happens)");
				scanf("%d %d", &input_row, &input_col);
			}
			if (white_flip_possible(input_row, input_col) == 1)
			{
				flip_white_turn(input_row, input_col);
				print_board();
			}
			player++;
		}
		else				//black turn
		{
			while (black_flip_possible(input_row, input_col) != 1)
			{	
				printf("invalid input! (no flip happens)");
				scanf("%d %d", &input_row, &input_col);
			}
			if (black_flip_possible(input_row, input_col) == 1)
			{
				flip_black_turn(input_row, input_col);
				print_board();
			}
			player++;
		}
	}
	check_result(); 
}
