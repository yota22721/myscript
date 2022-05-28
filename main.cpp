#include <iostream>
#include<fstream>
#include <vector>
#include "parser.hpp"
#include "tokenizer.hpp"



using namespace std;

int main(int argc,char *argv[]){

    string cmd;
    Tokenizer tokenizer;
    Parser parser;

    
    //Activate myscript command line
    if(argc == 1)
        while(true){
            cout <<"xxxscript verson 0.0.0\n"<<"This is xxxscript command line.\n";
            cout << "Type 'exit' or press 'Ctrl + c' to end this command line."<<std::endl;
            cout <<">>";
            cin >> cmd;

            if(cmd == "exit")
                exit(1);
            
        }

    // Load myscript file
    ifstream ifs(argv[1]);

    if(ifs.fail()){
        cerr << "Error : Failed to open file "<<argv[1]<<endl;
        return -1;
    }

    string input = string(istreambuf_iterator<char>(ifs),istreambuf_iterator<char>());

    //Tokenize file content
    vector<Token> tokens = tokenizer.tokenize(input.c_str());
    //Parse token
    vector<Node*> nodes = parser.parse(tokens);
  


    return 0;

}