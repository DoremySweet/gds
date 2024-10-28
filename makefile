obj = main.o

gds :$(obj)
	echo "hello"

main.o : 
	g++ -std=c++17 -c creator/main.cpp -o release/main.o

clean :
	rm release/*.ogit status
	