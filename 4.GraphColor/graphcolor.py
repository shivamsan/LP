m = int(input("Enter Number of Max Colors: "))

g={}#dict

n = int(input("Enter Number of Edges: "))

for i in range(n):
    a,b = map(int, input().split())
    #a = int(input())
    #b = int(input())

    if g.get(a) == None:
        g[a] = []
    g[a].append(b)
    if g.get(b) == None:
        g[b] = []
    g[b].append(a)

print(g)




posCol = ["red", "green", "blue", "indigo", "orange", "yellow"]

def canColor(g,n,col,colList):
    for child in g[n]:
        if colList[child] == posCol[col]:
            return False
        
    return True


def graphColoring(g,m,v,n,colList):
    if n==v:
        return True
    
    for col in range(m):
        if(canColor(g,n,col,colList)):
            colList[n] = posCol[col]
            if graphColoring(g,m,v,n+1,colList) == True:
                return True
        colList[n] = -1

colList = {}

for i in g.keys():
    colList[i]= -1

if graphColoring(g,m,len(g.keys()),0,colList):
    print(colList)
else:
    print(f"can't color using m={m} colors")

"""
3
6
0 1
0 2
0 3
1 2
2 3
3 4
"""