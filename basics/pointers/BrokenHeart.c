// Example on how to use the pointer arithmetic.
#include <stdio.h>

void send_msg(char* ch){
	printf("%s", (ch + 6));
}

int main(){
	char *message = "Don't call me.";
	char arr_message[] = "Don't call me";

	// You can use any variable either message or arr_message
	send_msg(arr_message); // This will print : call me.

	return 0;
}