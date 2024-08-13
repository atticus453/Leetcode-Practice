#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        
        stack<char> st;
        string newStr;
        char backwardChar;
        for(int i = 0; i < s.size(); i++) {
            
            if( s[i] >= 'A' && s[i] <= 'Z') {
                st.push(s[i] - 'A' + 'a');
                newStr += s[i] - 'A' + 'a';
            }
            if( s[i] >= 'a' && s[i] <= 'z') {
                st.push(s[i]);
                newStr += s[i];
            } 
            if( s[i] >= '0' && s[i] <= '9') {
                st.push(s[i]);
                newStr += s[i];
            } 
            continue;
        }

        if(newStr.size() == 0) return true;

        for(char currChar : newStr) {
            
            backwardChar = st.top();
            st.pop();
            if(backwardChar != currChar) return false;
        }
        
        return true;
    }
};