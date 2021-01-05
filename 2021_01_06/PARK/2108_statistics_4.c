#include <stdio.h>
#include <math.h>

// 2021.01.04 00:22

// ���� ver.1
// ����, �ݿø� ��� 
// merge sort ���� �Ϸ�

// ���� ver.2 
// ��� ��� -0, �ֺ�

// ���� ver.3
// �߾Ӱ� ����, �ֺ�

// ���� ver.4 
// ī���� �迭�θ� �����ϴ� �� ����
// merge sort�� �߾Ӱ� ���ϴ� �ɷ� �ٲ�
// �ٲ��� ���� �¾ƹ���(�� 48�ð� �ٻ��)
// �ᱹ�� �߾Ӱ��� �������� �ɷ�.. �Ƹ��� ���鼭 ���� üũ�ؼ� �׷� ��
// ��� Ǯ�ڴٴ� ������ �� ������ �ڵ��ϱ�. Ʋ���� �� Ʋ�ȴ��� ���� ���� ������ �ٽ� 
// �����η��� ����� ��� �������� ���� ��� Ǯ�� �ٽ� ����� ��� ���� �غ��� // �׻� ����ȭ �ϱ� 

// ���� ���� �� �̷� ����� �ڵ�(ī�������θ� ����)
// https://www.acmicpc.net/source/18408265
// https://www.acmicpc.net/source/9658626

// �ݿø��� round, math.h
// �����տ��� -0.
// �ֺ��� 2��°�� �������� ���
// for���� ���� ó���� �ʱⰪ�� ���ǰ��� ���� ���ϰ� �����ٷ� ���ٴ� ���. 

int CountArr[8001] = {0,}; // ī���� �迭(�ֺ��� ���� ���)
int SortedArr[500001] = {0,}; // merge sort�� ���ĵ� �迭
int Arr[500001] = {0,}; // ��� ���� ������ �迭

// ������ �迭�� �ϳ��� ��ġ�� �����ϴ� �Լ�
int merge(int Start, int End, int Middle, int Arr[]) {
	int i = Start, j = Middle+1, k = Start;
	
	while(i <= Middle && j <= End) {
		if (Arr[i] < Arr[j]) {
			SortedArr[k] = Arr[i];
			i = i + 1;
		}
		else {
			SortedArr[k] = Arr[j];
			j = j + 1;
		}
		k = k + 1;
	}
	
	if (i <= Middle) {
		for(; i <= Middle; i++) {
			SortedArr[k] = Arr[i];
			k = k + 1;
		}
	}
	else if (j <= End) {
		for(; j <= End; j++) {
			SortedArr[k] = Arr[j];
			k = k + 1;
		}
	}
	
	for(int l = Start; l <= End; l++) {
		Arr[l] = SortedArr[l];
	}
	
}

// �迭�� ũ�Ⱑ 1�� �� ������ ������ �Լ� 
int merge_sort(int Start, int End, int Arr[]) {
	int Middle = (Start + End)/2;
	
	if (Start < End) {
		merge_sort(Start, Middle, Arr);
		merge_sort(Middle+1, End, Arr);
		merge(Start, End, Middle, Arr);
	}
}

int main(void) {
	int N, Index, Max = 0, Min = 8001, Sum = 0;
	int Bool = 0, MaxCount = 0, MaxCountMinNum = 8001, SecNum = 0;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Index);
		Arr[i] = Index; // ��� ���� Arr�迭�� ���� 
		Sum = Sum + Index; //��� ��տ� ����� �� �հ� 
		
		Index = Index + 4000; // ī���� �迭�� ���� Index (-4000 == 0, 4000 == 8000. ������ ǥ���ϱ� ���ؼ�)
		
		CountArr[Index] = CountArr[Index] + 1; // �ش� ���� ���� �� �������� �ִ� �迭 

		if (Index > Max)
			Max = Index; // ������ ����ϱ� ���� Max 
		if (Index < Min)
			Min = Index; // ������ ����ϱ� ���� Min 
	}
	
	// ������
	printf("%d\n", (int)round((double)Sum/N)); // round �Լ��� �̿��Ͽ� �ݿø�. 
	
	// �߾Ӱ�
	merge_sort(0, N-1, Arr); // merge sort�� ����
	printf("%d\n", Arr[N/2]); // N/2 �Ŀ� +1�� ���� ���� ������ �迭�� 0���� �����ϴϱ�
	
	// �ֺ�
	for (int i = Min; i < 8001; i++) {
		if (CountArr[i] > MaxCount) { 
			MaxCount = CountArr[i]; // ���� ���� �Էµ� ���� ����  MaxCount
			MaxCountMinNum = i; // ���� �󵵰� ���� �� �� ���� ���� ��
		}
	}
	
	for (int i = MaxCountMinNum+1; i < 8001; i++) { // �ֺ��� �� �ϳ� ���� �˻� 
		if (CountArr[i] == MaxCount)
			Bool = 1; // �� �ϳ��� �ƴ϶�� Bool = 1 
	}
	
	if (Bool) { // �ֺ��� �ϳ��� �ƴ϶�� 
		for (int j = MaxCountMinNum+1; j < 8001 && !SecNum; j++) { //���� �󵵰� ���� �� �� 2��°��  ���� ���� ���� ������
			if (CountArr[j] == MaxCount)
				SecNum = j;
		}
	}
	else
		SecNum = MaxCountMinNum; // �� �ϳ���� �ֺ��� ���� �󵵰� ���� �� �� ���� ���� ��

	printf("%d\n", SecNum-4000); // ī���� �迭�̴ϱ� ���� ���� -4000�� �� �� 
	printf("%d\n", Max-Min); // ó�� �Է� ���� �� ���ص� Max�� Min�� Ȱ���� ���� 
	
	return 0;
}
//Test Case

//3 1 2 3
//3 4000 4000 4000
//3 -1 -1 1
//5 0 0 0 1 3
//5 0 0 -8 -11 -100
//3 -4000 3999 0
