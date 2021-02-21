#include <stdio.h>

// 2021.02.18 18:18

// ������ �Լ�
// Ȯ���ϴ� �Լ� 

int N, White = 0, Blue = 0;
int Paper[129][129];

int Split(int StartI, int StartJ, int NowN);
int CheckPaper(int IndexI, int IndexJ, int NowN);

int Split(int StartI, int StartJ, int NowN) {
	if (CheckPaper(StartI, StartJ, NowN)) { // ��������~ 
		NowN = NowN/2;
		Split(StartI, StartJ, NowN);
		Split(StartI, StartJ+NowN, NowN);
		Split(StartI+NowN, StartJ, NowN);
		Split(StartI+NowN, StartJ+NowN, NowN);
	}
	return 0;
}

int CheckPaper(int IndexI, int IndexJ, int NowN) { // ����� ���� �� �Դϱ�~? 
	int Color = Paper[IndexI][IndexJ];
	for (int i = IndexI; i < IndexI+NowN; i++) {
		for (int j = IndexJ; j < IndexJ+NowN; j++) {
			if (Color != Paper[i][j])
				return 1; // have to split
		}
	}
	Color == 1 ? Blue++ : White++;
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
	
	printf("%d\n%d\n", White, Blue);
	
	return 0;
}
