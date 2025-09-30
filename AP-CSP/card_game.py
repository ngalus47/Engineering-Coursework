# AP CSP Performance Task 
#high card game

#The purpose of this is to express my creative expression by creating a game to entertain the user.

#Used the random library to draw random cards
import random 
#used the replit library to clear the console within replit
import replit 
#used the time library to add a delay between each print to the console
import time 

#deal cards to user and computer
def dealCards():
	cardValue = random.randint(0, len(cards) - 1)
	return cardValue

#Logic whether user wins, loses, or ties
def gameLogic(computer, user, score):
	#if the user ties with the computer
	while(user == computer):
		time.sleep(waitTime)
		print(FONT_NORMAL + "\nWHAT! You tied, time for war...")
		time.sleep(waitTime)
		input(FONT_NORMAL + "\nPress enter to continue...")
		replit.clear()
		
		score = tieLogic(score, 1)
		return score

	#if the user doesn't tie with the computer
	else:
		#if the user has a higher value card they win
		if(user > computer):
			time.sleep(waitTime)
			print(FONT_NORMAL + "\nNice You Win!")
			score += 10
			return score
	
		#if the user has a lower card value they'll lose
		elif(user < computer):
			time.sleep(waitTime)
			print(FONT_NORMAL + "\nSorry, you lose.")
			score -= 5
			return score
	
		#if an error were to ever occur
		else:
			print(FONT_BR_RED + "\nERROR!")



	
#logic if the user ties with the computer
def tieLogic(score, tieCount):
	computerCard = dealCards()
	userCard = dealCards()

	#sub title to separate a tie
	print(" ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Tie", tieCount, "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")

	displayCards(computerCard, userCard)

	#if the user ties with the computer
	while(userCard == computerCard):
		time.sleep(waitTime)
		print(FONT_NORMAL + "\nWHAT! You tied again, the war continues...")
		tieCount += 1

		time.sleep(waitTime)
		input(FONT_NORMAL + "\nPress enter to continue...")
		replit.clear()
		return tieLogic(score, tieCount)

	else:
		#if the user has a higher card value they win the tie
		if(userCard > computerCard):
			time.sleep(waitTime)
			print(FONT_NORMAL + "\nNice! You won the war!")
			score += 20 * tieCount
			return score
	
		#if the user has a lwoer card value they lose the tie
		elif(userCard < computerCard):
			time.sleep(waitTime)
			print(FONT_NORMAL + "\nSorry, you lost the war.")
			score -= 10 * tieCount
			return score

		#if an error were to ever occur
		else:
			print(FONT_BR_RED + "\nERROR!")

	tieCount = 0

#displays the cards to the user nicely
def displayCards(computerCard, userCard):
	time.sleep(waitTime)
	print(FONT_NORMAL + "\n\t○\tThe computer's card:", 
		random.choice(cardSuits), cards[computerCard])
	
	time.sleep(waitTime)
	print(FONT_NORMAL + "\t○\t\t\t  Your card:", 
		random.choice(cardSuits), cards[userCard])

#text colors
FONT_NORMAL = chr(27)+"[0;0m"
FONT_BR_BLUE = chr(27)+"[1;34m"
FONT_BR_RED = chr(27)+"[1;31m"

#Card suit color coded
cardSuits = [FONT_BR_BLUE + '♤', FONT_BR_RED + '♡',
	FONT_BR_BLUE + '♧', FONT_BR_RED + '♢']

#Card values
cards = ['Two', 'Three', 'Four', 'Five', 'Six',
	'Seven', 'Eight', 'Nine', 'Ten', 'Jack',
	'Queen', 'King', 'Ace']

userInput = '1'
waitTime = 0.75
		
#title
print("♤ ♡ ♧ ♢ ♤ ♡ ♧ ♢ ♤ ♡ ♧ ♢ High Card ♤ ♡ ♧ ♢ ♤ ♡ ♧ ♢ ♤ ♡ ♧ ♢")

#rules
print("\nRules: The aim of the game is to have the higher card\n\t   value with two being the lowest and ace being \n\t   the highest. If there's a tie, you'll then go \n\t   to war, where you'll be able to win or lose \n\t   double the points. There will be a total of ten\n\t   rounds, and at the end, you'll get your score.")

#pause in code
time.sleep(5)
input(FONT_NORMAL + "\nPress enter to continue...")
replit.clear()

#begins while loop/game process
while(userInput == '1'):
	replit.clear()
	count = 1 #reset the current round the user is on
	score = 0 #reset the score

	#while loop for game logic and display for 10 rounds
	while(count <= 10):
		#seperate each round
		print(" ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Round", count, "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")

		#deal the cards to the user and computer
		computerCard = dealCards()
		userCard = dealCards()

		#displays the user's and computer's cards
		displayCards(computerCard, userCard)

		#calculates who wins and the user's score
		score = gameLogic(computerCard, userCard, score)

		#At the end of each round the user will be prompted to press enter to continue and it will clear the consol and increase the round counter
		time.sleep(waitTime)
		input(FONT_NORMAL + "\nPress enter to continue...")
		replit.clear()
		count += 1

	#after 10 rounds the user will get their results
	print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Results ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
	print("\nYour socre:", score, "points") #prints the user's score

	time.sleep(waitTime)
	userInput = input(FONT_NORMAL + "\nWould you like to play another game? yes(1) or no(2): ") #prompts the user if they'd want to play again

	#checks to make sure that it's a valid input
	while(userInput != '1'):
		if(userInput == '2'):
			break
		
		else: #if userInput is not valid it will reprompt the user
			userInput = input(FONT_NORMAL + "Please enter 1 for yes or 2 for no: ")

#end statement
print("\nThank you for playing high card!")