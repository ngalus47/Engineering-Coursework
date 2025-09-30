#rock paper scissors. WHOOOOOOOOOO!

import random

print("- - - - - - - - - - Rock Paper Scissors - - - - - - - - - -")

playAgain = "yes"
choices = ["Rock", "Paper", "Scissors"]

while(playAgain == "yes"):
	compNum = random.randint(0, 2)
	comp = choices[compNum]
	player = int(input("\nRock[0], Paper[1], or Scissors[2]: "))

	if(player == compNum):
		print("\n\tWHATTTT! YOU TIED! You both chose", comp)
	elif(player == 0):
		if(comp == "Scissors"):
			print("\n\tYou win! WHOOOOOOO! Computer chose", comp)
		else:
			print("\n\tYou lose! BOOOOOOOO! Computer chose", comp)
	elif(player == 1):
		if(comp == "Rock"):
			print("\n\tYou win! WHOOOOOOO! Computer chose", comp)
		else:
			print("\n\tYou lose! BOOOOOOOO! Computer chose", comp)
	elif(player == 2):
		if(comp == "Paper"):
			print("\n\tYou win! WHOOOOOOO! Computer chose", comp)
		else: 
			print("\n\tYou lose! BOOOOOOOO! Computer chose", comp)
	else:
		print("\n\tERROR!")

	playAgain = str(input("\nDo you want to play again? (yes/no) "))

print("\nThanks for playing! Have a good day! :)")