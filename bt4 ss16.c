#include <stdio.h>
int main(){
	FILE *file = fopen("bt03.txt", "r");
		int numLines = 0;
char ch;
while ((ch = fgetc(file)) != EOF) {
if (ch == '\n') {
numLines++;
}
}
	fclose(file);
printf("Su dung trong file: %d\n", numLines);
		return 0;
}
