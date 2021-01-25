#include<stdio.h>

// 2021.01.17 21:31

// ���� ��ȹ�� ������ memoization�� �� ������ üũ�ϴ� ���� �߿�

// ���� �˰� �� ����
// �迭 �ʱ�ȭ �� �� a[10] = {1,1}. �̸� 11********�� �Ǵ� �� 

// �ĵ��� ������ � ��Ģ�� ������ �ִ��� ([i] = [i-1] + [i-5]) �ľ��ϸ� ���� ����   

int main(void) {
	int T, N;
	long long int PadovanSequence[100] = {1, 1, 1, 2, 2};
	
	scanf("%d", &T);
	
	for (int i = 5; i < 100; i++) {
		PadovanSequence[i] = PadovanSequence[i-5] + PadovanSequence[i-1];
	}
	
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%lld\n", PadovanSequence[N-1]);
	}
	
	return 0;
} 
