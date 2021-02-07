#ifndef LAB1_LEXER_H
#define LAB1_LEXER_H

#include "token.h"
#include "fstream"
#include "vector"

using namespace std;

class lexer
{
public:
	lexer() {}
	~lexer() {}
	void check(string fileName);
	void checkToken();
	void checkID();
	void checkLine(); // check for line comment
	void checkBlock();   // check for block comment
	void update(tokenType type ,int lineNum); // update the token 
private:

	ifstream input;

	int line = 1;
	char a; // state a automata
	char b; // state b automata
	string value = "";
	int starting = 0;
	vector<token> vectorToken;

};

#endif /* LAB1_LEXER_H */
