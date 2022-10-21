#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Trie
{
private:
    /* data */
public:
    int isLeaf = false;
    Trie *child[26];
    Trie(/* args */);
    ~Trie();
    void insert(string s, int i = 0){
        if(i == s.size()){
            isLeaf = true;
        }else{
            // i have the position in the ith of the current pointer 
            int current = s[i] - 'a';
            if(child[current] == 0){
                child[current] = new Trie();
            }
            child[current]->insert(s, i+1);
        }
    }
    bool haveWord(string s, int i = 0){
        if(i == s.size()){
            return isLeaf;
        }else{
            int current = s[i] - 'a';
            if(child[current] == 0){
                return false;
            }
            return child[current]->haveWord(s, i+1);
        }
    }

    bool havePrefix(string s, int i = 0){
        if(i == s.size()){
            return true;
        }else{
            int current = s[i] - 'a';
            if(child[current] == 0){
                return false;
            }
            return child[current]->havePrefix(s, i+1);
        }
    }
};

Trie::Trie(/* args */)
{
    memset(child, 0, sizeof(child));
}

Trie::~Trie()
{

}
int main()
{
   Trie *root = new Trie();

   root->insert("hello");
   root->insert("helle");
   cout<<root->haveWord("helle")<<endl;       // prints 1
   return 0;
}