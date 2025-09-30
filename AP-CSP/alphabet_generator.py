#https://replit.com/@Interlink/trial-and-error-counting?v=1#main.py
import random
import time

answer = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
	"K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", 
	"V", "W", "X", "Y", "Z"]

guess = []
tries = 0

viewProgress = bool()

def AssignChr():
	return random.choice(answer)

def NumCheck(num):
	print(num)
	while (not num.isnumeric()) :
		num = input("Enter a VALID number: ")
	else :
		return num

def ProgressCheck(inputCheck):
	print(inputCheck)
	if(int(inputCheck) == 1):
		viewProgress = True
		print(viewProgress)
		return viewProgress

	elif(int(inputCheck) == 2):
		viewProgress = False
		print(viewProgress)
		return viewProgress

	else:
		Error()

def Error():
	userInput = input("Please enter (1) to view progress or (2) to not view the progress: ")

	userInput = NumCheck(userInput)
	ProgressCheck(userInput)

print("Title")

userInput = input("\nEnter (1) to view progress or (2) to not view the progress: ")
userInput = NumCheck(userInput)

viewProgress = ProgressCheck(userInput)
print(viewProgress)

while(len(guess) < 26):
	guess.append(AssignChr())

while(guess != answer):
	if(viewProgress == True):
		print(guess)
	elif(viewProgress == False):
		if(tries == 0):
			print("Loading")
		elif(tries%20 == 0):
			print(".")

	time.sleep(0.2)

	for i in range(len(answer)):
		if(answer[i] != guess[i]):
			guess[i] = AssignChr()

	tries += 1

print("\nlearned in", tries, "tries")