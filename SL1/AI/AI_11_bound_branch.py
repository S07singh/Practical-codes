def is_safe_backtracking(row, col, assignment):
    """Check if placing a queen is safe for backtracking."""
    for prev_row in range(row):
        prev_col = assignment[prev_row]
        if prev_col == col or abs(prev_col - col) == abs(prev_row - row):
            return False
    return True

def solve_n_queens_backtracking(n):
    """Backtracking approach."""
    assignment = [-1] * n
    solutions = []

    def backtrack(row):
        if row == n:
            solutions.append(assignment.copy())
            return
        for col in range(n):
            if is_safe_backtracking(row, col, assignment):
                assignment[row] = col
                backtrack(row + 1)
                assignment[row] = -1

    backtrack(0)
    return solutions



def solve_n_queens_branch_bound(n):
    """Branch & Bound approach."""
    solutions = []
    cols = [False] * n
    diag1 = [False] * (2 * n)
    diag2 = [False] * (2 * n)
    assignment = [-1] * n

    def backtrack(row):
        if row == n:
            solutions.append(assignment.copy())
            return
        for col in range(n):
            if not cols[col] and not diag1[row + col] and not diag2[row - col + n]:
                assignment[row] = col
                cols[col] = diag1[row + col] = diag2[row - col + n] = True
                backtrack(row + 1)
                cols[col] = diag1[row + col] = diag2[row - col + n] = False
                assignment[row] = -1

    backtrack(0)
    return solutions



def print_board(solution):
    n = len(solution)
    for row in solution:
        line = ['.'] * n
        line[row] = 'Q'
        print(' '.join(line))
    print()



if __name__ == "__main__":
    try:
        n = int(input("Enter number of queens (N): "))
        if n <= 0:
            print("N must be a positive integer.")
        else:
            print("\nChoose algorithm:")
            print("a) Backtracking")
            print("b) Branch and Bound")
            choice = input("Enter choice (a/b): ").strip().lower()

            if choice == 'a':
                solutions = solve_n_queens_backtracking(n)
                print(f"\n[Backtracking] Total solutions: {len(solutions)}")
            elif choice == 'b':
                solutions = solve_n_queens_branch_bound(n)
                print(f"\n[Branch & Bound] Total solutions: {len(solutions)}")
            else:
                print("Invalid choice!")
                exit()

            if solutions:
                print("\nExample solution:")
                print_board(solutions[0])
            else:
                print("No solution exists.")

    except ValueError:
        print("Please enter a valid integer.")
