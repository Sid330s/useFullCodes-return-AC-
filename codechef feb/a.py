def getList(dictionary):
    return list(dictionary.keys())
def modInverse(a, m):
    for x in range(1, m):
        if (((a%m) * (x%m)) % m == 1):
            return x
    return 1

numberOfTestCases=int(input())
for _ in range(numberOfTestCases):
    n=int(input())
    dictionary={}
    totalTeamNames=0
    inp=input().split()
    for word in inp:
        body=word[1:]
        if body in dictionary:
            dictionary[body].append(word[0])
        else:
            dictionary[body]=[word[0]]
    numOfBodies=len(dictionary)
    listOfKeys=getList(dictionary)
    for i in range(numOfBodies):
        for j in range(i+1,numOfBodies):
            NOfIntersect=len(set(dictionary[body[i]]).intersection(set(dictionary[body[j]])))
            totalTeamNames=totalTeamNames+2*(len(dictionary[body[i]])-NOfIntersect)*(len(dictionary[body[j]])-NOfIntersect)
    print(totalTeamNames)
