#define _CRT_SECURE_NO_WARNINGS

#include <vmsys.h>
#include <string.h>
#include <stdio.h>
#include "YahooSrv.h"

/*****************************************************************************
 * FUNCTION
 *  mre_srv_currenttime_to_unixtime
 * DESCRIPTION
 *  this fuction is  used to convert current GMT time to unixtime stamp
 * PARAMETERS
 *  void
 * RETURNS
 *  VMINT   [OUT]  returns seconds since 1st january 1970
 *****************************************************************************/
VMINT mre_srv_currenttime_to_unixtime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    VMINT status, month_sec;
    VMINT32 seconds;
    vm_time_t *time;

#ifdef WIN32
    float time_diff;
#else 
    float time_zone_diff, time_diff;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MRE_YN_SRV_LOG_ON
    vm_log_debug("Enter mre_srv_currenttime_to_unixtime()");
#endif 

    time = (vm_time_t*) vm_malloc(sizeof(vm_time_t));
    status = vm_get_time(time);
    switch (time->mon)
    {
        case 1:
            month_sec = 0;
            break;
        case 2:
            month_sec = 2678400;
            break;
        case 3:
            month_sec = 5097600;
            break;
        case 4:
            month_sec = 7776000;
            break;
        case 5:
            month_sec = 10368000;
            break;
        case 6:
            month_sec = 13046400;
            break;
        case 7:
            month_sec = 15638400;
            break;
        case 8:
            month_sec = 18316800;
            break;
        case 9:
            month_sec = 20995200;
            break;
        case 10:
            month_sec = 23587200;
            break;
        case 11:
            month_sec = 26265600;
            break;
        case 12:
            month_sec = 28857600;
            break;
        default:
            break;
    }

#ifdef WIN32
    time_diff = 5.5 * 60 * 60;
#else /* WIN32 */ 
    time_zone_diff = vm_get_sys_time_zone();
    time_diff = time_zone_diff * 60 * 60;
#ifdef MRE_YN_SRV_LOG_ON
    vm_log_debug("time zone diff: %d", time_zone_diff);
#endif 
#ifdef MRE_YN_SRV_LOG_ON
    vm_log_debug("time zone diff: %d", time_diff);
#endif 
#endif /* WIN32 */ 

    seconds =
        31536000 * (time->year - 1970) + (time->day + (time->year - 1972) / 4) * 86400 + time->hour * 3600 +
        time->min * 60 + time->sec + month_sec;
#ifdef MRE_YN_SRV_LOG_ON
    vm_log_debug("seconds: %d", seconds);
#endif 
    seconds = (VMINT32)(seconds - time_diff);
    vm_free(time);
#ifdef MRE_YN_SRV_LOG_ON
    vm_log_debug("seconds: %d", seconds);
#endif 
#ifdef MRE_YN_SRV_LOG_ON
    vm_log_debug("Exit mre_srv_currenttime_to_unixtime()");
#endif 
    return seconds;

}


/*****************************************************************************
 * FUNCTION
 *  mre_srv_unixtime_to_string
 * DESCRIPTION
 *  this fuction is  used to convert UNIX time format to GMT format
 * PARAMETERS
 *  digit       [IN]        
 *  VMCHAR*  :- time string in unix time format(?)(?)
 * RETURNS
 *  VMCHAR* :- resulted string in GMT format
 *****************************************************************************/
#if 0
VMCHAR *mre_srv_unixtime_to_string(const VMCHAR *digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    VMINT time_unix = 0;
    VMSTR s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*digit >= '0' && *digit <= '9')
    {
        time_unix = (time_unix * 10) + (*digit - '0');
        digit++;
    }
    s = mre_common_unixtime_to_string(time_unix);
#ifdef MRE_YN_SRV_LOG_ON
    vm_log_debug("date string = %s", s);
#endif 
    return s;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mre_srv_url_encoding
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string          [IN]        
 *  url_str(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
VMSTR mre_srv_url_encoding(VMSTR string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT alloc, newlen;
    VMCHAR *ns = NULL, *testing_ptr = NULL;
    VMUCHAR in;
    VMUINT strindex = 0;
    VMUINT length;
    VMSTR temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MRE_YN_SRV_LOG_ON
    vm_log_debug("Enter in mre_srv_url_encoding");
#endif 
    temp = string;
    if (!string)
    {
        return NULL;
    }

    alloc = strlen(string) + 1;
    newlen = alloc;

    ns = (VMSTR) vm_malloc(alloc);

    length = alloc - 1;

    while (length--)
    {
        in = *string;

        switch (in)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
            case '_':
            case '~':
            case '.':
            case '-':
                ns[strindex++] = in;
                break;
            default:
                newlen += 2;    /* this'll become a %XX */
                if (newlen > alloc)
                {
                    alloc *= 2;
                    testing_ptr = (VMCHAR*) vm_realloc(ns, alloc);
                    ns = testing_ptr;
                }

                sprintf(&ns[strindex], "%%%02X", in);
                strindex += 3;
                break;
        }
        string++;
    }
    ns[strindex] = 0;
    vm_free(temp);
    temp = NULL;
#ifdef MRE_YN_SRV_LOG_ON
    vm_log_debug("Exit from  mre_srv_url_encoding");
#endif 
    return ns;
}
