CXX = g++
CXXFLAGS = -Wall -g -std=c++98 -pedantic
TARGET = renttracker
TEST_TARGET = test_runner

all: $(TARGET)

$(TARGET): src/main.o src/RentTracker.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) src/main.o src/RentTracker.o

test: tests/testMain.o src/RentTracker.o
	@echo "======================================"
	@echo "      RUNNING FUNCTIONALITY TESTS     "
	@echo "======================================"
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) tests/testMain.o src/RentTracker.o
	@./$(TEST_TARGET)

memcheck: tests/testMain.o src/RentTracker.o
	@echo "======================================"
	@echo "       CHECKING MEMORY MANAGEMENT     "
	@echo "======================================"
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) tests/testMain.o src/RentTracker.o
	@valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_TARGET) 2>&1 | grep -E "definitely lost|indirectly lost|ERROR SUMMARY" || true
	@echo ""
	@echo "SCORING:"
	@echo "- 0 bytes lost = 40/40 marks"
	@echo "- Any bytes lost = 0/40 marks"
	@echo "======================================"

grade: test memcheck
	@echo ""
	@echo "======================================"
	@echo "     COMPLETE GRADING SUMMARY         "
	@echo "======================================"
	@echo "Run 'make test' for functionality (60%)"
	@echo "Run 'make memcheck' for memory (40%)"
	@echo "======================================"

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

tests/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o tests/*.o $(TARGET) $(TEST_TARGET)

.PHONY: all test memcheck grade clean
