#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "Trie.h"
using namespace std;

vector<char> readFile(string fileName);

void generateWords(Trie& trie, vector<char>& listOfChars, vector<string>& listOfWords);

void writeFile(string fileName, vector<string> listOfWords);
