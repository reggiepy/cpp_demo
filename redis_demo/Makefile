# 定义编译器和标志
CXX = g++
CXXFLAGS = -std=c++11 -I/root/vcpkg/installed/x64-linux/include
LDFLAGS = -L/root/vcpkg/installed/x64-linux/lib -ljsoncpp -lhiredis

# 定义目标文件
TARGET = main
SOURCES = main.cpp RedisHandler.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# 默认目标
all: $(TARGET)

# 编译源文件生成目标文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 链接目标文件生成可执行文件
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(TARGET)

# 清理目标文件和可执行文件
clean:
	rm -f $(OBJECTS) $(TARGET)

