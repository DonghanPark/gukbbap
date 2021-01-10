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

int Arr[1000001] = {0,}; // ó�� ���� �Է� �޴� �迭
int SortedArr[1000001] = {0,}; // ���ĵ� �迭 

int merge(int Left, int Right, int Middle, int Arr[]) {
	
	int i = Left, j = Middle+1, k = Left; //Arr�� ���� i,j SortedArr�� ���� k 
	
	while(i <= Middle && j <= Right) { // ���߿� ���� ������ �𸣴�
		if (Arr[i] < Arr[j]) { // �� �ֿ� ���� ���� �� �Ǵ�
			SortedArr[k] = Arr[i]; // ���� ���� ����
			i = i + 1; // ���� �����ϱ� ���� �ε�����
		}
		else {
			SortedArr[k] = Arr[j];
			j = j + 1;
		}
		k = k + 1; //SortedArr�� ���� �����ϱ� ���� �ε�����
	}
	
	if (i <= Middle) { // i�� ���̰� j���� �� �� ���
		for (; i <= Middle; i++) {
			SortedArr[k] = Arr[i]; // ������ ���ϰ� ���� �κ��� �ڿ� �߰�
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
		Arr[i] = SortedArr[i]; // ���ĵ� �迭�� Arr�� ����
	}
	
}

int merge_sort(int Left, int Right, int Arr[]) {
	int Middle = (Left+Right)/2; // �迭�� ���� ����
	
	if (Left < Right) { // �������� ������ ���� ���� ������(�迭 ũ�� 2�̻� ���)
		merge_sort(Left, Middle, Arr); // ������(Left)���� ����(Middle)���� �迭 ������
		merge_sort(Middle+1, Right, Arr); // ������(Middle+1)���� ����(Right)���� �迭 ������
		merge(Left, Right, Middle, Arr); // merge sort ����
	}
}

int main(void) {
	int N;

	scanf("%d", &N); // �Է� �Ǵ� ��

	for (int i = 0; i < N; i++) {
		scanf("%d", &Arr[i]); // �迭�� �� �ޱ�
	}
	
	merge_sort(0, N-1, Arr); // merge sort ���� 

	for (int i = 0; i < N; i++) {
		printf("%d\n", Arr[i]); // ���ĵ� �迭 ���
	}
	
	return 0;
}
// 5 21345
