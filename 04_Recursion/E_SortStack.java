import java.util.Stack;

public class E_SortStack {
    // Function to insert an element at the correct position in the stack
    static void insertAtCorrectPosition(Stack<Integer> stack, int item) {
        if (stack.isEmpty() || item > stack.peek()) {
            stack.push(item);
        } else {
            int temp = stack.pop();
            insertAtCorrectPosition(stack, item);
            stack.push(temp);
        }
    }

    // Function to sort the stack in descending order
    static void sortStack(Stack<Integer> stack) {
        if (!stack.isEmpty()) {
            int temp = stack.pop();
            sortStack(stack);
            insertAtCorrectPosition(stack, temp);
        }
    }

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(11);
        stack.push(2);
        stack.push(32);
        stack.push(3);
        stack.push(41);
        System.out.println("Stack before sorting:");
        System.out.println(stack);

        sortStack(stack);

        System.out.println("Stack after sorting:");
        System.out.println(stack);
    }
}
