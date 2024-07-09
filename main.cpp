#include "Ultility.h"
#include "Trie.h"

int main()
{
    Trie trie;
    vector<string> listOfWords;
    vector<char> listOfChars;

    // Initialize a trie with provided words in text file
    trie.initTrie("Dic.txt");

    // Read a list of characters from the input file
    listOfChars = readFile("input.txt");

    // Generate words from the provided characters
    generateWords(trie, listOfChars, listOfWords);

    // Write a list of generated words to the output file
    writeFile("output.txt", listOfWords);
    return 0;
}
