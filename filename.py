import sys

def format_string(input_string):
    number, title = input_string.split(". ", 1)
    formatted_title = title.lower().replace(" - ", "-").replace(" ", "-")
    
    output1 = f"{number}-{formatted_title}.cpp"
    output2 = f"\"solved #{number} - {title}\""
    
    return output1, output2

def main():
    if len(sys.argv) < 2:
        print("Error: Missing command-line argument(s).")
        print("Usage: python3 filename.py \"<problem_number>. <problem_name>\"")
        sys.exit(1)

    input_string = sys.argv[1]

    if ". " not in input_string:
        print("Error: Invalid command-line argument(s).")
        print("Usage: python3 filename.py \"<problem_number>. <problem_name>\"")
        sys.exit(1)    
    
    output1, output2 = format_string(input_string)

    print(output1)
    print(output2)

if __name__ == "__main__":
    main()
