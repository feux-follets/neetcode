class Solution {
  public:
	bool isValid(string s) {
		stack<char> st;
		for (const char c : s) {
			// Open brackets
			if (c == '(' || c == '[' || c == '{') {
				st.push(c);
				continue;
			}
			// Close brackets
			if (st.empty())
				return false;
			// Not matched
			if ((c == ')' && st.top() != '(') || (c == ']' && st.top() != '[') || (c == '}' && st.top() != '{'))
				return false;
			else
				st.pop();
		}
		return st.empty();
	}
};
