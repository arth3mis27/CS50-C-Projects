#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Getting the card number from the user
    long card_number = get_long("Number: ");
    long detect_card = card_number;
    int total_sum = 0;
    int position = 1;
    // Keep working while card number bigger than 0
    while (card_number > 0)
    {
        // take the last number
        int last_digit = card_number % 10;
        // Luhn rule part
        if (position % 2 == 0)
        {
            int multiply = last_digit * 2;
            if (multiply > 9)
            {
                int first_number = multiply / 10;
                int last_number = multiply % 10;
                total_sum = total_sum + first_number + last_number;
            }
            else
            {
                total_sum = total_sum + multiply;
            }
        }
        else
        {
            total_sum = total_sum + last_digit;
        }
        position++;
        card_number = card_number / 10;
    }
    // checking the card if it's valid and detecting the card kind
    if (total_sum % 10 == 0)
    {
        int lenght = position - 1;
        while (detect_card > 99)
        {
            detect_card = detect_card / 10;
        }
        int first_digit_of_card_number = detect_card / 10;
        // Amex conditions
        if ((lenght == 15) && ((detect_card == 37) || (detect_card == 34)))
        {
            printf("AMEX\n");
        }
        // MASTERCARD conditions
        else if ((lenght == 16) && (((51 <= detect_card && detect_card <= 55))))
        {
            printf("MASTERCARD\n");
        }
        // VISA conditions
        else if (((lenght == 13) || (lenght == 16)) && (first_digit_of_card_number == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}
