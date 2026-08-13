#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int key);

int main(int argc, string argv[])
{
    // Make sure progrma was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Make sure every character in argv[1] is a digit
    int n = strlen(argv[1]);
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Convert argv[1] from a 'string' to an 'int'
    int key = atoi(argv[1]);
    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    // For each character in the plaintext
    printf("ciphertext: ");
    int j = strlen(plaintext);
    for (int i = 0; i < j; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");
    return 0;
}
char rotate(char c, int key)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            int index = c - 'A';
            // Caesar formula
            int cipher = (index + key) % 26;
            // Return Ascıı
            char k = cipher + 'A';
            return k;
        }
        else if (islower(c))
        {
            int index = c - 'a';
            // Caesar formula again
            int cipher = (index + key) % 26;
            // Return it Ascıı too
            char k = cipher + 'a';
            return k;
        }
    }
    else
    {
        return c;
    }
    return 1;
}
