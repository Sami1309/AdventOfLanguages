#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    fclose(fp);
}

int findFileLength(FILE *fp)
{

    if (fp == NULL)
    {
        perror("Error opening file");
        exit(-1);
    }

    int fileLength = 0;
    char line[256];

    if (fgets(line, 256, fp) != NULL)
    {
        fileLength++;
    }

    while (fgets(line, 256, fp) != NULL)
    {
        fileLength++;
    }

    return fileLength;
}

void freeArray(char **lines, int fileLength)
{
    for (int i = 0; i < fileLength; i++)
    {
        free(lines[i]);
    }
    free(lines);
}

int niceStrings(char **lines, int fileLength)
{
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    char *badStrings[4] = {"ab", "cd", "pq", "xy"};

    int niceCount = 0;
    int vowelCount;
    int doubleLetters;
    int invalidStrings;
    for (int i = 0; i < fileLength; i++)
    {
        //printf("%s\n", lines[i]);
        vowelCount = 0;
        doubleLetters = 0;
        invalidStrings = 0;

        char *letter = lines[i];
        char lastletter = ' ';

        //printf(lines[i]);
        for (letter; *letter; letter++)
        {
            //printf("%c", *letter);
            //printf(letter);
            for (int v = 0; v < 5; v++)
            {
                if (*letter == vowels[v])
                {
                    vowelCount++;
                }
            }
            if (lastletter == *letter)
            {
                doubleLetters++;
            }

            //printf(letter);

            for (int b = 0; b < 4; b++)
            {
                if (lastletter == (char)*badStrings[b] && *letter == *(badStrings[b] + 1))
                {
                    invalidStrings++;
                }
            }

            lastletter = *letter;
        }
        //printf("\n");
        // printf(lines[i]);
        // printf("\n");
        // printf("Vowel count is %d\n", vowelCount);
        // printf("Double letter pairs count is %d\n", doubleLetters);
        // printf("Contains %d invalid strings\n", invalidStrings);

        if (vowelCount >= 3 && doubleLetters >= 1 && invalidStrings == 0)
        {
            niceCount++;
            //printf("%s\n", lines[i]);
        }
    }

    return niceCount;
}

int niceStrings2(char **lines, int fileLength)
{

    int niceCount = 0;
    int doublePairs;
    int sandwiches;
    for (int i = 0; i < fileLength; i++)
    {
        //printf("%s\n", lines[i]);
        doublePairs = 0;
        sandwiches = 0;

        char *twolast = lines[i];
        char *onelast = lines[i] + 1;
        char *letter = lines[i] + 2;

        //printf(lines[i]);
        for (letter; *letter; letter++)
        {
            if (*letter == *twolast)
            {
                sandwiches++;
            }

            char *let2 = letter;
            char *let1 = letter + 1;
            for (let1; *let1; let1++, let2++)
            {
                if (*let2 == *twolast && *let1 == *onelast)
                {
                    doublePairs++;
                }
            }

            twolast++;
            onelast++;
        }

        //printf("\n");
        // printf(lines[i]);
        // printf("\n");
        // printf("Vowel count is %d\n", vowelCount);
        // printf("Double letter pairs count is %d\n", doubleLetters);
        // printf("Contains %d invalid strings\n", invalidStrings);

        if (sandwiches > 0 && doublePairs > 0)
        {
            niceCount++;
            printf("%s\n", lines[i]);
        }
    }

    return niceCount;
}
int main()
{
    FILE *fp;
    char *filename = "data/5.in\0";
    char **lines;

    fp = fopen(filename, "r");

    int fileLength = findFileLength(fp);

    lines = (char **)malloc(sizeof(char **) * fileLength);

    fillData(lines, fp, fileLength);

    int numNice = niceStrings(lines, fileLength);

    //test numNice
    //char *testStrings[2] = {"dvszwmarrgswjxmb", "haegwjzuvuyypxyu"};
    //int testNice = niceStrings(testStrings, 2);

    printf("%d\n", numNice); //Part 1 solution

    int numNice2 = niceStrings2(lines, fileLength);

    printf("%d", numNice2); //Part 2 solution

    freeArray(lines, fileLength);
}