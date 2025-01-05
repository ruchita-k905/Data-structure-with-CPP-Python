#Matric operation
def add(a,b):
    if len(a)!=len(b):
        raise ValueError("Matrices must have same dimensions")
    result = [[0 for _ in range(len(a[0]))]for _ in range (len(a))]

    for i in range (len(a)):
        for j in range (len(a[0])):
                result[i][j]=a[i][j]+b[i][j]
    return result

def sub(a,b):
    if len(a)!=len(b):
        raise ValueError("Matrices must have same dimensions")
    result = [[0 for _ in range(len(a[0]))]for _ in range (len(a))]

    for i in range (len(a)):
        for j in range (len(a[0])):
            result[i][j]=a[i][j]-b[i][j]
    return result

def mul(a,b):
    if len(a[0])!=len(b):
        raise ValueError("no of col in A must be same as no of rows in B")
    result = [[0 for _ in range(len(b[0]))]for _ in range (len(a))]

    for i in range (len(a)):
        for j in range (len(b[0])):
            for k in range (len(b)):
                result[i][j]+=a[i][k]*b[k][j]
    return result

def trp(a):
    return [[a[j][i] for j in range (len(a))]for i in range (len(a[0]))]

#driver code
A=[[1,2,3],
   [4,5,6],
   [7,8,9]]
B=[[9,8,7],
   [6,5,4],
   [3,2,1]]

print("Matrix A :",A)
print("Matrix B :",B)

print("Addition of A and B : ")
print(add(A,B))

print("substraction of A and B : ")
print(sub(A,B))

print("multiplication of A and B : ")
print(mul(A,B))

print("transpose of A : ")
print(trp(A))
