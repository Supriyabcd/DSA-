class HashTable:
    def __init__(self):
        #Number of buckets
        self.TABLE_SIZE = 100
        #Hashtable - list of lists(chaining)
        self.table = [[] for _ in range(self.TABLE_SIZE)]

        #Hash function
    def hash_function(self, key):
        return key % self.TABLE_SIZE
        
        #insertion of key-value pair into hash-value
    def insert(self, key, value):
        index = self.hash_function(key)
        self.table[index].append((key, value))
        print(f"{key} inserted")

        #search key in hashtable
    def search(self, key):
        index = self.hash_function(key)
        for k, v in self.table[index]:
            if k == key:
                return v
            return None

        #delete key in hashtable    
    def remove(self, key):
        index = self.hash_function(key)
        self.table[index] = [(k, v) for k, v in self.table[index] if k != key]
        print("Deletion done")

if __name__ == "__main__":
    ht = HashTable()

    while True:
        print("\nMenu:")
        print("1. Insert")
        print("2. Search")
        print("3. Delete")
        print("0. Exit")
        choice = int(input("Enter your choice : "))


        if choice == 1:
            key = int(input("Enter the key : "))
            value = int(input("Enter the value : "))
            ht.insert(key, value)
        elif choice == 2:
            key = int(input("Enter the key : "))
            v = ht.search(key)
            print(f"{v} found at key {key}")
        elif choice == 3:
            key = int(input("Enter the key : "))
            ht.remove(key)
        elif choice == 0:
            print("Exiting...")
            exit(0)
        else:
            print("Invalid choice. Please try again. ")

    