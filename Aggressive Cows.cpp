Question:
You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:

Input:
n=5 
k=3
stalls = [1 2 4 8 9]
Output:
3
Explanation:
The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, 
which also is the largest among all possible ways

ANS:
   
   int solve(int n, int k, vector<int> &a) {
        sort(a.begin(),a.end());
        int l=0,r=1e9,m,c,j,i,ans=0;
        while(l<=r){
            m=(l+r)/2;
            c=1;j=0;
//we assuming that first cow will be placed at first stall 
            for(i=1;i<n;i++){
                if(a[i]-a[j]>=m){
//by difference we're calulating that if diff>=mid then it is possible upto mid that
//we can place al our cows with minimum distance between any two of them.
//so we take them in c.
                    c++;j=i;
                    //j is to find dist b/w stall to max possible upto which we can place cows
                }
            }
//simply checking if we can put c cows upto mid and those c cows are more than or equal
// to k then we obivisouly put k cows to stalls with min dist. but we need to find max
// dist b/w any two of them possible so we check in right side. if not found we check in left. 
            if(c>=k){
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
