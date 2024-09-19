# execute files
TARGET = my_program

# compiler
CXX = g++

# flag for compiler
CXXFLAGS = -Wall -g -std=c++11

# .cpp files
SRCS = main.cpp student.cpp vector.cpp

# list object files from code files
OBJS = $(SRCS:.cpp=.o)

# run when call make
all: $(TARGET)

# linking .o and create exe file
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# complie .o to .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

#run

run: $(TARGET)
	./$(TARGET)