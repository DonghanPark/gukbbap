#include<stdio.h>
#include<limits.h>

// 2021.01.18 23:24
// ��ȿ - �䳢Ż

// i�� �ƴϸ鼭 �ּ�
// ��� 

// �÷��� ����� ���� �� ������ �� ���� // �Ʒ� �ڵ尡 �׷� // 2��° Ǯ�� ���� ��������
// ó�� 3�� -> 2�� �� ���� �� 1�� 
// ������ ��𿡼� �ϴ��Ŀ� ���� �ٸ�

// memoization�� ��� ������� ��� �����غ���. 
// ��Ʈ��ŷ���ε� Ǯ �� ���� ��

// ����� ��ȯ
// ������ ����� �� �� 2�� �� ����� ���� ���� ���ϴ� ���� �ƴ�
// �̹� ���� ��� 2�� �� ���� ���� ���� Cost�� ���ϴ� ���

int Temp[3], ColorArr[3], CostArr[3] = {0,};

int ReturnMin(int a, int b) {
	return (a < b) ? a : b;
} 

int main(void) {
	int N, MinCost = INT_MAX;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &ColorArr[0], &ColorArr[1], &ColorArr[2]);
		
		Temp[0] = Temp[0] + ReturnMin(CostArr[1], CostArr[2]) + ColorArr[0];
		Temp[1] = Temp[1] + ReturnMin(CostArr[0], CostArr[2]) + ColorArr[1];
		Temp[2] = Temp[2] + ReturnMin(CostArr[0], CostArr[1]) + ColorArr[2];
		
		for (int j = 0; j < 3; j++) {
			CostArr[j] = Temp[j];
			Temp[j] = 0;
		}
	}
	
	for(int i = 0; i < 3; i++) {
		if (CostArr[i] < MinCost)
			MinCost = CostArr[i];
	}
	
	printf("%d\n", MinCost);
	
	return 0;
}
/*
3
1 2 3
1 2 3
100 1 100
3
1 9 1
3 1 2
9 1 9
3
26 40 83
49 60 57
13 89 99
2 
101 100 101
100 1 100 
3
1 20 30
50 5 6
9 3 7
3 
2 1 3
2 1 5
5 4 3
3 
1 2 2
2 1 2
2 1 2
*/
