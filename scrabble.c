#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

// if Player 1 entered a word worth more points then prints "Player 1 wins!", if Player 2 entered a
// word worth more points then prints "Player 2 wins!", otherwise prints "Tie!"
int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

//Checks how many points a word is worth and returns the total number of points
int compute_score(string word)
{
    int score = 0;
    //looks through each character of the word
    for (int i = 0; i < strlen(word); i++)
    {
        // if the character is not an uppercase or lowercase letter then it is worth 0 points
        if (!((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122)))
        {
            score += 0;
        }
        // finds the number of points a lowercase letter is worth
        else if (islower(word[i]))
        {
            score += POINTS[(word[i] - 32) - 'A'];
        }
        // finds the number of points an uppercase letter is worth
        else
        {
            score += POINTS[word[i] - 'A'];
        }
    }
    return score;
}