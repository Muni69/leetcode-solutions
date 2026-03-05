class Solution {
public:
    int minOperations(string s) {
        int change1 = 0;
        int change2 = 0;
        for(int i=0;i<s.size();i++) 
        { 
            if(i%2==0) 
            { 
               if(s[i]!='0') change1++;
               if(s[i]!='1') change2++;
            }
            else 
            { 
                 if(s[i]!='1') change1++;
               if(s[i]!='0') change2++;
            }
        }
        return min(change1,change2);
    }
};