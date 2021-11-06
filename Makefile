CC = gcc
OBJS = my_sim.c my_draw.c my_entity.c my_food.c my_home.c

my_sim: $(OBJS) 
	$(CC) $^ -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib` -o $@ -Wall -Werror -Wextra
	$(CC) -g $^ -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib` -o my_sim.debug
clean:
	rm -f *.o

