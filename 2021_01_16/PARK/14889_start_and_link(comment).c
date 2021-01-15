#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 2021.01.13 17:47
// �ٸ���� �ڵ�� ���غ��� https://www.acmicpc.net/source/13484770

// 2���� ����� ���� ������ ����Ѵ�. 2���� �ּ� �ɷ�ġ ���̸� ���ϴ� ����
// ���� ����� �Լ�, ���� �ɷ�ġ�� ����ϴ� �Լ�, �ּҸ� ���ϴ� �Լ��� �������� 

// ���� ����� �Լ� : ��Ʈ��ŷ�� ����ߴ�. 15649 N&M�� �����ϰ� �������.
// ���� �������δ� N/2�� �Ǿ��� �� �� ���� �ɷ�ġ�� ����ϴ� �Լ��� ȣ���Ѵ� 
// ����� Visited�迭�� value�� 0�� ���� 1�� ������ ������ ����. 

// ���� �ɷ�ġ�� ����ϴ� �Լ� : �ɷ�ġ �迭(StatArr)�� ����ϱ� ���� 2�� for�� ����ߴ�
// ���ǹ����� 2���� ������ ��� 1�� ������ 0�� ������ �Ǵ��ؼ� �� �� �ɷ�ġ�� ����Ѵ�
// ��� �Ŀ� �ɷ�ġ ���� �ּҸ� ���ϴ� �Լ��� ȣ���Ѵ�

// �ɷ�ġ ���� �ּҸ� ���ϴ� �Լ� : ���� ���ϰ� ���ǹ����� �ּ� ���� ���ߴ�. 

int StatArr[20][20]; // ó�� stat�� �Է� �޴� �迭 
int Gap = 0, MinGap = INT_MAX; // ��ŸƮ ���� ��ũ���� ���� �� ���� �ּҰ�
int StartStat = 0, LinkStat = 0; // �� ���� ���� ����
int Visited[20] = {0,}; // ó�� ���� ���� �� ����ϴ� �迭 
int N; // �ο� �Է� �޴� ����

int GetMinGap(void) {
	Gap = abs(StartStat - LinkStat);
	
	if (MinGap > Gap) {
		MinGap = Gap;
	}
	return 0;
}

// ���� ���� �������� ���� �� ���Һ� �ֹ� �ɷ�ġ�� ����Ͽ� 2���� ���� ���ϰ� �� ���� �ּҸ� �Ǵ��Ѵ�
// ó�� �Է� ���� �迭�� ����ϱ� ���� 2�� for���� ����Ͽ���
int CalcStat(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Visited[i] && Visited[j]) { // �� ���Ұ� 1�� ���̶��
				StartStat = StartStat + StatArr[i][j];
			}
			else if (!Visited[i] && !Visited[j]) { // �� ���Ұ� 0�� ���̶�� 
				LinkStat = LinkStat + StatArr[i][j];
			}
		}
	}
	/*
	Gap = abs(StartStat - LinkStat);
	//Gap = StartStat > LinkStat ? StartStat - LinkStat : LinkStat - StartStat;
	if (MinGap > Gap) {
		MinGap = Gap;
	}
	*/
	GetMinGap();
	StartStat = 0, LinkStat = 0;
	return 0;
}

// Visited �迭�� value�� 1�� ���� 0�� ������ ���� �����Ѵ� 
// ���� ������ ���ؼ� ��� ����� ���� �ʿ��߰� ��Ʈ��ŷ�� ����Ͽ���.
// NowPlayer�� ���� ��� player������ ��Ÿ����
// Depth�� ���� ������ ������� ��Ÿ���� 
int MakeTeam(int NowPlayer, int Depth) {
	if (Depth == N/2) { // �� ���� �ο��� �� �ο��� ���̴�.
		CalcStat();
	}
	// ���� �����ϴ� ��� ����� �� Ž���� �ʿ��߱⿡ for���� ��͸� ����ߴ�. 
	// �Ʒ� ������ ���� value�� 0�� ���� 1�� ������ ��������. 
	for (int i = NowPlayer; i < N; i++) {
		if(!Visited[i]) {
			Visited[i] = 1;
			MakeTeam(i+1, Depth+1);
			Visited[i] = 0;
		}
	}
}

int main(void) {

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &StatArr[i][j]);
		}
	}
	
	MakeTeam(0, 0);
	
	printf("%d\n", MinGap);
	
	return 0;
}
