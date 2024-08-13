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
    bool isValid(string s) {
        stack<char> st;
        char temp;
        for(char c : s) {
            if(c == '(' or c == '[' or c == '{') {
                st.push(c);
            } else {
                if(st.empty()) return false;
                temp = st.top();
                st.pop();
                if(c == ')' && temp == '(') {
                    continue;
                } else if ( c == ']' && temp == '[') {
                    continue;
                } else if( c == '}' && temp == '{') {
                    continue;
                }
                return false;
            }
        }

        if(st.empty()) return true;
        return false;
    }
};