import cv2 as cv
L = 256
source_path = 'D:\XLA\DIP3E_Original_Images_CH03\Fig0310(b)(washed_out_pollen_image).tif'
source_jpg_path = 'D:\XLA\code\output_image\input.jpg'
out_jpg_path = 'D:\XLA\code\output_image\out.jpg'
def resize(frame, scale = 0.75):
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    dimensions = (width, height)
    return cv.resize(gray, dimensions)

def T(r):
    if r <= 3*L/8:
        return int(r/3)
    if r > 5 * L/ 8:
        return min(int((r+512)/3), L-1)
    return min(r * 3 - L, L - 1)

if __name__ == '__main__':
    gray = cv.imread(source_path, cv.IMREAD_GRAYSCALE)

    grayResized = resize(gray)
    cv.imwrite(source_jpg_path, grayResized)
    cv.imshow('before trans', grayResized)
    for i in range(grayResized.shape[0]):
        for j in range(grayResized.shape[1]):
            grayResized[i][j] = T(grayResized[i][j])
    cv.imshow('after trans', grayResized)
    cv.imwrite(out_jpg_path, grayResized)
    cv.waitKey(0)