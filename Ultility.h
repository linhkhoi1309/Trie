#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Trie.h"
using namespace std;

vector<char> input();

void generateWords(Trie& trie, vector<char>& listOfChars, vector<string>& listOfWords);

void output(vector<string> listOfWords);
