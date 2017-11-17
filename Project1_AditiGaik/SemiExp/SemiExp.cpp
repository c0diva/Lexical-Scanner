///////////////////////////////////////////////////////////////////////
// SemiExpression.cpp - collect tokens for analysis                  //
// ver 3.1                                                           //
// Language   : C++, Visual Studio 2015                              //
// Application: Parser component, CSE687 - Object Oriented Design    //
// Source     : Jim Fawcett, Syracuse University, CST 4-187          //
//              jfawcett@twcny.rr.com								 //
// Author     : Aditi Gaikwad, Syracuse University,					 //
//				agaikwad@syr.edu									 //
///////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include <unordered_map>
#include <exception>
#include "SemiExp.h"
#include "ITokCollection.h"
#include "../Tokenizer/Tokenizer.h"

using namespace Scanner;

SemiExp::SemiExp(Toker* pToker) : _pToker(pToker) {}
void SemiExp::setSemiExp(Toker* pToker) { _pToker = pToker; }

bool SemiExp::get(bool clear)
{
	if (_pToker == nullptr)
		throw(std::logic_error("no Toker reference"));
	_tokens.clear();
	while (true)
	{	std::string token = _pToker->getTok();
		if (token == "")
			break;
		_tokens.push_back(token);
		if (token == ";")
			return true;
		else if (token == "{" || token == "}" ) //Termination condition for open curly brace
			return true;
		else if (token == "#") //Termination condition for '#'
		{	
			return PoundSign(token);
		}
		else
			if (token == "public" || token == "protected" || token == "private") //Termination condition for access specifiers 
			{																	
				return AccessSpecifier(token);
			}
			else
				if (token == "for")   //Termination condition for for loop
				{	
					return	ForLoop(token);
				}
	}
	return false;
}
bool SemiExp::PoundSign(std::string token)
{
	while (true)
	{
		token = _pToker->getTok();
		_tokens.push_back(token);
		if (token == "\n")
			break;
	}
	return true;
}
bool SemiExp::AccessSpecifier(std::string token)
{
	while (true)
	{
		token = _pToker->getTok();
		_tokens.push_back(token);
		if (token == ":")
			break;
	}
	return true;
}
bool SemiExp::ForLoop(std::string token)
{
	while (token != ";")
	{
		token = _pToker->getTok();
		_tokens.push_back(token);
	}
	while (token != ";")
	{
		token = _pToker->getTok();
		_tokens.push_back(token);
	}
	while (token!=")")
	{
		token = _pToker->getTok();
		_tokens.push_back(token);
		if (token == ")")
			break;
	}
	return true;
}
std::string& SemiExp::operator[](int n)
{
	size_t t = n;
	if (t < 0 || t >= _tokens.size())
		throw(std::invalid_argument("index out of range"));
	return _tokens[t];
}
Token SemiExp::operator[](size_t n)
{
	if (n < 0 || n >= _tokens.size())
		throw(std::invalid_argument("index out of range"));
	return _tokens[n];
}
size_t SemiExp::length()
{
	return _tokens.size();
}
void SemiExp::push_back(const std::string& tok) //tokens are pushed back into the vector
{
	_tokens.push_back(tok);
	return;
}
size_t SemiExp::find(const std::string& token) //To find the token in the vector
{
	if (_pToker == nullptr)
		throw(std::logic_error("no Toker reference"));
	for (size_t i = 0; i < _tokens.size(); i++)
	{
		if (token == _tokens[i])
		{
			return i;
		}
	}
	return -1;
}
void SemiExp::printVector()
{
	for (size_t i = 0; i < _tokens.size(); i++)
	{
		std::cout << " " << _tokens[i];
	}
}
bool SemiExp::merge(const std::string& firstTok, const std::string& secondTok)
{
	return true;
}
bool SemiExp::remove(const std::string& tok) //removex token by comparing its string
{
	
	for (size_t i = 0; i < _tokens.size(); i++)
	{
		if (tok == _tokens[i])
		{
			_tokens.erase(_tokens.begin() + i);
			return true;
		}
	}
	return false;
}
bool SemiExp::remove(size_t i) //removes token by its position in the vector
{
	if (i < _tokens.size())
	{
		_tokens.erase(_tokens.begin() + i);
		return true;
	}
	else
	{
		std::cout << "\n Invalid token position";
		return false;
	}
}

