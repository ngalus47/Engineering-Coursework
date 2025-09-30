#Functions
print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Functions ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")

#Prompts user for inputs
firstNumber = int(input("\nPlease enter a number: ")) # here a global variable is defined we can modify it at any point of the program
secondNumber = int(input("Please enter a second number: "))

#Code without a function
print("\nCode without function")

#Finds all solutions with the two numbers
add = firstNumber + secondNumber
subtract = firstNumber - secondNumber
multiply = firstNumber * secondNumber
divide = firstNumber / secondNumber

#Code with function
print("\nCode with functions")

#Functions without paramaters
def addFunction():
	solution = firstNumber + secondNumber #local variable declared within the function
	add = solution
	return add

def subtractFunction():
	solution = firstNumber - secondNumber
	subtract = solution
	return subtract

def display():
	print("\t*\tAdding the two numbers equals", add) 
	print("\t*\tSubtracting the two numbers equals", subtract) 
	print("\t*\tMultiplying the two numbers equals", multiply) 
	print("\t*\tDividing the two numbers equals", divide) 

display()
#Functions with paramaters
def multiplyFunction(num1, num2): #num1 and num2 are local variables too, but are defined when you declare the function's paramaters and allow for you to input those values anytime when you call the function like on lines 62 and 63
	solution = num1 * num2 #on line 44 we define two new variable, but their local because they are paramaters of the function. They are also local because we can only modify it within the function, no where else
	multiply = solution
	return multiply

#if I where to try and modify num1 for example here outside of the function there would be an error, well a logical error since num1 with in the function will stay the same
num1 = 10 #but this new num1 will get the value of 10 and is now a global variable

def divideFunction(num1, num2):
	solution = num1 / num2
	divide = solution
	return divide

#Calling the functions without paramaters
add = addFunction()
subtract = subtractFunction()

#Calling the functions with paramaters
multiply = multiplyFunction(firstNumber, secondNumber) #here we make num1 = firstNumber and use a comma to separate the two integars and set num2 = secondNumber
divide = divideFunction(firstNumber, secondNumber)

#Prints the list nicely
print("\nNice print")
display()