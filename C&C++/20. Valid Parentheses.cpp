class Solution {
public:
    bool isValid(string s) {
        stack <char> in_stack;
        
        for(size_t i = 0; i < s.size(); i++)
        {
            if(in_stack.empty())
            {
              if(s[i] == '}' || s[i] == ']' || s[i] == ')') return false;
              else in_stack.push(s[i]);
            }
             
            else 
            {
              switch(s[i])
              {
                case '}':
                  if(in_stack.top() != '{') return false;
                  else in_stack.pop();
                  break;

                case ']':
                  if(in_stack.top() != '[') return false;
                  else in_stack.pop();
                  break;

                case ')':
                  if(in_stack.top() != '(') return false;
                  else in_stack.pop();
                  break;

                default: 
                  in_stack.push(s[i]);
                  break;
              } 
            }
        }

        if(in_stack.empty()) return true;
        else return false;
    }
};