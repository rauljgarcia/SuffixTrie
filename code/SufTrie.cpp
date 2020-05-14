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

    for(auto it : pre){
        if(!curr->children[it]){
            return false;
        } else {
            curr = curr->children[it];
        }
    }
    return true;
}

bool SufTrie::nodeEmpty(shared_ptr<sufTrie>& curr){
    for(auto it: curr->children){
    if(it.second == nullptr){
        return true;
        } 
    }
    return false;
}

bool SufTrie::delStrHelper(string& txt, shared_ptr<sufTrie>& root){
    if(root == nullptr){
        return false;
        }
    
    if(txt.size() == 0){
        root->children[(txt[0])] = nullptr;
        return true;
        }

    string part = txt.substr(1);
    if(delStrHelper(part, root->children[ (txt[0]) ])){

        if(nodeEmpty(root->children[(txt[0])])){
            root->children[(txt[0])] = nullptr;
            return true;
            } else { 
                return true;
            }
    } else {   
        return false;
        }
    return false;
}
 
bool SufTrie::delString(string& txt){
    if(delStrHelper(txt, root)){
        return true;
        } else {
    return false;
    }
}
