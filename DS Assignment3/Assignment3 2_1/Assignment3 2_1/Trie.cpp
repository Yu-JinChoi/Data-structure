#include<iostream>
#include "Trie.h"
using namespace std;

class Trie {
public:
	int size;
	Nptr *root;
public:
	void Create();
	int Insert(const char *key, int val);
	Nptr Search(const char *key);
	void Delete(const char *key);
	void Save(const char *filename);
	void Open(const char *filename);
};

void Trie::Create() {

}

int Trie::Insert(const char *key, int val) {

}

Nptr Trie::Search(const char *key) {

}

void Trie::Delete(const char *key) {
	
}

void Trie::Save(const char *filename) {

}

void Trie::Open(const char *filename) {

}