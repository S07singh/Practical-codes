def selection_sort(arr):
    """Sort the array using selection sort algorithm."""
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def bubble_sort(arr):
    """Sort the array using bubble sort algorithm."""
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

def display_top_scores(arr, top_n):
    """Display the top N scores from the sorted array."""
    if top_n > len(arr):
        top_n = len(arr)
    print(f"Top {top_n} Scores:")
    for i in range(top_n):
        print(f"{i + 1}. {arr[i]}%")

def main():
    # Input the first-year percentage of students
    n = int(input("Enter the number of students: "))
    percentages = []
    for i in range(n):
        percentage = float(input(f"Enter the percentage for student {i + 1}: "))
        percentages.append(percentage)
    
    # Sorting using selection sort
    sorted_percentages_selection = percentages.copy()  # Create a copy to sort
    selection_sort(sorted_percentages_selection)
    print("Sorted array using Selection Sort:")
    display_top_scores(sorted_percentages_selection, 5)
    
    # Sorting using bubble sort
    sorted_percentages_bubble = percentages.copy()  # Create a copy to sort
    bubble_sort(sorted_percentages_bubble)
    print("\nSorted array using Bubble Sort:")
    display_top_scores(sorted_percentages_bubble, 5)

if __name__ == "__main__":
    main()

