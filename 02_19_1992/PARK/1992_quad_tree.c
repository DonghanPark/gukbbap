#include <stdio.h>

// 2021.02.19 17:22

// ������ �Լ�
// Ȯ���ϴ� �Լ� 

int N, White = 0, Blue = 0;
int Screen[65][65];

int Split(int StartI, int StartJ, int NowN);
int CheckScreen(int IndexI, int IndexJ, int NowN);

int Split(int StartI, int StartJ, int NowN) {
	
	if (CheckScreen(StartI, StartJ, NowN)) { // �� ���� ���� �ƴ϶�� ������! 
		printf("(");
		NowN = NowN/2;
		Split(StartI, StartJ, NowN);
		Split(StartI, StartJ+NowN, NowN);
		Split(StartI+NowN, StartJ, NowN);
		Split(StartI+NowN, StartJ+NowN, NowN);
		printf(")");
	}

	return 0;
}

int CheckScreen(int IndexI, int IndexJ, int NowN) { // �� ���� �� �¾ƿ�??!! 
	int Color = Screen[IndexI][IndexJ];
	for (int i = IndexI; i < IndexI+NowN; i++) {
		for (int j = IndexJ; j < IndexJ+NowN; j++) {
			if (Color != Screen[i][j])
				return 1; // have to split 
		}
	}
	printf("%d", Color);
	return 0; // don't have to split
}

int main(void) {
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) { // �迭 �ʱ�ȭ 
		for (int j = 0; j < N; j++) {
			scanf("%1d", &Screen[i][j]);
		}
	}
	
	Split(0, 0, N);
		
	return 0;
}
