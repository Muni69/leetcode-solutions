class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { 
        sort(strs.begin(),strs.end());
        if(strs.empty()) 
        { 
            return "";
        } 
        string result = ""; 
        string first = strs[0]; 
        string last = strs[strs.size()-1]; 

        for(int i=0;i<first.length()&&i<last.length();i++) 
        { 
              if(first[i]!=last[i])
              {
                break;
              } 
              else 
              { 
                result.push_back(first[i]);
              }
        } 
        return result; 
    }
};