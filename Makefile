CXX = g++
CXXFLAGS = -Wall -Werror -g -std=c++98 -pedantic
TARGET = oddjobs
SRCDIR = src
OBJS = $(SRCDIR)/main.o $(SRCDIR)/OddJobs.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/OddJobs.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TARGET)
	./$(TARGET)

memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

clean:
	rm -f $(SRCDIR)/*.o $(TARGET)

.PHONY: all test memcheck clean
