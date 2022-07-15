//Given an integer N, find its factorial.
class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> res;
        res.push_back(1);
        for(int x=2;x<=N;x++)
        {
            int carry = 0;
            for(int i=res.size()-1;i>=0;i--)
            {
                int value = res[i]*x+carry;
                res[i] = value%10;
                carry = value/10;
            }
            while(carry!=0)
            {
                res.insert(res.begin(),carry%10);
                carry/=10;
            }
        }
        return res;
    }
};