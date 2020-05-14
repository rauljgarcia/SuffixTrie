#include <iostream>
#include <string>
#include <vector>
#include "../code/SufTrie.h"

using namespace std;

int main(){
    SufTrie mySTrie;

    vector<string>txt;
    txt.insert(txt.end(), {"ba", "car", "boy"});
    for(int i=0; i<txt.size(); i++){
        mySTrie.suffixTrie(txt[i]);
    }

    string deletionWord = "car";
    if(mySTrie.delString(deletionWord)){
        cout<<"The string '"<<deletionWord<<"' has been sucessfully deleted from Trie"<<endl;
    } else {
        cout<<"The string '"<<deletionWord<<"' was not found in Trie"<<endl;
    }

    // string substr = "bana";
    // if(mySTrie.searchSub(substr) == true){
    //     cout<<"Substring '"<<substr<<"' was found in the trie"<<endl;
    //     } else {
    //         cout<<"Substring '"<<substr<<"' was not found in the trie"<<endl;
    //     };

    string pre = "ba";
    if(mySTrie.searchPre(pre)== true){
        cout<<"The prefix '"<<pre<<"' was found in Trie"<<endl;
        } else {
            cout<<"The prefix '"<<pre<<"' was not found in Trie"<<endl;
        };

    return 0;
}