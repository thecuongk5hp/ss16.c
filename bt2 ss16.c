#include <stdio.h>
int main(){
	FILE *file = fopen("bt01.txt", "r");
	char ch;
while ((ch = fgetc(file)) != EOF) {
    printf("%c", ch);
}
	fclose(file);
} 
