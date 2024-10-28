obj = main.o

creator :$(obj)
	g++ ./release/main.o -o ./release/creator.out

main.o : 
	g++ -I ./ -std=c++17 -c ./creator/main.cpp -o ./release/main.o

clean :
	rm ./release/*.o