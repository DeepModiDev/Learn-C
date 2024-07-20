#include <stdio.h>

void print_str(char str[]){
	printf("Size of str: %i \n", sizeof(str));
	printf("String is: %s \n", str);
}
int main(){
	char str[] = "Deep";

	print_str(str);

	return 0;
}