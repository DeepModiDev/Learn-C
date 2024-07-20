#include <stdio.h>

int main(){

	int num;

	do{
		printf("Enter number: ");
		scanf("%d", &num);

		printf("Entered number is: %d \n", num);

		if(num % 2 != 0)
			break;
	}while(1);

	return 0;
}