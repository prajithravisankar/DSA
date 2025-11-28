class DynamicArray {
private:
    int *arr; // arr is pointer to list of int
    int size;
    int capacity;

public:

    DynamicArray(int capacity) : capacity(capacity), size(0) {
        arr = new int[capacity];
    }

    int get(int i) {
        // assuming i is valid
        return arr[i];
    }

    void set(int i, int n) {
        // assuming i is valid
        arr[i] = n;
    }

    void pushback(int n) {
        if (size == capacity) {
            resize();
        }

        arr[size] = n;
        size += 1;
    }

    int popback() {
        size -= 1;
        return arr[size];
    }

    void resize() {
        capacity = capacity * 2;
        int *newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};

