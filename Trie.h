#pragma once
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct TrieNode
{
    char data;
    bool wordEnd;
    TrieNode *children[26];

    TrieNode();
};

struct Trie
{
    TrieNode *root;

    Trie();
    void initTrie(string fileName);
    void insertKey(string key);
    ~Trie();
};

void deleteNodes(TrieNode* root);