#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//code made by Pupercoder on 26th April 2021

// Points for each letter of the alphabet 
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// lowercase letters 
int small_letters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

// values for caps letters 
int capital_letters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
int temp_Points [] = {};


int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calculates Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    // if score1 > score2 player 1 wins
    if (score1 > score2)
    {
        printf("Player 1 wins");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins");
    }
    else
    {
        printf("Tie");
    }
}

int compute_score(string word)
{
    int score = 0;
    //return score 
    for (int i = 0; i < strlen(word); i++)
    {
        // checks if the letter is upper
        if (isupper(word[i]))
        {
            
            for (int f = 0; f < sizeof(capital_letters); f++)
            {
                if (word[i] == capital_letters[f])
                {
                    temp_Points[i] = POINTS[f];
                    score += temp_Points[i];
                }
            }
        }
        else if (islower(word[i]))
        {
            for (int f = 0; f < sizeof(small_letters); f++)
            {
                if (word[i] == small_letters[f])
                {
                    temp_Points[i] = POINTS[f];
                    score += temp_Points[i];
                }
            }
        }
        // if contains something else from letters ignore the word
        else
        {
            i += 1;
        }
    }
    // returns 
    return score;
}