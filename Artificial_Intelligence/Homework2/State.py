from random import randint
import copy


class State:

    def __init__(self, grid):
        self.grid = grid

    '''
    Array that contains the snapshot of the game.
    | 1 2 3 |
    | 8   4 |   ===> [1,2,3,8,-1,4,7,6,5]
    | 7 6 5 |
    '''
    grid = []

    # Right positions of the numbers in the grid array according to goal state
    goalStateMap = {
        1: 0,
        2: 1,
        3: 2,
        4: 5,
        5: 8,
        6: 7,
        7: 6,
        8: 3,
        -1: 4
    }

    goalState = [1, 2, 3, 8, -1, 4, 7, 6, 5]

    # Finds the empty tile index
    def findEmptyIndex(self):
        emptyPosition = -1
        for i in range(0, 9):
            if self.grid[i] == -1:
                emptyPosition = i
                break
        if emptyPosition == -1:
            raise AssertionError
        return emptyPosition

    # Makes all the possible moves by calling makeMove() function for all tiles in the current state and returns the all possible moves
    def makeAllMoves(self):
        states = []
        for i in range(0, 9):
            state = copy.deepcopy(self)
            state2 = copy.deepcopy(state)
            tempstate = state.makeMove(state.grid, i)
            if not tempstate.compare(state2):
                if state is not None:
                    states.append(state)
        return states

    # Given position and grid, tries to move the tile at the index position if it is possible
    def makeMove(self, grid, position):
        emptyPosition = self.findEmptyIndex()

        # Do not move empty tile on itself
        if position == emptyPosition:
            return self

        # Evaluate the possible moves of the empty tile
        if emptyPosition == 0:
            possiblePositions = [emptyPosition + 1, emptyPosition + 3]

        elif emptyPosition == 1:
            possiblePositions = [emptyPosition + 1, emptyPosition - 1, emptyPosition + 3]

        elif emptyPosition == 2:
            possiblePositions = [emptyPosition - 1, emptyPosition + 3]

        elif emptyPosition == 3:
            possiblePositions = [emptyPosition + 1, emptyPosition - 3, emptyPosition + 3]

        elif emptyPosition == 4:
            possiblePositions = [emptyPosition + 1, emptyPosition - 1, emptyPosition - 3, emptyPosition + 3]

        elif emptyPosition == 5:
            possiblePositions = [emptyPosition - 1, emptyPosition - 3, emptyPosition + 3]

        elif emptyPosition == 6:
            possiblePositions = [emptyPosition + 1, emptyPosition - 3]

        elif emptyPosition == 7:
            possiblePositions = [emptyPosition + 1, emptyPosition - 1, emptyPosition - 3]

        elif emptyPosition == 8:
            possiblePositions = [emptyPosition - 1, emptyPosition - 3]

        # Make move
        tempGrid = grid
        if position in possiblePositions:
            tempGrid[emptyPosition] = tempGrid[position]
            tempGrid[position] = -1
        return State(tempGrid)

    # str method for visualizing the states
    def __str__(self):
        string = "--------------\n"
        string += "| " + str(self.grid[0]) + " | " + str(self.grid[1]) + " | " + str(self.grid[2]) + " |\n"
        string += "-------------\n"
        string += "| " + str(self.grid[3]) + " | " + str(self.grid[4]) + " | " + str(self.grid[5]) + " |\n"
        string += "-------------\n"
        string += "| " + str(self.grid[6]) + " | " + str(self.grid[7]) + " | " + str(self.grid[8]) + " |\n"
        string += "-------------\n"
        string += "Distance to goal: " + str(self.distanceToGoal())
        return string

    # Randomly generates initial states
    def generateInitialState(self):
        state = copy.deepcopy(self)
        for i in range(0, randint(30, 40)):
            pos = randint(0, 8)
            state.makeMove(state.grid, pos)

        return state

    # State equality checkers
    def compare(self, state):
        flag = True
        for i in range(0, 9):
            if self.grid[i] != state.grid[i]:
                flag = False

        return flag

    def __eq__(self, state):
        flag = True
        for i in range(0, 9):
            if self.grid[i] != state.grid[i]:
                flag = False

        return flag

        # Distance measure that we used in our program. It calculates (for every tile)
        # the distance of the tile's current position and its position in the goal state
    def distanceToGoal(self):
        distance = 0
        for i in range(0, 9):
            number = self.grid[i]
            rightPosition = self.goalStateMap[number]
            distance += abs(rightPosition - i)
        return distance
