#include <stdio.h>

// 2020.12.28 18:29
// �� ������ ���� �� ��

// for �ȿ��� index �����ϸ� ���� ������ ������.
// ex) 1 2(+5) 8 9 10 

int main(void) {
	int n = 0, m = 0, temp = 0;
	int num = 0;
	
	scanf("%d", &n);

	for (int i = 1; m == 0 && i <= n; i++) {
		num = i;

		while (num) {
			temp = temp + num%10;
			num = num/10;
		}

		if (n == i+temp)
			m = i;

		temp = 0;
	}
	
	printf("%d\n", m);
	
	return 0;
}

