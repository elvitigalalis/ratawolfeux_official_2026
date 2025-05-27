#include "LogSystem.h"

#include <iostream>

LogPriority LogSystem::printPriorityLevel = LogPriority::TEST;

void LogSystem::logMessage(LogPriority logPriority,
                           const std::string logMessage) {
  if (static_cast<int>(logPriority) < static_cast<int>(printPriorityLevel))
    return;

  std::string prefixForLogMessage;
  switch (logPriority) {
    case LogPriority::TEST:
      prefixForLogMessage = "(Test)";
      break;
    case LogPriority::INFO:
      prefixForLogMessage = "(Information)";
      break;
    case LogPriority::WARNING:
      prefixForLogMessage = "(Warning)";
      break;
  }
  std::cout << prefixForLogMessage << logMessage << '\n';
}