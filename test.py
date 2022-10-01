def next_palin_drome(n):
    while True:
        n+=1
        if str(n) == str(n)[::-1]:
            return n 

n=123
print(next_palin_drome(n))
