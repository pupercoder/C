#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//writing out the command lines and signed keys 
bool validate(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        if (validate(key) == true)
        {
            //getting an input from the user 
            string plaintext = get_string("plaintext: ");
            int charcount = strlen(plaintext);
            char ciphertext[charcount];
            string abc = "abcdefghijklmnopqrstuvwxyz";
            for (int i = 0; i < charcount; i++)
            {
                if (isupper(plaintext[i]) != 0)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if (abc[j] == tolower(plaintext[i]))
                        {
                            ciphertext[i] = toupper(key[j]);
                            break;
                        }
                    }
                }
                else if (islower(plaintext[i]) != 0)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if (abc[j] == plaintext[i])
                        {
                            ciphertext[i] = tolower(key[j]);
                            break;
                        }
                    }
                }
                else
                {
                    ciphertext[i] = plaintext[i];
                }
            }
            //provide ciphertext for users
            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }
        else
        {
            //give notices to the user 
            //printing output 
            printf("Please make sure your key is a permutation of all 26 characters - not more, not less.\n");
            return 1;
        }
    }
    else
    {
        //print if there is an error
        //return to the first operation 
        printf("Input error. Please provide a single key.\n");
        return 1;
    }
}
//create match 
bool validate(string key)
{
    int matches = 0;
    //create an if loop to get proper output 
    if (strlen(key) == 26)
    {
        //asigning a cypher for each char
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int i = 0; i < 26; i++)
            {
                if (tolower(key[i]) == c)
                {
                    matches++;
                    break;
                }
            }
        }
        if (matches == 26)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        //return score
        return false;
    }
}
//made by pupercoder