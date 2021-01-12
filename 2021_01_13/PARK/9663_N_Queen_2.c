#include <stdio.h>
#include <stdlib.h>

// 2021.01.11 11:12

// �湮���� Ȯ�� 2���� �迭�� ��������� => �ð��ʰ� 
// index�� x�� value�� y�� ��� �� �迭�� ����� ��

// �ٸ� ��� �ڵ� ���� �غ��� 
// https://www.acmicpc.net/source/21665771 
// https://www.acmicpc.net/source/2802464

int N, Count = 0;
int QueenPlace[16];

int CheckPlace (int x, int y) {
	for (int i = 0; i < x; i++) {
		if (QueenPlace[i] == y || abs(x-i) == abs(QueenPlace[i]-y)) {
			return 0;
		}
	}
	return 1;
}

int NumberOfCases (int NowDepth) {
	
	if (NowDepth == N) {
		Count = Count + 1;
		return 0;
	}
	
	for (int i = 0; i < N; i++) {
		QueenPlace[NowDepth] = i;
		if (CheckPlace(NowDepth, i)) {
			NumberOfCases(NowDepth + 1);
		}
	}
	
}

int main(void) {
	
	scanf("%d", &N);
	
	NumberOfCases(0);
	
	printf("%d\n", Count);
		
	return 0;
}
