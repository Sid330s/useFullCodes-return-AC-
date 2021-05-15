def getList(dictionary):
    return list(dictionary.keys())
def modInverse(a, m):
    for x in range(1, m):
        if (((a%m) * (x%m)) % m == 1):
            return x
    return 1
def NOfCommonTerms(lst1, lst2):
    return len(list(set(lst1) & set(lst2)))
numberOfTestCases=int(input())
for _ in range(numberOfTestCases):
    dictionary={}
    n=int(input())
    totalTeamNames=0
    words=input().split()
    for word in words:
        body=word[1:]
        heads=[]
        dictionary[body]=dictionary.get(body,heads)
        dictionary[body].append(word[0])
    listOfKeys=getList(dictionary)
    for i in range(len(dictionary)):
        for j in range(i+1,len(dictionary)):
            common=NOfCommonTerms(dictionary[listOfKeys[i]],dictionary[listOfKeys[j]])
            term=(len(dictionary[listOfKeys[i]])-common)*(len(dictionary[listOfKeys[j]])-common)
            totalTeamNames=totalTeamNames+term
    print(2*totalTeamNames)
