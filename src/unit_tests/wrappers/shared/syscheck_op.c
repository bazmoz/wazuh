/*
 * Copyright (C) 2015-2020, Wazuh Inc.
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation.
 */

#include "syscheck_op.h"

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

HANDLE wrap_syscheck_op_CreateFile (LPCSTR lpFileName,
                                    __UNUSED_PARAM(DWORD dwDesiredAccess),
                                    __UNUSED_PARAM(DWORD dwShareMode),
                                    __UNUSED_PARAM(LPSECURITY_ATTRIBUTES lpSecurityAttributes),
                                    __UNUSED_PARAM(DWORD dwCreationDisposition),
                                    __UNUSED_PARAM(DWORD dwFlagsAndAttributes),
                                    __UNUSED_PARAM(HANDLE hTemplateFile)) {
    check_expected(lpFileName);

    return mock_type(HANDLE);
}

WINBOOL wrap_syscheck_op_CloseHandle (HANDLE hObject) {
    check_expected(hObject);

    return mock();
}

DWORD wrap_syscheck_op_GetLastError (VOID) {
    return mock();
}

DWORD wrap_syscheck_op_FormatMessage (__UNUSED_PARAM(DWORD dwFlags),
                                      __UNUSED_PARAM(LPCVOID lpSource),
                                      __UNUSED_PARAM(DWORD dwMessageId),
                                      __UNUSED_PARAM(DWORD dwLanguageId),
                                      char** lpBuffer,
                                      __UNUSED_PARAM(DWORD nSize),
                                      __UNUSED_PARAM(va_list *Arguments)) {
    *lpBuffer = mock_type(char*);
    return 0;
}

HLOCAL wrap_syscheck_op_LocalFree (__UNUSED_PARAM(HLOCAL hMem)) {
    return NULL;
}

DWORD wrap_syscheck_op_GetSecurityInfo (__UNUSED_PARAM(HANDLE handle),
                                        __UNUSED_PARAM(SE_OBJECT_TYPE ObjectType),
                                        __UNUSED_PARAM(SECURITY_INFORMATION SecurityInfo),
                                        __UNUSED_PARAM(PSID *ppsidOwner),
                                        __UNUSED_PARAM(PSID *ppsidGroup),
                                        __UNUSED_PARAM(PACL *ppDacl),
                                        __UNUSED_PARAM(PACL *ppSacl),
                                        __UNUSED_PARAM(PSECURITY_DESCRIPTOR *ppSecurityDescriptor)) {
    return mock();
}

WINBOOL wrap_syscheck_op_ConvertSidToStringSid(__UNUSED_PARAM(PSID Sid),LPSTR *StringSid) {
    *StringSid = mock_type(LPSTR);
    return mock();
}

WINBOOL wrap_syscheck_op_LookupAccountSid (__UNUSED_PARAM(LPCSTR lpSystemName),
                                           __UNUSED_PARAM(PSID Sid),
                                           LPSTR Name,
                                           LPDWORD cchName,
                                           __UNUSED_PARAM(LPSTR ReferencedDomainName),
                                           __UNUSED_PARAM(LPDWORD cchReferencedDomainName),
                                           __UNUSED_PARAM(PSID_NAME_USE peUse)) {
    strncpy(Name, mock_type(char*), *cchName);

    return mock();
}