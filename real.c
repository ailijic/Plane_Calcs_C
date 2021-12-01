#include "i4/type.h"
#include "i4/xalloc.h"
#include "real.h"
#include <math.h>

struct Real* Real_ctor(void) { return xmalloc(xsizeof(struct Real)); }

void  Real_dtor(struct Real* a_this) { xfree(a_this); }

struct Real* Real_init(struct Real* a_this, F64 a_value) {
  a_this->t = a_value;
  return a_this;
}

F64 Real_asF64(struct Real a_this) { return a_this.t; }

struct Real Real_neg(struct Real a_value) {
  return (struct Real){.t = -a_value.t};
}

struct Real Real_e(struct Real a_value) { // e^a_value
  return (struct Real){.t = exp(a_value.t)};
}

struct Real Real_add(struct Real a_lhs, struct Real a_rhs)
{
  return (struct Real){.t = a_lhs.t + a_rhs.t};
}

struct Real  Real_sub(struct Real a_lhs, struct Real a_rhs)
{
  return (struct Real){.t = a_lhs.t - a_rhs.t};
}

struct Real  Real_mul(struct Real a_lhs, struct Real a_rhs)
{
  return (struct Real){.t = a_lhs.t * a_rhs.t};
}

struct Real  Real_div(struct Real a_lhs, struct Real a_rhs)
{
  return (struct Real){.t = a_lhs.t / a_rhs.t};
}
