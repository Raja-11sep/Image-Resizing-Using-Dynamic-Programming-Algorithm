#include<bits/stdc++.h>
using namespace std;
int minFallingPathSum(vector<vector<int>>&mat,vector<vector<int>>&dp,int r,int c)
    {
         if(c<0 || c>=mat[0].size())
         return INT_MAX;
         if(r==(mat.size()-1))
         return mat[r][c];
         
         if(dp[r][c]!=INT_MAX)
         return dp[r][c];
         int le=minFallingPathSum(mat,dp,r+1,c-1);
         int mi=minFallingPathSum(mat,dp,r+1,c);
         int ri=minFallingPathSum(mat,dp,r+1,c+1);

         return dp[r][c]=mat[r][c]+min(le,min(ri,mi));

         
    }
int main() 
{
    int row,col;
    
	cout<<"Enter number of rows"<<endl;
	cin>>row;
	
	cout<<"Enter number of columns"<<endl;
	cin>>col;
	
	vector<vector<int>>matrix(row,vector<int>(col,0));
	
	for(int i=0;i<row;i++)
	{
	    for(int j=0;j<col;j++)
	    {
	        cin>>matrix[i][j];
	    }
	}
	
	
	int ans=INT_MAX;
    vector<vector<int>>dp(row,vector<int>(col,INT_MAX));
           for(int i=0;i<col;i++)
           {
             int k= minFallingPathSum(matrix,dp,0,i);
             ans=min(ans,k);
           }
    cout<<ans;

	
	return 0;
}


