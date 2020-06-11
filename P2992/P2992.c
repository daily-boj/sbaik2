// this is legit shit code
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
	char raw[6];
	int numbers[10];
	scanf("%s", raw);
	int num = atoi(raw);
	int digits = numOfDigits(num);
	
	for (int i = 0; i < 10; i++){
		numbers[i] = 0;
	}
	
	for (int i = 0; i < digits; i++){
		numbers[(int) raw[i] - 48]++;
	}
	
	int max = 1;
	for (int i = 0; i < digits; i++){
		max *= 10;
	}

	
	char fstr[digits];
	int temp = num + 1;
	for(;temp < max; temp++) {
		sprintf(fstr, "%d", temp);
		int ctr = 0;
		
		int nnn[10];
		for (int i = 0; i < 10; i++){
			nnn[i] = 0;
		}
		for (int i = 0; i < digits; i++) {
			int m = (int) fstr[i] - 48;
			nnn[m]++;
			if (nnn[m] > numbers[m]) {
				ctr = 1;
			}
		}
		if (ctr == 0) {
			break;
			
		}
	}
	
	if (temp == max) {
		printf("0\n");
	} else {
		printf("%d\n", temp);
	}
}
