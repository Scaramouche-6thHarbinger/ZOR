#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdio.h>
#include <stdlib.h>

/* enabling a log level with a higher value also enables all log levels below it...
 LOG_NONE is supposed to be run in prod
 LOG_VERBOSE is for messages that arent required
 LOG_DEBUG is for messages that include info about variables that are passed around etc..
 LOG_INFO is for day-to-day actions the server does (this is your usual DEBUG)
 LOG_WARNING is for non-crucial failed tasks, errors in conversions, casts etc...
 LOG_ERROR is for failed tasks, like sending a packet that failed
 LOG_FATAL is for gamebreaking bugs that require a complete halt of the application
*/
typedef enum {
    LOG_VERBOSE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL,
    LOG_NONE, // idk why XD
} log_status;

#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_DEBUG
#endif

#define _LOGF(fmt, ...) \
        do { if (LOG_LEVEL <= LOG_FATAL) fprintf(stderr, "[FATAL]    %s:%d:%s(): " fmt "\n%s", __FILE__, \
                                __LINE__, __func__, __VA_ARGS__); exit(-1); } while (0)
#define LOGF(...) _LOGF(__VA_ARGS__, "")

#define _LOGE(fmt, ...) \
        do { if (LOG_LEVEL <= LOG_ERROR) fprintf(stderr, "[ERROR]    %s:%d:%s(): " fmt "\n%s", __FILE__, \
                                __LINE__, __func__, __VA_ARGS__); } while (0)
#define LOGE(...) _LOGE(__VA_ARGS__, "")

#define _LOGW(fmt, ...) \
        do { if (LOG_LEVEL <= LOG_WARNING) fprintf(stderr, "[WARNING]  %s:%d:%s(): " fmt "\n%s", __FILE__, \
                                __LINE__, __func__, __VA_ARGS__); } while (0)
#define LOGW(...) _LOGW(__VA_ARGS__, "")

#define _LOGI(fmt, ...) \
        do { if (LOG_LEVEL <= LOG_INFO) fprintf(stderr, "[INFO]     %s:%d:%s(): " fmt "\n%s", __FILE__, \
                                __LINE__, __func__, __VA_ARGS__); } while (0)
#define LOGI(...) _LOGI(__VA_ARGS__, "")

#define _LOGD(fmt, ...) \
        do { if (LOG_LEVEL <= LOG_DEBUG) fprintf(stderr, "[DEBUG]    %s:%d:%s(): " fmt "\n%s", __FILE__, \
                                __LINE__, __func__, __VA_ARGS__); } while (0)
#define LOGD(...) _LOGD(__VA_ARGS__, "")

#define _LOG(fmt, ...) \
        do { if (LOG_LEVEL <= LOG_VERBOSE) fprintf(stderr, "[VERBOSE]  %s:%d:%s(): " fmt "\n%s", __FILE__, \
                                __LINE__, __func__, __VA_ARGS__); } while (0)
#define LOG(...) _LOG(__VA_ARGS__, "")

#endif