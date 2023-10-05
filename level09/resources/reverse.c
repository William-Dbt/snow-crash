#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
		printf("Usage: ./a.out <string>\n");
		return 1;
	}

    FILE *fptr = fopen(argv[1], "r");
    if (!fptr) {
		printf("Error: Can't open file %s\n", argv[1]);
		return 1;
	}

    char buff[255];
    fgets(buff, 255, (FILE*)fptr); 

	size_t i;
    for (i = 0; i < strlen(buff) - 1; i++)
        buff[i] = buff[i] - i;

	buff[i] = '\0';
    printf("%s\n", buff);
    fclose(fptr);
    return 0;
}
