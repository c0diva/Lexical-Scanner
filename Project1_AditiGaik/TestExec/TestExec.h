#ifndef TESTEXEC_H
#define TESTEXEC_H
/////////////////////////////////////////////////////////////////////
// TestExec.h - Demonstrates the requirements of project 1         //
// ver 1.0                                                         //
// Language   :C++, Visual Studio 2015                             //
// Application:Lexical Scanner, CSE687 - Object Oriented Design    //
// Author	  :Aditi Gaikwad, Syracuse University				   //
//			   agaikwad@syr.edu									   //		
/////////////////////////////////////////////////////////////////////
/*
* Package Operations:
*---------------------------
* This package provides entry point for demonstarting all the requirements 
* of the project 1.
* This is achieved by creating functions for every requirement.
*
* Build Process:
* -----------------------
* Required Files: Tokenizer.h, Tokenizer.cpp, SemiExp.h, SemiExp.cpp
* Build Command: devenv TestExec.sln /rebuild debug
*
* Maintenance History:
* ----------------------
* ver 1.0: Feb 8th, 2016
* -first release
*
*/
#include "../Tokenizer/Tokenizer.h"
#include "../SemiExp/SemiExp.h"
namespace Scanner
{
	class TestExec
	{
	public:
		void Requirement3();
		void Requirement4();
		void Requirement5();
		void Requirement6_7_8();
		void Requirement9();
		void TestExec::ReqAlphanum();
		void TestExec::ReqPunctuator();
		void TestExec::ReqCComm();
		void TestExec::ReqCppComm();
		void TestExec::ReqSpecialChars();
		void TestExec::ReqQuotedStrings();
		void TestExec::PushBack();
		size_t TestExec::Find();
		size_t TestExec::Length();
		TestExec();
		~TestExec();
		Toker* toker;
		SemiExp* semi;

	};
}



#endif