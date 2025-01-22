#ifndef REDISHANDLER_H
#define REDISHANDLER_H

#include <hiredis/hiredis.h>
#include <string>
#include <iostream>

// RedisHandler 类用于封装 Redis 操作
class RedisHandler {
public:
    // 构造函数：host 是 Redis 服务器地址，port 是端口，password 是连接密码（可选）
    RedisHandler(const std::string& host, int port, const std::string& password = "");

    // 析构函数：释放 Redis 连接
    ~RedisHandler();

    // 连接到 Redis 服务器并进行身份验证（如果需要）
    bool connect();

    // 设置 Redis 键值对
    bool set(const std::string& key, const std::string& value);

    // 获取 Redis 键值对
    std::string get(const std::string& key);

private:
    redisContext *c;    // Redis 连接对象
    std::string host;    // Redis 服务器地址
    int port;            // Redis 服务器端口
    std::string password;  // Redis 连接密码
};

#endif

