s = input()
a = 1 
b = 1
for i in range(0,len(s)-1):
    for j in range(0,i+1):
        a *= int(s[j])
    for j in range(i+1, len(s)):
        b *= int(s[j])
    if a == b:
        print("YES")
        exit()
    else :
        a = 1
        b = 1

print("NO")        
