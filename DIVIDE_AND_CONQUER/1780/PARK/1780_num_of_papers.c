#include <stdio.h>
// 2187

// 2021.02.19 20:06

// index�� row, col�� ������ �� ���� ������ �� 
// �������� �ð��� ���� ���� -> for ��� : 524ms, �Ȼ�� : 500ms

// ������ �Լ�
// Ȯ���ϴ� �Լ� 

int N, MinusOne = 0, PlusOne = 0, Zero = 0;
int Paper[2188][2188];

int Split(int StartI, int StartJ, int NowN);
int CheckPaper(int IndexI, int IndexJ, int NowN);

int Split(int StartI, int StartJ, int NowN) {
	if (CheckPaper(StartI, StartJ, NowN)) { // �ٸ��� ������ ����!! 
		NowN = NowN/3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Split(StartI+NowN*i, StartJ+NowN*j, NowN);
			}
		}
		/*
		Split(StartI, StartJ, NowN);
		Split(StartI, StartJ+NowN, NowN);
		Split(StartI, StartJ+NowN+NowN, NowN);
		Split(StartI+NowN, StartJ, NowN);
		Split(StartI+NowN, StartJ+NowN, NowN);
		Split(StartI+NowN, StartJ+NowN+NowN, NowN);
		Split(StartI+NowN+NowN, StartJ, NowN);
		Split(StartI+NowN+NowN, StartJ+NowN, NowN);
		Split(StartI+NowN+NowN, StartJ+NowN+NowN, NowN);
		*/
	}
	return 0;
}

int CheckPaper(int IndexI, int IndexJ, int NowN) { // ����� �� ���� ���ΰ���?? 
	int Color = Paper[IndexI][IndexJ];
	for (int i = IndexI; i < IndexI+NowN; i++) {
		for (int j = IndexJ; j < IndexJ+NowN; j++) {
			if (Color != Paper[i][j])
				return 1; // have to split 
		}
	}
	Color == 1 ? PlusOne++ : (Color == -1) ? MinusOne++ : Zero++;
	return 0; // don't have to split
}

int main(void) {
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) { // �迭 �ʱ�ȭ 
		for (int j = 0; j < N; j++) {
			scanf("%d", &Paper[i][j]);
		}
	}
	
	Split(0, 0, N);
	
	printf("%d\n%d\n%d\n", MinusOne, Zero, PlusOne);
	
	return 0;
}
