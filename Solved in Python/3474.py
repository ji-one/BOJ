import sys
t = int(sys.stdin.readline())
while t>0:
    n = int(sys.stdin.readline())
    cnt_5 =0
    i=5
    while n // i >0:
        cnt_5 += n//i
        i *= 5
    print(cnt_5)
    t -= 1
