//2017.09.27
//http://www.acmicpc.net/problem/1260
//�⺻ DFS, BFS
#include <stdio.h>
#include<string.h>

int n; // ������ �� ����
int map[2000][2000]; //2000-> 1000, 2002 -> 1002 �ϸ� Ʋ���µ� �ͱ�?
int visit[2000]; // ���� ��İ� �湮 ���θ� ��Ÿ���� �迭
int Queue[2002];
int front, rear;

void DFS(int v)
{
	visit[v] = 1; // ���� v�� �湮�ߴٰ� ǥ��

	printf("%d ", v);
	for (int i = 1; i <= n; i++)
	{
		// ���� v�� ���� i�� ����Ǿ���, ���� i�� �湮���� �ʾҴٸ�
		if (map[v][i] == 1 && !visit[i])
		{
			// ���� i���� �ٽ� DFS�� �����Ѵ�
			DFS(i); //��� ���
		}
	}

}
void BFS(int v)
{
	visit[v] = 1; //ù��° ���� v�� �湮�ߴٰ� ǥ��
	Queue[rear++] = v; //ù��° ť�� �����͸� �����ϰ� rear�� ����
	while (front != rear)
	{
		//ť�� ���ִ� ù��° �����͸� �����ϸ� for���� �� ������
		//���� v�� �������ָ� front�� ���� 1 ����
		v = Queue[front++];
		printf("%d ", v);
		for (int i = 1; i <= n; i++)
		{
			if (map[v][i] == 1 && !visit[i])
			{
				visit[i] = 1;
				Queue[rear++] = i;
			}
		}
	}

}
int main()
{
	int start; // ���� ����
	int Edge; //�������� 
	int v1, v2; //������Ŀ� ���� ��,���� �Է°�

	scanf("%d%d%d", &n, &Edge, &start); //������ ������ ������ �� ���������� �Է�

	for (int i = 0; i<Edge; i++) //������� �����!
	{
		scanf("%d%d", &v1, &v2);
		map[v1][v2] = map[v2][v1] = 1; // ���� v1�� ���� v2�� ����Ǿ��ٰ� ǥ��
	}
	DFS(start); // DFS (����Ž��) 
	printf("\n");

	memset(visit, 0x0, sizeof(visit));

	BFS(start); //BFS (����Ž��)  

	return 0;
}