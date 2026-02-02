class Solution {
public:
    int mySqrt(int x) {
      if(x<2) 
      { 
        return x;
      }
      int low =1;
      long high = x;
      int ans =1;
      while(low<=high) 
      { 
        long mid = (low + high)/2;
        if(mid*mid<=x) 
        { 
            ans=mid;
            low = mid +1;
        }
        else 
        { 
            high = mid -1;
        }
       
      }
      return ans;
    }
};