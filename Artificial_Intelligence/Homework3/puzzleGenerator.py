from State import State
from random import randint
import time


class PuzzleGenerator:

    def generatePuzzles(puzzleCount):
        newPuzzles = []
        for i in range(puzzleCount):
            start = State(State.goalState)
            newStates = []
            expandeds = [start]
            count = 0
            for i in range(randint(15, 20)):
                newStates = start.makeMove()
                start = newStates[randint(0, len(newStates) - 1)]
                while start in expandeds:
                    start = newStates[randint(0, len(newStates) - 1)]
                expandeds.append(start)
                count += 1
            newPuzzles.append(start)
        return newPuzzles
