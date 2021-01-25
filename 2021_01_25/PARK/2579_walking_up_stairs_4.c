#include <stdio.h>

// 2021.01.21 00:38

// ���������� ����
// 1������ ������ 2�� ���;� �Ѵٰ� �����ؼ� Ʋ��. 211�� ������
// 111�� ������ �ݷʰ� ��������. memoization�� ��������  ���� ��� 
 
// ��� memoization�� ��� ���� �����ϱ� 
// ��͸� ������ȹ������ Ǯ �� �ִ� ��� �׻� �����ϱ� 

// �߰� ���� https://www.acmicpc.net/board/view/52508

int ReturnBiger(int a, int b) {
	return (a > b) ? a : b;
}

int main(void) {
	int N;
	int Stairs[300], Dp[300];

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Stairs[i]);
	}
	
	Dp[0] = Stairs[0];
	
	if (N > 1)
		Dp[1] = Dp[0] + Stairs[1];	
	if (N > 2)
		Dp[2] = ReturnBiger(Stairs[1]+Stairs[2], Stairs[0]+Stairs[2]);
	if (N > 3) {
		for (int i = 3; i < N; i++) {
			Dp[i] = ReturnBiger(Dp[i-3]+Stairs[i-1], Dp[i-2]) + Stairs[i];
		}
	}

	printf("%d\n", Dp[N-1]);
	
	return 0;
}
/*35253761
11
1---
6---
4
7---
3--
7 --
5-
2---
1
5---
3---

11
1
6
4
7
3
7
5
2
1
5
3
*/
