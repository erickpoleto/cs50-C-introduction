#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    do 
    {
        height = get_int("height: ");
    }
    while (height < 1 || height >= 9);
    
    for (int i = 0; i < height ; i++)
    {
        for (int j = height; j > i + 1; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("#");
        printf("\n");

    }
    

}
