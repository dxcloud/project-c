CXX=g++
CFLAGS += -Wall -ansi -pedantic
CFLAGS += -DLOG_ENABLED

### SFML path
SFMLDIR:=/usr/local/lib
SFMLFLAGS += -L$(SFMLDIR)
SFMLFLAGS += -lsfml-graphics -lsfml-window -lsfml-system

EXEC=SaC2.out
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS) $(SFMLFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

%.d: %.cpp
	@set -e; rm -f $@; \
	 $(CXX) -MM $(CFLAGS) $< > $@.$$$$; \
	 sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	 rm -f $@.$$$$

-include $(SRC:.cpp=.d)

.PHONY: clean mrproper

clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf *.d $(EXEC)
