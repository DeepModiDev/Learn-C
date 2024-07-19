#include <stdio.h>

int main(){
	int n;

	printf("Enter number: ");
	scanf("%d", &n);

	int sum = 0;
	for(int i=1; i<=n; i++){
		sum = sum + i;
	}

	printf("Sum of %d natural numbers are: %d\n",n,sum);

	// We can also use the formula directly.
	// sum = (n * (n + 1)) / 2
	// Ex = (10 * 11) / 2 = 55 Sum of First 10 natural numbers
	// sum = 1+2+3+4+5+6+7+8+9+10 = 55

	return 0;
}