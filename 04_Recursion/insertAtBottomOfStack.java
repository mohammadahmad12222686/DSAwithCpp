
import java.util.Stack;

public class insertAtBottomOfStack {

    // Function to insert an element at the bottom of a stack
    static void insertAtBottom(Stack<Integer> stack, int item) {
        if (stack.isEmpty()) {
            stack.push(item);
        } else {
            int temp = stack.pop();
            insertAtBottom(stack, item);
            stack.push(temp);
        }
    }

   

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(3);
        stack.push(5);
        stack.push(1);

        System.out.println("Stack before sorting:");
        System.out.println(stack);

        insertAtBottom(stack,100);
        
        System.out.println("Stack after inserting:");
        System.out.println(stack);
    }
}
