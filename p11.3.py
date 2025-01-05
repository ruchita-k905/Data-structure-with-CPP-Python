def quick_sort(arr):
    if len(arr)<=1:
        return arr
    else:
        pivot=arr[len(arr)//2]
        left=[x for x in arr if x<pivot]
        midd=[x for x in arr if x==pivot]
        right=[x for x in arr if x>pivot]

    return quick_sort(left)+midd+quick_sort(right)

#driver code
percentage=[40.2,12.3,23.5,85.0,62.3,78.5,98.7]
print("Original array")
print(percentage)
percentage = quick_sort(percentage)
print("\n Sorted array")
print(percentage)
print("Top five scores :",percentage[-5:][::-1])

