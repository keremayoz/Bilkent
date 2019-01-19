from State import State
from puzzleGenerator import PuzzleGenerator
from random import randint
import copy


class A_Star:

    # Store all paths visited in queue
    queue = []

    def a_star_search(self, start, goal, heuristic_id,):
        # Form a one element queue consisting of start
        self.queue.append([start])
        # While queue is not empty
        while(self.queue):

            # Select the min score path to extend its last node
            if heuristic_id == 1:
                minIndexInQueue = self.queue.index(min(self.queue, key=lambda o: len(o) + State.heuristic1(o[-1])))
            else:
                minIndexInQueue = self.queue.index(min(self.queue, key=lambda o: len(o) + State.heuristic2(o[-1])))
            stateWillBeExpanded = self.queue[minIndexInQueue][-1]

            # If goal node is found in front of the queue, announce success
            if stateWillBeExpanded == goal:
                print("Success: " + str(len(self.queue[minIndexInQueue])) + "\n")
                '''
                i = 1
                for goalPathStates in self.queue[minIndexInQueue]:
                    print("Step: " + str(i))
                    i += 1
                    print(goalPathStates)
                '''
                return

            # Expand the state with min score
            newStates = stateWillBeExpanded.makeMove()

            # Remove the cycling paths
            for a in newStates:
                if a in self.queue[minIndexInQueue]:
                    newStates.remove(a)

            # Add the newly expanded paths
            for states in newStates:

                # Build the new paths with newStates in the terminal position
                expandedPath = copy.deepcopy(self.queue[minIndexInQueue])
                expandedPath.append(states)
                exists = False

                # If queue currently consists a path with same terminal node and least cost, do not add new extended path
                for i in range(len(self.queue)):
                    for j in range(len(self.queue[i])):
                        if states == self.queue[i][j]:
                            exists = True
                            if j + 1 > len(expandedPath):
                                self.queue[i] = expandedPath
                                break

                # If it is not in the queue, means not expanded or added before, simply add it to queue
                if not exists:
                    self.queue.append(expandedPath)

            # Delete the first path in queue
            del self.queue[minIndexInQueue]
