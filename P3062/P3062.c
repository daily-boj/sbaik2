#include <stdio.h>
#include <stdlib.h>

int numOfDigits(int i) {
	int d = 0;
	while(i > 0) {
		i/=10;
		d++;
	}
	return d > 0 ? d : 1;
}
int main() { 
	int n;
	scanf("%d", &n);
	while(n > 0) {
		char raw[6];
		scanf("%s", raw);
		int number = atoi(raw);
		int digits = numOfDigits(number);
		int	rnumber = 0;
		for (int i = digits - 1; i >= 0; i--) {
			int temp = 1;
			for (int j = 0; j < i; j++) {
				temp *= 10;
			}
			rnumber += temp * ((int)raw[i] - 48);
		}
		int fnumber = number + rnumber;
		int fdigit = numOfDigits(fnumber);
		char fstr[7];
		sprintf(fstr, "%d", fnumber);
		
		
		int result = 1;
		for (int i = 0; i < fdigit/2; i++) {
			if (fstr[i] != fstr[fdigit - i - 1]) {
				result = 0;
				break;
			}
		}
		
		printf(result == 1 ? "YES\n":"NO\n");
		if (n > 1) scanf("\n");
		n--;
	}
	return 0; 
}