class Solution {
    public int min(int x, int y) {
        if (x < y) return x;
        else return y;
    }
    
    public int max(int x, int y) {
        if (x > y) return x;
        else return y;
    } 
    
    public int maxProfit(int[] prices) {
        int profit = 0, buy = prices[0];
        for (int i = 1; i < prices.length; i++){
            profit = max(profit, prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        return profit;
        
    }
}