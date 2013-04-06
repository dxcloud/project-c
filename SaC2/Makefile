#
CXX=g++
CFLAGS += -W -Wall -ansi -pedantic
CDIR=
#LDFLAGS += -I/$()

EXEC=SaC2
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.d: %.cpp
	set -e; rm -f $@; \
	 $(CXX) -M $(CFLAGS) $< > $@.$$$$; \
	 sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	 rm -f $@.$$$$

include $(SRC:.cpp=.d)

#%.o: %.cpp
$(OBJ): $(SRC)
	$(CXX) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf $(EXEC)