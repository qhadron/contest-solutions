import sys
P=int(input())
Q=int(input())
W=int(input())
for i in range(101):
    if (i * W/100 + P*(100-W)/100-Q >= -.5):
        print(i);
        sys.exit();

print("DROP THE COURSE")
