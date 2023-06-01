CFLAGS = -std=c++14 -Wall -pedantic 
LFLAGS = -std=c++14 -Wall -pedantic 
CO     = g++ 
LD     = $(CO)

NAME1  = main
NAME2  = serialport
NAME3  = analysis

OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
OBJS3  = $(NAME3).o

EXEC1  = $(NAME1).x

.PHONY: help
help:
	@echo "make all    		    Kompiluje wszystkie programy"
	@echo "make run-$(NAME1)  	Uruchamia program $(NAME1)"
	@echo "make clean       	Usuwa pliki *.o oraz *.x"
	
.PHONY: all 
all: $(EXEC1) 

$(EXEC1): $(OBJS1) $(OBJS2) $(OBJS3)
	$(LD) $(LFLAGS) -o $@ $^

%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<
	
.PHONY: run-$(EXEC1) 

run-$(NAME1): $(EXEC1)
	./$(EXEC1) 

.PHONY: clean
clean: 
	rm -f *.o *.x
