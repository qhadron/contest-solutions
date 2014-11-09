def P(tot,a,b,cur,backupofb):
	if (len(cur)==a):
		if ( sum([int(i) for i in cur])==backupofb):
			tot.append(cur)
	else:
		P(tot,a,b,"0"+cur,backupofb)
		if (b>0):
			P(tot,a,b-1,"1"+cur,backupofb)

for i in range(int(input())):
        s=input()
        n,k=s.split(" ")
        tot=[];
        P(tot,int(n),int(k),"",int(k))
        print("The bit patterns are")
        tot.sort()
        tot=tot[::-1]
        for i in tot:
            print(i)
        print()
