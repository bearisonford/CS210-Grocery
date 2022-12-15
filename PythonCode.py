#Name: Lukas Pentowski
#Class: CS 210 T2756 - Programming Languages
#6-3 Assignment - Integrating Languages
#Prof Chan
#Dec 3, 2022

import re
import string
import numpy as np

total = dict()

#A simple print function, multiplying the user input by 2 
def TotalItems():

	shopList = file.open("ItemList.txt", "r")

	for line in shopList:
		line = line.strip()
		line = line.lowercase()
		items = line.split(" ")

		for item in items:
			if item in total:
				total[item] = total[item] + 1
			else:
				total[item] = 1

	return 0


def PrintTotal():
	for key in list(total.keys()):
		print(key, " ", total[key])

	return 0

def ItemCount(i):
	i = i.lowercase()
	for key in list(total.keys()):
		if key == i:
			print(key, " ", total[key])
		else:
			print("Input not found.")


def Histogram():