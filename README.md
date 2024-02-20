# Lexical-Analyzer-using-Flex
This project provides valuable experience in compiler design and implementation, including a deep understanding of the language's lexical structure and proficiency in writing regular expressions and implementing scanners.


INTRODUCTION
This project, based on creating the first phase of a Compiler for the C++ programming language, focuses on generating lexemes from the given input and verifying the syntax correctly using a syntax tree. 
It works for constructs such as conditional statements, loops and the ternary operator. The main idea of this is to properly implement the tokenization and verification of an input using the following procedures
1. Generate lexemes after conducting  line by line tokenization
2. Generate Syntax Tree for the code and verify its grammatical correctness

The main tools used in the project include LEX which identifies predefined
patterns and generates tokens for the patterns matched and YACC which parses the
input for semantic meaning and generates an abstract syntax tree and intermediate
code for the source code.


ARCHITECTURE OF LANGUAGE

C++ constructs implemented:
1. Simple If and if-else
2. Ternary operator
3. While loop
4. For-loop
Arithmetic expressions with +, -, *, /, ++, -- are handled
Boolean expressions with >,=,<=,== are handled
Error handling reports undeclared variables


WORKING

The input source code is read character by character from a file or user input.
The scanner reads the input one character at a time and matches the input against a set of regular expressions to recognize tokens.
When a regular expression matches a sequence of characters in the input, the corresponding token is identified and a Lexeme object is created to represent the token.
The Lexeme object contains the type of token (an integer value) and the value of the token (a string).
The getNextToken() function returns the Lexeme object to the parser.
The parser processes the Lexeme objects to build an abstract syntax tree (AST) that represents the input source code.
If the scanner encounters an error while scanning the input (e.g., a character that doesn't match any token), it reports an error and halts the scanning process.
Once all input has been processed, the scanner returns the AST to the caller.


Lexical Analysis Algorithm:

● LEX tool was used to create a scanner for C++ language
● The scanner transforms the source file from a stream of bits and bytes into a
series of meaningful tokens containing information that will be used by the later
stages of the compiler.
● The scanner also scans for the comments (single-line and multiline comments)
and writes the source file without comments onto an output file which is used in
the further stages.
● All tokens included are of the form T_.Eg: T_pl for ‘+’,T_min for ‘-’, T_lt for
‘<’, etc.
A global variable ‘yylavl’ is used to record the value of each lexeme scanned.
‘yytext’ is the lex variable that stores the matched string.
● Skipping over white spaces and recognizing all keywords, operators, variables
and constants is handled in this phase.
● Scanning error is reported when the input string does not match any rule in the
lex file.
● The rules are regular expressions which have corresponding actions that execute
on a match with the source input.

