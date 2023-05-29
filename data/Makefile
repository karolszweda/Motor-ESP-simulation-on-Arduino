CFLAGS = -Wall -pedantic
LFLAGS = -Wall -pedantic
CO     = g++
LD     = $(CO)

NAME1  = main

OBJS1  = $(NAME1).o

EXEC1  = $(NAME1).x

option = serial

.PHONY: help
help:
	@echo "make all    		    Kompiluje wszystkie programy"
	@echo "make run-$(NAME1)  	Uruchamia program $(NAME1)"
	@echo "make clean       	Usuwa pliki *.o oraz *.x"
	
.PHONY: all 
all: $(EXEC1) 

$(EXEC1): $(OBJS1)
	$(LD) $(LFAGS) -o $@ $^

%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<
	
.PHONY: run-$(EXEC1) 

run-$(NAME1): $(EXEC1)
	./$(EXEC1) 

.PHONY: clean
clean: 
	rm *.o *.x
