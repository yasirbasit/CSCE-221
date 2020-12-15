'''
Author: your name
Date: 2020-09-13 19:03:14
LastEditTime: 2020-09-13 22:54:03
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: /hw1/bi.py
'''
import matplotlib.pyplot as plt
def Binary_Search(v, x):
    mid = low = comp = 0
    high = len(v) - 1
    while low < high:
        mid = int((low + high) / 2)
        if v[int(mid)] < x:
            low = mid + 1
            comp += 1
        else:
            high = mid
    if x == v[int(low)]:
        comp += 1
        return int(low), comp
    else:
        print("sth wrong")

if __name__ == '__main__':
    dat = []
    x = []
    y = []
    # k = int(input("k: "))
    for k in range(0, 12):
        n = 2 ** k
        x.append(n)
        for i in range(0, n):
            dat.append(i)
        # print("The last number of the vector is ", dat[n - 1])
        a, b = Binary_Search(dat, n - 1)
        # print("comp: ", b)
        y.append(b)
    for i in range(len(x)):
        print(x[i])
    for i in range(len(y)):
        print(y[i])
    