#ifndef LOGGER_H
#define LOGGER_H

enum LOG_SEVERITY {
  BOOT,
  CONSOLE,
  DEBUG,
  INFO,
  WARN,
  ERROR,
  CRITICAL,
  SEVERE,
  FATAL
};

void logMessage(LOG_SEVERITY severity, String message);

#endif