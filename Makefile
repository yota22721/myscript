parser: tokenizer.cpp token.cpp main.cpp node.cpp parser.cpp
		g++ tokenizer.cpp token.cpp main.cpp node.cpp parser.cpp -o parser


clean:
	rm -f *.o parser