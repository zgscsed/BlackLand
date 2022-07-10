/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年5月29日20:25:17
 * @Description: 重新将三方库的日志定义， 项目只需应用该文件即可使用日志库
 */

#ifndef LOG_HPP_
#define LOG_HPP_

#include <minlog/src/logger.hpp>
using namespace minlog;
namespace Abyss {

#define ABYSS_LOG_DEBUG minlog::Logger(__FILE__, __LINE__, minlog::Logger::DEBUG).Stream()
#define ABYSS_LOG_INFO minlog::Logger(__FILE__, __LINE__, minlog::Logger::INFO).Stream()
#define ABYSS_LOG_WARN minlog::Logger(__FILE__, __LINE__, minlog::Logger::WARN).Stream()
#define ABYSS_LOG_ERROR minlog::Logger(__FILE__, __LINE__, minlog::Logger::ERROR).Stream()
#define ABYSS_LOG_FAIL minlog::Logger(__FILE__, __LINE__, minlog::Logger::FAIL).Stream()
}
#endif // !LOG_HPP_

