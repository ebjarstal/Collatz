
# calculates Collatz sequence of given n and returns sequence list
def collatz(n: int) -> list:
    if n < 1:
        raise ValueError("Input must be greater or equal to 1")

    sequence = [n]  # creates sequence list, initialized with n
    cursor = n

    i = 1
    while cursor != 1:
        if cursor % 2 == 0:
            cursor //= 2
            sequence.append(cursor)
        else:
            cursor = 3*cursor + 1
            sequence.append(cursor)
        i += 1

    print(f"Number of steps: {i-1}")
    print("Sequence: ", end="")
    for j in range(i-1):
        print(f"{sequence[j]} -> ", end="")
    print(f"{sequence[i-1]}")

    return sequence


def main():
    user_number = int(input("Enter number: "))
    collatz(user_number)


if __name__ == "__main__":
    main()
