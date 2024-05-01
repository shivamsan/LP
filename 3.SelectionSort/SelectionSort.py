def selection_sort(a):
    for i in range (len(a) - 1):
        min_index =1
        for j in range(i, len(a)):
            if a[min_index] > a[j]:
                min_index = j
        
        a[i], a[min_index] = a[min_index], a[i]

        #print(a)

a=[7,4,7,2,4,5,72,9,2,5]

print("Unsorted array: ",a)
selection_sort(a)
print("Sorted array: ",a)
        