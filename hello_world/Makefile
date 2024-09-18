# Điều kiện kiểm tra hệ điều hành
ifeq ($(OS),Windows_NT)
    RM = del /Q
    EXEC = $(TARGET).exe
else
    RM = rm -f
    EXEC = $(TARGET)
endif

# Biến cho trình biên dịch
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Tên tệp thực thi
TARGET = helloworld_advanced

# Tìm tất cả các file .cpp trong thư mục và tạo danh sách các file .o tương ứng
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Quy tắc biên dịch
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Quy tắc biên dịch các file .cpp thành .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Quy tắc chạy chương trình
run:
	./$(EXEC)

# Quy tắc dọn dẹp
clean:
	$(RM) *.o $(EXEC)
