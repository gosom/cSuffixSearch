#include <iostream>
#include <chrono>
#include "cedartrie.h"
#include "fcgi_stdio.h"
#include <stdlib.h>

using namespace std::chrono;
using cedartrie::CeDarTrie;


int main()
{
    int count = 0;
    while(FCGI_Accept() >= 0)
        printf("Content-type: text/html\r\n"
               "\r\n"
               "<title>FastCGI Hello!</title>"
               "<h1>FastCGI Hello!</h1>"
               "Request number %d running on host <i>%s</i>\n",
                ++count, getenv("SERVER_NAME"));
//    CeDarTrie trie;
//    auto t0 = high_resolution_clock::now();
//    trie.load("/home/giorgos/projects/suffixSearch/small.txt");
//    auto t1 = high_resolution_clock::now();
//    std::cout << duration_cast<milliseconds>(t1-t0).count() << "msec" << std::endl;
//    std::string line;
//    while (std::cin >> line) {
//        std::string v(line);
//        auto t0 = high_resolution_clock::now();
//        auto res = trie.lookup(v);
//        auto t1 = high_resolution_clock::now();
//        duration_cast<milliseconds>(t1-t0).count();
//        std::cout << "Found " << res.size() << " in " << duration_cast<milliseconds>(t1-t0).count() << "msecs" << std::endl;
//    }
    return 0;
}

