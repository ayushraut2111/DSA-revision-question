def change(a):
    for i in range(len(a)):
        a[i]=i+1

a=[]
for i in range(5):
    a.append(i)
print(a,end='\n\n')
change(a)
print(a)
