# Lexical-scanner
Lexical scanner in C++ consisting Tokenizer and SemiExpression.

This project mainly consists of two packages named Tokenizer and SemiExpressions.
Third package is the starting point of the project.

Tokenizer:
It extracts words, called tokens, from a stream of characters. Token boundaries are white-space characters, transitions between alphanumeric and punctuator characters, and comment and string boundaries. Certain classes of punctuator characters belong to single character or two character tokens so they require special rules for extraction.

SemiExpressions:
groups tokens into sets, each of which contain all the information needed to analyze some grammatical construct without containing extra tokens that have to be saved for subsequent analyses. SemiExpressions are determined by special terminating characters: semicolon, open brace, closed brace, newline when preceeded on the same line with '#', and colon when preceded by one of the three tokens "public", "protected", or "private".
