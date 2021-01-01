#include <stdio.h>

// 2020.12.29 20:54
// 2231_Digit_Generator�� ����� �� 
// ù �ڵ�� 6666���� count�� 2���� �÷��� Ʋ�ȴ� ��
// �� �ڵ忡���� ���ϴ� ��(*666*)�� �ϳ��� üũ�ϰ� �ݺ����� �����°� ����Ʈ

int main(void) {
	int n = 0, temp = 0, count = 0;
	
	scanf("%d", &n);
	
	for (int i = 666; ;i++) {
		temp = i;
		while (temp) {
			if (temp%1000 == 666) {
				count = count + 1;
			}
			temp = temp/10;
		}
		
		if (count)
			n = n - 1;
			
		if (!n) {
			printf("%d\n", i);
			return 0;
		}
		count = 0; 
	}
	
	return 0;
}
