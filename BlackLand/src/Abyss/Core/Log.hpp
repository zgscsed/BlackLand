/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @Author: zgscsed
 * @Date: 2022年5月29日20:25:17
 * @Description: 重新将三方库的日志定义， 项目只需应用该文件即可使用日志库
 */

#ifndef LOG_HPP_
#define LOG_HPP_

#include <minlog/src/logger.hpp>

namespace Abyss {
#define ABYSS_LOG_DEBUG LOG_DEBUG 
#define ABYSS_LOG_INFO LOG_INFO
#define ABYSS_LOG_WARN LOG_WARN
#define ABYSS_LOG_ERROR LOG_ERROR
}
#endif // !LOG_HPP_

