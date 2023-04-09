#include <stdio.h>


int main()
{
	FILE *fp;
	char str[] = "Hello, world";
	char buffer[20];

	fp = fopen("test.txt", "w");

	fputs(str, fp);

	fclose(fp);

	fp = fopen("test.txt", "r");

	fgets(buffer, 20, fp);
	printf("%s", buffer);

	fclose(fp);

	return (0);
}
