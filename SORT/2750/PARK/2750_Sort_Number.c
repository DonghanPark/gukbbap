#include <stdio.h>

// 2020.12.30 09:34
// �׳� �ּ� ���ؼ� ��� ����ϸ� �Ǵµ� ������ �����̴� �׷��� Ǯ�� 
// selection sort�� Ǯ���� 
// bubble sort, insertion sort �߰��� �ٽ� �н��ϱ�
// ��������, ��������, �������� ������ �����ٰ� ��.
// ���������� ��� BEST������ �ð����⵵�� n^2�� �ƴ� n 
// reference : https://gmlwjd9405.github.io/2018/05/06/algorithm-insertion-sort.html

int main(void) {
	int N, Min = 0, MinIndex = 0, Temp = 0;
	int Arr[1000] = {0,};
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}
	
	for (int i = 0; i < N; i++) {
		Min = Arr[i];
		for (int j = i; j < N; j++) {
			if (Arr[j] <= Min) {
				Min = Arr[j];
				MinIndex = j;
			}
		}
		Temp = Arr[i];
		Arr[i] = Arr[MinIndex];
		Arr[MinIndex] = Temp; 
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", Arr[i]);
	}
	
	return 0;
}
