#include <stdio.h>

// 2021.01.13 23:07

// �̹� ������ �� �ִ� ������ �ٽ� �ݺ��Ͽ� �ߺ������� ����� �� ��ſ�
// �޸������̼�(memoization)�̶�� ����� ����ؼ� ���� �����͸�  �����صδ� ��
// ��ͷ� �����ϴ� �κ� �����ϱ� https://blog.naver.com/kks227/220777103650
// �߰� ����  https://url.vet/wn5qj

int FiboArr[41]; // N�� 0~40 

int main(void) {
	int T, N;
	
	scanf("%d", &T);
	
	FiboArr[0] = 0;
	FiboArr[1] = 1; // �ʱ� �ʱ�ȭ �� 
	
	for (int i = 2; i < 41; i++) { // �Ǻ���ġ ���� ���� 
		FiboArr[i] = FiboArr[i-1] + FiboArr[i-2];
	}
	
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		if (N == 0)
			printf("%d %d\n", 1, 0);
		else
			printf("%d %d\n", FiboArr[N-1], FiboArr[N]);
	}
	
	// �Ǻ���ġ ������ 0�� �����ϴ� Ƚ��, 1�� �����ϴ� Ƚ�쿡 ���� ������
	// ����ϸ� {1,0,1,1,2,3,5...}, {0,1,1,2,3,5,8...}
	// �Ǻ���ġ�� �����ٴ� ���� �� �� �ִ�. 
	
	return 0;
}
