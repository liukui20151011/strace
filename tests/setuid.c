/*
 * Copyright (c) 2016-2019 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "tests.h"
#include "scno.h"

#ifdef __NR_setuid

# define SYSCALL_NR	__NR_setuid
# define SYSCALL_NAME	"setuid"

# if defined __NR_setuid32 && __NR_setuid != __NR_setuid32
#  define UGID_TYPE	short
#  define GETUGID	syscall(__NR_geteuid)
#  define CHECK_OVERFLOWUGID(arg)	check_overflowuid(arg)
# else
#  define UGID_TYPE	int
#  define GETUGID	geteuid()
#  define CHECK_OVERFLOWUGID(arg)
# endif

# include "setugid.c"

#else

SKIP_MAIN_UNDEFINED("__NR_setuid")

#endif
