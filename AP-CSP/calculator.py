#Calculator

characters = []
userInput = input("Please enter a Calculation")

def IndexCheck(index):
	print(index)
	if(index <= 0 and characters[index] != '-'):
		print("error")

def Add(currentCount):
	IndexCheck(currentCount)

	result = int(characters[currentCount - 1]) + int(characters[currentCount + 1])
	characters[currentCount] = result

	characters.pop(currentCount + 1)
	characters.pop(currentCount - 1)


def Substract(currentCount):
	print("subtract")

def Multiply(currentCount):
	print("multiply")

def Divide(currentCount):
	print("divide")

def Sorter():
	numCount = 0
	count = 0
	for character in userInput:
		print(count)
		if(character.isnumeric()):
			if(numCount >= 1):
				characters[count - 1] += character
			else:
				characters.append(character)
				
			numCount += 1
			
		elif(not character.isnumeric()):
			characters.append(character)
			numCount = 0

		print(characters)
		count += 1
	return characters

def Calculate():
	while(len(characters) != 1):
		count = 0		
		for index in characters:
			if(index == '*'):
				Multiply(count)
			elif(index == '/'):
				Divide(count)
			elif(index == '+'):
				Add(count)
			elif(index == '-'):
				Substract(count)
			else:
				print(characters[count], "is not a valid input")
				
			count += 1

while(userInput != 'done'):
	characters = Sorter()
	print(characters)

	Calculate()
	print(characters)
	characters.clear()

	userInput = input("Do you need to enter another calculation?")
	