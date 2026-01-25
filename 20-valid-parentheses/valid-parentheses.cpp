class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i=0;i<s.length();i++) 
        { 
            if(s[i]=='{')
            {
                stack.push(s[i]);
            } 
            else if(s[i]=='(') 
            { 
                stack.push(s[i]);
            } 
            else if(s[i]=='[') 
            {
                stack.push(s[i]);
            }
            else 
            {  
                if(stack.size()==0) 
                { 
                    return false;
                }

               if(stack.top()=='(' && s[i]==')') 
               { 
                stack.pop();
               }
               else if(stack.top()=='{' && s[i]=='}') 
               { 
                stack.pop();
               } 
               else if(stack.top()=='[' && s[i]==']') 
               { 
                stack.pop();
               }
               else 
               { 
                return false;
               }
            }
        } 
        if(stack.size()==0) 
        { 
            return true;
        }
        else 
        {
            return false;
        }
    }
    
}; 
