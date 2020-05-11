#include <iostream>
#include <string>
#include <vector>
#include "../code/SufTrie.h"

using namespace std;

int main(){
    SufTrie mySTrie;

    string txt = "pana";
    mySTrie.suffixTrie(txt);


    return 0;
}