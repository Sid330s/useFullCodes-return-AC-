import math
def isPerfectSquare(x): 
  
    # Find floating point value of  
    # square root of x. 
    sr = math.sqrt(x) 
   
    # If square root is an integer 
    return ((sr - math.floor(sr)) == 0) 

def nextPerfectSquare(N): 
  
    nextN = math.floor(math.sqrt(N)) + 1
  
    return nextN * nextN 

def findMinimumNumber(n):
    count =0
    count1 =1
    while n%2==0:
        count += 1
        n//=2
    if count%2:
        count1*=2
    for i in range(3, int(math.sqrt(n))+1, 2):
        count =0
        while n%i==0:
            count+=1
            n //=i
        if count%2:
            count1 *=i
    if n >2:
        count1 *=n
    return count1


def modInverse(a, m) : 
    m0 = m 
    y = 0
    x = 1
  
    if (m == 1) : 
        return 0
  
    while (a > 1) : 
  
     
        q = a // m 
  
        t = m 
  
    
        m = a % m 
        a = t 
        t = y 
  

        y = x - q * y 
        x = t 
  
  

    if (x < 0) : 
        x = x + m0 
  
    return x 

def translate(seq): 
       
    table = { 
        'ATA':'I', 'ATC':'I', 'ATT':'I', 'ATG':'M', 
        'ACA':'T', 'ACC':'T', 'ACG':'T', 'ACT':'T', 
        'AAC':'N', 'AAT':'N', 'AAA':'K', 'AAG':'K', 
        'AGC':'S', 'AGT':'S', 'AGA':'R', 'AGG':'R',                  
        'CTA':'L', 'CTC':'L', 'CTG':'L', 'CTT':'L', 
        'CCA':'P', 'CCC':'P', 'CCG':'P', 'CCT':'P', 
        'CAC':'H', 'CAT':'H', 'CAA':'Q', 'CAG':'Q', 
        'CGA':'R', 'CGC':'R', 'CGG':'R', 'CGT':'R', 
        'GTA':'V', 'GTC':'V', 'GTG':'V', 'GTT':'V', 
        'GCA':'A', 'GCC':'A', 'GCG':'A', 'GCT':'A', 
        'GAC':'D', 'GAT':'D', 'GAA':'E', 'GAG':'E', 
        'GGA':'G', 'GGC':'G', 'GGG':'G', 'GGT':'G', 
        'TCA':'S', 'TCC':'S', 'TCG':'S', 'TCT':'S', 
        'TTC':'F', 'TTT':'F', 'TTA':'L', 'TTG':'L', 
        'TAC':'Y', 'TAT':'Y', 'TAA':'_', 'TAG':'_', 
        'TGC':'C', 'TGT':'C', 'TGA':'_', 'TGG':'W', 
    } 
    protein ="" 
    if len(seq)%3 == 0: 
        for i in range(0, len(seq), 3): 
            codon = seq[i:i + 3] 
            protein+= table[codon] 
    return protein 

def isPrime(n): 
      
    # Corner case 
    if (n <= 1): 
        return False
  
    # Check from 2 to n-1 
    for i in range(2, n): 
        if (n % i == 0): 
            return False
  
    return True
   
for _ in range(int(input())):
    p1, n1, p2, n2 = 0,0,0,0
    x, y = map(int, input().split())
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))

    pos1 = []
    neg1 = []
    pos2 = []
    neg2 = []
    
    hashp1, hashn1, hashp2, hashn2 = {}, {}, {}, {}
    
    max1, max2 = 0,0
    isThereZero = 0
    
    
    for i in arr1:
        if i>0:
            pos1.append(i)
            hashp1[i]=1
            p1+=1
        elif i<0:
            neg1.append(i)
            if i<max1:
                max1 = i
            hashn1[i]=1
            n1+=1
        else:
            isThereZero = 1



            
    for i in arr2:
        if i>0:
            pos2.append(i)
            hashp2[i]=1
            p2+=1
        elif i<0:
            neg2.append(i)
            if i<max2:
                max2 = i
            hashn2[i]=1
            n2+=1
        else:
            isThereZero = 1


            
    count1 = 0



    
    if isThereZero:
        count1+=(p1+n1)*(p2+n2)
    for i in pos1:
        
        temporaryVariable1 = findMinimumNumber(i)
        
        j=1
        
        temporaryVariable2 = temporaryVariable1
        
        while temporaryVariable2 <= abs(max1):
            
            if hashn1.get(int(-1*temporaryVariable2), 0):
                
                abc = math.sqrt(i*temporaryVariable2)
                
                if hashp2.get(int(abc), 0):
                    
                    count1+=1
                    
                if hashn2.get(int(-1*abc), 0):
                    
                    count1+=1
                    
            j+=1
            
            temporaryVariable2 = temporaryVariable1*pow(j, 2)

    
    for i in pos2:
        
        temporaryVariable1 = findMinimumNumber(i)
        
        j=1
        
        temporaryVariable2 = temporaryVariable1
        
        while temporaryVariable2<=abs(max2):
            
            if hashn2.get(int(-1*temporaryVariable2), 0):
                
                abc = math.sqrt(i*temporaryVariable2)
                
                if hashp1.get(int(abc), 0):
                    
                    count1+=1
                    
                if hashn1.get(int(-1*abc), 0):
                    
                    count1+=1
                    
            j+=1
            
            temporaryVariable2 = temporaryVariable1*pow(j, 2)
            
    print(count1)
