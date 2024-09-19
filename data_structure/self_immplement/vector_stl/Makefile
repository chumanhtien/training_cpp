# Tên của tệp thực thi
TARGET = my_program

# Trình biên dịch
CXX = g++

# Cờ cho trình biên dịch
CXXFLAGS = -Wall -g -std=c++11

# Các tệp .cpp
SRCS = main.cpp Student.cpp vector.cpp

# Tạo ra danh sách các tệp .o tương ứng từ các tệp .cpp
OBJS = $(SRCS:.cpp=.o)

# Quy tắc biên dịch mặc định (khi gõ `make`)
all: $(TARGET)

# Quy tắc để tạo ra tệp thực thi từ các tệp đối tượng
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Quy tắc để tạo ra các tệp .o từ các tệp .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Quy tắc để dọn dẹp (xóa các tệp .o và tệp thực thi)
clean:
	rm -f $(OBJS) $(TARGET)

# Quy tắc để chạy chương trình
run: $(TARGET)
	./$(TARGET)
