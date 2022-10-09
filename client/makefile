all:
	g++ -c src/main.cpp	-o build/obj/main.o
	g++ build/obj/main.o -o build/main -std=c++17 -lsfml-network

clean:
	find build -maxdepth 1 -type f -delete
	rm -f build/obj/*