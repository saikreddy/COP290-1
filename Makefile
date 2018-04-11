 
output: COP_1.o
	g++ COP_1.o -o output

COP_1.o: COP_1.cpp
	g++ -c COP_1.cpp

clean:
	rm *.o output
 