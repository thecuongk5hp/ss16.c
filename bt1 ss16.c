#include <stdio.h>
int main(){
	FILE *file = fopen("bt01.txt", "w");
		char chuoi[100];
		printf("Nh?p chu?i: ");
		gets(chuoi);
		fprintf(file, "%s", chuoi);
		fclose(file);

		return 0;
}
