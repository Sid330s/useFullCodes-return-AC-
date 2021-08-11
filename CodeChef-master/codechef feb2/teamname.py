t=int(input())
while t>0:
    ans=0
    d={}
    n=int(input())
    it=input().split()
    for w in it:
        v=w[1:]
        if v not in d:
            d[v]=[w[0]]
        else:
            d[v].append(w[0])
    d1=list(d.keys())
    for i in range(len(d)):
        for j in range(i+1,len(d)):
            x=len(set(d[d1[i]]).intersection(set(d[d1[j]])))
            ans+=2*(len(d[d1[i]])-x)*(len(d[d1[j]])-x)
    print(ans)
    t=t-1
