/*
 * Error code list.
 */
#ifndef __ERROR_CODE_H__
#define __ERROR_CODE_H__
enum err_code {
    this_is_a_err_code = 0,
    /* system related */
    EE_NO_MEMORY = ((0xee01 << 8) + 0),

    /* app related */
    EE_INVALID_VIEW = ((0xee02 << 8) + 0),

    /* utils related */
    EE_INVALID_UTILS = ((0xee03 << 8) + 0),

    /* network and http */
    EE_GET_HTTP_HANDLE_FAIL   = ((0xee04 << 8) + 1),
    EE_NETWORK_UNAVAILABLE    = ((0xee04 << 8) + 2),
    EE_INVALID_JSON_DATA      = ((0xee04 << 8) + 3)


};

extern void err_code(int code);
#endif
