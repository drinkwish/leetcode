//76ms, 99.75%

//the basic ieda of these problem is wrong in my solution

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        if(_dict.find(word.size()) == _dict.end()){
            vector<string> *vec = new vector<string>;
            _dict.insert(pair<int, vector<string>*>(word.size(), vec));
        }
        _dict[word.size()]->push_back(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(_dict.find(word.size()) == _dict.end()) return false;
        
        vector<string> *d = _dict[word.size()];
        for(int i_ = 0; i_< d->size(); ++i_){
            if(match(word, (*d)[i_])) return true;
        }
        return false;
    }
    
    WordDictionary(){}
    ~WordDictionary(){
        for(map<int, vector<string>*>::iterator iter = _dict.begin(); iter != _dict.end(); ++iter){
            vector<string> *tmp = iter->second;
            delete tmp;
        }
    }
    
private:
    bool match(string a, string b){
        for(int i_ = 0; i_ < a.size(); ++i_){
            if(a[i_] != b[i_] && a[i_] != '.') return false;
        }
        return true;
    }
    
    map<int, vector<string>*> _dict;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");