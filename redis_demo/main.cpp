#include "RedisHandler.h"
#include <iostream>

int main() {
    // 创建 RedisHandler 对象，连接到 Redis 服务器，设置密码（如果有）
    RedisHandler redisHandler("127.0.0.1", 6379, "yourpassword");

    // 连接 Redis 服务器，如果连接失败，则退出程序
    if (!redisHandler.connect()) {
        std::cerr << "Failed to connect to Redis server." << std::endl;
        return 1;  // 返回 1 表示错误
    }

    // 设置键值对
    if (redisHandler.set("key", "value")) {
        std::cout << "Key set successfully." << std::endl;
    }

    // 获取键值对
    std::string value = redisHandler.get("key");
    std::cout << "Key value: " << value << std::endl;

    return 0;  // 返回 0 表示成功
}

