class maxHeap {
  private:
    // Initialize your data members

  public:
    priority_queue<int> pq;

    void push(int x) {
        pq.push(x);
        // Insert x into the heap
    }

    void pop() {
        pq.pop();
        // Remove the top (maximum) element
    }

    int peek() {
        if(pq.empty()) return -1;
        return pq.top();
        // Return the top element or -1 if empty
    }

    int size() {
        return pq.size();
        // Return the number of elements in the heap
    }
};