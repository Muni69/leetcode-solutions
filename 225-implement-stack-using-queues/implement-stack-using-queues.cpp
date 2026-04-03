class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        // Rotate the queue
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};