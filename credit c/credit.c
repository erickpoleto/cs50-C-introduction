#include <stdio.h>
#include <cs50.h>

//make functions visible to the main code by calling in before
bool calcCreditIntegrity(long creditCard);
bool verifyIntegrity(int someAll);
char *creditName(bool calcCreditIntegrity, long creditCard);


int main(void)
{   
    long creditCard = 0;
    bool calcCredit = false;
    do
    {
        creditCard = get_long("Credit Card Number: \n");
        //associete the calc function to an bool variable
        calcCredit = calcCreditIntegrity(creditCard);
    }
    while (creditCard <= 0);
    //print the function result
    printf("%s", creditName(calcCredit, creditCard));
    
}


bool calcCreditIntegrity(long creditCard)
{
    //calcule for knowing if the credit card is a true one
    //initialize variables
    int multiply = 0;
    int some = 0;
    int number1 = 0;
    int number2 = 0;
    long creditSingle = creditCard;
    int someSingle = 0;
    int someAll = 0;
    //initialize creditMultiple that is creditCard divided by 10
    long creditMultiple = creditCard / 10;
    //initialize a loop, that only finish when creditMultiple reach Zero
    while (creditMultiple > 0)
    {
        multiply = (creditMultiple % 10) * 2;
        //verify if is a two digits multiple, them turn separeted
        if (multiply >= 10)
        {
            number1 = (multiply % 10);
            number2 = (multiply / 10) % 100;
            some = some + number1 + number2;
            creditMultiple = creditMultiple / 100;
        }
        else
        {
            some = some + multiply;
            creditMultiple = creditMultiple / 100;
        }
    }
    //an loop to catch the non-multiplyed numbers of the credit card
    while (creditSingle > 0)
    {
        someSingle = someSingle + (creditSingle % 10);
        creditSingle = creditSingle / 100;
    }
    someAll = someSingle + some;
    bool verificar = verifyIntegrity(someAll);
    return verificar;
}

bool verifyIntegrity(int someAll)
{
    /*verify if the Credit Card is true*/
    /*veryfy if the value ends with zero, then de credit card is true*/
    if (someAll % 10 == 0)
    {   
        return true;   
    }
    else
    {   
        return false;
    }
    
}

char *creditName(bool calcCreditIntegrity, long creditCard)
{
    //verify if the credit card is true, them run the next code
    if (calcCreditIntegrity == true)
    { 
        //initializing varibles
        long card = creditCard;
        int credit = 0;
        int digits = 0;
        //making a loop for go throug credit card numbers and descrease by 10, after every step, 
        //finalize when the i variable is 0
        for (long i = card; i > 0; i = i / 10)
        {
            //verify if is the last 2 digits
            if (i / 100 == 0)
            {
                //take the two last numbers and put in credit variable
                credit = i % 100;
                //increment digits by 1
                digits++;
                break;
            }
            else
            {
                digits++;
            }
        }
        //verify if is amex, master, visa, or invalid by the unic specs of them
        if (digits == 14 && (credit == 34 || credit == 37))
        {
            return ("AMEX\n");
        }
        else if (digits == 15 && (credit >= 51 && credit <= 55))
        {
            return ("MASTERCARD\n");
        }
        else if ((digits == 12 || digits == 15) && ((credit / 10) % 10 == 4))
        {
            return ("VISA\n");
        }
        else
        {
            return ("INVALID\n");
        }
    }
    else
    {
        return ("INVALID\n");
    }
    return "";
}