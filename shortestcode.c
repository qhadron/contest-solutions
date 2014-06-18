main(b,c,d){while(getchar()>32){}while(1+scanf("%d%c%d",&b,&c,&d)&&printf("%d\n",((c&=255)==43)?b+d:(c==45)?b-d:b*d)){}}
