class Solution {
public:
    
    string makeKey(const string &s){
        
        int aux[26];
        memset(aux, 0, sizeof(int) * 26);
        for(auto ch : s) aux[ch-'a']++;

        string ret = "";        
        for(int i = 0 ; i < 26; ++i){
            if(aux[i] == 0) continue;
            char t = (char)('a'+i);
            ret += t;
            ret += to_string(aux[i]);
            
        }
        return ret;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > umap;
        
        
        
        for(auto str : strs){
            string key = makeKey(str);
            // cout << key << endl;
            if(umap.count(key) != 0)
                umap[key].emplace_back(str);
            else
                umap.insert(make_pair(key, vector<string>(1, str)));
        }
            vector<vector<string>> ret;

        for(auto iter = umap.begin(); iter != umap.end(); ++iter)
            ret.emplace_back(iter->second);

        return ret;

        
        
    }
};
