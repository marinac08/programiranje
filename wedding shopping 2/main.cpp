#include <bits/stdc++.h>
using namespace std;

int M, C, price[25][25];
int dp[210][25];

int main(){
    int i, j, k, TC, score;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &M, &C);
        for(i=0; i<C; i++){
            scanf("%d", &price[i][0]);
            for(j=1; j<=price[i][0]; j++){
                scanf("%d", &price[i][j]);
            }
        }
        for(i=0; i<=M; i++){
            for(j=0; j<=C; j++){
                dp[i][j] = -1;
            }
        }
        dp[M][0] = 0;
        for(i=0; i<C; i++){
            for(j=M; j>=0; j--){
                if(dp[j][i] != -1){
                    for(k=1; k<=price[i][0]; k++){
                        int new_money = j - price[i][k];
                        if(new_money >= 0){
                            dp[new_money][i+1] = max(dp[new_money][i+1], dp[j][i]);
                        }
                    }
                }
            }
        }
        score = -1;
        for(j=0; j<=M; j++){
            if(dp[j][C] != -1){
                score = max(score, M - j);
            }
        }
        if(score<0) printf("no solution\n");
        else printf("%d\n", score);
    }
}
