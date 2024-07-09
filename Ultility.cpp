#include "Ultility.h"
#include "Trie.h"

vector<char> readFile(string fileName)
{
    ifstream fIn(fileName);
    char c;
    vector<char> listOfChars;
    while (!fIn.eof())
    {
        fIn >> c;
        listOfChars.push_back(c);
    }

    fIn.close();
    return listOfChars;
}

void backtrack()
{
}

void generateWords(Trie &trie, vector<char>& listOfChars, vector<string>& listOfWords)
{
    int charCount[26] = {0};
    for (int i = 0; i < listOfChars.size(); i++)
    {
        charCount[listOfChars[i] - 'a']++;
    }
}

void writeFile(string fileName, vector<string> listOfWords)
{
    ofstream fOut(fileName);

    fOut << listOfWords.size() << '\n';

    for (int i = 0; i < listOfWords.size(); i++)
    {
        fOut << listOfWords[i] << '\n';
    }

    fOut.close();
}