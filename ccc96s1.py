def test(n):
  a=sum ( [ i for i in range(1,n) if n % i == 0 ] )
  if (a<n):
    print (str(n) + " is a deficient number.")
  elif (a==n):
    print (str(n) + " is a perfect number.")
  else:
    print (str(n) + " is an abundant number.")

num=int(input())
for i in range(num):
  test(int(input()))
