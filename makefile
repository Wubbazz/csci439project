build:
	g++ -Wall -Wextra main.cpp tokenizer.cpp shape.cpp circle.cpp block.cpp -lSDL2 -o prog
run:
	./prog < test.cb
clean:
	rm prog
