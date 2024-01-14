# Word Tally
Display the frequency of words in a text stream.

## Introduction
I made this program after reading "The C Programming Language" by Brian Kernighan.
The main goal of this project was to practice using C and hashmaps.

Right now, the program uses a linked list to store each word and its frequency.
todo: convert the program to use a hashmap and measure the performance difference.

## Quick Start

	git clone https://github.com/mxilinas/word_tally
	cd word_tally
	make
	./countwords <test.txt
	
## Demo

	./countwords <test.txt

	In            1
	a             5
	quaint        1
	village       2
	nestled       1
	between       1
	rolling       1
	hills         1
	and           7
	babbling      1
	brooks        1
	the          12
	aroma         1
	of            7
	freshly       1
	baked         1
	bread         1
	wafted        1
	through       1
	air           2
