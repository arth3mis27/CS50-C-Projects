#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// adding the points
const int points[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);

int main(void)
{
    // Getting the words from the users
    string word1 = get_string("Player 1: \n");
    string word2 = get_string("Player 2: \n");
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    // copmaere the scores and dedicate the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie\n");
    }
}

int compute_score(string word)
{
    // make a loop to get each letter
    int score = 0;
    int i;
    for (i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            // adjust letters according to ascıı
            char letter = toupper(word[i]);
            int index = letter - 'A';
            score = score + points[index];
        }
    }
    return score;
}
