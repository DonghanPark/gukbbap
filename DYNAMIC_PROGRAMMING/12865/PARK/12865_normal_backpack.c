#include <stdio.h>

// 2021.02.02 21:48

// ������ memoization�� ����ϴµ� ����� ��
// �迭�� ��� ��������, �׸��� � ��ȭ���� �������� �˾Ƴ��µ� ������

// ��� ������ ���̻� ������ ���� �ʴ� �κ��� �ִµ� �� �κ��� �ذ��� ��� ã��
// ������ ���ߴ� �κ� ����α� 

// DP�� 1�������� �� �� �������� �ƴ� ���������� �ؾ��ϴ� ������
// ���������� �ϸ� �տ��� �̸� ���� ���� �״�� �ߺ����� ����� ���� ����
// ���԰� 7�̰� ��ġ�� 10�� ������ �� 3���� 10�� ��� ������ 10�� �� Pack[3]+10�� �Ǵ� ��
// �׷��� 20�� �Ǵϱ� ���� ����ߴ� 10�̶�� ���� ���� �ʴ� �� 

// 1���� �迭�� ����� ���� 

int Backpack[101][100001] = {0,};

int Max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int N, K, Index;
	int Weight[101], Value[101];
	
	scanf("%d %d", &N, &K);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &Weight[i], &Value[i]);
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - Weight[i] >= 0)
				Backpack[i][j] = Max(Backpack[i-1][j-Weight[i]]+Value[i], Backpack[i-1][j]);
			else
				Backpack[i][j] = Backpack[i-1][j];
		}
	}
	
	printf("%d\n", Backpack[N][K]);
	
	return 0;
}
