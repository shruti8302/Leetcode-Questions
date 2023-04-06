class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        priority_queue<int> pq;
        
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        int score = 0;
        
        while(!pq.empty()){
            int l1 = pq.top();
            pq.pop();
            
            if(pq.empty()) return score;
            
            int l2 = pq.top();
            pq.pop();
            
            if(l1 > 1) pq.push(l1-1);
            if(l2 > 1) pq.push(l2-1);
            
            score++;
        }
        return score;
    }
};