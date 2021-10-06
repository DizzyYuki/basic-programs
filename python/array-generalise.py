# Ramesh is given  a task to generalise the array. 
# An array is called generalise if median of that array is equal to sum ‘k’.
# Ramesh has less knowledge amongst median so he decided to take help from you.
# Your task is to count the number of elements that you must add to the median of given array equal to a number ‘k’.

# Input Description:
# First line contains a number ‘n’.next line contains n space separated numbers.next line contains a number ‘k’

# Output Description:
# Print the count required in order to make the median of array equal to k

# Sample Input :
# 6 
# 10 20 30 100 150 200
# 30
# Sample Output :
# 1

# Solution

import statistics as st

occurances = int(input())
l1 = list(map(int,input().split()))
k = int(input())

if k in l1 and int(st.median(l1)) not in l1:
    print('1')
else:
    print(occurances-1)
