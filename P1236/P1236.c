#include <stdio.h>

int main() {
	int y, x;
	char c;
	scanf("%d %d\n", &y, &x);
	int ys[y];
	int xs[x];
	for (int i = 0; i < y; i++) {
		ys[i] = 0;
	}
	for (int i = 0; i < x; i++) {
		xs[i] = 0;
	}
	
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			scanf("%c", &c);
			if (c == 'X') {
				ys[i] = 1;
				xs[j] = 1;
			}
		}
		if (y - i > 1) {
			scanf("\n");
		}
	}
	int yc = y, xc = x;
	for (int i = 0; i < y; i++) {
		yc -= ys[i];
	}
	for (int i = 0; i < x; i++) {
		xc -= xs[i];
	}
	printf("%d\n", yc > xc ? yc : xc);
}
