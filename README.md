## Introduction
This project came from the need to efficiently store milions of tokens and
be able to perform search based on prefixes.

Given N tokens (strings), each one holding an integer value ID,
and a prefix Q return me all the tokens (with their IDs) starting with Q.
Moreover I wanted a data structure that can be created dynamically.

I chose to use an double-array trie.
I used the implementation from

N. Yoshinaga and M. Kitsuregawa. A Self-adaptive Classifier for Efficient Text-stream Processing. Proc. COLING 2014, pp. 1091--1102. 2014.

The library can be found here: http://www.tkl.iis.u-tokyo.ac.jp/~ynaga/cedar/#dl

## Usage

First install the cedar library as descibed here:http://www.tkl.iis.u-tokyo.ac.jp/~ynaga/cedar/#dl


```c++
#include "cedartrie.h"
CeDarTrie trie;
// you can insert keys one by one
trie.insert("token1", 1);
trie.insert("token2", 3);
// when you insert the same key twice the old 
// value is replaced by the latest
// This behavior is different that the cedar's lib!

// or you can load from a file
// each line should be of the form: ID    token (TAB separated)
trie.load("file-with-tokens");
// retrieve
// lookup method return a vector of Result.
// Result has attributes key and value
trie.lookup("tok");
```

## Perfomance
The perfomance is really good.
My primary concerns was memory size and lookup times.

For 10M of tokens (with 10M integer IDs) it uses around 1Gb of memory. I think this is pretty good.

Lookup time is very fast also.

The initial insetions of 10M keys is relatively slow, although in my use case will happen only once and sometimes some new keys will be added.

Here are some benchmarks of the cedar library:http://www.tkl.iis.u-tokyo.ac.jp/~ynaga/cedar/#perf


