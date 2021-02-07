#include "token.h"
#include <sstream>

string token::printToken()
{
	string tokenOutput;
	tokenOutput = "(" + mapToken[type]  + ",\"" + value + "\"," + printLineNUM() + ')';
	return tokenOutput;

}


string token::printTokenUND()
{
	string tokenOutput;
	tokenOutput = "(" + mapToken[type] + ",\"" + value + "\n" + "\"," + printLineNUM() + ')';
	return tokenOutput;

}

string token ::printLineNUM()
{
	stringstream input;
	input << line;
	string lineNUM = input.str();
	return lineNUM;


}