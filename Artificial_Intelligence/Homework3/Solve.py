from A_Star import A_Star
from puzzleGenerator import PuzzleGenerator
from random import randint
from State import State
import time
import copy

roots = PuzzleGenerator.generatePuzzles(25)
timesh1 = []
timesh2 = []

for i in range(len(roots)):
    solver = A_Star()
    print("Puzzle " + str(i + 1))
    print(roots[i])
    goalState = State([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, -1]])

    t1 = time.time()
    A_Star.a_star_search(solver, roots[i], goalState, 1)
    t2 = time.time()
    timesh1.append(t2 - t1)

    t1 = time.time()
    A_Star.a_star_search(solver, roots[i], goalState, 2)
    t2 = time.time()
    timesh2.append(t2 - t1)

print("HEURISTIC 1")
for i in range(len(timesh1)):
    print("Puzzle : " + str(i) + ": " + str(timesh1[i]))

print("HEURISTIC 2")
for i in range(len(timesh2)):
    print("Puzzle : " + str(i) + ": " + str(timesh2[i]))
