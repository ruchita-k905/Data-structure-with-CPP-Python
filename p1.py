'''Python program to store marks scored in subject “Fundamental of Data Structure” by
N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency'''
#marks of fds computing avg absent high low score 
def avg_s(marks):
    count=0
    total=0
    for mark in marks :
        if mark!=-1:
            total=total+mark
            count+=1
    if count==0:
        return 0
    return total/count

def ab_students(marks):
    return marks.count(-1)

def high_low_score(marks):
    valid_m = [mark for mark in marks if mark!=-1]

    if len(valid_m)==0:
        return None,None
    
    high = max(valid_m)
    low = min(valid_m)
    return high,low

def high_fmarks(marks):
    frequency = {}
    for mark in marks :
        if mark != -1:
            if mark in frequency :
                frequency[mark] +=1
            else:
                frequency[mark]=1
    if len(frequency)==0:
        return None
    return max(frequency, key=frequency.get)

#driver code
marks = []
n = int(input("how many elements : "))
for i in range(0,n):
    x= int(input("Enter element:"))
    marks.append(x)
print("Marks  : ",marks)

avg=avg_s(marks)
print("Average score of class : ",avg)

absent=ab_students(marks)
print("Absent no of students : ",absent)

high,low=high_low_score(marks)
print("Highest score : ",high," ,Lowest score : ",low)

fmarks = high_fmarks(marks)
print("Marks with highest frequency : ",fmarks)
