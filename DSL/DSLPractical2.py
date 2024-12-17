# Function for average score of the class
def average(listofmarks):
    total = 0
    count = 0
    for mark in listofmarks:
        if mark != -999:
            total += mark
            count += 1
    if count > 0:
        avg = total / count
        print("Total Marks : ", total)
        print("Average Marks : {:.2f}".format(avg))
    else:
        print("No valid marks to calculate average.")

# Function for Highest score in the test for the class
def Maximum(listofmarks):
    max_score = None
    for mark in listofmarks:
        if mark != -999:
            if max_score is None or mark > max_score:
                max_score = mark
    return max_score

# Function for Lowest score in the test for the class
def Minimum(listofmarks):
    min_score = None
    for mark in listofmarks:
        if mark != -999:
            if min_score is None or mark < min_score:
                min_score = mark
    return min_score

# Function for counting the number of students absent for the test
def absentcount(listofmarks):
    count = 0
    for mark in listofmarks:
        if mark == -999:
            count += 1
    return count

# Function for displaying marks with highest frequency
def maxFrequency(listofmarks):
    frequency = {}
    for mark in listofmarks:
        if mark != -999:
            if mark in frequency:
                frequency[mark] += 1
            else:
                frequency[mark] = 1
    if frequency:
        max_freq = max(frequency.values())
        most_frequent_marks = [mark for mark, freq in frequency.items() if freq == max_freq]
        return most_frequent_marks, max_freq
    return [], 0

# Main function
marksinFDS = []
numberofstudents = int(input("Enter total number of students : "))
for i in range(numberofstudents):
    marks = int(input("Enter marks of student " + str(i + 1) + " : "))
    marksinFDS.append(marks)

flag = 1
while flag == 1:
    print("\n\n MENU \n")
    print("1. Total and Average Marks of the Class")
    print("2. Highest and Lowest Marks in the Class")
    print("3. Number of Students absent for the test")
    print("4. Marks with Highest Frequency")
    print("5. Exit\n")
    ch = int(input("Enter your Choice (from 1 to 5) : "))
    
    if ch == 1:
        average(marksinFDS)
    elif ch == 2:
        print("Highest Score in Class : ", Maximum(marksinFDS))
        print("Lowest Score in Class : ", Minimum(marksinFDS))
    elif ch == 3:
        print("Number of Students absent for the test : ", absentcount(marksinFDS))
    elif ch == 4:
        marks, fr = maxFrequency(marksinFDS)
        if marks:
            print("Marks with highest frequency are:", marks)
            print("Frequency:", fr)
        else:
            print("No valid marks to calculate frequency.")
    elif ch == 5:
        flag = 0
        print("Thanks for using this program!")
    else:
        print("!!Wrong Choice!!")

    if ch != 5:
        a = input("Do you want to continue (yes/no) : ")
        if a.lower() == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")

