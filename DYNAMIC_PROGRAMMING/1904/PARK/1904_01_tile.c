#include <stdio.h>

// 2021.01.15 23:00
// Deli Spice - Confession

// ��Ģ�� �Ǻ���ġ�� �����ٴ� ���� �˸� ���� ����

// N�� ���� 1000000 ���� ������ �׳� �Ǻ���ġ�� ���ϸ� ����÷ο� �߻�
// ��� �� ���� �ƴ� ó�� ���� �� 15746�� �������� �־�� ��

// �Ʒ� �ڵ�ó�� �޸� ������ ����
// https://www.acmicpc.net/source/25214617

// https://youtu.be/gX4imVi8R6U?t=2431

int NumberOfBinaryTile[1000002];

int main(void) {
	int N;
	
	NumberOfBinaryTile[1] = 1;
	NumberOfBinaryTile[2] = 2;
	
	for (int i = 3; i < 1000001; i++) { // �Ǻ���ġ ���� ���ϱ� 
		NumberOfBinaryTile[i] = (NumberOfBinaryTile[i-1] + NumberOfBinaryTile[i-2])%15746;
	}
	
	scanf("%d", &N);
	printf("%d\n", NumberOfBinaryTile[N]);
	//printf("%d\n", NumberOfBinaryTile[N]%15746);
	
	return 0;
}
