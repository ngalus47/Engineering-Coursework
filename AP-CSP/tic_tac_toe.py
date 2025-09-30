import replit
import time

currentBoard = {'A1' : ' ', 'B1' : ' ', 'C1' : ' ',
			    'A2' : ' ', 'B2' : ' ', 'C2' : ' ',
			    'A3' : ' ', 'B3' : ' ', 'C3' : ' '}

turn = 0
waitTime = 0.75

playAgain = True
gameOver = False

piece = 'X'

def Start():
	global currentBoard
	global turn
	global gameOver
	
	gameOver = False
	turn = 0

	for i in currentBoard:
		currentBoard[i] = ' '

def Gameloop():
	global piece
	global turn

	GamePiece()	
	location = LocationInput()

	while(currentBoard[location] != ' '):
		print("\n\tSPACE IS TAKEN")
		location = LocationInput()
		
	else:
		currentBoard[location] = piece
		replit.clear()
		BoardDisplay()
		
	if(turn >= 4):
		global gameOver
		WinCheck()

def LocationInput():
	userInput = InputCheck(str(input("\nEnter the location to place " + piece + ': ')))
	return userInput
	
def BoardDisplay():
	print(" # # # # # Tic-Tac-Toe # # # # #")
	print("\n\t\t\t A\t B\t C")
	print("\t\t  +" + "-" * 12)
	print("\t\t1 |  " + currentBoard['A1'] + ' | ' + currentBoard['B1'] + ' | ' + currentBoard['C1'])
	print("\t\t  | " + "---+" * 2 + "---")
	print("\t\t2 |  " + currentBoard['A2'] + ' | ' + currentBoard['B2'] + ' | ' + currentBoard['C2'])
	print("\t\t  | " + "---+" * 2 + "---")
	print("\t\t3 |  " + currentBoard['A3'] + ' | ' + currentBoard['B3'] + ' | ' + currentBoard['C3'])
	
def GamePiece():
	global piece 
	
	if(turn % 2 == 0):
		piece = "X".upper()
	else:
		piece = "O".upper()

def InputCheck(check):
	for i in currentBoard.keys():
		if(i == check.upper()):
			return check.upper()

	userInput = input("\nPlease enter a VALID input: ")
	InputCheck(userInput)
	return userInput.upper()

def NumCheck(num):
	while(not num.isnumeric() or int(num) != 1 and int(num) != 2):
		num = input("Please enter 1 for yes or 2 for no: ")
	else:
		return num

def WinCheck():
	global turn
	
	if(currentBoard['A1'] == currentBoard['A2'] == currentBoard['A3'] != ' '):
		WinDisplay()
		
	elif(currentBoard['B1'] == currentBoard['B2'] == currentBoard['B3'] != ' '):
		WinDisplay()
		
	elif(currentBoard['C1'] == currentBoard['C2'] == currentBoard['C3'] != ' '):
		WinDisplay()
		
	elif(currentBoard['A1'] == currentBoard['B2'] == currentBoard['C3'] != ' '):
		WinDisplay()
		
	elif(currentBoard['C1'] == currentBoard['B2'] == currentBoard['A3'] != ' '):
		WinDisplay()
		
	elif(currentBoard['A1'] == currentBoard['B1'] == currentBoard['C1'] != ' '):
		WinDisplay()
		
	elif(currentBoard['A2'] == currentBoard['B2'] == currentBoard['C2'] != ' '):
		WinDisplay()
		
	elif(currentBoard['A3'] == currentBoard['B3'] == currentBoard['C3'] != ' '):
		WinDisplay()

	elif(turn == 8):
		print("\n\tNo one won. It's a tie.")			

def WinDisplay():
	global piece
	global gameOver

	print("\n\tPlayer " + piece + " Won! Good Job!")
	gameOver = True

print(" # # # # # Tic-Tac-Toe # # # # #")
print("\nObjective: Get three pieces in a \n\t\t   row either vertically, \n\t\t   horizontally, or \n\t\t   diagonally to win.")

time.sleep(waitTime)
input("\nPress ENTER to continue... ")

while(playAgain == True):
	replit.clear()
	BoardDisplay()
	
	while(turn != 9 and gameOver != True):
		Gameloop()

		turn += 1

	else:
		time.sleep(waitTime)
	
		userInput = input("\nWould you like to play again? \n\t   1 for yes or 2 for no: ")
		userInput = NumCheck(userInput)
	
		if(int(userInput) == 1):
			Start()
		elif(int(userInput) == 2):
			playAgain = False
		else:
			print('error')
		
print("\nThanks for playing!")