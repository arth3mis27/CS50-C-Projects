#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // Getting height
    do
    {
        height = get_int("Height?: ");
    }
    while (height < 1 || height > 8);
    // Building pyramid

    for (int i = 0; i < height; i++)
    {
        // printing spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        // Building left pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        // spaces that between two pyramids
        printf("  ");

        // Building the right pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
