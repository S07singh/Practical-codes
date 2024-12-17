# Initialize balance
balance = 0

def deposit(num):
    global balance
    balance += num
    print(f"Deposited {num}. New balance: {balance}")

def withdrawal(num):
    global balance
    if balance >= num:
        balance -= num
        print(f"Withdrew {num}. New balance: {balance}")
    else:
        print("Withdrawal not possible because balance is insufficient.")

while True:
    data = input("Please enter the transaction details (or type 'Exit' to end): ")
    if data.lower() == 'exit':
        break
    
    try:
        action, amount_str = data.split()
        amount = int(amount_str)
        if action.upper() == 'D':
            deposit(amount)
        elif action.upper() == 'W':
            withdrawal(amount)
        else:
            print("Invalid transaction type. Use 'D' for deposit and 'W' for withdrawal.")
    except ValueError:
        print("Invalid input format. Please enter in the format 'D amount' or 'W amount'.")

print("Final Balance =", balance)

