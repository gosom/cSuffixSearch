#include "cedartrie.h"
#include <fstream>
#include <iostream>

namespace cedartrie{

CeDarTrie::CeDarTrie(){

}

CeDarTrie::CeDarTrie(std::string fname){

}

CeDarTrie::~CeDarTrie(){

}

void CeDarTrie::insert(const std::string& key, int value){
    const char* k = key.c_str();
    auto v = trie.update(k, strlen(k), value);
    v = value;
}

std::vector<Result> CeDarTrie::lookup(const std::string& prefix){
    std::vector<Result> ret;
    const char* pf = prefix.c_str();
    int buffer = 1024;
    trie_t::result_triple_type* result_triple = new trie_t::result_triple_type[buffer];
    if (const size_t n = trie.commonPrefixPredict(pf, result_triple, buffer)) {
        if(n >= buffer){
            delete [] result_triple;
            result_triple = new trie_t::result_triple_type[n];
            trie.commonPrefixPredict(pf, result_triple, n);
        }
        char suffix[255];
        ret.reserve(n);
        for(size_t i=0; i<n; ++i){
            trie.suffix(suffix, result_triple[i].length, result_triple[i].id);
            std::string s(suffix);
            std::string key = prefix + s;
            int val = result_triple[i].value;
            Result r{key, val};
            ret.push_back(r);
        }
        delete [] result_triple;
    }
    return ret;
}

bool CeDarTrie::load(std::string fname){
    std::ifstream ifs(fname);
    if(!ifs){
        std::cerr << "Cannot open file " << fname << std::endl;
        return false;
    }
    std::string key;
    int value;
    trie.clear();
    int failed = 0;
    while(ifs >> value && ifs >> key){
        if(key.size() < 255)
            insert(key, value);
        else
            failed++;
    }
    std::cerr << "Skipped " << failed << " keys" << std::endl;
}

}
