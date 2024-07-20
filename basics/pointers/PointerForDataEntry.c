#include <stdio.h>

int main(){

	char name[64];

	printf("Enter your name: ");
	scanf("%63s", name);

	printf("\nYour name is : %s",name);

	return 0;
}