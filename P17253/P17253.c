#include <stdio.h>
int main() { 
	long long int n;
	scanf("%lld", &n);
	if (n == 0) {
		printf("NO\n");
		return 0;
	}
	for(;n > 0; n /= 3) {
		if (n % 3 > 1) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0; 
}