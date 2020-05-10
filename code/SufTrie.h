#ifndef SUFTRIE_H__
#define SUFTRIE_H__

#include <string>
#include <memory>


struct trieNode {
    char ch;
    bool isLeaf;
    shared_ptr<trieNode>children;
};


class sufTrie {

};

#endif // SUFTRIE_H__

