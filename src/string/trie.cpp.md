---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2907
  bundledCode: "#line 1 \"src/string/trie.cpp\"\n#include <iostream>\n#include <string>\n\
    #include <vector>\n#include <algorithm>\nusing namespace std;\n// BEGIN\n\n//\
    \ char_size:\u6587\u5B57\u306E\u7A2E\u985E\u6570, margin:\u5148\u982D\u6587\u5B57\
    \ntemplate <int char_size, int margin>\nstruct Trie{\n    struct TrieNode{\n \
    \       int nxt[char_size];  //\u5B50\u30CE\u30FC\u30C9\u306E\u756A\u53F7\n  \
    \      vector<int> idx;  // prefix\u306E\u4E00\u81F4\u3059\u308B\u6587\u5B57\u5217\
    \u306E\u756A\u53F7\u306E\u96C6\u5408\n        TrieNode(){\n            fill(nxt,\
    \ nxt+char_size, -1);\n        }\n    };\n\n    vector<TrieNode> nodes;\n    Trie(){\n\
    \        nodes.push_back(TrieNode());\n    };\n    void add(const string &str,\
    \ int id){\n        int node_index = 0;\n        nodes[0].idx.push_back(id);\n\
    \        for(int i=0;i<int(str.size());i++){\n            int c = str[i] - margin;\n\
    \            if(nodes[node_index].nxt[c] == -1){\n                nodes[node_index].nxt[c]\
    \ = int(nodes.size());\n                nodes.push_back(TrieNode());\n       \
    \     }\n            node_index = nodes[node_index].nxt[c];\n            nodes[node_index].idx.push_back(id);\n\
    \        }\n    }\n    // \u6587\u5B57\u5217\u306E\u8FFD\u52A0\n    void add(const\
    \ string &str){\n        add(str, int(nodes[0].idx.size()));\n    }\n    // \u5BFE\
    \u5FDC\u3059\u308Bnode\u756A\u53F7\u306E\u691C\u7D22\n    int find(const string\
    \ &str){\n        int node_index = 0;\n        for(int i=0;i<int(str.size());i++){\n\
    \            int c = str[i] - margin;\n            if(nodes[node_index].nxt[c]\
    \ == -1){\n                return -1;\n            }\n            node_index =\
    \ nodes[node_index].nxt[c];\n        }\n        return node_index;\n    }\n};\n\
    \n// END\n\n// varify\n// https://onlinejudge.u-aizu.ac.jp/problems/2907\nint\
    \ N, Q;\nvector<string> words;\nTrie<26, 'a'> trie;\nvector<int> ls;\n\nint main()\
    \ {\n    cin >> N >> Q;\n    words.resize(N);\n    for(int i=0;i<N;i++) cin >>\
    \ words[i];\n    sort(words.begin(), words.end());\n    // suffix trie\u6728\u306E\
    \u69CB\u7BC9\n    for(int i=0;i<N;i++){\n        reverse(words[i].begin(), words[i].end());\n\
    \        trie.add(words[i]);\n        reverse(words[i].begin(), words[i].end());\n\
    \    }\n    string pre, suf;\n    for(int i=0;i<Q;i++){\n        cin >> pre >>\
    \ suf;\n        // suffix\u306E\u4E00\u81F4\u3059\u308Bnode\u3092\u63A2\u7D22\n\
    \        reverse(suf.begin(),suf.end());\n        int id = -1;\n        if((id\
    \ = trie.find(suf)) < 0 || id >= trie.nodes.size()){\n            cout << 0 <<\
    \ endl;\n            continue;\n        }\n        ls = trie.nodes[id].idx;  //\
    \ suffix\u306E\u4E00\u81F4\u3059\u308B\u6587\u5B57\u5217\u306E\u756A\u53F7\u96C6\
    \u5408\n        // prefix\u3092\u4E8C\u5206\u63A2\u7D22\n        int lo, hi;\n\
    \        lo = lower_bound(words.begin(), words.end(), pre) - words.begin();\n\
    \        lo = lower_bound(ls.begin(), ls.end(), lo) - ls.begin();\n        pre\
    \ += '~';\n        hi = lower_bound(words.begin(), words.end(), pre) - words.begin();\n\
    \        hi = lower_bound(ls.begin(), ls.end(), hi) - ls.begin();\n        cout\
    \ << hi - lo << endl;\n    }\n    return 0;\n}\n"
  code: "#include <iostream>\n#include <string>\n#include <vector>\n#include <algorithm>\n\
    using namespace std;\n// BEGIN\n\n// char_size:\u6587\u5B57\u306E\u7A2E\u985E\u6570\
    , margin:\u5148\u982D\u6587\u5B57\ntemplate <int char_size, int margin>\nstruct\
    \ Trie{\n    struct TrieNode{\n        int nxt[char_size];  //\u5B50\u30CE\u30FC\
    \u30C9\u306E\u756A\u53F7\n        vector<int> idx;  // prefix\u306E\u4E00\u81F4\
    \u3059\u308B\u6587\u5B57\u5217\u306E\u756A\u53F7\u306E\u96C6\u5408\n        TrieNode(){\n\
    \            fill(nxt, nxt+char_size, -1);\n        }\n    };\n\n    vector<TrieNode>\
    \ nodes;\n    Trie(){\n        nodes.push_back(TrieNode());\n    };\n    void\
    \ add(const string &str, int id){\n        int node_index = 0;\n        nodes[0].idx.push_back(id);\n\
    \        for(int i=0;i<int(str.size());i++){\n            int c = str[i] - margin;\n\
    \            if(nodes[node_index].nxt[c] == -1){\n                nodes[node_index].nxt[c]\
    \ = int(nodes.size());\n                nodes.push_back(TrieNode());\n       \
    \     }\n            node_index = nodes[node_index].nxt[c];\n            nodes[node_index].idx.push_back(id);\n\
    \        }\n    }\n    // \u6587\u5B57\u5217\u306E\u8FFD\u52A0\n    void add(const\
    \ string &str){\n        add(str, int(nodes[0].idx.size()));\n    }\n    // \u5BFE\
    \u5FDC\u3059\u308Bnode\u756A\u53F7\u306E\u691C\u7D22\n    int find(const string\
    \ &str){\n        int node_index = 0;\n        for(int i=0;i<int(str.size());i++){\n\
    \            int c = str[i] - margin;\n            if(nodes[node_index].nxt[c]\
    \ == -1){\n                return -1;\n            }\n            node_index =\
    \ nodes[node_index].nxt[c];\n        }\n        return node_index;\n    }\n};\n\
    \n// END\n\n// varify\n// https://onlinejudge.u-aizu.ac.jp/problems/2907\nint\
    \ N, Q;\nvector<string> words;\nTrie<26, 'a'> trie;\nvector<int> ls;\n\nint main()\
    \ {\n    cin >> N >> Q;\n    words.resize(N);\n    for(int i=0;i<N;i++) cin >>\
    \ words[i];\n    sort(words.begin(), words.end());\n    // suffix trie\u6728\u306E\
    \u69CB\u7BC9\n    for(int i=0;i<N;i++){\n        reverse(words[i].begin(), words[i].end());\n\
    \        trie.add(words[i]);\n        reverse(words[i].begin(), words[i].end());\n\
    \    }\n    string pre, suf;\n    for(int i=0;i<Q;i++){\n        cin >> pre >>\
    \ suf;\n        // suffix\u306E\u4E00\u81F4\u3059\u308Bnode\u3092\u63A2\u7D22\n\
    \        reverse(suf.begin(),suf.end());\n        int id = -1;\n        if((id\
    \ = trie.find(suf)) < 0 || id >= trie.nodes.size()){\n            cout << 0 <<\
    \ endl;\n            continue;\n        }\n        ls = trie.nodes[id].idx;  //\
    \ suffix\u306E\u4E00\u81F4\u3059\u308B\u6587\u5B57\u5217\u306E\u756A\u53F7\u96C6\
    \u5408\n        // prefix\u3092\u4E8C\u5206\u63A2\u7D22\n        int lo, hi;\n\
    \        lo = lower_bound(words.begin(), words.end(), pre) - words.begin();\n\
    \        lo = lower_bound(ls.begin(), ls.end(), lo) - ls.begin();\n        pre\
    \ += '~';\n        hi = lower_bound(words.begin(), words.end(), pre) - words.begin();\n\
    \        hi = lower_bound(ls.begin(), ls.end(), hi) - ls.begin();\n        cout\
    \ << hi - lo << endl;\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/trie.cpp
  requiredBy: []
  timestamp: '2019-07-21 22:56:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/trie.cpp
layout: document
redirect_from:
- /library/src/string/trie.cpp
- /library/src/string/trie.cpp.html
title: src/string/trie.cpp
---
