standardDeviation:
	g++ -Wall -o standardDeviation.out standardDeviation.cpp

hakohige:
	g++ -Wall -o hakohige.out hakohige.cpp

clean:
	-rm standardDeviation.out hakohige.out
