#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isValid(const char *s) {
    size_t length = strlen(s);

    char *stack = malloc(length + 1);

    if (stack == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int top = -1;

    for (size_t i = 0; i < length; i++){
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        }
    }




}