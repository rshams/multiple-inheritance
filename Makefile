app: main.c
	make clean
	g++ main.c
	@echo "***************************\n"
	make run

clean:
	rm -rf *.o

run:
	./a.out
