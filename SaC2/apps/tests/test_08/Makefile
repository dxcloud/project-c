
SAC2_PREFIX = ../../..
INCLUDE = -I$(SAC2_PREFIX)/include/utils -I$(SAC2_PREFIX)/include/types

CXX = g++
CXXFLAGS += -Wall -pedantic -std=c++11 -O2 $(INCLUDE)

EXEC = test_08

SFML_PATH          ?= $(SAC2_PATH)/libs/SFML-2.0
SFML_INCLUDES       = -I$(SFML_PATH)/include \
                      -isystem $(SFML_PATH)/include

SFML_FLAGS         += -L$(SFML_PATH)/lib \
                      -lsfml-graphics \
                      -lsfml-audio \
                      -lsfml-window \
                      -lsfml-system \
                      -Wl,-rpath,$(SFML_PATH)/lib

CXXFLAGS           += $(SFML_INCLUDES)

LDFLAGS            += $(SFML_FLAGS)

all: $(EXEC)

$(EXEC): test_08.o sac2_math.o sac2_vector2d.o
	$(CXX) -o $@ $^ $(LDFLAGS)

test_08.o: test_08.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

sac2_math.o: $(SAC2_PREFIX)/src/sac2_math.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

sac2_vector2d.o: $(SAC2_PREFIX)/src/sac2_vector2d.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	rm -rf *~ *.o $(EXEC)
