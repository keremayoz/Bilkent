import copy


class BBS:

    # Initializer
    def __init__(self, initialState):
        self.initialState = initialState
        self.goalState = [1, 2, 3, 8, -1, 4, 7, 6, 5]
        path = [initialState]
        self.queue = [path]
        self.closedList = []

    # Sort the paths by their total length + distance to the goal
    def sortQueue(self):
        for passnum in range(len(self.queue) - 1, 0, -1):
            for i in range(passnum):
                if len(self.queue[i]) > len(self.queue[i + 1]):
                    temp = self.queue[i]
                    self.queue[i] = self.queue[i + 1]
                    self.queue[i + 1] = temp

    def checkGoal(self):
        if not self.queue:
            print("Success \n")
            print(self.queue[0])

    def contains(self, state):
        for i in range(len(self.closedList)):
            if self.closedList[i].compare(state):
                return True
        return False

    def removeLoops(self, states):
        newStates = copy.deepcopy(states)
        length = len(states)
        for i in range(0, length):
            for closedState in self.closedList:
                if newStates[i].compare(closedState):
                    del newStates[i]
                    length -= 1

        return newStates

    def solve(self):
        while self.queue:
            if self.queue[0][-1].distanceToGoal() == 0:
                return self.queue[0]
            # Extend the front path's last state
            newStates = self.queue[0][-1].makeAllMoves()

            for i in range(0, len(self.queue[0]) - 1):
                for newState in newStates:
                    if self.queue[0][i].compare(newState):
                        newStates.remove(newState)

            # For every possible extension
            for state in newStates:
                # Append the new path
                temp = copy.deepcopy(self.queue[0])
                temp.append(state)
                self.queue.append(temp)

            # Delete the extended path
            del self.queue[0]

            # Sort the queue
            self.sortQueue()
            # print(self.queue[0][-1])


class BBSDP(BBS):

    def rem(self, queue):
        i = len(queue) - 1
        while i > 0:
            if queue[i][-1].compare(queue[i - 1][-1]):
                if len(queue[i][-1]) > len(queue[i - 1][-1]):
                    queue.pop(i)
            i -= 1
        return queue

    def solve(self):
        while self.queue:
            if self.queue[0][-1].distanceToGoal() == 0:
                print("Success")
                return self.queue[0]
            # Extend the front path's last state
            newStates = self.queue[0][-1].makeAllMoves()

            for i in range(0, len(self.queue[0]) - 1):
                for newState in newStates:
                    if self.queue[0][i].compare(newState):
                        newStates.remove(newState)
            # For every possible extension
            for state in newStates:
                # Append the new path
                temp = copy.deepcopy(self.queue[0])
                temp.append(state)
                self.queue.append(temp)

            del self.queue[0]
            self.sortQueue()

            self.rem(self.queue)
