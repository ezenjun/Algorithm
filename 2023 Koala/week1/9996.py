n = int(input())
pattern = input().split('*')
for i in range(n):
    s = input()
    if pattern[0] in s:
        idx = s.find(str(pattern[0]))
        if pattern[1] in s[idx:]:
            print("DA")
        else:
            print("NE")
    else:
            print("NE")