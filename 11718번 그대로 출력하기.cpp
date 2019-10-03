/*#include <stdio.h>

#define MAX 100

char String[MAX][MAX] = {};
int Deadline=MAX;

int main() {
	int i, j;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			scanf("%c", &String[i][j]);
			if (String[i][j] == '\n')	break;
			if (String[i][MAX-1] != '\n')	
				fflush(stdin);
		}
		if (String[i][0] == '\n') {
			String[i][0] = ' ';
			Deadline = i;
			break;
		}
	}

	for (i = 0; i < Deadline; i++) {
		for (j = 0; j < MAX; j++) {
			printf("%c", String[i][j]);
			if (String[i][j] == '\n')	break;
			if (j == MAX - 1)  break;
		}
	}
	return 0;
}
*/

#include <stdio.h>
int main() {
	char w;
	for (; ~scanf("%c", &w);)printf("%c", w);
}