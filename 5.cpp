// Add and Search Word - Data structure design

class WordDictionary {
private:
  struct Node {
    std::array<Node*, 26> children = {};
    bool is_word = false;
  };
  Node* root = new Node();
public:
    /** Initialize your data structure here. */
    WordDictionary() { 
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
      Node* ptr = root;
      for (const char &c : word) {
        if (!ptr->children[c-'a']) {
          ptr->children[c-'a'] = new Node();
        }
        ptr = ptr->children[c-'a'];
      }
      ptr->is_word = true;
    }
  
    bool hasPrefix(Node* ptr, string word) {
      if (!ptr) return false;
      for (auto it = word.begin(); it != word.end(); it++) {
        if (*it == '.') {
          string str = "";
          if (it+1 != word.end()) {
            str = string(it+1, word.end());
          }
          for (auto &c : ptr->children) {
             if (hasPrefix(c, str)) {
              return true; 
             }
          }
          return false;
        } else {
          if (!ptr->children[*it - 'a']) {
            return false;
          }
          ptr = ptr->children[*it - 'a'];
        }
      }
      return ptr->is_word;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
      return hasPrefix(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
