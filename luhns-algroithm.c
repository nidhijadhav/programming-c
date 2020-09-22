#include <stdio.h>
#include <math.h>


int main(void)
{
    //gets card number from user
    long card_num = get_long("Number: ");

    //length of card number
    int card_len = log10(card_num) + 1;

    //string of original card numbers seperated
    int card_digits[card_len];

    //string of all digits that are going to be added together
    int addition[20];

    //index to keep track of addition string
    int addition_index = 0;

    //sum of all final digits to check if card is valid
    int check_num = 0;


    //loop that creates all the strings needed
    for (int i = 0; i < card_len; i++)
    {
        int m = i + 1;
        card_digits[i] = card_num % 10;
        card_num = (card_num - card_digits[i]) / 10;

        //multiplys every other digit in the card number by 2 starting with the second to last digit
        if (m % 2 == 0)
        {
            int mult = card_digits[i] * 2;
            int mult_len = log10(mult) + 1;

            //if the product is a double digit, this will split it into two
            if (mult_len == 2)
            {
                addition[addition_index] = mult % 10;
                addition_index++;
                addition[addition_index] = (mult - addition[addition_index - 1]) / 10;
            }
            else
            {
                addition[addition_index] = mult;
            }
        }

        //copy the odd digits into the addition string
        else
        {
            addition[addition_index] = card_digits[i];
        }
        addition_index++;
    }

    //loop that will add all the digits from the addition string together
    for (int i = 0; i < addition_index; i++)
    {
        check_num = check_num + addition[i];
    }

    //function to check if card is valid and what card type it is
    if (check_num % 10 == 0)
    {
        if (card_len == 15)
        {
            if (card_digits[card_len - 1] == 3)
            {
                if (card_digits[card_len - 2] == 4 || card_digits[card_len - 2] == 7)
                {
                    printf("AMEX\n");
                }

                else
                {
                    printf("INVALID\n");
                }
            }
        }

        else if (card_len == 13)
        {
            printf("VISA\n");
        }

        else if (card_len == 16)
        {
            if (card_digits[card_len - 1] == 4)
            {
                printf("VISA\n");
            }

            else if (card_digits[card_len - 1] == 5)
            {
                if (card_digits[card_len - 2] == 1 || card_digits[card_len - 2] == 2 || card_digits[card_len - 2] == 3
                    || card_digits[card_len - 2] == 4 || card_digits[card_len - 2] == 5)
                {
                    printf("MASTERCARD\n");
                }

                else
                {
                    printf("INVALID\n");
                }
            }

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
