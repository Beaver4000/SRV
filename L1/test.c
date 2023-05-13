#include <stdio.h>
#include <string.h>

int main(){
	char buffer[100];
	while(gets(buffer)) {
	if (!strcmp(buffer,"I992 Kuzmin Alexander")) printf("Passed \n");
	else printf ("Not passed \n");
}
return 0;
}