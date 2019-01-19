class State:

    grid = []

    goalState = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, -1]]

    def __init__(self, grid):
        self.grid = grid

    def __eq__(self, other):
        for i in range(0, 4):
            for j in range(0, 4):
                if self.grid[i][j] != other.grid[i][j]:
                    return False
        return True
    # Emege saygı..

    def __str__(self):
        string = "---------------------\n"
        string += "| " + ((1 - abs((self.grid[0][0] // 10))) * " ") + str(self.grid[0][0]) + " | " + ((1 - abs((self.grid[0][1] // 10))) * " ") + str(self.grid[0][1])
        string += " | " + ((1 - abs((self.grid[0][2] // 10))) * " ") + str(self.grid[0][2]) + " | " + ((1 - abs((self.grid[0][3] // 10))) * " ") + str(self.grid[0][3]) + " |\n"
        string += "---------------------\n"
        string += "| " + ((1 - abs((self.grid[1][0] // 10))) * " ") + str(self.grid[1][0]) + " | " + ((1 - abs((self.grid[1][1] // 10))) * " ") + str(self.grid[1][1])
        string += " | " + ((1 - abs((self.grid[1][2] // 10))) * " ") + str(self.grid[1][2]) + " | " + ((1 - abs((self.grid[1][3] // 10))) * " ") + str(self.grid[1][3]) + " |\n"
        string += "---------------------\n"
        string += "| " + ((1 - abs((self.grid[2][0] // 10))) * " ") + str(self.grid[2][0]) + " | " + ((1 - abs((self.grid[2][1] // 10))) * " ") + str(self.grid[2][1])
        string += " | " + ((1 - abs((self.grid[2][2] // 10))) * " ") + str(self.grid[2][2]) + " | " + ((1 - abs((self.grid[2][3] // 10))) * " ") + str(self.grid[2][3]) + " |\n"
        string += "---------------------\n"
        string += "| " + ((1 - abs((self.grid[3][0] // 10))) * " ") + str(self.grid[3][0]) + " | " + ((1 - abs((self.grid[3][1] // 10))) * " ") + str(self.grid[3][1])
        string += " | " + ((1 - abs((self.grid[3][2] // 10))) * " ") + str(self.grid[3][2]) + " | " + ((1 - abs((self.grid[3][3] // 10))) * " ") + str(self.grid[3][3]) + " |\n"
        string += "---------------------\n"
        return string

    def heuristic1(self):
        count = 0
        for i in range(0, 4):
            for j in range(0, 4):
                if self.grid[i][j] != self.goalState[i][j]:
                    count += 1
        return count

    def heuristic2(self):
        count = 0
        manhattan_map = {
            1: (0, 0),
            2: (0, 1),
            3: (0, 2),
            4: (0, 3),
            5: (1, 0),
            6: (1, 1),
            7: (1, 2),
            8: (1, 3),
            9: (2, 0),
            10: (2, 1),
            11: (2, 2),
            12: (2, 3),
            13: (3, 0),
            14: (3, 1),
            15: (3, 2),
            -1: (3, 3),
        }

        for i in range(0, 4):
            for j in range(0, 4):
                count += abs(i - manhattan_map[self.grid[i][j]][0])
                count += abs(j - manhattan_map[self.grid[i][j]][1])
        return count

    def makeMove(self):

        x = -1
        y = -1

        for i in range(0, 4):
            for j in range(0, 4):
                if self.grid[i][j] == -1:
                    x = i
                    y = j
                    break

        newStates = []
        tempGrid = [row[:] for row in self.grid]
        tempGrid2 = [row[:] for row in self.grid]
        tempGrid3 = [row[:] for row in self.grid]
        tempGrid4 = [row[:] for row in self.grid]

        if x == 0 and y == 0:
            tempGrid[0][0] = tempGrid[0][1]
            tempGrid[0][1] = -1
            newStates.append(State(tempGrid))

            tempGrid2[0][0] = tempGrid2[1][0]
            tempGrid2[1][0] = -1
            newStates.append(State(tempGrid2))

        elif x == 0 and y == 1:
            tempGrid[0][1] = tempGrid[0][0]
            tempGrid[0][0] = -1
            newStates.append(State(tempGrid))

            tempGrid2[0][1] = tempGrid2[1][1]
            tempGrid2[1][1] = -1
            newStates.append(State(tempGrid2))

            tempGrid3[0][1] = tempGrid3[0][2]
            tempGrid3[0][2] = -1
            newStates.append(State(tempGrid3))

        elif x == 0 and y == 2:
            tempGrid[0][2] = tempGrid[0][1]
            tempGrid[0][1] = -1
            newStates.append(State(tempGrid))

            tempGrid2[0][2] = tempGrid2[0][3]
            tempGrid2[0][3] = -1
            newStates.append(State(tempGrid2))

            tempGrid3[0][2] = tempGrid3[1][2]
            tempGrid3[1][2] = -1
            newStates.append(State(tempGrid3))

        elif x == 0 and y == 3:
            tempGrid[0][3] = tempGrid[0][2]
            tempGrid[0][2] = -1
            newStates.append(State(tempGrid))

            tempGrid2[0][3] = tempGrid2[1][3]
            tempGrid2[1][3] = -1
            newStates.append(State(tempGrid2))

        elif x == 1 and y == 0:
            tempGrid[1][0] = tempGrid[0][0]
            tempGrid[0][0] = -1
            newStates.append(State(tempGrid))

            tempGrid2[1][0] = tempGrid2[2][0]
            tempGrid2[2][0] = -1
            newStates.append(State(tempGrid2))

            tempGrid3[1][0] = tempGrid3[1][1]
            tempGrid3[1][1] = -1
            newStates.append(State(tempGrid3))

        elif x == 1 and y == 1:
            tempGrid[1][1] = tempGrid[0][1]
            tempGrid[0][1] = -1
            newStates.append(State(tempGrid))

            tempGrid2[1][1] = tempGrid2[1][2]
            tempGrid2[1][2] = -1
            newStates.append(State(tempGrid2))

            tempGrid3[1][1] = tempGrid3[2][1]
            tempGrid3[2][1] = -1
            newStates.append(State(tempGrid3))

            tempGrid4[1][1] = tempGrid4[1][0]
            tempGrid4[1][0] = -1
            newStates.append(State(tempGrid4))

        elif x == 1 and y == 2:
            tempGrid[1][2] = tempGrid[0][2]
            tempGrid[0][2] = -1
            newStates.append(State(tempGrid))

            tempGrid2[1][2] = tempGrid2[1][3]
            tempGrid2[1][3] = -1
            newStates.append(State(tempGrid2))

            tempGrid3[1][2] = tempGrid3[2][2]
            tempGrid3[2][2] = -1
            newStates.append(State(tempGrid3))

            tempGrid4[1][2] = tempGrid4[1][1]
            tempGrid4[1][1] = -1
            newStates.append(State(tempGrid4))

        elif x == 1 and y == 3:
            tempGrid[1][3] = tempGrid[0][3]
            tempGrid[0][3] = -1
            newStates.append(State(tempGrid))

            tempGrid2[1][3] = tempGrid2[2][3]
            tempGrid2[2][3] = -1
            newStates.append(State(tempGrid2))

            tempGrid3[1][3] = tempGrid3[1][2]
            tempGrid3[1][2] = -1
            newStates.append(State(tempGrid3))

        elif x == 2 and y == 0:
            tempGrid[2][0] = tempGrid[1][0]
            tempGrid[1][0] = -1
            newStates.append(State(tempGrid))

            tempGrid2[2][0] = tempGrid2[3][0]
            tempGrid2[3][0] = -1
            newStates.append(State(tempGrid2))

            tempGrid3[2][0] = tempGrid3[2][1]
            tempGrid3[2][1] = -1
            newStates.append(State(tempGrid3))

        elif x == 2 and y == 1:
            tempGrid[2][1] = tempGrid[2][0]
            tempGrid[2][0] = -1
            newStates.append(State(tempGrid))

            tempGrid2[2][1] = tempGrid2[2][2]
            tempGrid2[2][2] = -1
            newStates.append(State(tempGrid2))

            tempGrid3[2][1] = tempGrid3[1][1]
            tempGrid3[1][1] = -1
            newStates.append(State(tempGrid3))

            tempGrid4[2][1] = tempGrid4[3][1]
            tempGrid4[3][1] = -1
            newStates.append(State(tempGrid4))

        elif x == 2 and y == 2:
            tempGrid[2][2] = tempGrid[2][1]
            tempGrid[2][1] = -1
            newStates.append(State(tempGrid))

            tempGrid2[2][2] = tempGrid2[2][3]
            tempGrid2[2][3] = -1
            newStates.append(State(tempGrid2))

            tempGrid3[2][2] = tempGrid3[1][2]
            tempGrid3[1][2] = -1
            newStates.append(State(tempGrid3))

            tempGrid4[2][2] = tempGrid4[3][2]
            tempGrid4[3][2] = -1
            newStates.append(State(tempGrid4))

        elif x == 2 and y == 3:
            tempGrid[2][3] = tempGrid[2][2]
            tempGrid[2][2] = -1
            newStates.append(State(tempGrid))

            tempGrid2[2][3] = tempGrid2[1][3]
            tempGrid2[1][3] = -1
            newStates.append(State(tempGrid2))

            tempGrid3[2][3] = tempGrid3[3][3]
            tempGrid3[3][3] = -1
            newStates.append(State(tempGrid3))

        elif x == 3 and y == 0:
            tempGrid[3][0] = tempGrid[3][1]
            tempGrid[3][1] = -1
            newStates.append(State(tempGrid))

            tempGrid2[3][0] = tempGrid2[2][0]
            tempGrid2[2][0] = -1
            newStates.append(State(tempGrid2))

        elif x == 3 and y == 1:
            tempGrid[3][1] = tempGrid[3][2]
            tempGrid[3][2] = -1
            newStates.append(State(tempGrid))

            tempGrid2[3][1] = tempGrid2[3][0]
            tempGrid2[3][0] = -1
            newStates.append(State(tempGrid2))

            tempGrid3[3][1] = tempGrid3[2][1]
            tempGrid3[2][1] = -1
            newStates.append(State(tempGrid3))

        elif x == 3 and y == 2:

            tempGrid[3][2] = tempGrid[3][3]
            tempGrid[3][3] = -1
            newStates.append(State(tempGrid))

            tempGrid2[3][2] = tempGrid2[3][1]
            tempGrid2[3][1] = -1
            newStates.append(State(tempGrid2))

            tempGrid3[3][2] = tempGrid3[2][2]
            tempGrid3[2][2] = -1
            newStates.append(State(tempGrid3))

        elif x == 3 and y == 3:
            tempGrid[3][3] = tempGrid[2][3]
            tempGrid[2][3] = -1
            newStates.append(State(tempGrid))

            tempGrid2[3][3] = tempGrid2[3][2]
            tempGrid2[3][2] = -1
            newStates.append(State(tempGrid2))

        return newStates
