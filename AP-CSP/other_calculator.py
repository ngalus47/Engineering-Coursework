print("- - - - - - - - - - Simple Calculator - - - - - - - - - -")

calclate = "yes"

while calclate == "yes":
	method = str(input("\nPress + for adding, - for subtracting, \n* for multiplying, or / for dividing: "))
	
	valueOne = int(input("\nInput the first value: "))
	valueTwo = int(input("\nInput the second value: "))

	answer = int(0)

	if method == "+":
		answer = valueOne + valueTwo
		print("\n\tEquals", answer)
	elif method == "-":
		answer = valueOne - valueTwo
		print("\n\tEquals", answer)
	elif method == "*":
		answer = valueOne * valueTwo
		print("\n\tEquals", answer)	
	elif method == "/":
		answer = valueOne / valueTwo
		print("\n\tEquals", answer)
	else:
		print('\n\tERROR!')

	calclate = str(input("\nDo you need to do another caculation (yes/no)?: "))

print("\nThank you for using my simple calculator!")