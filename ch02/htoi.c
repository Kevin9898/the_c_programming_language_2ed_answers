#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "htoi.h"

int isValid(const char *str);
int parseHex(const char *str, int *value);

int htoi(const char *str, int *value){
    const char *hexStr = str;
    if (!isValid(str)) {
        return -1;
    }
    if (hexStr[0] == '0' && (hexStr[1] == 'x' || hexStr[1] == 'X')) {
        hexStr += 2;
    }
    while (hexStr[0] == '0') {
        ++hexStr;
        if (*hexStr == '\0'){
            return 0;
        }
    }
    return parseHex(hexStr, value);
}

int parseHex(const char *hexStr, int *value)
{
    int number = 0;
    const char *start = hexStr;
    const char *end = hexStr + strlen(hexStr);
    for(; start < end; ++start) {
        number = (number << 4) +
            (isdigit(*start) ? *start - '0' : tolower(*start) - 'a' + 10);
    }
    *value = number;
    return 0;
}

int isValid(const char *str)
{
    const int maxHexValueLength  = 8;
    const char *valueStart = str;
    const char *valueEnd = str + strlen(str);
    if (valueStart == valueEnd) {
        return 0;
    }

    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
        valueStart += 2;
    }
    while (valueStart[0] == '0') {
        ++valueStart;
        if (valueStart == valueEnd) {
            return 1;
        }
    }
    if (valueEnd - valueStart > maxHexValueLength) {
        return 0;
    }
    for (; valueStart < valueEnd; valueStart++) {
        if( !isxdigit(*valueStart)) {
            return 0;
        }
    }
    return 1;
}