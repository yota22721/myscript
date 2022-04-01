tokenizer: tokenizer.cpp token.cpp main.cpp 
		g++ tokenizer.cpp token.cpp main.cpp -o tokenizer



clean:
	rm -f *.o tokenizer