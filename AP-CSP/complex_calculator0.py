#complex calculator

print("- - - - - - - - - - Complex Calculator - - - - - - - - - -")

calclate = "yes"

while calclate == "yes":
	method = str(input("\nPress + for adding, - for subtracting, \n* for multiplying, or / for dividing: "))
	
	values = int(input("\nHow many values do you have?: "))
	counter = int(1) 
	variable = int()
	numbers = []

	while (counter <= values):
		varablie = int(input("Input value: "))

		numbers.append(varablie)

		counter += 1

	answer = int()

	if method == "+":
		for i in range(0, values):
			answer += numbers[i]		

		print("\n\tEquals", answer)
	elif method == "-":
		for i in range(0, values):
			answer -= numbers[i]		

		print("\n\tEquals", answer)
	elif method == "*":
		for i in range(0, values):
			answer *= numbers[i]		

		print("\n\tEquals", answer)
	elif method == "/":
		for i in range(0, values):
			answer /= numbers[i]		

		print("\n\tEquals", answer)
	else:
		print('\n\tERROR!')

	calclate = str(input("\nDo you need to do another caculation (yes/no)?: "))

print("\nThank you for using my complex calculator!")