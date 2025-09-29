arr = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]

def printWave(arr):
    ROWS, COLS = len(arr), len(arr[0])

    for j in range(COLS):
        if j % 2 == 0:
            for i in range(ROWS):
                print(arr[i][j], end = ' ')
        else:
            for i in range(ROWS - 1, -1, -1):
                print(arr[i][j], end = ' ')
        print()

printWave(arr)