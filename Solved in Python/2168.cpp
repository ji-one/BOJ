x, y = input().split()
x = int(x)
y = int(y)

def gcd(x,y):
    if y==0:
        return x
    else:
        return gcd(y,x%y)
    
g = gcd(x,y)

print(x + y - g)
