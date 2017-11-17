// TestExecutive.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////
// TestExec.cpp - Demonstrates the requirements of project 1       //
// ver 1.0                                                         //
// Language   :C++, Visual Studio 2015                             //
// Application:Lexical Scanner, CSE687 - Object Oriented Design    //
// Author	  :Aditi Gaikwad, Syracuse University				   //
//			   agaikwad@syr.edu									   //		
/////////////////////////////////////////////////////////////////////

#include "TestExec.h"

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <fstream>

using namespace Scanner;

TestExec::TestExec()
{
	toker = new Toker();
}

TestExec::~TestExec()
{
	delete toker;
	delete semi;
}
//Alphanumeric 
void TestExec::ReqAlphanum()
{
	std::cout << "\n\n-- Demonstrating for Alphanum ---\n";
	std::string fileSpec = "../TestExec/Req4_Alphanum.txt";

	std::ifstream in(fileSpec);
	if (!in.good())
	{
		std::cout << "\n  can't open " << fileSpec << "\n\n";
		return;
	}
	Toker Req4;
	Req4.attach(&in);

	do
	{
		std::string tok = Req4.getTok();
		if (tok == "\n")
			tok = " newline";
		std::cout << "\n -- " << tok;
	} while (in.good());
	return;
}
//Punctuator
void TestExec::ReqPunctuator()
{
	std::cout << "\n\n-- Demonstrating for Punctuator ----\n";
	std::string fileSpec = "../TestExec/Req4_Punctuator.txt";

	std::ifstream in(fileSpec);
	if (!in.good())
	{
		std::cout << "\n  can't open " << fileSpec << "\n\n";
		return;
	}
	Toker Req4;
	Req4.attach(&in);
	do
	{
		std::string tok = Req4.getTok();
		if (tok == "\n")
			tok = " newline";
		std::cout << "\n -- " << tok;
	} while (in.good());
	return;
}
//'c' comment
void TestExec::ReqCComm()
{
	std::cout << "\n\n-- Demonstrating for 'C' Comments ----\n";
	std::string fileSpec = "../TestExec/Req4_CComm.txt";
	std::ifstream in(fileSpec);
	if (!in.good())
	{
		std::cout << "\n  can't open " << fileSpec << "\n\n";
		return;
	}
	Toker* Req4 = new Toker(true);
	Req4->attach(&in);
	do
	{
		std::string tok = Req4->getTok();
		if (tok == "\n")
			tok = " newline";
		std::cout << "\n -- " << tok;
	} while (in.good());
	return;
	delete Req4;
}
//'c++' comments 
void TestExec::ReqCppComm()
{
	std::cout << "\n\n-- Demonstrating for 'C++' Comments ----\n";
	std::string fileSpec = "../TestExec/Req4_CppComm.txt";
	std::ifstream in(fileSpec);
	if (!in.good())
	{
		std::cout << "\n  can't open " << fileSpec << "\n\n";
		return;
	}
	Toker* Req4=new Toker(true);
	Req4->attach(&in);
	do
	{
		std::string tok = Req4->getTok();
		if (tok == "\n")
			tok = " newline";
		std::cout << "\n -- " << tok;
	} while (in.good());
	return;
	delete Req4;
}
// Special Characters
void TestExec::ReqSpecialChars()
{ 
	std::cout << "\n\n-- Demonstrating for Special one and two Characters ----\n";
	std::string fileSpec = "../TestExec/Req4_SpecialChars.txt";
	std::ifstream in(fileSpec);
	if (!in.good())
	{
		std::cout << "\n  can't open " << fileSpec << "\n\n";
		return;
	}
	Toker Req4;
	Req4.attach(&in);
	do
	{
		std::string tok = Req4.getTok();
		if (tok == "\n")
			tok = " newline";
		std::cout << "\n -- " << tok;
	} while (in.good());
	return;
}
// Quoted Strings
void TestExec::ReqQuotedStrings()
{
	std::cout << "\n\n-- Demonstrating Quoted Strings ----\n";
	std::string fileSpec = "../TestExec/Req4_QuotedString.txt";
	std::ifstream in(fileSpec);
	if (!in.good())
	{
		std::cout << "\n  can't open " << fileSpec << "\n\n";
		return;
	}
	Toker Req4;
	Req4.attach(&in);
	do
	{
		std::string tok = Req4.getTok();
		if (tok == "\n")
			tok = " newline";
		std::cout << "\n -- " << tok;
	} while (in.good());
	return;
}
// Requirement No 3
void TestExec::Requirement3()
{
	std::cout << "-------- Demonstrating Requirements for Project 1 -------";
	std::cout << "\n\n******* Requirement 3 ********";
	std::cout << "\n\n C++ packages for Tokenizing is Tokenizer,";
	std::cout << "\n for collecting SemiExpressions is SemiExp, ";
	std::cout << "\n and a scanner interface for ITokCollection in SemiExp.";
	return;
}
//Requirement No 4
void TestExec::Requirement4()
{
	std::cout << "\n\n******* Requirement 4 ********";
	ReqAlphanum();
	ReqPunctuator();
	ReqCComm();
	ReqCppComm();
	ReqSpecialChars();
	ReqQuotedStrings();
	return;
}
// Requirement No 5
void TestExec::Requirement5()
{
		std::cout << "\n\n******* Requirement 5 ********";
		std::string fileSpec = "../TestExec/Req5.txt";
		std::ifstream in(fileSpec);
		if (!in.good())
		{
			std::cout << "\n  can't open " << fileSpec << "\n\n";
			return;
		}
		std::string tok;
		Toker Req5;
		Req5.attach(&in);
		std::cout << "\n";
		std::cout << "\n\n Token BEFORE calling getTok() function: " << tok;
		do
		{		
			tok = Req5.getTok();
			std::cout << "\n\n Token AFTER calling getTok() function: " << tok;
			if (tok == "\n")
				tok = " newline";
		} while (in.good());
		return;
}
// Requirement No 6, 7 and 8
void TestExec::Requirement6_7_8()
{
	std::cout << "\n\n\n******* Requirement 6, 7 and 8 ********\n";
	Toker* Req6_7_8 = new Toker(false);
	std::string fileSpec = "../TestExec/Req6_7_8.txt";   
	std::fstream in(fileSpec);
	if (!in.good())
	{
		std::cout << "\n  can't open file " << fileSpec << "\n\n";
		return;
	}
	Req6_7_8->attach(&in);
	semi= new SemiExp(Req6_7_8);
	while (semi->get())
	{
		std::cout << "\n  -- semiExpression --";
		std::cout << semi->show(true);
	}
	/*
	May have collected tokens, but reached end of stream
	before finding SemiExp terminator.
	*/
	if (semi->length() > 0)
	{
		std::cout << "\n  -- semiExpression --";
		std::cout << semi->show(true);
		std::cout << "\n\n";
	}
	return;
}
//Requirement No 9
void TestExec::Requirement9()
{
	std::cout << "\n\n******* Requirement 9 ********";
	std::cout << "\n\nSemiExp class of SemiExp package implements the";
	std::cout<<"\ninterface ITokenCollection with a declared method get()\n\n ";
	return;
}

int main()
{
	TestExec test;
	test.Requirement3();
	test.Requirement4();
	test.Requirement5();
	test.Requirement6_7_8();
	test.Requirement9();
	return 0;
}