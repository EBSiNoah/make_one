# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import random
import copy

def makeOne(num):
    
    table=[[0,0,0,1],[1,1,1,0],[1,1,0,1],[1,0,1,1],[1,1,0,1],[0,1,1,1],[1,0,0,1],[1,1,1,0],[1,1,0,1],[1,0,1,1],[0,1,0,1],[1,1,1,0],[1,0,0,1],[1,1,1,0],[1,1,0,1],[0,0,1,1],[1,1,0,1],[1,1,1,0],[1,0,0,1],[1,1,1,0],[0,1,0,1],[1,0,1,1],[1,1,0,1],[1,1,1,0],[1,0,0,1],[0,1,1,1],[1,1,0,1],[1,0,1,1],[1,1,0,1],[1,1,1,0]]
    idx=[0,0,0,0]
    count=0
    loopnum=0
    i=0
    while num>1:
        idx[0]=num//5
        idx[1]=num//3
        idx[2]=num//2
        idx[3]=num-1
        i=0
        while table[num%30][i]!=0:
           loopnum+=1
           i+=1
        num=idx[i]
        print(i," : ",idx[i])
        count+=1
    
    return count

def makeOne01(num):
    global B_tree
    global branch
    table=[[0,0,0,1],[1,1,1,0],[1,1,0,1],[1,0,1,1],[1,1,0,1],[0,1,1,1],[1,0,0,1],[1,1,1,0],[1,1,0,1],[1,0,1,1],[0,1,0,1],[1,1,1,0],[1,0,0,1],[1,1,1,0],[1,1,0,1],[0,0,1,1],[1,1,0,1],[1,1,1,0],[1,0,0,1],[1,1,1,0],[0,1,0,1],[1,0,1,1],[1,1,0,1],[1,1,1,0],[1,0,0,1],[0,1,1,1],[1,1,0,1],[1,0,1,1],[1,1,0,1],[1,1,1,0]]
    idx=[0,0,0,0]
    count=0
    i=0
    j=0
    k=0
    m=1
    loopnum=0
    branch=[]
    B_tree=[]
    branch.append(num)
    B_tree.append([num])
    branch.clear()

    while (j<num and idx[i]!=1):
        k=0
        m=1
        for k in range(j):
            m=m*2
        k=0
        while (idx[i]!=1 and k<m):
            idx[0]=B_tree[j][k]//5
            idx[1]=B_tree[j][k]//3
            idx[2]=B_tree[j][k]//2
            idx[3]=B_tree[j][k]-1
            i=0
            while (table[B_tree[j][k]%30][i]!=0):
                loopnum=loopnum+1
                i=i+1
            branch.append(idx[i])
            branch.append(idx[3])
            k=k+1
        B_tree.append(copy.deepcopy(branch))
        branch.clear()
        count=count+1
        j=j+1
    return count

def makeOneTest():
    #j=random.randrange(1,30000);
    #print(j)
    print(makeOne01(30000))

def main():
    makeOneTest()
    
if( __name__ == "__main__" ):
    main()