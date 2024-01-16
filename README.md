# Word Tally
Display the frequency of words in a text stream.

## Introduction
I made this program after reading "The C Programming Language" by Brian Kernighan.
This project is part of a larger series about exploring data structures in C.

## The Algorithm

### The Naive Approach
> Depends on a list of tallies.
> Performs a linear search at each word in the text.
1. Read a word
2. Look through the list of tallies.
	- If there is a tally for the word, increment it by one.
	- Else create a new tally for that word.

### The Solution
> Depends on a dictionary.
> Lookups happen in constant time (on average)
1. Read a word.
2. Look it up in the dictionary.
	- If there is an entry for that word, increment its tally by one.
	- Else create a new entry for that word.

## Quick Start

	git clone https://github.com/mxilinas/word_tally
	cd word_tally
	make
	wget https://www.gutenberg.org/cache/epub/100/pg100.txt
	./countwords <pg100.txt
	
## Demo

	./countwords <pg100.txt

	sword               366
	healthy               2
	swore                55
	Argued                2
	threatening           5
	hither              305
	commenting            2
	sworn               138
	conclude             28
	...
