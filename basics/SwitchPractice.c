#include <stdio.h>

int main(){
	char ch;

	printf("Select day Mon, Tue, Wed, Thu, Fri, Sat\n");
	scanf("%c", &ch);

	switch(ch){
		case 'm':
			printf("You selected Monday.\n");
			break;
			
		case 't':
			printf("You selected Tuesday.\n");
			break;

		case 'w':
			printf("You selected Wednesday.\n");
			break;

		case 'h':
			printf("You selected Thursday.\n");
			break;

		case 'f':
			printf("You selected Friday.\n");
			break;

		case 's':
			printf("You selected saturday.\n");
			break;

		default: printf("Not a valid day.\n");
	}
	return 0;
}