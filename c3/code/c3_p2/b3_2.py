import cv2 as cv
import numpy as np

def histogramEqualizing(img, n, m, R):
    count = [0 for i in range(0, R)]
    p = [0 for i in range(0, R)]
    total = m * n
    for i in range(0, n):
        for j in range(0, m):
            count[img[i][j]] += 1
    for i in range(0, R):
        if i > 0:
            count[i] += count[i-1]
        p[i] = round((count[i] * (R-1))/total)
    res = img
    for i in range(0, n):
        for j in range(0, m):
            res[i][j] = p[res[i][j]]
    return res

if __name__ == '__main__':
    img1 = [[1,2,0,4], [1,0,0,7], [2,2,1,0], [4,1,2,1],[2,0,1,1]]
    img2 = [[0,5,0,5,5], [1,7,6,6,7], [5,5,6,2,7], [6,6,7,5,6], [0,1,5,0,2]]
    print("before-----------------------")
    print("image 1")
    for x in img1: print(x)
    print("image 2")
    for x in img2: print(x)
    print("after------------------------")
    print("image 1")
    for x  in histogramEqualizing(img1,5, 4, 8): print(x)
    print("image 2")
    for x in histogramEqualizing(img2, 5, 5, 8) : print(x)