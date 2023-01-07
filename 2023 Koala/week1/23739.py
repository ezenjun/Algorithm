n = int(input())
arr=[0]*n
ans=0
sum=0
for i in range(n):
    arr[i]= int(input())
    if (arr[i]/2) <= 30-sum:
        ans+=1
    sum += arr[i]
    if sum>=30:
        sum=0
print(ans)