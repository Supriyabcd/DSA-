
class QueueUsingStack:
    def __init__(self):
        self.stack_1 = []
        self.stack_2 = []

    def transferStack1toStack2(self):
        while self.stack_1:
            self.stack_2.append(self.stack_1.pop())

    def enqueue(self, data):
        self.stack_1.append(data)
        print(f'{data} enqueued\n')

    def dequeue(self):
        if not self.stack_2:
            if not self.stack_1:
                print("Queue is empty. Cannot dequeue")
            self.transferStack1toStack2()
        topValue = self.stack_2.pop()
        print(f"{topValue} dequeued \n")
    
    def is_Empty(self):
        if not self.stack_1 and not self.stack_2:
            print("Queue is empty")
        else :
            print("Queue is not empty")
    
    def display(self):
        if not self.stack_1 and not self.stack_2:
            print('Stack is empty\n')
        else :
            print("Stack elements: ", end = " ")
            self.transferStack1toStack2()
            print(" ".join(map(str,reversed(self.stack_2))))

def main():
    queue = QueueUsingStack()

    while True:
        print("\n Queue Menu: ")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Check whether empty or not")
        print("4. Display ")
        print("0. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            value = int(input("Enter integer to be enqueued: "))
            queue.enqueue(value)
        elif choice == 2:
            queue.dequeue()
        elif choice == 3:
            queue.is_Empty()
        elif choice == 4:
            queue.display()
        elif choice == 0:
            print("Exiting...")
            exit(0)
        else:
            print("Invalid choice. Please try again")

if __name__ == "__main__":
    main()
