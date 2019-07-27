
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;

struct dict{
    dict(const string & k, int v)
	: _word(k)
	, _num(v)
	{}
    string _word;
    int _num;
};
bool comp(const dict &a, const dict &b){
    return a._word < b._word;
}
int main(){
    vector<dict> words;
    int cnt=0;
    string filename("/home/ak/0725/The_Holy_Bible.txt");
    ifstream ifs;
    ifs.open(filename);
    string strTmp;
        string wordTmp;
        int flag;
        while(wordTmp.clear(),ifs>>wordTmp){
            flag=0;
            if((wordTmp[0]>='0'&&wordTmp[0]<='9')||wordTmp[0]==' '){
                continue;
            }
            for(auto & word : words){
                if(word._word==wordTmp){
                    flag=1;
                    word._num++;
                    //cout << wordTmp <<" " << word._num <<endl;
                    break;
                }
            }
            if(0==flag){
                words.push_back(dict(wordTmp,1));
                //cout << wordTmp <<" 1" <<endl;
            }
        }
    ofstream ofs("词典");
    sort(words.begin(),words.end(),comp);
    for(auto & word : words){
        ofs << word._word << " " << word._num << "\n";
    }
    ifs.close();
    ofs.close();
    cout << "ok" <<endl;
    return 0;
}