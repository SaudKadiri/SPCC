#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_keyword(char *word)
{
    static const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
        "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
        "union", "unsigned", "void", "volatile", "while"
    };
    int i = 0;
    while(i < 32 && strcmp(word, keywords[i])) {
        i++;
    }
    return i < 32;
}

bool is_operator(char token)
{
    static const char operators[] = {'+', '-', '*', '/', '%', '='};
    
    for (int i = 0; i < 6; i++) {
        if (token == operators[i]) {
            return true;
        }
    }
    return false;
}

int main(void)
{
    char chr;
    char word[20];
    int i = 0;
    FILE *input = fopen("program.txt", "r");
    
    if (input == NULL) {
        printf("No such input file.\n");
        return 1;
    }
    while ((chr = fgetc(input)) != EOF) {
        if (is_operator(chr)) {
            printf("%c is an operator.\n", chr);
        } else if (isalnum(chr)) {
            word[i++] = chr;
        } else if ((chr == '\n' || chr == ' ') && i != 0) {
            word[i] = '\0';
            i = 0;
            if (is_keyword(word)) {
                printf("%s is a keyword.\n", word);
            } else {
                printf("%s is an identifier\n", word);
            }
        }
    }
    return 0;
}
