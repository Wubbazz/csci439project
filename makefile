build:
	g++ -Wall -Wextra src/main.cpp src/tokenizer.cpp src/shape.cpp src/circle.cpp src/block.cpp -Iinclude -lSDL2 -o prog
run:
	./prog < testfiles/test.cb
clean:
	rm prog
