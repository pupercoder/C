#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define OUT 0
#define IN 1
 
int main() {
 
    printf("Enter text to calculate Grade:\n");
 
    int symbols = 0;
    int letters = 0;
    int words = 0;
    int sentences = 0;
 
    int flag = OUT;
 
    int ch = 0;
 
    while ((ch = getchar()) != '\n') {
        ++symbols;
        if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))) {
            ++letters;
        }
        if ((ch == '.') || (ch == '!') || (ch == '?')) {
            ++sentences;
        }
        if (isspace(ch) && flag) {
            ++words;
            flag = OUT;
        }
        if (!isspace(ch) && !flag) {
            flag = IN;
        }
    }
    if (flag) {
        ++words;
    }
 
    double L = ((double)letters / words) * 100.0;
    double S = ((double)sentences / words) * 100.0;
 
    double index = 0.0588 * L - 0.296 * S - 15.8;
 
    if (index < 1) {
        printf("Before Grade 1\n");
    }
    else if (index >= 16) {
        printf("Grade 16+\n");
    }
    else {
        printf("Grade %d\n", (int)round(index));
    }
 
 
    return 0;
}