from utils import generate_random_sequence


# Node class
class Node:
    def __init__(self, data):
        self.data = data  # Assign data
        self.next = None  # Initialize next as null


# Linked List class contains a Node object
class LinkedList:
    def __init__(self):
        self.head = None

    def printList(self):
        temp = self.head
        while temp:
            print('\t\t\t' + str(temp.data))
            temp = temp.next


# Hash Table with chaining (avoid collisions with Linked List)
class HashTable:
    def __init__(self, length):
        self.length = length
        self.hashTable = dict()
        self.numCollisions = 0

    def hashFunction(self, value):
        return hash(value) % self.length

    def add(self, value):
        """ Add a value to hash table """
        index = self.hashFunction(value)
        node = Node(value)

        if index not in self.hashTable.keys():
            linked_list = LinkedList()
            linked_list.head = node
            self.hashTable[index] = linked_list
        else:
            self.numCollisions += 1
            cur = self.hashTable[index].head

            while cur.next:
                cur = cur.next
            cur.next = node

    def printHashTable(self):
        for i in range(self.length):
            print('Key: ' + str(i))
            if i not in self.hashTable.keys():
                print('\t\t\tNULL')
            else:
                self.hashTable[i].printList()

    def search(self, value):
        """ Search a value in hash table """
        index = self.hashFunction(value)
        num_comparisons = 0

        if index not in self.hashTable.keys():
            return -1, num_comparisons
        else:
            cur = self.hashTable[index].head

            num_comparisons += 1
            if value == cur.data:
                return index, num_comparisons

            while cur.next:
                cur = cur.next
                num_comparisons += 1
                if value == cur.data:
                    return index, num_comparisons

            return -1, num_comparisons


if __name__ == '__main__':
    random_seq = generate_random_sequence(20)
    print('- Random sequence: ' + str(random_seq))

    # Create Hash Table
    hash_table = HashTable(length=10)
    for ele in random_seq:
        hash_table.add(ele)

    print('\n- Hash Table:')
    hash_table.printHashTable()

    print('\n- Number of collisions: ' + str(hash_table.numCollisions))

    number_search = 336
    print('\n- Search number: ' + str(number_search))
    result, comps = hash_table.search(number_search)
    print('Number of comparisons: ' + str(comps))
    if result == -1:
        print('Not found!')
    else:
        print('Index: ' + str(result))

    number_search = 150
    print('\n- Search number: ' + str(number_search))
    result, comps = hash_table.search(number_search)
    print('Number of comparisons: ' + str(comps))
    if result == -1:
        print('Not found!')
    else:
        print('Index: ' + str(result))
