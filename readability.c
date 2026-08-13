#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
// Prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: \n");

    // Count the number of letters,words and sentences in the text
    int count_of_letters = count_letters(text);
    int count_of_words = count_words(text);
    int count_of_sentences = count_sentences(text);
    const float Magic_n1 = 0.0588;
    const float Magic_n2 = 0.296;
    const float Magic_n3 = 15.8;
    // Compute the Coleman-Liau index
    float L = ((float) count_of_letters / count_of_words) * 100.0;
    float S = ((float) count_of_sentences / count_of_words) * 100.0;
    float index = (Magic_n1 * L) - (Magic_n2 * S) - Magic_n3;
    int grade = round(index);

    // Print the grade level
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
// Create the function that counts letters
int count_letters(string text)
{
    int letters = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters = letters + 1;
        }
    }
    return letters;
}
// Create the function that counts words
int count_words(string text)
{
    int words = 1;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (text[i] == ' ')
        {
            words = words + 1;
        }
    }
    return words;
}

// Create the function that counts sentences
int count_sentences(string text)
{
    int sentences = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentences = sentences + 1;
        }
    }
    return sentences;
}
