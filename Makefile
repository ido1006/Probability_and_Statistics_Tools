all: standardDeviation hakohige regrressionLine

standardDeviation:
	g++ -Wall -o standardDeviation.out standardDeviation.cpp

hakohige:
	g++ -Wall -o hakohige.out hakohige.cpp

regressionLine:
	g++ -Wall -o regressionLine.out regressionLine.cpp

clean:
	-rm standardDeviation.out hakohige.out