void SemiExp::toLower()  //changes all the strings of the vector to lowercase
{
	std::locale loc;
	for (size_t i = 0; i < _tokens.size(); i++)
	{
		size_t j = 0;
		std::string s = "";
		while (j < (_tokens[i].length()))
		{
			char c = _tokens[i].at(j);
			if (c <= 'a' && c >= 'z')
			{
				s += c;
				j++;
			}
			else
			{
				s += std::tolower(c, loc);
				j++;
			}
		}
		_tokens[i] = s;
	}
	return;
}

void SemiExp::trimFront() //trims the blank spaces in front of the string
{
	size_t j = 0;
	for (size_t i = 0; i < _tokens.size(); i++)
	{
		for (; j < _tokens[i].length(); j++)
		{
			if (_tokens[i].at(0) != '\n')
				break;
			else
				_tokens[i].erase(0, 1);
			j--;
		}
	}
	
	
	
	return;
}

void SemiExp::clear()
{
	_tokens.clear();
	return;
}

std::string SemiExp::show(bool showNewLines)
{
	std::string s = "";
	if (showNewLines)
	{
		s += "\n";
	}
	for (auto token : _tokens)
		if (token != "\n")
		{
			s += token;
			s += " ";
		}
	if (showNewLines)
	{
		s += "\n";
	}
	return s;
}


#ifdef SEMIEXP
int main()
{
	Toker toker;
	std::string fileSpec = "../Tokenizer/Tokenizer.cpp";   //"../Tokenizer/test.txt";
	std::fstream in(fileSpec);
	if (!in.good())
	{
		std::cout << "\n  can't open file " << fileSpec << "\n\n";
		return 1;
	}
	toker.attach(&in);

	// std::cout << "\n xcvbnmm,,,,";
	SemiExp semi(&toker);
	semi.printVector();
	while (semi.get())
	{
		std::cout << "\n  -- semiExpression --";
		std::cout << semi.show(true);
	}
	/*
	   May have collected tokens, but reached end of stream
	   before finding SemiExp terminator.
	 */
	if (semi.length() > 0)
	{
		std::cout << "\n  -- semiExpression --";
		std::cout << semi.show(true);
		std::cout << "\n\n";
	}
	std::cout << "-------Demonstration of push_back------- \n\n";
	std::cout << "Vector elements are:\n";
	semi->push_back("\nTHIS");
	semi->push_back("IS");
	semi->push_back("DEMONSTRATION");
	semi->push_back("EXAMPLE");
	semi->printVector();
	std::cout << "\n\n-------Demonstration of find------- \n\n";
	semi->find("DEMONSTRATION");
	std::string output6 = semi->show(true);
	std::cout << output6;
	std::cout << "\n\n-------Demonstration of Length------- \n\n";
	semi->length();
	//Demonstrating trimFront function
	std::cout << "\n\n-----Demonstration for trimFront()-----\n";
	semi->push_back("\ntrimming front");
	std::string output4 = semi->show(true);
	std::cout << "\nBefore trimming: " << output4;
	semi->trimFront();
	std::string output5 = semi->show(true);
	std::cout << "\nAfter trimming: " << output5;
	//Demonstrating toLower function
	std::cout << "\n\n----Demonstration for toLower()-------";
	std::cout << "\n\nConverting tokens to the lowercase:\n\n ";
	semi->toLower();
	std::string String = semi->show(true);
	std::cout << String;
	//Demonstrating operator function
	std::cout << "\n\n-----Demonstration for operator-----\n\n";
	std::string Operator = semi->operator[](1);
	std::cout << "Copying the token at position 1 into string = " << Operator;
	//Demonstrating remove by token
	std::cout << "\n\n-----Demonstration for remove token-----\n\n";
	semi->remove("is");
	std::string output1 = semi->show(true);
	std::cout << " Vector after removing token 'is' :\n";
	std::cout << output1;
	//Demonstrating remove by index
	std::cout << "\n\n------Demonstration for remove at the index----\n\n";
	std::cout << "Vector before removing token: ";
	std::string output3 = semi->show(true);
	std::cout << output3;
	std::cout << "Vector after removing token at index 2 :";
	semi->remove(2);
	std::string output2 = semi->show(true);
	std::cout << output2 << "\n\n";
	return 0;
}
#endif