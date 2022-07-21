chess:main.o chess.o
	gcc $^ -o $@ -g
%.o:%.c 
	gcc -c $<

.PHONY:run
run:
	./chess
.PHONY:clean
clean:
	del chess.exe *.o