#include <stdio.h>

// 2021.01.29 00:05

// ó�� Ǭ �ڵ�� ��� ����� ���� Ž������ �ʾƼ� Ʋ��
// i or j�� ���� 0�� ���� -1�� ���� �� �ٸ� �޸𸮸� �����ϴϱ� Ʋ�ȴ� ��
//  i or j�� ���� 0�� ���� ���� ó�����ִ� ���� 

int Count[1001][1001];

int main(void) {
	char Str1[1001], Str2[1001];
	int MaxCount = 0;
	
	scanf("%s", Str1);
	scanf("%s", Str2);
	
	for (int i = 0; Str1[i] != 0; i++) {
		for (int j = 0; Str2[j] != 0; j++) {
			if (i == 0 || j == 0) {
				if (Str1[i] == Str2[j])
					Count[i][j] = 1;
				else
					Count[i][j] = i == 0 ? Count[i][j-1]: Count[i-1][j];
			}
			else if (Str1[i] == Str2[j]) {
				Count[i][j] = Count[i-1][j-1] + 1;
			}
			else {
				Count[i][j] = Count[i-1][j] >= Count[i][j-1] ? Count[i-1][j] : Count[i][j-1];
			}
			if (Count[i][j] > MaxCount)
				MaxCount = Count[i][j];
		}
	}
	
	printf("%d\n", MaxCount);
	
	return 0;
}
/*
AACGGAACACGCTTTAAGGGCGATGGAATACCGTGGGTTTACCTAAAACTA
AATCTGGCCTATTCTGGGTCAAATGGCGTGAGCAAACATCGTACA

31

AAATATA
ATATA

5
*/
