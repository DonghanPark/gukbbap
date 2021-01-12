#include <stdio.h>
#include <string.h>

// 2021.01.08 22:49
// ����ü ����� ������ �˰� ���� ����
// ����ü Ȯ���� �����ϱ�. 11650_sort_coordinate ���� �� ����ü Ȱ�� ��������

// �ߺ� ó���� sort �� �� �� �ĸ��Ϸ��� �ϴ� ������� ��.
// �׳�  ��ºο��� ó�����ָ� �Ǵ� �� 

// N�� 1�� ���� ó������ ���ؼ� 100%���� Ʋ�ȴٰ� ���Դ� ��
// strcmp�� ��ȯ�� -1, 0, 1�� �ƴ϶� ����, 0, ���

char StringArr[20000][51] = {0,};
char SortedStringArr[20000][51] = {0,};

int merge(int Left, int Right, int Middle, char StringArr[][51]) {
	
	int i = Left, j = Middle+1, k = Left;
	// ���� Ȯ�� �ʿ�. 0�� �Ǹ� ���߱� (clear)
	// �ߺ� word
	int iLength = 0, jLength = 0;
	
	while(i <= Middle && j <= Right) {
		for (int l = 0; StringArr[i][l]; l++) // ù��° �迭 ����
			iLength = iLength + 1;
		for (int l = 0; StringArr[j][l]; l++) // �ι�° �迭 ����
			jLength = jLength + 1;
		
		if (iLength < jLength) { // ù��° �迭�� ���̰� ������
			for (int l = 0; l < 51; l++) {
				SortedStringArr[k][l] = StringArr[i][l];
			}
			i = i + 1;
		}
		else if (jLength < iLength) { // �ι�° �迭�� ���̰� ������
			for (int l = 0; l < 51; l++) {
				SortedStringArr[k][l] = StringArr[j][l];
			}
			j = j + 1;
		}
		else { // ���̰� ������ 
			if (strcmp(StringArr[i], StringArr[j]) < 0) { // ���� ������
				for (int l = 0; l < 51; l++) {
					SortedStringArr[k][l] = StringArr[i][l];
				}
				i = i + 1;
			}
			else {
				for (int l = 0; l < 51; l++) {
					SortedStringArr[k][l] = StringArr[j][l];
				}
				j = j + 1;
			}
		}
		k = k + 1;
		iLength = 0; // ���� ���� �ʱ�ȭ
		jLength = 0;
	}
	
	if (i <= Middle) {
		for (; i <= Middle; i++) {
			for (int l = 0; l < 51; l++) {
				SortedStringArr[k][l] = StringArr[i][l];
			}
			k = k + 1;
		}
	}
	else if (j <= Right) {
		for(; j <= Right; j++) {
			for (int l = 0; l < 51; l++) {
				SortedStringArr[k][l] = StringArr[j][l];
			}
			k = k + 1;
		}
	}

	for (int i = Left; i <= Right; i++) {
		for (int l = 0; l < 51; l++) {
			StringArr[i][l] = SortedStringArr[i][l];
		}
	}
}

int merge_sort(int Left, int Right, char StringArr[][51]) {
	int Middle = (Left+Right)/2;
	
	if (Left < Right) {
		merge_sort(Left, Middle, StringArr);
		merge_sort(Middle+1, Right, StringArr);
		merge(Left, Right, Middle, StringArr);
	}
}


int main(void) {
	int N;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s", &StringArr[i]);
	}
	
	merge_sort(0, N-1, StringArr);
	
	printf("%s\n", StringArr[0]);
	for (int i = 1; i < N; i++) {
		if (strcmp(SortedStringArr[i-1], SortedStringArr[i]) != 0)
			printf("%s\n", SortedStringArr[i]);
	}
	
	return 0;
}
