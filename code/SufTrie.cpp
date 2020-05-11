#include <iostream>
#include "SufTrie.h"
using namespace std;

SufTrie::SufTrie(){
root = CreateNode();
}

SufTrie::~SufTrie(){
}

shared_ptr<sufTrie>SufTrie::CreateNode(){
    shared_ptr<sufTrie>node(new sufTrie);
    return node;
}

void SufTrie::suffixTrie(string txt){
    txt+="$";
    for(int i=0; i<txt.length(); i++){
        shared_ptr<sufTrie>curr = root;
        string part = txt.substr(i);
        for(int j = 0; j<part.length(); j++){
            if(curr->children[part[j]] == nullptr){
            curr->children[part[j]] = CreateNode();
                }
            curr = (curr->children[part[j]]);
            }
        }
    }




