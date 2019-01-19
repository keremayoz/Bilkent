from PuzzleGenerator import PuzzleGenerator
from BranchAndBoundSearch import BBS
from BranchAndBoundSearch import BBSDP
from State import State
import time

initalStates = PuzzleGenerator.generatePuzzle(25)

timesBBS = []
timesBBSDP = []

for i in range(0, 25):
    print("BBS " + str(i) + " STARTED")
    t1 = time.time()
    search = BBS(initalStates[i])
    s1 = search.solve()
    t2 = time.time()
    timesBBS.append(t2 - t1)
    print("BBS " + str(i) + " DONE!")

for i in range(0, 25):
    print("BBSDP " + str(i) + " STARTED")
    t1 = time.time()
    search2 = BBSDP(initalStates[i])
    s2 = search2.solve()
    t2 = time.time()
    timesBBSDP.append(t2 - t1)
    print("BBSDP " + str(i) + " DONE!")

for i in range(len(s2)):
    print(s2[i])

print("BBS -- BBSDP\n***************")
c1 = 0
c2 = 0
for i in range(0, 25):
    if timesBBSDP[i] > 0.00000000001:
        # print(i)
        c = timesBBS[i] / timesBBSDP[i]
        if c >= 0.98:
            print("BBS is worse -- (timeBBS / timeBBSDP) \n" + str(c))
            c1 = c1 + 1
        else:
            print("BBSDP is worse -- (timeBBS / timeBBSDP) \n" + str(c))
            c2 = c2 + 1
    else:
        print(i)
        c1 = c1 + 1

print("\n\nBBS " + str(c1) + "\nBBSDP " + str(c2))

'''
for i in range(len(s1)):
    print(s1[i])
'''
'''
for i in range(len(s2)):
    print(s2[i])

'''
