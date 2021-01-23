#ifndef STRINGS_H
#define STRINGS_H

const char* concat(const char* a, const char* b);
const char* combine_list(const char** list, unsigned int len);
const char* substring(const char* input, unsigned int start, unsigned int end);

#endif