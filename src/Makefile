GCC = gcc
CFLAGS = -g -Wall
TARGET = test

OBJECTS = $(patsubst %.c, %.o, $(notdir $(wildcard *.c)))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo -e "\033[1;33m\n$(OBJECTS) ==> $@ \033[0m..."
	$(GCC) -o $@ $^ $(CFLAGS) $(LIBS)
	@echo

%.o: %.c
	@echo -e "\033[1;33m\nCompiling $< ==> $@ \033[0m..."
	$(GCC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

.PHONY: clean
