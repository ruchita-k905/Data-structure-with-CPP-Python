#selection sort
def selection(m):
    n=len(m)
    for i in range (n):
        min=i
        for j in range(i+1,n):
            if m[min]>m[j]:
                min=j
        m[i],m[min]=m[min],m[i]

#driver
percentages=[56.9,90.4,80.0,65.8,44.3,76.3]
print("Original array :",percentages)

selection(percentages)
print("sorted array : ",percentages)

print("top 5 scores : ",percentages[-5:][::-1])
