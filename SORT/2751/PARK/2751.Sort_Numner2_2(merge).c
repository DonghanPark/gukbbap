#include <stdio.h>

// 2020.12.31 18:41
// �ð����⵵ �����ϱ� 
// ����, ����, ����δ� ���� �ȳ��ͼ� �� �����ϰ� Ǯ����

// ���������� ��� �����쿡�� �⺻ ������ ������� 1MB(���氡��)
// �����Ҵ� �Ǵ� ��������, ����ƽ(������))�� ���� ũ�� ������ ���ٰ� ��

// quick sort�� ����ϸ� �ð��ʰ��� ������ ������� ��(���� ���ƾ� AC ���´ٰ� ��)
// merge sort ����ؼ� Ǯ��� ��
// ü���� merge sort�� �� ���� ����  

// �迭�� 2��� ����(������ ����)�ؼ� Arr[2000002}�� �����ؼ�
// �Է¹޴� ���ڰ� index�� �ǰ� �� value�� 1�� �ٲٰ�
// value�� 1�� �� ����ϴ� ����� ���� 

int Arr[1000001] = {0,};
int SortedArr[1000001] = {0,};

int merge(int Left, int Right, int Middle, int Arr[]) {
	
	int i = Left, j = Middle+1, k = Left;
	
	while(i <= Middle && j <= Right) {
		//printf("i %d j %d\n", Arr[i], Arr[j]);
		if (Arr[i] < Arr[j]) {
			SortedArr[k] = Arr[i];
			//printf("!%d ", SortedArr[k]);
			i = i + 1;
		}
		else {
			SortedArr[k] = Arr[j];
			//printf("@%d ", SortedArr[k]);
			j = j + 1;
		}
		k = k + 1;
	}
	
	if (i <= Middle) {
		for (; i <= Middle; i++) {
			SortedArr[k] = Arr[i];
			k = k + 1;
		}
	}
	else if (j <= Right) {
		for(; j <= Right; j++) {
			SortedArr[k] = Arr[j];
			k = k + 1;
		}
	}

	for (int i = Left; i <= Right; i++) {
		Arr[i] = SortedArr[i];
	}
	
}

int merge_sort(int Left, int Right, int Arr[]) {
	int Middle = (Left+Right)/2;
	
	if (Left < Right) {
		merge_sort(Left, Middle, Arr);
		merge_sort(Middle+1, Right, Arr);
		merge(Left, Right, Middle, Arr);
	}
}

int main(void) {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}
	
	merge_sort(0, N-1, Arr);
	printf("\n\n");
	for (int i = 0; i < N; i++) {
		printf("%d\n", Arr[i]);
	}
	
	return 0;
}
// 5 21345
