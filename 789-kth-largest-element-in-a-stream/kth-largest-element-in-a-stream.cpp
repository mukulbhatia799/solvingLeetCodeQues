class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    vector<int> nums;
public:
    KthLargest(int k, vector<int>& nums) {
        this->nums = nums;
        this->k = k;
        for(int i = 0; i < k; i++) {
            if(nums.size() > i) pq.push(nums[i]);
        }
        for(int i = k; i < nums.size(); i++) {
            if(pq.empty() || pq.size() < k) pq.push(nums[i]);
            else if(!pq.empty() && pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            } 
        }
    }
    
    int add(int val) {
        cout << "pq size: " << pq.size() << endl;
        if(pq.empty() || pq.size() < k) pq.push(val);
        else if(!pq.empty() && pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};