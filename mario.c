#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt); 

int main(void) 

{
    //getting positive input 
    int number = get_positive_int("Height: "); 
    //creatinhg height parameter and lines 
    for (int height = 0; height < number; height++) 
    {
        //printing spaces before pyramids 
        for (int spaces = number - height - 2; spaces >= 0; spaces--) 
        {
            printf(" ");
        }
        //for pyramid on the left 
        for (int row = 0; row <= height; row++)
        {
            printf("#");
        }
        printf("  ");
        //right pyramid
        for (int row2 = 0; row2 <= height; row2++)
        {
            printf("#"); 
        }
        printf("\n");
    }
}

int get_positive_int(string prompt) 

{
    int number; 
    do 
    {
        //defining biggest value 
        number = get_int("%s", prompt); 
    }
    //check if in a right range 
    while (number < 1 || number > 8); 
    //return if false
    return number; 
}