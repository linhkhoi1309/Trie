#include "Trie.h"

TrieNode::TrieNode()
{
    data = '\0';
    wordEnd = false;
    for (int i = 0; i < 26; i++)
        children[i] = nullptr;
}

Trie::Trie()
{
    root = new TrieNode;
}

void Trie::initTrie(string fileName)
{
    ifstream fIn(fileName);

    string word;

    while (!fIn.eof())
    {
        fIn >> word;
        insertKey(word);
    }

    fIn.close();
}

void Trie::insertKey(string key)
{
    TrieNode *cur = root;
    for (int i = 0; i < key.size(); i++)
    {
        if (cur->children[key[i] - 'a'] == nullptr)
        {
            TrieNode *newNode = new TrieNode;
            cur->children[key[i] - 'a'] = newNode;
        }
        cur = cur->children[key[i] - 'a'];
    }
    cur->wordEnd = 1;
}

Trie::~Trie()
{
}