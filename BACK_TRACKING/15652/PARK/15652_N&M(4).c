#include <stdio.h>

// 2021.01.10 23:30

int N, M;
int Sequence[8];// char�� ���� �� �� ����

int BackTracking (int StartValue, int NowDepth) {
	if (NowDepth == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", Sequence[i]);
		}
		printf("\n");
		return 0;
	}
	for (int j = 1; j <= N; j++) { // �ߺ� ���. �湮���� üũ �ʿ� ���� 
		if (StartValue <= j) { // �񳻸������� ���� ����
			Sequence[NowDepth] = j;
			BackTracking(j, NowDepth+1);
		}
	}
	return 0;
}

int main(void) {
	
	scanf("%d %d", &N, &M);
	
	BackTracking(1, 0);
	
	return 0;
} 
