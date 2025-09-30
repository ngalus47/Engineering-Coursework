#You Won The Lottery
import random
import time
import replit

lotteryTickets = {100 : 0,
				  30 : 10,
				  25 : 100,
				  20 : 1_000,
				  15 : 2_500,
				  12 : 5_000,
				  10 : 15_000,
				  8 : 50_000,
				  5 : 150_000,
				  4 : 500_000,
				  3 : 1_000_000,
				  2 : 2_500_000,
				  1 : 10_000_000,
				  0 : 50_000_000}

houses = {"Cardboard Box" : 3, 
		  "Outdoor Play house" : 200,
		  "Small Appartment" : 1_000,
		  "Medium Appartment" : 2_500, 
		  "Large Appartment" : 5_000,
		  "Cheap Condo" : 10_000,
		  "Average Condo" : 25_000,
		  "Fancy Condo": 50_000,
		  "Small House" : 100_000,
		  "Medium House" : 200_000,
		  "Large House": 300_000,
		  "Small Mansion" : 1_000_000,
		  "Medium Mansion": [2_500_000], 
		  "Large Mansion" : [5_000_000],
		  "The Moon" : [1_000_000_000],
		  "The Earth" : [1_000_000_000_000]}

veichles = {"Cars" : {"Toy Car" : 1,
					  "Cheap Remote Control Car" : 15,
					  "Decent Remote Control Car" : 75,
					  "Fantastic Remote Control Car" : 200,
					  "Dirt Bike" : 500,
					  "Nice Motorcycle" : 1_000,
					  "Fast Motorcycle" : 1_500,
					  "Abused Car" : 2_000,
					  "Decently Used Car" : 6_000,
					  "Maintained Used Car" : 15_000,
					  "New Car" : 30_000,
					  "New SUV" : 40_000,
					  "New Truck" : 50_000,
					  "Classic Car" : 100_000,
					  "Sports Car" : 250_000,
					  "Luxury Car" : 300_000,
					  "Super Car" : 800_000,
					  "Hyper Car" : 1_500_000,
					  "Race Car" : 5_000_000,
					  "Flying Car" : 25_000_000,
					  "Space Car" : 75_000_000},
		    "Boat" : {"Rubber Ducky" : 1,
					  "Toy Boat" : 3,
					  }}

waitTime = 0.5

def NumCheck(num):
	while(not num.isnumeric):
		num = input("Please Enter A Valid Number: ")

	return num

def Lottery():
	winPercent = random.randint(0, 101)

	for i in lotteryTickets:
		if(i <= winPercent):
			amount = lotteryTickets[i]
			return amount


count = 1
gameOver = False

while(gameOver == False):
	money = Lottery()
	print(money)
	gameOver = True
else:
	playAgain = input("Would you like to play again? yes (1) or no (2): ")

	playAgain = NumCheck(playAgain)
	playAgain
	
	while(playAgain != 1):
			if(playAgain == 2):
				break
			
			else: 
				playAgain = input("Please enter 1 for yes or 2 for no: ")
		
	