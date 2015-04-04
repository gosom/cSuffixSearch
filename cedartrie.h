#ifndef CEDARTRIE_H
#define CEDARTRIE_H
#include <string>
#include <vector>
#include "cedarpp.h"

namespace cedartrie{

typedef cedar::da<int, cedar::NaN<int>::N1, cedar::NaN<int>::N2, false> trie_t;

struct Result{
    std::string key;
    int value;
};

class CeDarTrie
{
public:
    CeDarTrie();
    CeDarTrie(std::string fname);
    ~CeDarTrie();

    void insert(const std::string& key, int value);
    std::vector<Result> lookup(const std::string& prefix);
    void dump(const std::string fname);
    bool load(const std::string fname);
private:
    trie_t trie;
};

}

#endif // CEDARTRIE_H
