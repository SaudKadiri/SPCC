#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Function to parse the HTML code
void parser(char* str)
{
    // Store the length of the
    // input string
    int n = strlen(str);
    int start = 0, end = 0;
    int i = 0;

    while (str[i] != '>') {
        i++;
    }
    start = i + 1;
    
    // Remove the blank spaces
    while (str[start] == ' ') {
        start++;
    }
    i = start;
    
    // Traverse the string
    while (i < n && str[i] != '<') {
        i++;
    }
    end = i - 1;

    // Print the characters in the
    // range [start, end]
    for (int i = start; i <= end; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}


// Driver Code

int main()
{
    // Given Input
    char input1[] = "<h1>This is a statement</h1>";
    char input2[] = "<h1> This is a statement with some spaces</h1>";
    char input3[] = "<p> This is a statement with some @ #$ ., / special characters</p> ";
    
    printf("Parsed Statements:\n");

    // Function Call
    parser(input1);
    parser(input2);
    parser(input3);

    return 0;
}
