#include <bits/stdc++.h>
using namespace std;

class node{
public:
	char ch;
	bool isTerminal;
	unordered_map<char,node*> h;

	node(char c){
		ch = c;
		isTerminal = false;
	}
};
