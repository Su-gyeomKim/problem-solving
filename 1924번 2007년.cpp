#include <stdio.h>

int M[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; // �� ���� �� ��, �������� ����ϱ� ���� 0�� ����
char D[7][4] = { "SUN","MON","TUE","WED","THU","FRI","SAT" }; // 7�� ���� �������� �� ���� ����

int main()
{
	int Sum = 0; // �����ϼ�

	int x, y; //�Է¹��� ���� x=month, y=day
	scanf("%d %d", &x, &y);

	for (int i = 0; i<x; i++) Sum = Sum + M[i]; //���� �ϼ�
	int date = (Sum + y) % 7; //date�� ��Ȯ�� ��¥ (���� �� + �Է� ��)
	printf("%s\n", D[date]);

	return 0;
}