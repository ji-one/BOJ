s1 = input()
s2 = input()

a = [0 for i in range(ord('z')+1)]
b = [0 for i in range(ord('z')+1)]
rst = 0

for i in s1:
    a[ord(i)] += 1

for i in s2:
    b[ord(i)] += 1

for i in range(ord('a'), ord('z')+1):
    if a[i] != b[i]:
        rst += abs(a[i]-b[i])

print(rst)
