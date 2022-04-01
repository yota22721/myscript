#include <iostream>
#include<fstream>
#include <vector>
#include "tokenizer.hpp"


using namespace std;

int main(int argc,char *argv[]){

    string cmd;
    Tokenizer tokenizer;

    

    if(argc == 1)
        while(true){
            cout <<"xxxscript verson 0.0.0\n"<<"This is xxxscript command line.\n";
            cout << "Type 'exit' or press 'Ctrl + c' to end this command line."<<std::endl;
            cin >> cmd;

            if(cmd == "exit")
                exit(1);
            
        }

    ifstream ifs(argv[1]);

    if(ifs.fail()){
        cerr << "Error : Failed to open file "<<argv[1]<<endl;
        return -1;
    }

    string input = string(istreambuf_iterator<char>(ifs),istreambuf_iterator<char>());

    vector<Token> tokens = tokenizer.tokenize(input.c_str());
  


    return 0;

}