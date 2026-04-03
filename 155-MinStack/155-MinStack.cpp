// Last updated: 4/3/2026, 2:01:52 PM
class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {}

    void push(int val) {
        long long v = val;
        if (st.empty()) {
            st.push(v);
            mini = v;
        } else {
            if (v >= mini) {
                st.push(v);
            } else {
                st.push(2 * v - mini);
                mini = v;
            }
        }
    }

    void pop() {
        if (st.empty())
            return;

        long long tp = st.top();
        st.pop();

        if (tp < mini) {
            mini = 2 * mini - tp;
        }
    }

    int top() {
        long long tp = st.top();
        if (tp < mini)
            return (int)mini;
        return (int)tp;
    }

    int getMin() { return (int)mini; }
};