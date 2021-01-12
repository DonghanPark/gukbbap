#include <stdio.h>

// 2021.01.10 23:21

int N, M;
int Sequence[8], Visited[9]; // char�� ���� �� �� ����

int BackTracking (int StartValue, int NowDepth) {
	if (NowDepth == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", Sequence[i]);
		}
		printf("\n");
		return 0;
	}
	for (int j = StartValue; j <= N; j++) { // �ߺ��� ����� �ϹǷ� ���۰� ����
		if (!Visited[j]) {
			Visited[j] = 1;
			Sequence[NowDepth] = j;
			BackTracking(j, NowDepth+1);
			Visited[j] = 0;
		}
	}
	return 0;
}

int main(void) {
	
	scanf("%d %d", &N, &M);
	
	BackTracking(1, 0);
	
	return 0;
} 
