#include <stdio.h>
#include <string.h>
#include "boggle.h"

char board[MAX][MAX + 1];
int N;
int M;
int dr[] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int dc[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
char word[MAX];

void initBoard(void) {
	int i;
	int j;

	N = MAX;
	M = MAX + 1;

	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<M ; j++) {
			board[i][j] = '\0';
		}
	}
}

void createBoard(void) {
	int i;

	scanf("%d %d", &N, &M);
	scanf("%s", word);
	word[strlen(word)] = '\0';

	for (i=0 ; i<N ; i++) {
		scanf("%s", board[i]);
	}
}

void printBoard(void) {
	int i;

	for (i=0 ; i<N ; i++) {
		printf("%s\n", board[i]);
	}
}

int searchWord(void) {
	int i;
	int j;

	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			if (board[i][j] == *word) {
				if (DFS(i, j, word) == 1) {
					return 1;
				}
			}
		}
	}

	return 0;
}

int DFS(int row, int col, const char *word) {
	int i;
	int nr;
	int nc;

	if ((row < 0) || (row >= N) || (col < 0) || (col >= M)) {
		return 0;
	}
	else if (board[row][col] != word[0]) {
		return 0;
	}
	else if (strlen(word) == 1) {
		return 1;
	}
	else {
		for (i=0 ; i<8 ; i++) {
			nr = row + dr[i];
			nc = col + dc[i];

			if (DFS(nr, nc, word + 1) == 1) {
				return 1;
			}
		}
		return 0;
	}
}
