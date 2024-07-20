#include <stdio.h>

int main(){

	char name[20];

	printf("Enter your name: ");
	fgets(name, sizeof(name), stdin);
	printf("\nYour name is: %s",name);

	return 0;
}

/**
 * Difference between the scanf() and fgets()
 *  scanf(): 
 * 	1. will allow you to take input of any length until and unless you specify the length.
 * 	2. scanf() will fail for the input with the spaces. it stops taking input as soon as it encounter the first space.
 * 	3. scanf() will not only allow you to more than one field, but it also allow you to enter structured data including
 * 		the ability to specify what character appers between the field.
 * 
 * 	fgets():
 * 	1. fgets() will allow you to take input of any length but specifying the size of input is mandatory.
 * 	2. fgets() can easily handle the spaces as long as it is within the limit. Ex: "This is a line containing space." length: 34
 * 	3. fgets() can only allow you to enter just one string into a buffer. No other data types. Just strings. Just one buffer.
 **/