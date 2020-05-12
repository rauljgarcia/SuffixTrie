#include <iostream>
#include <string>
#include <vector>
#include "../code/SufTrie.h"

using namespace std;

int main(){
    SufTrie mySTrie;

    string txt = "bana";
    mySTrie.suffixTrie(txt);

    // string substr = "apan";
    // if(mySTrie.searchSub(substr) == true){
    //     cout<<"Substring '"<<substr<<"' was found in the trie"<<endl;
    //     } else {
    //         cout<<"Substring '"<<substr<<"' was not found in the trie"<<endl;
    //     };
    
    // string pre = "pan";
    // if(mySTrie.searchPre(pre)== true){
    //     cout<<"The prefix '"<<pre<<"' was found in Trie"<<endl;
    //     } else {
    //         cout<<"The prefix '"<<pre<<"' was not found in Trie"<<endl;
    //     };


    return 0;
}