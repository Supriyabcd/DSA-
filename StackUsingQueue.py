from collections import deque

class StackUsingQueue:
    def __init__ (self):
        self.queue = deque()

    def Push(self, value):
        self.queue.append(value)
        #Move all prev elements to back of queue
        for i in range(len(self.queue)-1):
            self.queue.append(self.queue.popleft())
        print(f'{value} pushed into stack')

    def Pop(self):
        if self.queue:
            print("Stack is empty. Cannot pop")
        self.queue.pop()
        print(f'{int(self.queue.popleft())} popped from stack')

    def Top(self):
        if self.queue:
            print("Stack is empty")
        print(f'{int(self.queue[0])} is the top element')

    def printStack(self):
        if not self.queue:
            print("Stack is empty\n")    
        else:
            print("Stack elements: ", end="")
            print(" ".join(map(str,self.queue)))

def main():
    stack = StackUsingQueue()

    while True:
        print("\nMenu:")
        print("1. Push")
        print("2. Pop")
        print("3. Top")
        print("4. Print stack")
        print("0. Exit")
        choice = int(input("Enter your choice : "))

        if choice == 1:
            data = int(input("Enter the element to be pushed: "))
            stack.Push(data)
        elif choice == 2:
            stack.Pop()
        elif choice == 3:
            stack.Top()
        elif choice == 4:
            stack.printStack()
        elif choice == 0:
            print("Exiting...")
            exit(0)
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()