// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

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

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //fopen file, check if return value is null, if yes, return false
    FILE *infile = fopen(dictionary, "r");
    if (infile == NULL)
    {
        printf ("Not able to open the external file\n");
        return false;
    }
    //read strings from the file one at a time, we can use fscanf(file (pointer), %s(string), word(character where we will read the word into))
    //we will do the previous step until fscanf return EOF --> end of the file.
    //for each word we read, we can create a node with malloc (remember to check if null) and copy the word there using strcpy
    //for previous: node *n = malloc(sizeof(node)); and strcpy(n->word, "Hello");
    char *word = malloc(46 * sizeof(char));
    while(fscanf (infile, "%s", word) != EOF)
    {
        node *n = malloc (sizeof(node));
        if (n == NULL)
        {
            printf ("Not able to allocate memory for a node\n");
            return false;
        }
        strcpy(n->word, word);
        hash (word);
    }


    //now we insert the node in the hashtable
    //for that we use the hash function, which takes a string and returns an index. Later on we'll modify this function.
    //hashtable is an array of linked lists, please set pointers in the right order (don't lose access)

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
