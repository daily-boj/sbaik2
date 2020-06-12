#include <stdio.h>

int main() {
	int n, rows;
	scanf("%d\n%d\n", &n, &rows);
	char lower[n];
	char upper[n];
	
	int stairs[rows][n - 1];
	scanf("%s\n", lower);
	
	for (int i = 0; i < n; i++) {
		upper[i] = (char) (65 + i);
	}
	
	char c;
	int lowerStartIndex = -1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < n - 1; j++) {
			scanf("%c", &c);
			stairs[i][j] = c == '-' ? 1 : 0;
			if (c == '?') {
				lowerStartIndex = i + 1;
			}
			if (lowerStartIndex == -1 && c == '-') {
				int temp = upper[j];
				upper[j] = upper[j + 1];
				upper[j + 1] = temp;
			}
		}
		if (rows - i > 1) {
			scanf("\n");
		}
		
	}
	for (int i = rows - 1; i >= lowerStartIndex ; i--) {
		for (int j = 0; j < n - 1; j++) {
			if (stairs[i][j] == 1) {
				int temp = lower[j];
				lower[j] = lower[j + 1];
				lower[j + 1] = temp;
			}
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	printf("%c, ", upper[i]);
	// }
	// printf("\n");
	
	// for (int i = 0; i < n; i++) {
	// 	printf("%c, ", lower[i]);
	// }
	// printf("\n");
	char ans[n - 1];
	int recentlySwapped = 0;
	for (int i = 0; i < n - 1; i++) {
		if (recentlySwapped == 0 && upper[i] == lower[i + 1] && upper[i + 1] == lower[i]) {
			// printf("[%c %c]\n[%c %c]\n\n", upper[i], upper[i + 1], lower[i] , lower[i + 1]);
			int temp = upper[i];
			upper[i] = upper[i + 1];
			upper[i + 1] = temp;
			ans[i] = '-';
			recentlySwapped = 1;
		} else {
			ans[i] = '*';
			recentlySwapped = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		// printf("%c %c\n", upper[i], lower[i]);
		if (upper[i] != lower[i]) {
			for(int j = 0; j < n - 1; j++) {
				printf("x");
			}
			printf("\n");
			return 0;
		}
	}
	
	for (int i = 0; i < n - 1; i++) {
		printf("%c", ans[i]);
	}
	printf("\n");
	// for (int i = 0; i < rows; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		printf("%d", stairs[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
	return 0;
}
