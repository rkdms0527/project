#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 6
int gameboard[N][N];

/*
//main
void main (��) {
�ʿ��� ������ ����;
init_othello(); //���� �ʱ�ȭ
while (isGameEnd() == 0) { //game ���� ���� Ȯ��
	 	 print_othello(); //��ġ ���� ��� ��
	 	 if (��ġ�� ������ ĭ�� �ִ��� Ȯ��)
	 	 	 continue; //�� player ��� ��ġ�� �Ұ����ϸ� �ݺ����� ������������
	 	 ��ġ�� ��ǥ �Է� �ޱ�;
	 	 if (�Է� ��ǥ�� �������� üũ)
	 	 	 if (������ �õ�) {
				 � ���������� ���;
				 �� �ٲ�;
	 	 	 }
	 	 else
			 �������� �Է����� ���;
}
check_result(); //��� ���
}
*/
void main (){
	reset_game();
	print_board();
}
