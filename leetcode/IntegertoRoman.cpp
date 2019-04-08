class Solution {
public:
    string intToRoman(int num) {
        string str;
        
        if (num < 1 && num > 3999)
            return str;
        
        //охур1000
        int count = num / 1000;
        if (count > 0) {
            add(str, count, "M");
        }
        
        num = num % 1000;
        count = num / 100;
        add2(str, count, "C", "D", "M");
        
        num = num % 100;
        count = num / 10;
        add2(str, count, "X", "L", "C");
        
        num = num % 10;
        count = num;
        add2(str, count, "I", "V", "X");
        
        return str;
    }
    
private:
    void add(string &str, int count, string ss) {
        for (; count > 0; count--)
            str = str + ss;
    }
    
    void add2(string &str, int count, string s1, string s2, string s3) {
        if (count == 9)
            str = str + s1 + s3;
        else if (count == 4)
            str = str + s1 + s2;
        else {
            if (count >= 5) {
                count = count - 5;
                str += s2;
            }
            add(str, count, s1);
        }
    }
};