array = [[0 for col in range(100)] for row in range(100)]

n = int(input())
for i in range(n):
    a, b = list(map(int, input().split()))
    for row in range(0, 10):
        for col in range(0, 10):
            array[b + row][a + col] = 1

rst = 0
for i in range(0, 100):
    for j in range(0, 100):
        if array[i][j] == 1:
            rst += 1

print(rst)
