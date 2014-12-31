#ifndef LIBCOMPAT_H
#define LIBCOMPAT_H

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
  #define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
  #define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif
 
#define __func__ __FUNCTION__

// time
struct timezone
{
  int  tz_minuteswest; /* minutes W of Greenwich */
  int  tz_dsttime;     /* type of dst correction */
};

int gettimeofday(struct timeval *tv, struct timezone *tz);

// threads
struct timespec {
        long tv_sec;
        long tv_nsec;
};

#ifdef __cplusplus
}
#endif

#endif LIBCOMPAT_H
