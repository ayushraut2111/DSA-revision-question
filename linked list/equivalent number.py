def is_Power(x, y):
   while (x%y == 0):
       x = x / y
   return x == 1
for _ in range(int(input())):
    a,b=map(int,input().split())
    if max(a,b)%min(a,b)!=0:
        print("no")
    else:
        count=max(a,b)//min(a,b)
        if is_Power(a,count) or is_Power(b,count):
            print("yes")
        else:
            print("no")

