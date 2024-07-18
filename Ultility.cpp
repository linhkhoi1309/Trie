#include "Ultility.h"
#include "Trie.h"

vector<char> input()
{
    char c;
    vector<char> listOfChars;
    while (cin >> c)
    {
        listOfChars.push_back(c);
    }
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

void output(vector<string> listOfWords)
{
    cout << listOfWords.size() << '\n';

    for (int i = 0; i < listOfWords.size(); i++)
    {
        cout << listOfWords[i] << '\n';
    }
}