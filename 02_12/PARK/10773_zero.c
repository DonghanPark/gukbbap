#include <stdio.h>

// 2021.02.10 20:39

// ������ ���� �ִ� ��� 0���� �ٲٰ� ���� �ִ� �ͺ���
// �׳� ���� �ִ� ���� �ð��� �� ��� �Դ� �� 

int main(void) {
	int K, Num, Index = 0, Sum = 0;
	int Account[100000];
	
	scanf("%d", &K);
	
	while(K--) {
		scanf("%d", &Num);
		
		if (Num != 0) {
			Account[Index] = Num;
			Sum = Sum + Account[Index];
			Index = Index + 1;
		}
		else {
			Index = Index - 1;
			Sum = Sum - Account[Index];
		}
	}

	printf("%d\n", Sum);
	
	return 0;
}
