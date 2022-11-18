# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import random

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

def makeOneTest():
    j=random.randrange(1,30000);
    print(j)
    print(makeOne(j))

def main():
    makeOneTest()
    
if( __name__ == "__main__" ):
    main()