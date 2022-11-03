a=list(map(int,input().split()))
n=len(a)
temp=[]
ans=[]
for i in range(n):
    temp.append(a[i])
    temp.sort()
    if len(temp)%2!=0:
        ans.append(temp[len(temp)//2])
    else:
        ans.append((temp[len(temp)//2-1]+temp[len(temp)//2])/2)
for i in range(n):
    if ans[i]==int(ans[i]):
        ans[i]=int(ans[i])
print(ans)
