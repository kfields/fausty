#pragma once

#define FAUSTY_SINGLE

#if defined FAUSTY_QUAD
typedef long double fy_real;
#elif defined FAUSTY_DOUBLE
typedef double fy_real;
#else
typedef float fy_real;
#endif

typedef fy_real* fy_buffer_t;
typedef fy_real** fy_buffers_t;

#define FAUSTFLOAT fy_real
