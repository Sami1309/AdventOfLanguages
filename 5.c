#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//C is the introverted prodigy senior who lets all the freshman copy his old homework
void fillData(char **lines, FILE *fp, int fileLength)
{

    fseek(fp, 0, SEEK_SET);

    int pos = 0;
    char line[256];

    while (fgets(line, 17, fp) != NULL)
    {
        if (strcmp(line, "\n") != 0)
        {
            lines[pos] = (char *)malloc(sizeof(char) * (strlen(line)));
            strcpy(lines[pos], line);
            pos++;
        }
    }
}

int findFileLength(FILE *fp)
{

    int fileLength = 0;
    char line[256];

    while (fgets(line, 256, fp) != NULL)
    {
        fileLength++;
    }

    return fileLength;
}

void freeArray(char **lines, int fileLength)
{
    for (int i = 0; i < fileLength; i++)
        free(lines[i]);

    free(lines);
}

int niceStrings(char **lines, int fileLength)
{
    //String must contain at least 1 vowel, none of the bad strings, and at least one set of double letters
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    char *badStrings[4] = {"ab", "cd", "pq", "xy"};

    int niceCount = 0;
    int vowelCount;
    int doubleLetters;
    int invalidStrings;
    for (int i = 0; i < fileLength; i++)
    {
        vowelCount = 0;
        doubleLetters = 0;
        invalidStrings = 0;

        //Pointer to beginning of string
        char *letter = lines[i];

        //Iterate through every letter in the string
        for (letter; *letter; letter++)
        {
            for (int v = 0; v < 5; v++)
                if (*letter == vowels[v])
                    vowelCount++;

            if (letter != lines[i] && *(letter - 1) == *letter)
                doubleLetters++;

            for (int b = 0; b < 4; b++)
                if (letter != lines[i] && *(letter - 1) == *badStrings[b] && *letter == *(badStrings[b] + 1))
                    invalidStrings++;
        }

        if (vowelCount >= 3 && doubleLetters >= 1 && invalidStrings == 0)
            niceCount++;
    }

    return niceCount;
}

int niceStrings2(char **lines, int fileLength)
{
    //String must contain one pair of identical strings of length 2 each, non-overlapping,
    //and 1 "sandwich" where two identical strings surround a third
    int niceCount = 0;
    int doublePairs;
    int sandwiches;
    for (int i = 0; i < fileLength; i++)
    {
        doublePairs = 0;
        sandwiches = 0;

        for (char *letter = lines[i]; *letter; letter++)
        {
            if (letter != lines[i] && letter - 1 != lines[i] && *letter == *(letter - 2))
                sandwiches++;

            if (letter != lines[i])
                for (int j = 2; *(letter + j); j++)
                    if (*(letter + j - 1) == *(letter - 1) && *(letter + j) == *letter)
                        doublePairs++;
        }

        if (sandwiches > 0 && doublePairs > 0)
            niceCount++;
    }

    return niceCount;
}

int main()
{
    FILE *fp;
    char *filename = "data/5.in\0";
    char **lines;

    //Open the file containing the input
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(-1);
    }

    //Cycle through the file to find its length
    int fileLength = findFileLength(fp);

    //Use length to allocate an appropriately sized array to house the input
    lines = (char **)malloc(sizeof(char *) * fileLength);

    //Read the input into the array
    fillData(lines, fp, fileLength);

    fclose(fp);

    //Part 1 solution
    printf("%d\n", niceStrings(lines, fileLength));

    //Part 2 solution
    printf("%d", niceStrings2(lines, fileLength));

    //Free the memory used for the array
    freeArray(lines, fileLength);
}