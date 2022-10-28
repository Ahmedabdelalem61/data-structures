#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Trie
{
public:
    static const int maxLen = 26;
    bool isLeaf = false;
    Trie *child[maxLen];
    Trie(/* args */)
    {
        memset(child, 0, sizeof(child));
    }
    ~Trie();
    void insert(string s, int i = 0)
    {
        if (i == s.size())
            isLeaf = true;
        else
        {
            // i have the position in the ith of the current pointer
            int current = s[i] - 'a';
            if (child[current] == 0)
                child[current] = new Trie();
            child[current]->insert(s, i + 1);
        }
    }
    bool haveWord(string s, int i = 0)
    {
        if (i == s.size())
        {
            return isLeaf;
        }
        else
        {
            int current = s[i] - 'a';
            if (child[current] == 0)
            {
                return false;
            }
            return child[current]->haveWord(s, i + 1);
        }
    }

    bool haveWordWithLooping(string s, int i = 0)
    {
        for (i = 0; i <= s.size(); i++)
        {
            if (i == s.size())
            {
                return true;
            }
            else
            {
                int current = s[i] - 'a';
                if (child[current] == 0)
                {
                    return false;
                }
            }
        }
        return false;
    }

    bool havePrefix(string s, int i = 0)
    {
        if (i == s.size())
        {
            return true;
        }
        else
        {
            int current = s[i] - 'a';
            if (child[current] == 0)
            {
                return false;
            }
            return child[current]->havePrefix(s, i + 1);
        }
    }
    void getAllWords(vector<string> &str, string cur = "")
    {
        if (isLeaf)
        {
            cout <<"cur is heh : " <<cur<<endl;
            str.push_back(cur);
        }

        for (int i = 0; i < maxLen; i++)
        {
            if (child[i])
            {
                child[i]->getAllWords(str,cur + (char)(i + 'a'));
                // str.erase(str.end()-1);

            }

        }
    }

    void autoComplete(string compPrefix, vector<string> &str, string cur = "")
    {
        Trie *currNode = this;
        for(int i = 0 ;i< compPrefix.size();i++){
            int curr = compPrefix[i] -'a';
            if(!currNode->child[curr]){
                return;
            }
            currNode =currNode->child[curr];
        }
        currNode->getAllWords(str,compPrefix);
    }
};

int main()
{
    Trie *root = new Trie();
    root->insert("a");
    root->insert("ab");
    root->insert("abcd");
    root->insert("bcd");
    root->insert("xyz");
    root->insert("xyzw");

    vector<string> str;

    // root->getAllWords(str);
    root->autoComplete("ab",str);
    for (auto word : str)
        cout << word << endl;

    // cout << root->haveWordWithLooping("hello") << endl; // prints 1
    return 0;
}