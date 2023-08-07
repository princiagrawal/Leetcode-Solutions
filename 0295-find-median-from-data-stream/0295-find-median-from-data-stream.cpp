class MedianFinder {
public:

    priority_queue<int>maxi;//maxHeap for half left part
    priority_queue<int,vector<int>,greater<int>>mini;//minHeap for half right part

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxi.push(num);
        mini.push(maxi.top());
        maxi.pop();
        if(mini.size()>maxi.size()){
//hm hmesha max heap me jyada element rkhenge mtlb left part jyada wala hoga
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {//by codestorywithMIK
        //in qstn it is saying ordered list==>heap
        if(mini.size()==maxi.size()){//even
            return (maxi.top()+mini.top())/2.0;
        }
        else{//odd
            return maxi.top();
        }
    }
};
// The idea is to divide numbers into 2 balanced halves, one half low stores low numbers, the other half high stores high numbers. To access the median in O(1), we need a data structure that give us the maximum of low half and the minimum of high half in O(1). That's where maxHeap and minHeap come into play.
// We use maxHeap to store a half of low numbers, top of the maxHeap is the highest number among low numbers.
// We use minHeap to store a half of high numbers, top of the minHeap is the lowest number among high numbers.