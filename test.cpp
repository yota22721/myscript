#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;

char *reader(const char *input){
    char *cursor = (char*)input;
    while(*cursor != '\n'){
        cout << *cursor << endl;
        cursor++;
    }
    return cursor;
    

}

class Test
{
private:
        vector<Test> tk;
        int value;
        string name;
public:

        vector<Test> hello(void);

};







void cmp(void){
    const char* t= "abcdef";
    const char* x = "abc12";

    if(memcmp(t,x,3) == 0){
        cout << "Partly correct."<<endl;
    }

}

int main(int argc,char* argv[])
{
    //Testing string constructor
    char data[] = {'3','4','5'};
    int n = 5;
    vector<int> point ={4,5,6,7,8,1,2,3};

    for(auto it=point.begin();it !=point.end();++it){
        auto next = it;
        ++next;
        
        cout <<"Current number : "<<it[0] << " Next number : "<< it[1] <<endl;
        cout << "Now it = "<< *it<<endl;
    }

 
    string blank =" ";

    cmp();

    if(blank == " ")
    {
        cout << "It's white space!" <<endl;
    }

    string str(data,end(data));
    cout << str <<endl;

    // stlen = string(p,n);

    cout << str << endl;


    //load file using string's method
    ifstream ifs(argv[1]);
    if(ifs.fail()){
        cerr << "Error : Failed to open a file. "<<argv[1];
    }
    string input = string(istreambuf_iterator<char>(ifs),istreambuf_iterator<char>());
    

    //cout << *reader(input.c_str()) << endl;
    exit(1);
}