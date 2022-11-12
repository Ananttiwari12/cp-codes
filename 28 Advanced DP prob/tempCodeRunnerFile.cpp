
    int &ans=memo[idx][weight];

    if(ans!=-1) return ans;

    // do not take weight
    ans=knapsack(idx+1, weight);

    // take weight
    if(weight+w[idx]<=W){
        ans=max(ans,values[idx]+knapsack(idx+1,weight+w[idx]));
    }