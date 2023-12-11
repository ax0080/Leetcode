class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l[n], r[n];
        l[0] = prices[0];
        r[n-1] = prices[n-1];

        for(int i = 1; i < n; i++)
        {
            l[i] = min(l[i-1], prices[i]); //記錄第i天以左的最小值
        }

        for(int i = n-2; i >= 0; i--){
            r[i] = max(r[i+1],prices[i]); //記錄第i天以右的最大值
        }

        int profit = 0;
        for(int i = 0; i < n; i++){
            profit = max(profit,r[i]-l[i]); //算出每一天的利益的最大值
        }


        return profit;
    }
};

//最直接的想法就是用兩個for迴圈去找出最大的profit，但這麼做的時間複雜度是O(n^2)
//此處提供一個時間複雜度和空間複雜度皆為O(n)的解法