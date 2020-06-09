#include <stdio.h>

int main() { 
	int T; //T = tests
	scanf("%d\n", &T);
	while(T > 0) {
	    int arr[8] = {0,0,0,0,0,0,0,0};
	    char a, b, c;
        scanf("%c%c%c\n", &a, &b, &c);
        arr[4 * ((int) a == 72) + 2 * ((int) b == 72) + ((int) c == 72)]++;
        
	    for (int i = 3; i < 40; i ++) {
	        a = b;
	        b = c;
	        scanf("%c", &c);
	        arr[4 * ((int) a == 72) + 2 * ((int) b == 72) + ((int) c == 72)]++;
	    }
	    printf("%d %d %d %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7]);
	    if (T > 1)  scanf("\n");
	    T--;
	}
	return 0; 
} 
