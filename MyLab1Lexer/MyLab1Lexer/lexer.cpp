#include "lexer.h"
#include <fstream>
#include <iostream>
#include <cctype>// I am using cc type for some function like isspace to check for white space
using namespace std;

void lexer::check(string fileName)
{
	input.open(fileName.c_str());

	if (input)
	{
		while (input.get(a))
		{
			checkToken();
		}
		update(END, line);
		cout << "Total Tokens = " << vectorToken.size() << endl;
	}
	else
		cout << "Reading file error" << endl;
}

void lexer::checkToken()
{   
	// first thing check for white space
	while (isspace(a))
	{
		if (a == '\n')
			line++; // if it is a white space
		input.get(a);
		if (input.eof()) // flag 
			break;
	}
	switch (a)
	{
		case ',':
			value = ",";
			update(COMMA, line);
			break;
		case '.':
			value = ".";
			update(PERIOD, line);
			break;
		case '?':
			value = "?";
			update(Q_MARK, line);
			break;
		case '(':
			value = "(";
			update(LEFT_PAREN, line);
			break;
		case ')':
			value = ")";
			update(RIGHT_PAREN, line);
			break;
		case '*':
			value = "*";
			update(MULTIPLY, line);
			break;
		case '+':
			value = "+";
			update(ADD, line);
			break;
		case ':': 
			value = ":";
			b = input.peek(); // return the b character
			if (b == '-')
			{
				value = ":-";
				update(COLON_DASH, line);
				input.get(a);
			}
			else
				update(COLON, line);
			break;
		case '\'':
			checkLine(); // will just call another function
			break;
		case '#':
			checkBlock(); // call block 
			break;
		default:
			if (isalpha(a))//Check if character is alphabetic
				checkID();
			else if (!input.eof())// flag
			{
				value += a;
				update(UNDEFINED, line);
			}
			break;
	}
}

void lexer::checkID()
{
	value += a;
	input.get(a);
	while (isalnum(a)) // Check if character is alphanumeric using locale
	{
		value += a;
		input.get(a);
	}
	if (value == "Schemes")
		update(SCHEMES, line);
	else if (value == "Facts")
		update(FACTS, line);
	else if (value == "Rules")
		update(RULES, line);
	else if (value == "Queries")
		update(QUERIES, line);
	else
		update(ID, line);
	checkToken();



}



void lexer::checkLine()
{
	bool endOfString = false;
	value += a;
	starting = line;
	while (endOfString == false)
	{
		if (input.peek() == -1)
		{
			update(UNDEFINED, starting);
			endOfString = true;
		}
		else
		{
			input.get(a);
			switch (a)
			{
			case '\n':
				line++;
				value += a;
				break;
			case '\'':
				value += a;
				b = input.peek();
				if (b != '\'')
				{
					update(STRING, starting);
					endOfString = true;
				}
				else
				{
					input.get(a);
					value += a;
				}
				break;
			default:
				value += a;
				break;
			}
		}
	}
}

void lexer::checkBlock()
{
	value += a;
	starting = line; 
	b = input.peek();
	if (b != '|')
	{
		input.get(a);
		while (a != '\n') // if a is not space
		{
			value += a;
			input.get(a);
		}
		if (a == '\n')
			line++;
		update(COMMENT, starting);

	}
	else
	{
		input.get(a);
		value += a;
		input.get(a);
		b = input.peek();
		while ((a != '|' || b != '#') && b != -1)

		{
			if (a == '\n')
			line++;
			value += a;
			input.get(a);
			b = input.peek();
		}
		if (a == '|' && b == '#')
		{
			value += a;
			input.get(a);
			value += a;
			update(COMMENT, starting);
		}
		else if (input.peek() == EOF)
		{
			line++;
			//cout << "UND3" << endl;
			 //cout << value << endl;
			//cout << starting << endl;
			update(UNDEFINED, starting);
			
		}
	}
}


void lexer::update(tokenType type, int lineNum)
{
	token newToken(type, value, lineNum);
	vectorToken.push_back(newToken) ;//keep the updated the number of tokens

	if (type == UNDEFINED && line == 12 )
	{   
		cout << newToken.printTokenUND() << endl;
		value = "";
		
	}
	else
	{ 
		cout << newToken.printToken() << endl;
		value = "";
    }

}