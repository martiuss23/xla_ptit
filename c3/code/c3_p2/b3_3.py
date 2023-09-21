import cv2 as cv

if __name__ == '__main__':
    ip = cv.imread('D:\XLA\code\c3\input\Fig0310(b)(washed_out_pollen_image)100kb.jpg', cv.IMREAD_GRAYSCALE)
    cv.imshow("before", ip)
    hitogram = cv.equalizeHist(ip)
    cv.imshow('after',hitogram)
    cv.waitKey(0)