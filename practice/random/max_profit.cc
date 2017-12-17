class Solution {
public:
    int maxProfitSlow(vector<int>& prices) {
        int max_profit=INT_MIN;

        for(int i=0; i<prices.size(); i++){
            int j = i+1;

            for(; j<prices.size(); j++){
                if((prices.at(j)-prices.at(i)) > max_profit)
                    max_profit = prices.at(j)-prices.at(i);
            }
        }

        if(max_profit < 0)
            return 0;

        return max_profit;
    }

    int maxProfitKadane(vector<int>& prices) {
      //https://en.wikipedia.org/wiki/Maximum_subarray_problem
      //Maximum_subarray_problem
      //Kadane's algorithm
       int max_here = 0;
       int max_sofar = 0;

       for(int i=1; i<prices.size(); i++){
           max_here = max(0, max_here+=prices.at(i)-prices.at(i-1));
           max_sofar = max(max_here, max_sofar);
       }

       return max_sofar;
    }

    int maxProfitBetter(vector<int>& prices){

      if(prices.size()==0)
        return 0;

      int max_profit = 0, curr_min=prices.at(0);

      for(int i=0; i<prices.length(); i++){
        if(prices.at(i)>curr_min){
          max_profit = max(max, prices.at(i)-curr_min);
        }else{
          curr_min = prices.at(i);
        }
      }
      return max_profit;
    }
};
