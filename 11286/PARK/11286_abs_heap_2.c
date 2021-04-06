#include <stdio.h>
#include <stdlib.h>

// 2021.04.06 14:56
// 1896KB 24ms

// �ٸ� ������� ����ü ����ؼ� ������. ���밪�� �������� �迭�� ���� �־ 

int N, PlusIndex = 0, MinusIndex = 0;
int Commend;
int PlusHeap[100001] = {0,};
int MinusHeap[100001] = {0,};

int Swap(int a, int b, int *Heap1, int *Heap2) {
	int Temp = Heap1[a];
	Heap1[a] = Heap2[b];
	Heap2[b] = Temp;
}

int PlusPush(int Num) {
	PlusHeap[++PlusIndex] = Num;
	
	int Child = PlusIndex;
	int Parent = PlusIndex/2;
	
	while (Child > 1 && PlusHeap[Child] < PlusHeap[Parent]) {
		Swap(Parent, Child, PlusHeap, PlusHeap);
		
		Child = Parent;
		Parent = Child/2;
	}
	
	return 0;
}

int MinusPush(int Num) {
	MinusHeap[++MinusIndex] = Num;
	
	int Child = MinusIndex;
	int Parent = MinusIndex/2;
	
	while (Child > 1 && MinusHeap[Child] > MinusHeap[Parent]) {
		Swap(Parent, Child, MinusHeap, MinusHeap);
		
		Child = Parent;
		Parent = Child/2;
	}
	
	return 0;
}

int PlusPop() {
	int Parent = 1;
	int Child = Parent*2;
	int PopNum = PlusHeap[Parent];
	PlusHeap[Parent] = PlusHeap[PlusIndex--];
	
	while (Parent*2 <= PlusIndex) {
		if (PlusHeap[Parent] < PlusHeap[Child] && PlusHeap[Parent] < PlusHeap[Child+1])
			break;
		else if (PlusHeap[Child] < PlusHeap[Child+1]) {
			Swap(Parent, Child, PlusHeap, PlusHeap);

			Parent = Child;
			Child = Parent*2;
		}
		else {
			Swap(Parent, Child+1, PlusHeap, PlusHeap);

			Parent = Child+1;
			Child = Parent*2;
		}
	}
	
	return PopNum;
}

int MinusPop() {
	int Parent = 1;
	int Child = Parent*2;
	int PopNum = MinusHeap[Parent];
	MinusHeap[Parent] = MinusHeap[MinusIndex--];
	
	while (Parent*2 <= MinusIndex) {
		if (MinusHeap[Parent] > MinusHeap[Child] && MinusHeap[Parent] > MinusHeap[Child+1])
			break;
		else if (MinusHeap[Child] > MinusHeap[Child+1]) {
			Swap(Parent, Child, MinusHeap, MinusHeap);

			Parent = Child;
			Child = Parent*2;
		}
		else {
			Swap(Parent, Child+1, MinusHeap, MinusHeap);

			Parent = Child+1;
			Child = Parent*2;
		}
	}
	
	return PopNum;
}

int main(void) {
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Commend);
		
		if (Commend < 0)
			MinusPush(Commend);
		else if (Commend > 0)
			PlusPush(Commend);
		else {
			if (MinusIndex > 0 && PlusIndex > 0) {
				if (abs(MinusHeap[1]) <= PlusHeap[1])
					printf("%d\n", MinusPop());
				else
					printf("%d\n", PlusPop());
			}
			else if (MinusIndex > 0 || PlusIndex > 0) {
				if (MinusIndex > 0)
					printf("%d\n", MinusPop());
				else
					printf("%d\n", PlusPop());
			}
			else
				printf("0\n");
		}
	}
	
	return 0;
}

