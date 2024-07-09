#include "Ultility.h"
#include "Trie.h"

vector<char> readFile(string fileName)
{
    ifstream fIn(fileName);
    char c;
    vector<char> listOfChars;
    while (fIn >> c)
    {
        listOfChars.push_back(c);
    }

    fIn.close();
    return listOfChars;
}

void backtrack(TrieNode *node, string path, int charCount[], vector<char> &listOfChars, vector<string> &listOfWords)
{
    if (path.size() >= 3 && node->wordEnd == true)
    {
        vector<string>::iterator it = find(listOfWords.begin(), listOfWords.end(), path);
        if (it == listOfWords.end())
        {
            listOfWords.push_back(path);
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (charCount[i] > 0 && node->children[i] != nullptr)
        {
            charCount[i]--;
            backtrack(node->children[i], path + char(i + 'a'), charCount, listOfChars, listOfWords);
            charCount[i]++;
        }
    }
}

void generateWords(Trie &trie, vector<char> &listOfChars, vector<string> &listOfWords)
{
    int charCount[26] = {0};
    for (int i = 0; i < listOfChars.size(); i++)
    {
        charCount[listOfChars[i] - 'a']++;
    }

    backtrack(trie.root, "", charCount, listOfChars, listOfWords);
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