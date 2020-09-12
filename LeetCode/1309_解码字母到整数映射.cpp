#include<vector>
using namespace std;

class Solution {
public:
    /*
        1. string容器的搜索操作?
        2. string如果搜索失败返回什么？
        3. C++ 的强制转换有哪几种？
        4. string如何判空？
        5. C++的字符串转数字的函数是？
        6. 如何获取string的子串？
    */

    string::size_type find_pos(const string &s, int pos){
        return s.find_first_of('#', pos);
    }

    string freqAlphabets(string s) {
        if(s.empty()){
            return NULL;
        }
        int base=static_cast<int>('a');
        cout << "base: " << base<<endl;
        string tmp{'a'}, tmp2;
        int head=0;
        string::size_type tail = find_pos(s, 0);
        string::size_type len = s.size();
        string result;
        int int_word;
        while(head != len){
            if(tail - head > 2){
                tmp[0]=s[head];
                int_word = base + stoi(tmp) - 1;
                result.push_back(static_cast<char>(int_word));
                cout << head <<": " << int_word<< endl;
                head++;
            }else{
                tmp2 = s.substr(head, tail);
                int_word = base + stoi(tmp2) - 1;
                result.push_back(static_cast<char>(int_word));
                head = tail + 1;
                tail = find_pos(s, head);
            }
        }
        return result;
    }
};