#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void solve(int** board,int x,int y,int* score,int n)
{
    if(x>=0 && y>=0 && x<n && y<n && board[x][y]>=0)
    {
        *score=*score+board[x][y];
        board[x][y]=-3;
        {
            solve(board,x+2,y-1,score,n);
            solve(board,x+2,y+1,score,n);
            solve(board,x-2,y-1,score,n);
            solve(board,x-2,y+1,score,n); 
            solve(board,x+1,y-2,score,n);
            solve(board,x+1,y+2,score,n);
            solve(board,x-1,y-2,score,n);
            solve(board,x-1,y+2,score,n);
        }
    }
}
int solve2(int** board,int x,int y,int n)
{
    if(x<n && y<n && x>=0 && y>=0 && board[x][y]>=0)
    {
        int temp=board[x][y];
        board[x][y]=-3;
        return temp+solve2(board,x+2,y+1,n)+solve2(board,x+2,y-1,n)+solve2(board,x-2,y+1,n)+solve2(board,x-2,y-1,n)+solve2(board,x+1,y+2,n)+solve2(board,x+1,y-2,n)+solve2(board,x-1,y+2,n)+solve2(board,x-1,y-2,n);
    }
    else
    return 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input30.txt", "r", stdin);
    freopen("output30.txt", "w", stdout);
    #endif

	int t;
	scanf("%d ",&t);
	while(t--)
	{
	    int n;
	    scanf("%d ",&n);
	    int *board[n];
	    int j=0;
	    int x,y;
	    x=-1;
	    y=-1;
	    while(j<n)
	    {
	        int* ptr=(int*)malloc(4*n);
	        int l=0;
	        while(l<n)
	        {
	            scanf("%d ",ptr+l);
	            if(ptr[l]==-3)
	            {
	                ptr[l]=0;
	                x=j;
	                y=l;
	            }
	            l++;
	        }
	        board[j]=ptr;
	        j++;
	    }
	    int ans=0;
	    ans=solve2(board,x,y,n);
	    printf("%d\n",ans);
	}
}

