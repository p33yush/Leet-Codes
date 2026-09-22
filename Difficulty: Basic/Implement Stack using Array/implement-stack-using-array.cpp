class myStack {
  public:
    
    int *arr;
    int top  = -1;
    int capacity=0;
    
    myStack(int n) {
        // Define Data Structures        arr= new int[n];
        capacity=n;
        arr = new int[capacity];
        top=-1;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top==-1;
        
    }

    bool isFull() {
        return top==capacity-1;
        // check if the stack is full
    }

    void push(int x) {
        if(isFull()) return;
        arr[++top]  = x;
        // inserts x at the top of the stack
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty()) return;
        top--;
        
    }

    int peek() {
        // Returns the top element of the stack
        if(isEmpty()) return -1;
        return arr[top];
        
    }
};