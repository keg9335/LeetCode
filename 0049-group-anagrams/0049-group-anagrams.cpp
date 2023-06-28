#include <map>
#include <vector>
using namespace std;

#define ALPAHBET_NUM 26

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> stringMap;
        for (string str : strs) {
            string key = getKey(str);
            if (!stringMap.count(key))
                stringMap.insert({key, vector<string>()});
            stringMap[key].push_back(str);
        }

        vector<vector<string>> anagrams;
        map<string, vector<string>>::iterator it;
        for (it = stringMap.begin(); it != stringMap.end(); it++) {
            anagrams.push_back(it->second);
        }
        return anagrams;
    }
private:
    string getKey(string str) {
        int count[ALPAHBET_NUM] = {0,};
        for (char c : str) count[c-'a']++;

        string key = "";
        for (int i = 0; i < ALPAHBET_NUM; i++) {
            key.append(to_string(i+'a'));
            key.append(to_string(count[i]));
        }

        return key;
    }
};