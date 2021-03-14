#include <stdio.h>
#include <stdlib.h>

// 2021.03.14 21:21

// �迭�� ī���� �迭�� ����ؼ� ��û �����ϰ� Ǯ�̰� �����ϳ�
// �̰� �� ������ ����� �� �ִ� ��. ���࿡ ���� ������ int ��ü���ٸ� Ʋ�� �ڵ�

// �ش� ���� ã�� �ű⼭ ���� ���ϴ� ���� ã������ �ϴ�
// ������ �̻��� ���� ��
// �׳� ó������ ������ ���ؾ� �ϴ� ���� 

int Card[500001], NumArr[500001], Repetition[500001];
int N, M;

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

// lower�� Upper�� ������ �ʰ� �׳� �ϳ��� �Լ��� ó���ϰ� �������� +1 ���൵ ���� �� 
int Lower(int Start, int End, int Num) {
	
	while (End > Start) {
		int MiddleIndex = Start+((End-Start)/2);
		if (Card[MiddleIndex] >= Num)
			End = MiddleIndex;
		else
			Start = MiddleIndex+1;
	}
	return End;
}

int Upper(int Start, int End, int Num) {
	
	while (End > Start) {
		int MiddleIndex = Start+((End-Start)/2);
		if (Card[MiddleIndex] > Num)
			End = MiddleIndex;
		else
			Start = MiddleIndex+1;
	}
	return End;
}

int main(void) {

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &Card[i]);
	
	qsort(Card, N, sizeof(int), compare);
	
	scanf("%d", &M);
	
	for (int i = 0; i < M; i++)
		scanf("%d", &NumArr[i]);

	for (int i = 0; i < M; i++) {
		printf("%d ", Upper(0, N, NumArr[i]) - Lower(0, N, NumArr[i]));
	}
	
	return 0;
} 
