#include<stdio.h>

int main(){
	int n;

	printf("Enter number: ");
	scanf("%d", &n);

	for(int i=1, j=n; i<=n && j >= 1; i++, j--){
		if(i % 2 == 0 && j % 2 == 0){
			printf("Divisible by 2. \n");
		}else if(i==j){
			printf("Both i and j are equal. \n");
			printf("i = %d, j = %d \n", i ,j);
		}else{
			printf("i is %d\n", i);
			printf("j is %d\n", j);
		}
	}
	return 0;
}

/**
 * This program has amazing mathematical property
 * in which if you start incrementing from 1 to N by 1 and at the 
 * same time if you start decrementing number from N to 1 by 1. then
 * it will intersect for following number in series.
 * 1, 5, 9, 13, 17, 21, 25,...N etc. 
 * Formula: Next intersection at: n+4 ex: n=1 then next intersect at n = 4
 **/