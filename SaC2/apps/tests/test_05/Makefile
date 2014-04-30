CXX        = g++
EXEC       = test_05

status_hpp = $(shell locate -l 1 SaC2/include/types/sac2_status_type.hpp)
status_cpp = $(shell locate -l 1 SaC2/src/sac2_status_type.cpp)
INCLUDE = $(shell dirname $(status_hpp))

CXXFLAGS   = -Wall -I$(INCLUDE) -pedantic -std=c++11

$(EXEC): status.o test_05.o
	$(CXX) $^ -o $(EXEC)

status.o: $(status_cpp) $(status_hpp)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test_05.o: test_05.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(EXEC) *~ *.o
