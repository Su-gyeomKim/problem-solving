#include<iostream>
using namespace std;

int a[10003], d[10003];

int main() {
	int n; cin >> n;
	for (int j = 1; j <= n; j++) cin >> a[j];

	d[1] = a[1];    d[2] = a[1] + a[2];

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1];
		d[i] = max(max(d[i - 3] + a[i - 1] + a[i], d[i - 2] + a[i]), d[i]);
	}
	cout << d[n];
}



/*
#include <stdio.h>
#pragma warning(disable:4996)

#define MAX = 10000
int WineList[10000] = { 0 }; //������ ����Ʈ
int CountWine;
int Result = 0;
//int result[3] = {};//����� �����ع��Ⱦ�
// |0 0 0| ���� ū�������� �ΰ� ���°� üũ�ϰ� �������� �ٸ��� ����, X00 �ε� �ڿ� ������ 0X0, 00X �ȵǴϱ� üũ�� �÷��� �ʿ�
int result[6667] = {};
int smallresult[6667][3] = {};
int Flag; // 0 = OOX, 1 =OXO ,2 = XOO
int i, j, k = 0, l = 0;

void Initialize();
int TryWine();


int main() {
	Initialize();
	printf("%d", TryWine());
	return 0;
}


void Initialize() {
	freopen("2156.txt", "r", stdin); setbuf(stdout, NULL);
	scanf("%d", &CountWine);
	for (i = 0; i < CountWine; i++)		scanf("%d", &WineList[i]);
}

int TryWine() {

	int MaximumCount = 6667; //(10000 / 3 * 2) + (10000 % 3);
	int MaxCount = (CountWine / 3 * 2) + (CountWine % 3);

	//result[0] = [1][2] [3]X .... O O X 
	//result[1] = [1] [2]X [3].... O X O 
	//result[2] = [1]X [2][3] .... X O O

	// WineList[N] = 0 �̸� ���ΰ�

	for (j = 0; WineList[j] > 0; j++) {
		k = ((j + 1) / 3) - 1; // j�� 2,5,8...(3�� ��� -1)�̶� +1, 3���� ���� ����-1 ����� 0,1,2,3...�� ����
		if ((j < 3) && ((j + 1) % 3 == 0)) {
			smallresult[0][0] = WineList[j - 2] + WineList[j - 1]; // OOX
			smallresult[0][1] = WineList[j - 2] + WineList[j];		// OXO
			smallresult[0][2] = WineList[j - 1] + WineList[j];		// xOO

			l = 0;
			while (l < 3) {
				//if (result[((j + 1) / 3) - 1] < smallresult[l]) // j�� 2,5,8...(3�� ��� -1)�̶� +1, 3���� ���� ����-1 ����� 0,1,2,3...�� ����
				//	result[((j + 1) / 3) - 1] = smallresult[l];
				l++;
			}

			if (result[k] == smallresult[0][0]) Flag = 0; // OOX
			if (result[k] == smallresult[0][1]) Flag = 1; // OXO
			if (result[k] == smallresult[0][2]) Flag = 2; // xOO
		}

		if ((j > 3) && ((j + 1) % 3 == 0)) {
			smallresult[k][0] = WineList[j - 2] + WineList[j - 1]; // OOX
			smallresult[k][1] = WineList[j - 2] + WineList[j];		// OXO
			smallresult[k][2] = WineList[j - 1] + WineList[j];		// xOO

			 ���� �������� �ִ��� �ƴ϶� �� ���� ������ [6][10] [13]X
			if (Flag == 1)		smallresult[k][0] = 0;

			if (Flag == 2){				smallresult[k][0] = 0,				smallresult[k][1] = 0;			}
			

			l = 0;
			while (l < 3) {
				//if (result[k] < smallresult[l]) // j�� 2,5,8...(3�� ��� -1)�̶� +1, 3���� ���� ����-1 ����� 0,1,2,3...�� ����
				//	result[k] = smallresult[l];
				l++;
			}

			if (result[k] == smallresult[k][0]) Flag = 0; // OOX
			if (result[k] == smallresult[k][1]) Flag = 1; // OXO
			if (result[k] == smallresult[k][2]) Flag = 2; // xOO
		}

	}

	for (j = 0; result[j] > 0; j++)
		Result += result[j];

	return Result;
}
*/