class Solution {
public:
    bool isOp(const string& s) {
        return (s == "*" || s == "/" || s == "+" || s == "-");
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> nums; 

        for(int i = 0; i < tokens.size(); i++) { 
            string c = tokens[i];

            if(isOp(c)) {
                if(nums.size() < 2) continue; 
                
                int n2 = nums.top(); nums.pop();
                int n1 = nums.top(); nums.pop();
                
                int newNum;
                if(c == "+") newNum = n1 + n2;
                else if(c == "-") newNum = n1 - n2;
                else if(c == "/") newNum = n1 / n2;
                else newNum = n1 * n2;
                
                nums.push(newNum);
            } 
            else nums.push(stoi(c)); 
            
        }
        
        return nums.top(); 
    }
};