class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        
        for (auto token : tokens) {
            if (isOperation(token)) {
                executeOpAndStackResult(token, nums);
            }
            else {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
    
private:
    bool isOperation(string token) {
        return token == "+" || token == "-" 
                || token == "*" || token == "/";
    }
    
    void executeOpAndStackResult(string op, stack<int>& nums) {
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        
        int result = 0;
        switch (op[0]) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1- num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            default:
                break;
        }  
        nums.push(result);
    }
};