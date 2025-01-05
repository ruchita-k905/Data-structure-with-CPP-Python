def ternary_search(members, roll, left, right):
    if right >= left:
        # Calculate mid1 and mid2 for dividing the range into three parts
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3

        # Check if roll matches any of the mid points
        if members[mid1] == roll:
            return True
        if members[mid2] == roll:
            return True

        # Recursively search in the appropriate segment
        if roll < members[mid1]:
            return ternary_search(members, roll, left, mid1 - 1)
        elif roll > members[mid2]:
            return ternary_search(members, roll, mid2 + 1, right)
        else:
            return ternary_search(members, roll, mid1 + 1, mid2 - 1)

    # Roll number not found
    return False

# Driver code
members = [104, 103, 102, 101, 105]
print("Original list of club members [roll]:", members)

members.sort()
print("Sorted list of club members [roll]:", members)

key = int(input("Enter roll no to search: "))

if ternary_search(members, key, 0, len(members) - 1):
    print("Roll no", key, "is a member of the club.")
else:
    print("Roll no", key, "is NOT a member of the club.")
