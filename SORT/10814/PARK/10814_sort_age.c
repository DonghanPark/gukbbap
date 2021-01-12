#include <stdio.h>

// 2021.01.09 21:21
// �׻� scanf ���� �� �����ϱ�

// ����ü �����ϱ�
// qsort, compare(pointer) ���� �����ϱ�

typedef struct person{ // ����ü ����. ����, ���� ��, �̸�
	int Age;
	int Join;
	char Name[101];
}Person;

Person Member[100000];
Person SortedMember[100000];

int merge(int Left, int Right, int Middle, Person Member[]) {
	
	int i = Left, j = Middle+1, k = Left;
	
	while(i <= Middle && j <= Right) {
		if (Member[i].Age < Member[j].Age) { // ���� ������
			SortedMember[k] = Member[i];
			i = i + 1;
		}
		else if (Member[i].Age == Member[j].Age) { // ���� ���ٸ�
			if (Member[i].Join < Member[j].Join) { // ������ �� �����ٸ�
				SortedMember[k] = Member[i];
				i = i + 1;
			}
			else { // ������ �����ٸ�
				SortedMember[k] = Member[j];
				j = j + 1;
			}
		}
		else { // ���̰� ������
			SortedMember[k] = Member[j];
			j = j + 1;
		}
		k = k + 1;
	}
	
	if (i <= Middle) {
		for (; i <= Middle; i++) {
			SortedMember[k] = Member[i];
			k = k + 1;
		}
	}
	else if (j <= Right) {
		for(; j <= Right; j++) {
			SortedMember[k] = Member[j];
			k = k + 1;
		}
	}

	for (int i = Left; i <= Right; i++) {
		Member[i] = SortedMember[i];
	}
	
}

int merge_sort(int Left, int Right, Person Member[]) {
	int Middle = (Left+Right)/2;
	
	if (Left < Right) {
		merge_sort(Left, Middle, Member);
		merge_sort(Middle+1, Right, Member);
		merge(Left, Right, Middle, Member);
	}
}

int main(void) {
	
	int N;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d %s", &Member[i].Age, &Member[i].Name);
		Member[i].Join = i; // ���� �� �񱳸� ���� ����
	}

	merge_sort(0, N-1, Member);
	
	for (int i = 0; i < N; i++) {
		printf("%d %s\n", Member[i].Age, Member[i].Name);
	}
	
	return 0;
} 
