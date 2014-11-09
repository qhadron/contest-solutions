n=int(input())
a,b=0,0
s=""
for i in range(n):
    s+=str(input())
if (s.count('s')+s.count('S'))<=(s.count('t')+s.count('T')):
    print("English")
else:
    print("French")
