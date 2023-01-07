import math
input = __import__('sys').stdin.readline
a,b,v = map(int,input().split())
ans = (v-b) / (a-b)
print(math.ceil(ans))