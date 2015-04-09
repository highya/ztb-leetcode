public class Solution {
    public int evalRPN(String[] tokens) {
        
        if (tokens==null || tokens.length == 0) return 0;
        
        Stack<Integer> stack = new Stack<Integer>();

        for(int i = 0; i < tokens.length; i++) {
            if (tokens[i].equals("+")) {
                stack.push(stack.pop() + stack.pop());
            }
            else if(tokens[i].equals("-")) {
                stack.push(-stack.pop() + stack.pop());
            }
            else if(tokens[i].equals("*")) {
                stack.push(stack.pop() * stack.pop());
            }
            else if(tokens[i].equals("/")) {
                int last = stack.pop();
                int first = stack.pop();
                stack.push(first / last);
            }
            else {
                stack.push(Integer.parseInt(tokens[i]));
            }
        }
        return stack.pop();
    }
}
