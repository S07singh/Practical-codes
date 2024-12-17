def list_union(list1, list2):
    """ Returns the union of two lists without duplicates """
    result = []
    for student in list1:
        if student not in result:
            result.append(student)
    for student in list2:
        if student not in result:
            result.append(student)
    return result

def list_intersection(list1, list2):
    """ Returns the intersection of two lists (common elements) """
    result = []
    for student in list1:
        if student in list2 and student not in result:
            result.append(student)
    return result

def list_difference(list1, list2):
    """ Returns elements in list1 but not in list2 """
    result = []
    for student in list1:
        if student not in list2 and student not in result:
            result.append(student)
    return result

def list_symmetric_difference(list1, list2):
    """ Returns students who play either cricket or badminton but not both """
    return list_union(list_difference(list1, list2), list_difference(list2, list1))

def number_of_neither(cricket, badminton, football, all_students):
    """ Returns the number of students who play neither cricket nor badminton """
    all_played = list_union(cricket, badminton)
    neither_count = 0
    for student in all_students:
        if student not in all_played:
            neither_count += 1
    return neither_count

def number_of_cricket_and_football_not_badminton(cricket, football, badminton):
    """ Returns the number of students who play both cricket and football but not badminton """
    cricket_football = list_intersection(cricket, football)
    return len(list_difference(cricket_football, badminton))

# Example Data: You can modify this as per actual student data
cricket_players = ["Alice", "Bob", "Charlie", "David"]
badminton_players = ["Alice", "Eve", "Frank", "Bob"]
football_players = ["Charlie", "David", "Eve", "George"]
all_students = list_union(list_union(cricket_players, badminton_players), football_players)

# a) List of students who play both cricket and badminton
both_cricket_badminton = list_intersection(cricket_players, badminton_players)
print("Students who play both Cricket and Badminton:", both_cricket_badminton)

# b) List of students who play either cricket or badminton but not both
either_cricket_badminton_not_both = list_symmetric_difference(cricket_players, badminton_players)
print("Students who play either Cricket or Badminton but not both:", either_cricket_badminton_not_both)

# c) Number of students who play neither cricket nor badminton
neither_count = number_of_neither(cricket_players, badminton_players, football_players, all_students)
print("Number of students who play neither Cricket nor Badminton:", neither_count)

# d) Number of students who play cricket and football but not badminton
cricket_football_not_badminton = number_of_cricket_and_football_not_badminton(cricket_players, football_players, badminton_players)
print("Number of students who play Cricket and Football but not Badminton:", cricket_football_not_badminton)