class Solution {
public:
    int bestClosingTime(string customers) {
        int score = 0;
        int maxScore = 0;
        
        for(int i = 0;i < customers.size();i++){
            if(customers[i] == 'Y'){
                score += 1;
            }else{
                score -= 1;
            }
            maxScore = max(maxScore,score);
        }
        if(maxScore == 0){
            return 0;
        }
        score = 0;

        for(int i = 0;i < customers.size();i++){
            if(customers[i] == 'Y'){
                score += 1;
            }else{
                score -= 1;
            }
            if(score == maxScore){
                return i+1;
            }
        }
        return 0;
    }
};