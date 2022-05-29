/*
 * Copyright (C) 2022 zgscsed. All rights reserved.
 * @filename: test_log.cpp
 * @Author: zgscsed
 * @Date: 2022-03-20 20:55:02
 * @LastEditors: zgscsed
 * @LastEditTime: 2022-04-14 21:50:38
 * @Description: main函数
 */

/*
架构设计：
    日志写入采用流的方式
    支持同步异步写入
    支持写入文件，控制台

    logfile类    日志写入
    logappend类  实际写入
    logger类     日志的时间进程等参数


*/

#include <iostream>

#include "../src/logger.hpp"
int main(void)
{
    std::cout << "hello log..."<<std::endl;
    std::string line = "sfsf";
    LOG_INFO << line;
    return 0;
}
