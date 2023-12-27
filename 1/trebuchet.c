#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>


int getCalibrationValue(char * input,ssize_t length)
{
   printf("%s",input);
   printf("%zu \n",length - 1); // -1 \n
}



int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("input", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
	getCalibrationValue(line,read);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
