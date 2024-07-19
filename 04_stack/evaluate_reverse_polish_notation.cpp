class Solution {
  public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (const string& s : tokens) {
			if (s == "+" || s == "-" || s == "*" || s == "/") {
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				int result;
				if (s == "+")
					result = left + right;
				else if (s == "-")
					result = left - right;
				else if (s == "*")
					result = left * right;
				else if (s == "/")
					result = left / right;
				st.push(result);
			} else {
				st.push(std::stoi(s.c_str()));
			}
		}
		return st.top();
	}
};
