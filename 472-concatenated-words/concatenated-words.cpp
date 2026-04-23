class Trie{
    public:
    vector<Trie*>children;
    bool end;
    Trie(): children(26), end(false){}
    void insert(string word){
        Trie* node= this;
        for(char ch: word){
            int index= ch-'a';
            if(!node->children[index])
                node->children[index]= new Trie();
            node= node->children[index];
        }
        node->end= true;
    }
};
class Solution {
public:
    Trie* trie= new Trie();
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string& a, const string& b){
            return a.size()<b.size();
        });
        vector<string>res;
        for(auto word: words){
            if(dfs(word))
                res.push_back(word);
            else
                trie->insert(word);
        }
        return res;
    }
    bool dfs(string word){
        if(word=="") return true;
        Trie* node= trie;
        for(int i=0; i<word.size(); i++){
            int index= word[i]-'a';
            if(! node->children[index])
                return false;
            node= node->children[index];
            if(node->end && dfs(word.substr(i+1)))
                return true;
        }
        return false;
    }
};