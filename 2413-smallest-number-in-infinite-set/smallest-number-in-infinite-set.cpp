class SmallestInfiniteSet {
    priority_queue<int, vector<int>, greater<int>> pq;
    int arr[1001] = {-1};
public:
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++) {
            pq.push(i);
            arr[i] = 1;
        }
    }
    
    int popSmallest() {
        int val = pq.top();
        cout << "pop: " << val << endl;
        pq.pop();
        arr[val] = -1;

        return val;
    }
    
    void addBack(int num) {
        cout << "add: " << num << endl;
        if(arr[num] == -1) pq.push(num);
        arr[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */