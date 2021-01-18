#include <stdio.h>
#include <stdlib.h>

// 21.01.12 17:33
// 2�� for���� ������� �ʰ� count / 9, count % 9 ����ؼ� index ����
// ���� ���� �ʴ� ���� ä������ ��� �װ� ó������ �ٽ� 0���� ä�� �� ��� Ʋ�� ��
// board�� ���� �ִ� ������ �ٲ�
// ���� ���� ���� ��� 1���� ����� ��������
// exit(0 or -1), stdlib.h

// �� �ڵ�� ���غ���  https://www.acmicpc.net/source/5270369
// https://www.acmicpc.net/source/24632801
// https://www.acmicpc.net/source/6715519

int Sudoku[9][9];
int Count = 0;

int CheckSudoku(int IndexI, int IndexJ, int NowNumber) {
	int BoxIndexI = IndexI-IndexI%3; //for squre index
	int BoxIndexJ = IndexJ-IndexJ%3;
	
	for (int i = 0; i < 9; i++) {
		if (i != IndexI && Sudoku[i][IndexJ] == NowNumber) { //row check
			return 0; 
		}
		else if (i != IndexJ && Sudoku[IndexI][i] == NowNumber) { //col check
			return 0;
		}
	}
	
	for (int j = BoxIndexI; j < BoxIndexI+3; j++) { // squre check
		for (int k = BoxIndexJ; k < BoxIndexJ+3; k++) {
			if ((j != IndexI || k != IndexJ) && Sudoku[j][k] == NowNumber) {
				return 0;
			}
		}
	}
	return 1;
}

int SolveSudoku(int Count) {
	if (Count == 81) { // ������ ĭ�� ������ 81��. 0���� ���������� 81�̸�
		
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", Sudoku[i][j]); // ������ ����ϼ��� 
			}
			printf("\n");
		}
		printf("\n");
		exit(0);
	}
	
	int i = Count / 9; // row
	int j = Count % 9; // col

	if (Sudoku[i][j] == 0) { // ���� index�� ���� ������ 
		for (int k = 1; k <= 9; k++) {
			if (CheckSudoku(i, j, k)) { // ���� k�� ���⿡ �˸��� ������ 
				Sudoku[i][j] = k; // ������ k ���� 
				SolveSudoku(Count + 1); // ���� index 
				Sudoku[i][j] = 0; // 1~9 �� �´� ���� ���� ���� ����� �ʱ�ȭ 
			}

		}
	}
	else { // ���� index�� ���� ������ 
		SolveSudoku(Count + 1); // ���� index 
	}

	return 0;
}

int main(void) {
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &Sudoku[i][j]);
		}
	}
	
	SolveSudoku(0);
	
	return 0;
}

/*
test case
0 0 2 0 9 6 0 0 0
0 0 9 0 5 8 7 0 0
0 5 0 2 7 1 9 4 0
0 0 5 8 1 7 4 0 0
0 0 0 9 3 5 2 1 7
1 9 7 6 2 4 8 3 5
0 6 4 5 8 3 1 7 0
0 0 1 7 4 9 6 0 0
0 0 0 1 6 2 0 0 4

0 6 0 0 0 0 2 0 9
0 0 0 8 2 0 5 0 0
0 1 0 9 0 3 0 0 0
3 7 0 0 9 0 0 0 6
1 0 0 0 0 0 0 0 8
2 0 0 0 4 0 0 5 1
0 0 0 5 0 4 0 9 0
0 0 3 0 7 9 0 0 0
5 0 9 0 0 0 0 6 0

0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/
