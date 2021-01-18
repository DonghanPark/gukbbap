#include <stdio.h>

// 2021.01.15 22:25
// The Black Skirts - Till the End of Time

// ������ if ������ �ٲ㼭 �ذ�(21 0 0�� ��� 1�̳��;� �ϴµ� 1048576�� ����) 

// ������ȹ�� ���� �ڷ� https://han.gl/2VFT8

int Memoization[21][21][21]; // w(a,b,c) �����ϱ� ���� �迭

int main(void) {
	int a, b, c;
	
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				if (i <= 0 || j <= 0 || k <= 0) { // 3���� index �� 0�� �ϳ��� ������
					Memoization[i][j][k] = 1; // value = 1�Դϴ�, �ƴ� ��쿡 ��� �� ������ ����� ���� 
				}
				else if (i < j && j < k) // i < j < k ��� 
					Memoization[i][j][k] = Memoization[i][j][k-1] + Memoization[i][j-1][k-1] - Memoization[i][j-1][k];
				else // �� �� ��� 
					Memoization[i][j][k] = Memoization[i-1][j][k] + Memoization[i-1][j-1][k] + Memoization[i-1][j][k-1] - Memoization[i-1][j-1][k-1];
			}
		}
	}

	while(1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) // a==b==c==-1�̶�� 
			break; //while�� �������� 
		else if (a <= 0 || b <= 0 || c <= 0) // 3�� �ϳ��� 0�̶��
			printf("w(%d, %d, %d) = %d\n", a, b, c, 1); // ���� 1
		else if (a > 20 || b > 20 || c > 20) // �ϳ��� 20���� ũ�� 
			printf("w(%d, %d, %d) = %d\n", a, b, c, Memoization[20][20][20]); // w(20, 20, 20)�� ��
		else
			printf("w(%d, %d, %d) = %d\n", a, b, c, Memoization[a][b][c]); // �������� w(a,b,c)�� ��
	}
	
	return 0;
}
