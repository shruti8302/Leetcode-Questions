class Solution {
public:
    bool isPerfectSquare(long long int num) {
        
        long long int square = sqrt(num);
        if(square * square == num)
            return true;
        else
            return false;
    }
};