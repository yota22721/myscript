#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;

char *reader(const char *input){
    char *cursor = (char*)input;
    while(*cursor){
        cout << *cursor << endl;

        cout << "next token : "<<*(cursor+1)<<" current token : "<< *cursor<<endl;
        cursor++;
    }
    return cursor;
    

}

void cmp(void){
    const char* t= "abcdef";
    const char* x = "abc12";

    if(memcmp(t,x,3) == 0){
        cout << "Partly correct."<<endl;    
    }

}

int main(int argc,char* argv[])
{
    bool a = true;

    cout <<"bool : "<<a<<endl;

    //load file using string's method
    ifstream ifs(argv[1]);
    if(ifs.fail()){
        cerr << "Error : Failed to open a file. "<<argv[1]<<endl;
        exit(1);
    }
    string input = string(istreambuf_iterator<char>(ifs),istreambuf_iterator<char>());

    reader(input.c_str());
    

    //cout << *reader(input.c_str()) << endl;
    exit(1);
}