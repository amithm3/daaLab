#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 128

int* shiftTable(char *pattern) {
    int *table = (int*)malloc(sizeof(int)*MAX);
    int m = strlen(pattern);
    for(int i = 0; i < MAX; i++) table[i] = m;
    for(int i = 0; i < m-1; i++) table[pattern[i]] = m-1-i;
    return table;
}

int horspool(char *text, char *pattern) {
    int *table = shiftTable(pattern);
    int m = strlen(pattern), n = strlen(text);
    int i = m-1;
    while(i < n) {
        int k = 0;
        while(k < m && pattern[m-1-k] == text[i-k]) k++;
        if(k == m) return i-m+1;
        else i += table[text[i]];
    }
    return -1;
}

void main() {
    char text[MAX], pattern[MAX];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    int pos = horspool(text, pattern);
    if(pos == -1) printf("Pattern not found\n");
    else printf("Pattern found at position %d\n", pos+1);
}
