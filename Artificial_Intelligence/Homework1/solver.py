import copy
from random import randint
from time import sleep


# State node that stores the current state of the puzzle
class Node:
    states = (0, 0, 0, 0, "Left")

    def __init__(self, ls, lb, rs, rb, b):
        self.states = (ls, lb, rs, rb, b)

    def __eq__(self, other):
        if self.states[0] == other.states[0] and self.states[1] == other.states[1] and self.states[2] == other.states[2] and self.states[3] == other.states[3] and self.states[4] == other.states[4]:
            return True
        return False

    def __str__(self):
        string = "-----------------------------------------------------------\n"
        string += str(self.states[0]) + " Soldier\t|\t\t\t|\t" + str(self.states[2]) + " Soldier\n"
        if self.states[4] == "Left":
            string += "         \t| Boat   \t\t|\n"
        else:
            string += "         \t|\t\t   Boat |\n"
        string += str(self.states[1]) + " Boy    \t|\t\t\t|\t" + str(self.states[3]) + " Boy\n"
        string += "-----------------------------------------------------------"
        return string

# Initial State
initial = Node(3, 2, 0, 0, "Left")

# 0 Length path, which is initial state itself
path0 = [initial]

# Queue that stores the list of paths in it
queue = [path0]

# Closed list that contains the states that are visited
closed = []


# Prints the queue
def printQueue(queue):
    print("............HEAD..........")
    for i in range(len(queue)):
        for j in range(len(queue[i])):
            print(str(queue[i][j].states) + "-->", sep='-->', end='', flush=True)
        if i < len(queue) - 1:
            print("\n")
    print("\n............TAIL..........\n")


# Prints the closed list
def printClosed(closed):
    print("..........................")
    for i in range(len(closed)):
        print(closed[i].states)
    print("..........................\n")


# Checks whether given node is currently visited or not
def contains(node):
    for i in range(len(closed)):
        if closed[i].states == node.states:
            return True
    return False


# Extends the given node and adds it to the current list and queue. After that it deletes the node that is expanded
def extendNode(node, ind):
    closed.append(node)
    # Print the steps
    print("\nStep " + str(ind) + "\nExpanding the state: ")
    print(str(node))

    # Path that contains the expanding node
    pathTemp = copy.deepcopy(queue[0])

    # Checks whether expanded or not
    expanded = False

    # Boat on the left
    if node.states[4] == "Left":

        # Move one soldier left to right
        if node.states[0] > 0:
            node1 = Node(node.states[0] - 1, node.states[1], node.states[2] + 1, node.states[3], "Right")
            if not contains(node1):
                expanded = True
                temp = copy.deepcopy(pathTemp)
                temp.append(node1)
                queue.insert(randint(1, len(queue) + 1), temp)

        # Move 2 boy left to right
        if node.states[1] == 2:
            node2 = Node(node.states[0], node.states[1] - 2, node.states[2], node.states[3] + 2, "Right")
            if not contains(node2):
                expanded = True
                temp = copy.deepcopy(pathTemp)
                temp.append(node2)
                queue.insert(randint(1, len(queue) + 1), temp)

        # Move 1 boy left to right
        if node.states[1] > 0:
            node3 = Node(node.states[0], node.states[1] - 1, node.states[2], node.states[3] + 1, "Right")
            if not contains(node3):
                expanded = True
                temp = copy.deepcopy(pathTemp)
                temp.append(node3)
                queue.insert(randint(1, len(queue) + 1), temp)

    # Boat on the right
    else:

        # Move one soldier right to left
        if node.states[2] > 0:
            node4 = Node(node.states[0] + 1, node.states[1], node.states[2] - 1, node.states[3], "Left")
            if not contains(node4):
                expanded = True
                temp = copy.deepcopy(pathTemp)
                temp.append(node4)
                queue.insert(randint(1, len(queue) + 1), temp)

        # Move 2 boy right to left
        if node.states[3] == 2:
            node5 = Node(node.states[0], node.states[1] + 2, node.states[2], node.states[3] - 2, "Left")
            if not contains(node5):
                expanded = True
                temp = copy.deepcopy(pathTemp)
                temp.append(node5)
                queue.insert(randint(1, len(queue) + 1), temp)

        # Move 1 boy right to left
        if node.states[3] > 0:
            node6 = Node(node.states[0], node.states[1] + 1, node.states[2], node.states[3] - 1, "Left")
            if not contains(node6):
                expanded = True
                temp = copy.deepcopy(pathTemp)
                temp.append(node6)
                queue.insert(randint(1, len(queue) + 1), temp)
    if not expanded:
        print("This state cannot be extended !\n")
    del queue[0]

# Goal state
goal = Node(0, 2, 3, 0, "Left")

# Step index
ind = 0

# Initial entrance message
print("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||")
print("INITIAL")
print("\nClosed List: ")
printClosed(closed)
print("Queue: ")
printQueue(queue)
print("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||")

# Expanding states by pressing enter to iterate
while queue:

    # Press enter to expand the current state
    keyPressed = input('\nPress Enter to continue extending : ')
    if keyPressed == "":
        ind += 1

        # Check whether goal is reached or not, that is if the goal is the last state of the first path of the queue
        if queue[0][-1] == goal:
            print("Path to the goal: ")
            printClosed(queue[0])
            break

        # Extend the first path in the queue
        extendNode(queue[0][-1], ind)

        # Print the current contents of the closed list and queue
        print("\nClosed List: ")
        printClosed(closed)
        print("Queue after expansion: ")
        printQueue(queue)
        print("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||")
