import array as arr

# Accept the % marks of the students
def accept_perc():
    a = arr.array('f', [])
    no_stud = int(input("Enter the number of Students: "))
    for i in range(no_stud):
        a.append(float(input("Enter the First Year % of Student[{0}]: ".format(i))))
    return a

# Print the % marks of the Students
def print_perc(a):
    for i in range(len(a)):
        print("\t{0:.2f}".format(a[i]), end=" ")
    print()

# Quick Sort Partition function
def partition(a, start, end):
    pivot = a[start]
    low = start + 1
    high = end
    while True:
        # Move high pointer to the left if element is greater than or equal to pivot
        while low <= high and a[high] >= pivot:
            high -= 1
        # Move low pointer to the right if element is less than or equal to pivot
        while low <= high and a[low] <= pivot:
            low += 1
        # Swap elements if pointers are not crossing
        if low <= high:
            a[low], a[high] = a[high], a[low]
        else:
            break
    # Swap pivot with high pointer element
    a[start], a[high] = a[high], a[start]
    return high

# Quick Sort function
def quick_sort(a, start, end):
    if start >= end:
        return a
    p = partition(a, start, end)
    quick_sort(a, start, p - 1)
    quick_sort(a, p + 1, end)
    return a

# Top 5 Scores
def top_five(a):
    print("Top five scores are:")
    cnt = len(a)
    if cnt < 5:
        start, stop = cnt - 1, -1
    else:
        start, stop = cnt - 1, cnt - 5
    for i in range(start, stop, -1):
        print("\t{0:.2f}".format(a[i]), end=" ")
    print()

# Driver program
if __name__ == "__main__":
    unsort_A = arr.array('f', [])
    quick_sort_A = arr.array('f', [])
    flag = 1
    while flag == 1:
        print("\n1. Accept array elements\n2. Display the Elements\n3. Quick Sort\n4. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            unsort_A = accept_perc()
        elif choice == 2:
            print_perc(unsort_A)
        elif choice == 3:
            print("Elements after sorting using Quick Sort:")
            quick_sort_A = quick_sort(unsort_A, 0, len(unsort_A) - 1)
            print_perc(quick_sort_A)
            top_five(quick_sort_A)
        elif choice == 4:
            print("Exiting program.")
            flag = 0
        else:
            print("Wrong choice. Please select a valid option.")

