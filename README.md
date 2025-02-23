 we need to count the number of triplets (i, j, k) such that:

i < j < k
arr[j] - arr[i] == d
arr[k] - arr[j] == d
In other words, we want to find all triplets where the difference between consecutive elements is exactly d. This can be efficiently solved by iterating over the array while keeping track of how many times we've seen values that can form valid triplets.

Plan:
Iterate over the array: For each element arr[j], we need to find if there are valid arr[i] and arr[k] such that:

arr[j] - arr[i] == d
arr[k] - arr[j] == d
Count occurrences:

Maintain two hash maps (or counters):
count1: This keeps track of how many times a number arr[i] has been seen such that arr[j] - arr[i] = d.
count2: This keeps track of how many times a number arr[k] could potentially form a valid triplet with arr[j].
Traverse the array:

For each arr[j] (acting as the middle element of the triplet):
Check if arr[j] - d exists in count1 (indicating there is a potential arr[i] that can form a valid triplet).
Then check if arr[j] + d exists in count2 (indicating there is a potential arr[k] that can form a valid triplet).
Count the valid triplets as you iterate through the array.
