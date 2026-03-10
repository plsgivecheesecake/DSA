class Solution {
public:
    const int M = 1e9+7;
    int numberOfStableArrays(int zero, int one, int limit) {
        long long dp[zero+1][one+1][2];
        memset(dp, 0, sizeof(dp));

        dp[0][0][0] = 1;
        dp[0][0][1] = 1;

        for (int z = 0; z <= zero; z++) {
            for (int o = 0; o <= one; o++) {
                if (z == 0 && o == 0) continue;

                if(z < limit){
                    if(z > 0){
                        dp[z][o][1] = dp[z-1][o][0];
                        if(z > 1){
                            dp[z][o][1] += dp[z-1][o][1];
                        }
                    }
                }else if(z == limit){
                    if(z > 0){
                        dp[z][o][1] = dp[z-1][o][0];
                        if(limit > 1){
                            dp[z][o][1] += dp[z-1][o][1];
                        }
                    }
                }else if(z > limit){
                    dp[z][o][1] = dp[z-1][o][0];
                    if(limit > 1){
                        dp[z][o][1] += dp[z-1][o][1] - dp[z-1-limit][o][0];
                    }
                }
                dp[z][o][1] %= M;
                dp[z][o][1] += M;
                dp[z][o][1] %= M;


                if(o < limit){
                    if(o > 0){
                        dp[z][o][0] = dp[z][o-1][1];
                        if(o > 1){
                            dp[z][o][0] += dp[z][o-1][0];
                        }
                    }
                }else if(o == limit){
                    if(o > 0){
                        dp[z][o][0] = dp[z][o-1][1];
                        if(limit > 1){
                            dp[z][o][0] += dp[z][o-1][0];
                        }
                    }
                }else if(o > limit){
                    dp[z][o][0] = dp[z][o-1][1];
                    if(limit > 1){
                        dp[z][o][0] += dp[z][o-1][0] - dp[z][o-1-limit][1];
                    }
                }
                dp[z][o][0] %= M;
                dp[z][o][0] += M;
                dp[z][o][0] %= M;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % M;
    }
};
