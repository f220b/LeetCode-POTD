// Last updated: 4/3/2026, 2:03:35 PM
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>result(n, vector<int>(n, 0));
        int x=1;
        int left=0,right=n-1,top=0,bottom=n-1;
        while(x <= n * n){
            for(int i=left;i<=right;i++){
                result[top][i]=x++;
            }
            top++;
            for(int j=top;j<=bottom;j++){
                result[j][right]=x++;
            }
            right--;

            if(top<=bottom && left<=right){
                for(int i=right;i>=left;i--){
                    result[bottom][i]=x++;
                }
                bottom--;
                for(int j=bottom;j>=top;j--){
                    result[j][left]=x++;
                }
                left++;
            }
        }
        return result;
    }
};