#include <stdio.h>
#include <string.h>
#include "htoi.h"

int main(int argc, char* argv[])
{
    char buff[128]={0};
    char * rt;
    do {
        rt = gets(buff);
        if (rt == NULL) {
            printf("input error!\n");
            continue;
        }
        int value = 0;
        if (htoi(buff, &value) != 0){
            printf("not valid hex number!\n");
            continue;
        };
        printf("the value of %s is: %d\n", buff, value);
    } while (strncmp("exit", buff, 128) != 0);
    return 0;
}