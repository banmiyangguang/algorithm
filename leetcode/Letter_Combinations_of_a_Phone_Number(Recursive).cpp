class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //差错控制记得做！！！
        //这里可以使用两个vector来回倒，取最终比较长的那个
        
        //init mp
        initMap(mp);
        //read input
        
        set<string> st;
        vector<string> vec1, vec2; //副本
        
        if (digits.length() == 0)
            return vec1;
        
        //先向 vec1 里写入数据
        string str2;
        for (int i = 0; i < mp[digits[0]].length(); i++) {
            str2.clear();
            str2 = str2 + mp[digits[0]][i];
            vec1.push_back(str2);
        }
        
        bool reverseFlag = true;
        for (int i = 1; i < digits.length(); i++) {
            if (reverseFlag) {
                insert(vec2, vec1, digits[i]);
            } else {
                insert(vec1, vec2, digits[i]);
            }
            reverseFlag = !reverseFlag;
        }
        
        vector<string> vec;
        vec = vec1.size() > vec2.size() ? vec1 : vec2;
        
        //去重
        for (auto beg = vec.begin(); beg != vec.end(); beg++) {
            st.insert(*beg);
        }
        
        vec.clear();
        for (auto beg = st.begin(); beg != st.end(); beg++) {
            vec.push_back(*beg);
        }
        
        return vec;
    }
private:
    void initMap(map<char,string>& mp) {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
    }
    //function: 利用 v2 里的数据插入到 v1 里去
    void insert(vector<string>& v1, vector<string>& v2, char ch) {
        v1.clear();
        for (int i = 0; i < v2.size(); i++) {
            string str = v2[i];
            for (int j = 0; j < mp[ch].length(); j++) {
                string str1 = str + mp[ch][j];
                v1.push_back(str1);
            }
        }
    }
    
private:
    map<char, string> mp;
};