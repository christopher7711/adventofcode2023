#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int getCalibrationValue(char * input,ssize_t length)
{
   char result[3];
   result[0] = 'a';
   //printf("%s",input);
   //printf("%zu \n",length - 1); // -1 \n
   for(int i=0;i < length ; i++){
    //printf("%c",input[i]);
    if(isdigit(input[i])){
      if(result[0] == 'a')
      {
        result[0] = input[i];
      }
      result[1] = input[i]; 
    }
    result[2] =  '\n';
  }
  return atoi(result);
  //puts(result);
  //printf("%d",value);
}



int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int Result = 0;

    fp = fopen("input", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
	  Result = Result + getCalibrationValue(line,read);
    printf("%d \n",Result);
    }
    printf("%d",Result);
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
