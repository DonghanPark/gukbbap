#include <stdio.h>

// 2021.01.10 20:40

int N, M;
int Sequence[8], Visited[9]; // char�� ���� �� �� ����
// ���� �迭�� �湮 ���� üũ �迭 

int BackTracking (int NowDepth) { // ���� ����(�� ��° ��� ������)
	if (NowDepth == M) { // M�� �̾Ҵٸ� 
		for (int i = 0; i < M; i++) {
			printf("%d ", Sequence[i]); // ���
		}
		printf("\n");
		return 0;
	}
	for (int j = 1; j <= N; j++) {
		if (!Visited[j]) { // �湮���� �ʾҴٸ� 
			Visited[j] = 1; // ���� �湮���� 
			Sequence[NowDepth] = j; // ���� ���° �̰� ���� ��������
			BackTracking(NowDepth+1); // ���
			Visited[j] = 0; // ���� ����� ���� ���� �̹湮
		}
	}
	return 0;
}

int main(void) {
	
	scanf("%d %d", &N, &M);
	
	BackTracking(0);
	
	return 0;
} 
