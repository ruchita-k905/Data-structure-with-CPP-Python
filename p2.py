#computing string operations
def long(string):
    word = string.split()
    return max(word, key=len)

def frequency(string,char):
    return string.count(char)

def palindrome(str):
    cleanedstr = str.replace(" ","").lower()
    return cleanedstr==cleanedstr[::-1]

def iofsubstr(string,s):
    return string.find(s)

def word(string):
    words=string.split()
    w_frequencies = {}
    for w in words:
        w=w.lower()
        if w in w_frequencies:
            w_frequencies[w]+=1
        else:
            w_frequencies[w]=1
    return w_frequencies

#driver code
string = "Madam is walking madam in the evening in the park"
print("Original string : ",string)

longest = long(string)
print("longest word in string : ",longest)

char = "a"
f = frequency(string,char)
print("Frequency of char 'a' :", f)

if palindrome(string):
    print("string is palindrome ")
else:
    print("string is NOT palindrome ")

sub="walking"
index = iofsubstr(string,sub)
if index!=-1:
    print("first apperance of substring ",sub," is at index : ",index)
else:
    print("Substring NOT Found")

word_occurences = word(string)
print("Occurences of each word : ",word_occurences)
