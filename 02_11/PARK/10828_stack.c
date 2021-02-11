#include <stdio.h>
#include <string.h>

// 2021.02.10 19:52:24

// ����ü�� Top, Stack[10000]�� �����ΰ� �� 
// https://www.acmicpc.net/source/10919744

// ���� https://www.acmicpc.net/source/17761153 

int main(void) {
	int N, Size = -1, PushNum;
	int Stack[10000], Command[7];
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s", Command);
		
		if (strcmp(Command, "push") == 0) {
			Size = Size + 1;
			scanf("%d", &Stack[Size]);
		}
		else if (strcmp(Command, "pop") == 0) {
			if (Size == -1)
				printf("%d\n", -1);
			else {
				printf("%d\n", Stack[Size]);
				Size = Size - 1;
			}
		}
		else if (strcmp(Command, "size") == 0)
			printf("%d\n", Size + 1);
		else if (strcmp(Command, "empty") == 0)
			printf("%d\n", (Size != -1) ? 0 : 1);
		else {
			if (Size == -1)
				printf("%d\n", -1);
			else
				printf("%d\n", Stack[Size]);
		}
	}
	
	return 0;
}
