//Iterator for Combination

class CombinationIterator {
private:
    const string s;
    const int len;
    
    vector<int> pos;  // position pointer(s)
    string      ans;  // current answer
    
    void inc(int i) {        
        if (pos[i] == s.size() - len + i)
            inc(i - 1);
        else {
            ++pos[i];
            ans[i] = s[pos[i]];
            
            while (++i < len) {
                pos[i] = pos[i - 1] + 1;
                ans[i] = s[pos[i]];
            }
        }
    }
    
public:
    CombinationIterator(string characters, int combinationLength) :
        s(characters),
        len(combinationLength),
        pos(len, 0),
        ans(s, 0, len)
    {
        for (int i = 1; i < len; ++i)
            pos[i] = i;
        --pos[len - 1];  // prep first increment       
    }
    
    string next() {
        inc(len - 1);  // increment pointer(s)
        return ans;
    }
    
    bool hasNext() {
        return (pos[0] != s.size() - len);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
