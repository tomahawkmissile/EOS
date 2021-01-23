#include "strings.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char* concat(const char* a, const char* b) {
    unsigned int len1=strlen(a),len2=strlen(b);
    char* ret = (char*)malloc(sizeof(char*)*(len1+len2));
    for(unsigned int i=0;i<len1+len2;i++) {
        if(i<len1) ret[i]=a[i];
        else ret[i]=b[i-len1];
    }
    return (const char*)ret;
}
const char* combine_list(const char** list, unsigned int len) {
    if(len < 1) {
        return NULL;
    } else if(len == 1) {
        return list[0];
    } else {
        unsigned int total=0;
        for(unsigned int i=0;i<len;i++) total+=strlen(list[i]);
        char* ret = (char*)malloc(sizeof(char*)*total);

        const char* ret = list[0];
        for(unsigned int i=1;i<len;i++) {
            ret = concat(ret,list[i]);
        }
        return ret;
    }
}