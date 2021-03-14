#include <stdio.h>

// �׳� 10816 Upper �Լ� �����ͼ� ��������� ���� Ǯ�� ����
// �Լ��� ���� �����ʰ� while ��������� �� ���� 

int K, N, LongestLAN = 0;
long long Sum = 0;
int LAN[10001];

int FindLongestLAN(int NowLAN, int End) {
	int Count = 0;

	for (int j = 0; j < K; j++)
		Count = Count + LAN[j]/NowLAN; // �� LAN ������ �� ���� ���ϱ� 

	if (Count >= N) { // ���� LAN�� ������ N���� ũ�ų� ���ٸ� 
		if (LongestLAN < NowLAN) // LAN �ִ� ���� ���� 
			LongestLAN = NowLAN;

		// Sum/N�� �´� ���, (200, 201)�̶� ��� 200�� �Ǵ� ��� ó�� 
		if (NowLAN == End || NowLAN == (NowLAN+End)/2) 
			return 0;
		else
			NowLAN = (NowLAN+End)/2; // �߰��� ����

		FindLongestLAN(NowLAN, End);
	}
	else // �۴ٴ� ���� LAN�� ���̸� �� �ٿ��� �Ѵٴ� �� 
		FindLongestLAN(NowLAN/2, NowLAN); 

	return 0;
}

int main(void) {
	
	scanf("%d %d", &K, &N);
	
	for (int i = 0; i < K; i++) {
		scanf("%d", &LAN[i]);
		Sum = Sum + LAN[i];
	}

	FindLongestLAN(Sum/N, Sum/N);
	
	printf("%d\n", LongestLAN);
	
	return 0;
}
