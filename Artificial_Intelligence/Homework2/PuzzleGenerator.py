from State import State



class PuzzleGenerator:
    @staticmethod
    def generatePuzzle(count):
        initialStates = []
        for i in range(0, count):
            tempState = State([1, 2, 3, 8, -1, 4, 7, 6, 5]).generateInitialState()
            initialStates.append(tempState)
        return initialStates



