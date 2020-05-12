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


bool SufTrie::searchSub(string substr){
    if(root == nullptr){
        return false;
    }
    shared_ptr<sufTrie>curr = root;
    
    for(auto it : substr){
        if(!curr->children[it]){
            return false;
        } else {
            curr = curr->children[it];
        }
    }
    
    if("$"){
        return true;
        } else {
            return false;
            }
}

bool SufTrie::searchPre(string pre){
    if(root == nullptr){
        return false;
        }

    shared_ptr<sufTrie>curr = root;
    for(int i = 0; i<pre.size(); i++){
        char ch = pre.at(i);
        shared_ptr<sufTrie> node = curr->children[(ch)];
        if(node == nullptr){
            return false;
        }
        curr = node;
    }
    return true;
}


