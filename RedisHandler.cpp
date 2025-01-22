#include "RedisHandler.h"

// 构造函数初始化 RedisHandler 对象
RedisHandler::RedisHandler(const std::string& host, int port, const std::string& password)
    : host(host), port(port), password(password), c(nullptr) {}

// 析构函数：关闭 Redis 连接
RedisHandler::~RedisHandler() {
    if (c) {
        redisFree(c);  // 释放 Redis 连接
    }
}

// 连接到 Redis 服务器，进行身份验证（如果密码不为空）
bool RedisHandler::connect() {
    // 创建与 Redis 的连接
    c = redisConnect(host.c_str(), port);
    if (c == nullptr || c->err) {
        if (c) {
            std::cerr << "Error: " << c->errstr << std::endl;  // 输出连接错误信息
        } else {
            std::cerr << "Can't allocate Redis context" << std::endl;  // 内存分配失败
        }
        return false;
    }

    // 如果设置了密码，进行身份验证
    if (!password.empty()) {
        // 执行 AUTH 命令进行密码验证
        redisReply* reply = (redisReply*)redisCommand(c, "AUTH %s", password.c_str());
        if (reply->type == REDIS_REPLY_ERROR) {
            std::cerr << "Authentication failed: " << reply->str << std::endl;  // 输出认证失败信息
            freeReplyObject(reply);  // 释放 Redis 回复对象
            return false;
        }
        freeReplyObject(reply);  // 认证成功，释放回复对象
    }

    return true;  // 连接成功
}

// 设置 Redis 键值对
bool RedisHandler::set(const std::string& key, const std::string& value) {
    // 执行 SET 命令
    redisReply* reply = (redisReply*)redisCommand(c, "SET %s %s", key.c_str(), value.c_str());
    if (reply->type == REDIS_REPLY_ERROR) {
        std::cerr << "SET command failed: " << reply->str << std::endl;  // 设置失败，输出错误信息
        freeReplyObject(reply);  // 释放回复对象
        return false;
    }
    freeReplyObject(reply);  // 释放回复对象
    return true;  // 设置成功
}

// 获取 Redis 键值对
std::string RedisHandler::get(const std::string& key) {
    // 执行 GET 命令
    redisReply* reply = (redisReply*)redisCommand(c, "GET %s", key.c_str());
    if (reply->type == REDIS_REPLY_ERROR) {
        std::cerr << "GET command failed: " << reply->str << std::endl;  // 获取失败，输出错误信息
        freeReplyObject(reply);  // 释放回复对象
        return "";
    }
    std::string result = reply->str;  // 获取到的值
    freeReplyObject(reply);  // 释放回复对象
    return result;  // 返回获取到的值
}

