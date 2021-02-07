#ifndef LAB1_TOKEN_H
#define LAB1_TOKEN_H
#include <string>
#include <map>

using namespace std;

enum tokenType 
{
	COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH,
	MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, WHITESPACE,
	UNDEFINED, END
};

class token
{   
public:

	token(tokenType token , string value, int line): type(token), value(value),line(line)
	{
		// initiazlizing
		// value type[example] = what you want
		mapToken[COMMA] = "COMMA";
		mapToken[PERIOD] = "PERIOD";
		mapToken[Q_MARK] = "Q_MARK";
		mapToken[LEFT_PAREN] = "LEFT_PAREN";
		mapToken[RIGHT_PAREN] = "RIGHT_PAREN";
		mapToken[COLON] = "COLON";
		mapToken[COLON_DASH] = "COLON_DASH";
		mapToken[MULTIPLY] = "MULTIPLY";
		mapToken[ADD] = "ADD";
		mapToken[SCHEMES] = "SCHEMES";
		mapToken[FACTS] = "FACTS";
		mapToken[RULES] = "RULES";
		mapToken[QUERIES] = "QUERIES";
		mapToken[ID] = "ID";
		mapToken[STRING] = "STRING";
		mapToken[COMMENT] = "COMMENT";
		mapToken[WHITESPACE] = "WHITESPACE";
		mapToken[UNDEFINED] = "UNDEFINED";
		mapToken[END] = "EOF";
	}
	~token() {}
	string printToken();
	string printTokenUND();
	string printLineNUM();

private:
	tokenType type;
	string value;
	int line;
	// I choose to use a map because it is easy to pair to token type with the sign
	// typedef pair<const Key, T> value_type;
	// there is also another way to do this is by switch statement
	map<tokenType, string> mapToken;
};

#endif //LAB1_TOKEN_H