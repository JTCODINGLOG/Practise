// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//Global variable for dictionary size
unsigned int track_size = 0;

// Returns true if word is in dictionary, else false
    // TODO
    //check in which part of the array the list the word could possibly be
    //set up a pointer variable to follow up through the list
    //create a loop that ends when list ends, where node->next is NULL
    //strcasecmp compares two strings case insensitive
bool check(const char *word)
{
    node *cursor = table[hash(word)];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //multiply each ascii value of a character by its position (starting by 1).
    //after we summarize these products, divide into the number of elements in the hash table with %.
    //i.e. 568 % 26    (if N = 26)
    //it needs to handle similarly upper and lower case. It also needs to provide a value for apostrophes.
    unsigned int hash_number = 0;
    int lenght = strlen(word);
    for (int i = 0, j = 1; i < lenght; i++, j++)
    {
        int upper = toupper(word[i]) * j;
        hash_number += upper;
    }
    return hash_number % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //fopen file, check if return value is null, if yes, return false
    //read strings from the file one at a time, we can use fscanf(file (pointer), %s(string), word(character where we will read the word into))
    //we will do the previous step until fscanf return EOF --> end of the file.
    //for each word we read, we can create a node with malloc (remember to check if null) and copy the word there using strcpy
    //for previous: node *n = malloc(sizeof(node)); and strcpy(n->word, "Hello");
    //now we insert the node in the hashtable
    //for that we use the hash function, which takes a string and returns an index. Later on we'll modify this function.
    //hashtable is an array of linked lists, please set pointers in the right order (don't lose access)

    //we'll also keep track of number of words "to help size function"
    FILE *infile = fopen(dictionary, "r");
    if (infile == NULL)
    {
        printf ("Not able to open the external file\n");
        return false;
    }
    char word [LENGTH +1];
    while(fscanf (infile, "%s", word) != EOF)
    {
        node *n = malloc (sizeof(node));
        if (n == NULL)
        {
            printf ("Not able to allocate memory for a node\n");
            return false;
        }
        strcpy(n->word, word);
        n->next = table[hash(word)];
        table[hash(word)] = n;
        track_size++;
    }
    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return track_size;
}

// Unloads dictionary from memory, returning true if successful, else false
    // TODO
    // create two variables to follow up.
    //while one helps freeing memory, the other one keeps track
    //two loops, one for the hash array, the other one for the list
    //firs loop ends after N times
    //second loop ends where node->next is equal to NULL
bool unload(void)
{
    node *cursor = NULL;
    node *cleaner = NULL;

    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            cleaner = cursor;
            cursor = cursor->next;
            free(cleaner);
        }
        table[i] = NULL;
    }
    return true;
}
