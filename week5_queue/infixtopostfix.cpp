#include <iostream>
#include <stack>
#include <string>

using namespace std;

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

int main() {
    string s;
    cout << "Masukan Infix : ";
    getline(cin, s);
    stack<char> st;
    string result;
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && priority(c) <= priority(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << "Postfix: " << result << endl;

    return 0;
}