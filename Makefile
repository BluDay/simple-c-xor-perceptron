# ( 0 _ o )

all:
	gcc -Wall -l m src/main.c -o bin/xor_perceptron

	chmod 755 bin/xor_perceptron
