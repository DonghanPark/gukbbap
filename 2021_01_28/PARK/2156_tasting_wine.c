#include <stdio.h>

// 2021.01.23 09:59
// �豤�� - ��������� 

// 2579_walking_up_Stairs�� ����� ����
// ���̴� �������� ������ �Ծ�� �Ѵ�, �ƴϴ� ���� 

// |011
// 1|01 
// |0110 - �ڵ� �� �����ϰ� �� �� ����. (|011�� �ߺ�. ���� WineMax[i-1]) 

// �� �����ϰ� �����ϱ� 

int ReturnBiger(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int N;
	int Wine[10000];
	int WineMax[10000] = {0,};
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Wine[i]);
		if (i == 0)
			WineMax[i] = Wine[i];
		else
			WineMax[i] = WineMax[i-1] + Wine[i];
		printf("%d %d\n", i, WineMax[i]);
	}
	
	if (N > 2) { //101, 011, 110
		WineMax[2] = ReturnBiger(ReturnBiger(WineMax[2]-Wine[0], WineMax[2]-Wine[1]), WineMax[2]-Wine[2]);
		printf("\n%d %d\n", 2, WineMax[2]);
	}
	if (N > 3) { //1101, 1011, 0110
		WineMax[3] = ReturnBiger(ReturnBiger(WineMax[3]-Wine[0]-Wine[3], WineMax[3]-Wine[1]), WineMax[3]-Wine[2]);
		printf("%d %d\n", 3, WineMax[3]);
	}
	if (N > 4) { // 011, 01, 0110
		for(int i = 4; i < N; i++) {
			WineMax[i] = ReturnBiger(WineMax[i-4]+Wine[i-1]+Wine[i-2], ReturnBiger(WineMax[i-3]+Wine[i-1], WineMax[i-2])+Wine[i]);
			printf("%d %d\n", i, WineMax[i]);
		}
	}
	// �� �����ϰ� ����. �����ϱ� 
	
	
	printf("%d", WineMax[N-1]);
	
	return 0;
}
