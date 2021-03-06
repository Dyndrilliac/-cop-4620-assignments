*******************************************************************

* Title:     COP 4620 Assignments
* Author:    [Matthew Boyette](mailto:N00868808@ospreys.unf.edu)
* Class:     Construction of Language Translators (COP 4620)
* Professor: Dr. Roger Eggen
* Term:      Spring 2017

*******************************************************************

This code makes use of my [Custom Java API](https://github.com/Dyndrilliac/java-custom-api). In order to build this source, you should clone the repository for the API using your Git client, then import the project into your IDE of choice (I prefer Eclipse), and finally modify the build path to include the API project. For more detailed instructions, see the README for the API project.

# Project 1 - Lexical Analyzer

* Due:       2/2/2017
* Submitted: 2/2/2017

The goal of this project is to produce a list of valid tokens to pass to the parser (Syntax Analyzer) in Project 2. In order to execute the program, the names of the files containing the text to be scanned must be fed to the program via command-line arguments. If you are GUI capable and not running in a terminal window, you can also just run the program without any arguments. You will then be prompted for a file path.

## Usage Examples

* ``./Binaries/P1.jar './Test Files/lex_t1.txt'``
* ``java -jar ./Binaries/P1.jar './Test Files/lex_t1.txt'``
* ``java -cp ".:$GITHUB/java-custom-api:$JAVA_LIBS/stdlib.jar:$CLASSPATH" Project1.CMinusLexerDemo './Test Files/lex_t1.txt'``
	* **NOTE**: This usage requires compilation before it will work! See the _Build Instructions_ section below.

## File Listing

* CMinusLexerDemo.java: **Class where the main method and program entry-point are located.**
* CMinusLexer.java:     **Class that represents the vast majority of the lexer logic.**
* Lexer.java:           **Class that provides the default Lexer interfaces.**
* Token.java:           **Class that provides a data structure for storing and accessing token data.**
* Support.java:         **Class that provides static utility support methods.**

## Design

The lexical analyzer opens the file, reads the text in line by line, strips comments/whitespace, and feeds each piece of input to Java's Regular Expression engine to match tokens with their lexemes using RegEx patterns.

## Build Instructions

* ``javac -g -cp ".:$GITHUB/java-custom-api:$JAVA_LIBS/stdlib.jar:$CLASSPATH" ./Project1/CMinusLexerDemo.java``

Note that your environment variables will likely be different. What's important is that you have the path to [stdlib.jar](https://introcs.cs.princeton.edu/java/stdlib/) and my [Custom Java API](https://github.com/Dyndrilliac/java-custom-api) in your classpath.

# Project 2 - Syntactical Analyzer

* Due:       03/02/2017
* Submitted: 03/02/2017

The goal of this project is to verify that the list of tokens passed in from Project 1 are in a syntactically correct order. In order to execute the program, the names of the files containing the text to be scanned must be fed to the program via command-line arguments. If you are GUI capable and not running in a terminal window, you can also just run the program without any arguments. You will then be prompted for a file path.

## Usage Examples

* ``./Binaries/P2.jar './Test Files/parse_a_t1.c'``
* ``java -jar ./Binaries/P2.jar './Test Files/parse_a_t1.c'``
* ``java -cp ".:$GITHUB/java-custom-api:$JAVA_LIBS/stdlib.jar:$CLASSPATH" Project2.CMinusParserDemo './Test Files/parse_a_t1.c'``
	* **NOTE**: This usage requires compilation before it will work! See the _Build Instructions_ section below.

## File Listing

* CMinusParserDemo.java: **Class where the main method and program entry-point is located.**
* CMinusSemantics.java:  **Class that represents the vast majority of the semantic analyzer logic.**
* CMinusParser.java:     **Class that represents the vast majority of the parser logic.**
* CMinusLexer.java:      **Class that represents the vast majority of the lexer logic.**
* Lexer.java:            **Class that provides the default Lexer interfaces.**
* Token.java:            **Class that provides a data structure for storing and accessing token data.**
* Support.java:          **Class that provides static utility support methods.**

## Design

This class functions as a generic syntactical analyzer for the C-Minus language. The parser is built in the model of a linear-bounded automaton processing a finite strand of tape which represents the list of tokens. I keep track of which index of the tape I am currently looking at. I can read, write, go forwards, go backwards, or can look back and ahead at any previous or future token, respectively. This effectively parses any language that is LL(k) parsable for any finite constant non-negative integer k. This parser could be made GLL(k) capable by executing all of the calls to the declaration method in parallel.

## Build Instructions

* ``javac -g -cp ".:$GITHUB/java-custom-api:$JAVA_LIBS/stdlib.jar:$CLASSPATH" ./Project2/CMinusParserDemo.java``

Note that your environment variables will likely be different. What's important is that you have the path to [stdlib.jar](https://introcs.cs.princeton.edu/java/stdlib/) and my [Custom Java API](https://github.com/Dyndrilliac/java-custom-api) in your classpath.

# Project 3 - Semantic Analyzer

* Due:       03/30/2017
* Submitted: 03/30/2017

The goal of this project is to verify that the list of tokens passed in from Project 1 are in a semantically correct order. In order to execute the program, the names of the files containing the text to be scanned must be fed to the program via command-line arguments. If you are GUI capable and not running in a terminal window, you can also just run the program without any arguments. You will then be prompted for a file path.

## Usage Examples

* ``./Binaries/P3.jar './Test Files/seman_a_t01.c'``
* ``java -jar ./Binaries/P3.jar './Test Files/seman_a_t01.c'``
* ``java -cp ".:$GITHUB/java-custom-api:$JAVA_LIBS/stdlib.jar:$CLASSPATH" Project3.CMinusSemanticsDemo './Test Files/seman_a_t01.c'``
	* **NOTE**: This usage requires compilation before it will work! See the _Build Instructions_ section below.

## File Listing

* CMinusSemanticsDemo.java: **Class where the main method and program entry-point is located.**
* CMinusSemantics.java:     **Class that represents the vast majority of the semantic analyzer logic.**
* CMinusParser.java:        **Class that represents the vast majority of the parser logic.**
* CMinusLexer.java:         **Class that represents the vast majority of the lexer logic.**
* Lexer.java:               **Class that provides the default Lexer interfaces.**
* Token.java:               **Class that provides a data structure for storing and accessing token data.**
* Support.java:             **Class that provides static utility support methods.**

## Design

This class functions as a generic semantic analyzer for the C-Minus language. It takes the symbol table and parse tree constructed during the parser phase to perform semantic checks.

## Build Instructions

* ``javac -g -cp ".:$GITHUB/java-custom-api:$JAVA_LIBS/stdlib.jar:$CLASSPATH" ./Project3/CMinusSemanticsDemo.java``

Note that your environment variables will likely be different. What's important is that you have the path to [stdlib.jar](https://introcs.cs.princeton.edu/java/stdlib/) and my [Custom Java API](https://github.com/Dyndrilliac/java-custom-api) in your classpath.

# Project 4 - Code Generator

* Due:       04/13/2017
* Submitted: 04/13/2017

The goal of this project is to generate the intermediate assembler code. In order to execute the program, the names of the files containing the text to be scanned must be fed to the program via command-line arguments. If you are GUI capable and not running in a terminal window, you can also just run the program without any arguments. You will then be prompted for a file path.

## Usage Examples

* ``./Binaries/P4.jar './Test Files/code_t1.c'``
* ``java -jar ./Binaries/P4.jar './Test Files/code_t1.c'``
* ``java -cp ".:$GITHUB/java-custom-api:$JAVA_LIBS/stdlib.jar:$CLASSPATH" Project4.CMinusCodeGenDemo './Test Files/code_t1.c'``
	* **NOTE**: This usage requires compilation before it will work! See the _Build Instructions_ section below.

## File Listing

* CMinusCodeGenDemo.java:    **Class where the main method and program entry-point is located.**
* CMinusCodeGeneration.java: **Class that represents the vast majority of the code generator logic.**
* CMinusSemantics.java:      **Class that represents the vast majority of the semantic analyzer logic.**
* CMinusParser.java:         **Class that represents the vast majority of the parser logic.**
* CMinusLexer.java:          **Class that represents the vast majority of the lexer logic.**
* Lexer.java:                **Class that provides the default Lexer interfaces.**
* Token.java:                **Class that provides a data structure for storing and accessing token data.**
* Support.java:              **Class that provides static utility support methods.**

## Design

This project attempts to make minimal modifications to the code previously submitted for Porjects 2 and 3 in order to implement the output of intermediate code.

## Build Instructions

* ``javac -g -cp ".:$GITHUB/java-custom-api:$JAVA_LIBS/stdlib.jar:$CLASSPATH" ./Project4/CMinusCodeGenDemo.java``

# Project 5 - YACC/Lex

* Due:       04/20/2017
* Submitted: 04/20/2017

This project is a lexer/parser combo for a SQL grammar.

## Usage Examples

* ``./Binaries/P5.out < './Test Files/sql_a_t1.txt'``
* ``./Project5/P5.out < './Test Files/sql_a_t1.txt'``
	* **NOTE**: This usage requires compilation before it will work! See the _Build Instructions_ section below.

## File Listing

* makefile: **This file contains the commands to compile the project.**
* p5.l:     **This is the input file for LEX/FLEX.**
* p5.y:     **This is the input file for YACC/BISON.**

## Design

This project uses LEX/FLEX and YACC/BISON to lex and parse a file containing SQL commands.

## Build Instructions

* ``make -C ./Project5``

You can also remove the files automatically generated by the compilation process using the following command:

* ``make -C ./Project5 clean``
