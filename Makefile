myscript: tokenizer.cpp token.cpp main.cpp node.cpp parser.cpp codegen.cpp
		g++ tokenizer.cpp token.cpp main.cpp node.cpp parser.cpp  codegen.cpp -o myscript


clean:
	rm -f *.o myscript
