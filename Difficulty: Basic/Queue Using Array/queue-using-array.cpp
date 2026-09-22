class myQueue {

  public:
    int *arr;
    int front = -1;
    int rear = -1;
    int capacity = 0;
    int size = 0;
    myQueue(int n) {
        // Define Data Structures
        capacity = n;
        arr = new int[capacity];
        front = 0;
        rear=-1;
        
    }

    bool isEmpty() {
        return size==0;
        // check if the queue is empty
    }

    bool isFull() {
        return capacity == size;
        // check if the queue is full
    }

    void enqueue(int x) {
        if(isFull()) return;
        arr[++rear] = x;
        size++;
        // Adds an element x at the rear of the queue.
    }

    void dequeue() {
        if(isEmpty()) return;
        front++;
        size--;
        // Removes the front element of the queue.
    }

    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
        // Returns the front element of the queue.
    }

    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
        // Return the last element of queue
    }
};