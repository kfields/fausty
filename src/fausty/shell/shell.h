#pragma once

#ifdef SHELL_HEADER
#include SHELL_HEADER
#else
#include "window.h"
#endif

#ifdef SHELL_CLASS
using Window = SHELL_CLASS;
#else
using Window = WindowBase;
#endif
