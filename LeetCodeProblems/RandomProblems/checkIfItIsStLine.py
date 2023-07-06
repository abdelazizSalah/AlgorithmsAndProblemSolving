points = [[1, 1], [2, 2], [3, 4], [4, 5], [5, 6], [7, 7]]
x0, y0 = points[0]
x1, y1 = points[1]

A = y0 - y1
B = x1 - x0
C = (x0 * y1) - (y0*x1)


def onLine(x, y):
    return (A*x) + (B*y) + C == 0


for point in points:
    if not onLine(point[0], point[1]):
        print(False)
        exit(-1)

print(True)
