#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float money = 0; 
    int much = 0;
    do
    {
        printf("coins in order: 25c, 10c, 5c, 1c\n");
        money = get_float("change: ");
    }
    while (money < 0);
    int coins = round(money * 100);
    while (coins - 25 >= 0 || coins - 10 >= 0 || coins - 5 >= 0 || coins - 1 >= 0)
    {
        if (coins - 25 >= 0)
        {
            coins = coins - 25;
            much++;
        } 
        else if (coins - 10 >= 0)
        {
            coins = coins - 10;
            much++;
        } 
        else if (coins - 5 >= 0)
        {
            coins = coins - 5;
            much++;
        } 
        
        else if (coins - 1 >= 0)
        {
            coins = coins - 1;
            much++;
        }
    }
    printf("%i\n", much); 

}
