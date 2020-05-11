#ifndef SUFTRIE_H__
#define SUFTRIE_H__

#include <string>
#include <memory>
#include <list>
#include <unordered_map>

using namespace std;

struct sufTrie {
    unordered_map<char, shared_ptr<sufTrie>>children;
};


class SufTrie {
    private:
    shared_ptr<sufTrie>root;
    typedef vector<shared_ptr<sufTrie>>indices;

    public:
    SufTrie();

    ~SufTrie();

    //returns pointer to a new node
    shared_ptr<sufTrie>CreateNode();

    //builds trie of suffixes of txt
    void suffixTrie(string txt);




    

};

#endif // SUFTRIE_H__

