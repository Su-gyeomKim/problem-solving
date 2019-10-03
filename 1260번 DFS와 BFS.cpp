//2017.09.27
//http://www.acmicpc.net/problem/1260
//기본 DFS, BFS
#include <stdio.h>
#include<string.h>

int n; // 정점의 총 갯수
int map[2000][2000]; //2000-> 1000, 2002 -> 1002 하면 틀리는데 왤까?
int visit[2000]; // 인접 행렬과 방문 여부를 나타내는 배열
int Queue[2002];
int front, rear;

void DFS(int v)
{
	visit[v] = 1; // 정점 v를 방문했다고 표시

	printf("%d ", v);
	for (int i = 1; i <= n; i++)
	{
		// 정점 v와 정점 i가 연결되었고, 정점 i를 방문하지 않았다면
		if (map[v][i] == 1 && !visit[i])
		{
			// 정점 i에서 다시 DFS를 시작한다
			DFS(i); //재귀 사용
		}
	}

}
void BFS(int v)
{
	visit[v] = 1; //첫번째 정점 v를 방문했다고 표시
	Queue[rear++] = v; //첫번째 큐에 데이터를 저장하고 rear값 증가
	while (front != rear)
	{
		//큐에 들어가있는 첫번째 데이터를 제외하며 for문이 다 끝난후
		//값을 v에 대입해주며 front의 값을 1 증가
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
	int start; // 시작 정점
	int Edge; //간전갯수 
	int v1, v2; //인접행렬에 넣을 행,열의 입력값

	scanf("%d%d%d", &n, &Edge, &start); //정점의 갯수와 간선의 수 시작정점을 입력

	for (int i = 0; i<Edge; i++) //인접행렬 만들기!
	{
		scanf("%d%d", &v1, &v2);
		map[v1][v2] = map[v2][v1] = 1; // 정점 v1과 정점 v2가 연결되었다고 표시
	}
	DFS(start); // DFS (깊이탐색) 
	printf("\n");

	memset(visit, 0x0, sizeof(visit));

	BFS(start); //BFS (넓이탐색)  

	return 0;
}