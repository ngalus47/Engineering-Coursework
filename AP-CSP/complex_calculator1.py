# Python program for simple calculator

numbers = []

# Function to add two numbers
def add(numbers):
	return sum(numbers)

# Function to subtract two numbers
def subtract(numbers):
	result = 1

	for i in numbers:
		result = result - i
	
	return result

# Function to multiply two numbers
def multiply(numbers):
	result = 1
    
	for i in numbers:
         result = result * i
    
	return result

# Function to divide two numbers
def divide(numbers):
	result = 1
    
	for i in numbers:
         result = result / i
    
	return result

print("Please select operation -\n" \
		"1. Add\n" \
		"2. Subtract\n" \
		"3. Multiply\n" \
		"4. Divide\n")


# Take input from the user
select = int(input("Select operations form 1, 2, 3, 4 :"))

numbers = int(input())
if select == 1:
	print(number_1, "+", number_2, "=",
					add(number_1, number_2))

elif select == 2:
	print(number_1, "-", number_2, "=",
					subtract(number_1, number_2))

elif select == 3:
	print(number_1, "*", number_2, "=",
					multiply(number_1, number_2))

elif select == 4:
	print(number_1, "/", number_2, "=",
					divide(number_1, number_2))
else:
	print("Invalid input")
