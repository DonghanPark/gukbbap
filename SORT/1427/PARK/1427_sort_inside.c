#include <stdio.h>

// 2021.01.04 18:53
// int ���� -2,147,483,648 ~ 2,147,483,647
// ī���� �迭�� ���� �峭 ���� 

int main(void) {
	int N, DescendingOrderN = 0; // ���ĵ��� ���� ��, ������������ ������ �� 
	int CountArr[10] = {0,}; // ī���� �迭. ���ڸ��� �� �� �ִ� ���� 0 ~ 9. �׷��� ũ�Ⱑ 10�� �迭 ���� 
	
	scanf("%d", &N);
	
	while(N) { // N = N/10���� 1�� �ڸ� ���� �߶� ���� ������
		CountArr[N%10] = CountArr[N%10] + 1; // ī���� �迭�� +1 ��
		N = N/10; // 1�� �ڸ��� ¥���� 
	}

	for (int i = 9; i >= 0; i--) { // ������������ �����ؾ� �ϴϱ� 9���� ����
		if (CountArr[i] > 0) { // ī���� �迭�� ���� ������
			for (int j = 0; j < CountArr[i]; j++) { // ī���� �迭 value �� ��ŭ 
				DescendingOrderN = (DescendingOrderN * 10) + i; // ������������ �� ����� �ֱ�. ���� ���� 10 ���ϰ� ���� �� �����ְ� 
			}
		}
	}
	
	printf("%d\n", DescendingOrderN);
	
	return 0;
}
