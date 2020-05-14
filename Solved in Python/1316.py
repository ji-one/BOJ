n = int(input())

rst = 0


for i in range(n):
    visited = [0 for i in range(ord('z') + 1)]
    prev = 'A'
    s = input()
    groupword = 1
    for c in s:
        if prev == c:
            continue
        elif visited[ord(c)] == 1:
            groupword = 0
            break
        else:
            visited[ord(c)] = 1
            prev = c

    if groupword == 1:
        rst += 1

print(rst)
