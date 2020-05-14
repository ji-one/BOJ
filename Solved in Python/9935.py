s = input()
e = input()

stack = []

eLen = len(e)

for i in s:
    stack.append(i)
    a = 0
    if len(stack) >= eLen and stack[-1] == e[eLen-1]:
        '''
        stack 에 들어있는 문자의 수가 폭발 문자열의 길이보다 길고
        폭발 문자열의 마지막 문자와 현재 stack 에 들어온 문자가 같으면
        '''
        for j in range(0, eLen):
            if stack[len(stack)-j-1] != e[eLen-1-j]:  # 폭발 문자열인지 끝에서 부터 비교 
                a = 1  # 폭발 문자열 아님                
                break

        if a == 0:  # 폭발 문자열
            for k in range(0, eLen):  # stack 에서 폭발 문자열 제거 
                stack.pop()

if len(stack) == 0:  # stack 이 비어있으면
    print("FRULA")
else:
    print("".join(map(str, stack)))


