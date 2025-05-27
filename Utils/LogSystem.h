#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include <sstream>
#include <string>

enum class LogPriority { TEST, INFO, WARNING };

class LogSystem {
 public:
  LogSystem();
  ~LogSystem();

  static void logMessage(LogPriority logPriority, const std::string logMessage);

 private:
  static LogPriority printPriorityLevel;
};

#define LOG_TEST(logMsg)                                         \
  {                                                                  \
    std::ostringstream logStringStream;                              \
    logStringStream << logMsg;                                   \
    LogSystem::logMessage(LogPriority::TEST, logStringStream.str()); \
  }

#define LOG_INFO(logMsg)                                         \
  {                                                                  \
    std::ostringstream logStringStream;                              \
    logStringStream << logMsg;                                   \
    LogSystem::logMessage(LogPriority::INFO, logStringStream.str()); \
  }

#define LOG_WARNING(logMsg)                                      \
  {                                                                  \
    std::ostringstream logStringStream;                              \
    logStringStream << logMsg;                                   \
    LogSystem::logMessage(LogPriority::TEST, logStringStream.str()); \
  }

#endif