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
	print_board();
	
	//��ġ�� ��ǥ �Է� �ޱ�;
	if ((player % 2) == 0)
		printf("put a new white othello : ");
	else 
		printf("put a new black othello : ");

		
	scanf("%d %d", &input_row, &input_col);
	player++;
	white_flip_possible(input_row, input_col);
	flip_white_turn(input_row, input_col);
	print_board();
}
