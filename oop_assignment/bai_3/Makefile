

# Biến cho trình biên dịch
CXX = g++
CXXFLAGS = -std=c++11 -Wall  # Thêm -mconsole để biên dịch dưới dạng ứng dụng console

# Tên tệp thực thi
TARGET_DIR = build
TARGET = $(TARGET_DIR)/my_program

# Điều kiện kiểm tra hệ điều hành
ifeq ($(OS),Windows_NT)
    RM = del /Q
    EXEC = $(TARGET)
    MKDIR = if not exist $(TARGET_DIR) mkdir $(TARGET_DIR)
else
    RM = rm -f
    EXEC = $(TARGET)
    MKDIR = mkdir -p $(TARGET_DIR)
endif

# Tìm tất cả các file .cpp trong thư mục src và tạo danh sách các file .o tương ứng trong $(TARGET_DIR)
SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp,$(TARGET_DIR)/%.o,$(SRCS))

# Quy tắc biên dịch
all: check_dir $(TARGET)
# Kiểm tra và tạo thư mục $(TARGET_DIR) nếu chưa tồn tại
check_dir:
	$(MKDIR)

# Biên dịch file thực thi từ các file .o
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Quy tắc biên dịch các file .cpp trong src thành .o trong $(TARGET_DIR)
$(TARGET_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Quy tắc chạy chương trình
run:
	$(EXEC)

# Quy tắc dọn dẹp
clean:
	$(RM) $(TARGET_DIR)\*.o $(TARGET_DIR)\*.exe
