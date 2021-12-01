#pragma once

#include "i4/type.h"
#include "gc.h"

struct Real {
  F64 t;
};

static Real* Real_new(void) {
  
}

struct Real* Real_ctor(void);
       void  Real_dtor(struct Real* a_this);
struct Real* Real_init(struct Real* a_this, F64 a_value);

F64 Real_asF64(struct Real a_this);

struct Real  Real_neg(struct Real a_value);
struct Real  Real_e  (struct Real a_value); // e^a_value

struct Real  Real_add(struct Real a_lhs, struct Real a_rhs);
struct Real  Real_sub(struct Real a_lhs, struct Real a_rhs);
struct Real  Real_mul(struct Real a_lhs, struct Real a_rhs);
struct Real  Real_div(struct Real a_lhs, struct Real a_rhs);

struct RealFn {
  struct Real* (*const ctor)(void);
         void  (*const dtor)(struct Real* a_this);
  struct Real* (*const init)(struct Real* a_this, F64 a_value);

          F64  (*const asF64)(struct Real a_this);

  struct Real  (*const neg)(struct Real a_value);
  struct Real  (*const e)  (struct Real a_value);

  struct Real  (*const add) (struct Real a_lhs, struct Real a_rhs);
  struct Real  (*const sub) (struct Real a_lhs, struct Real a_rhs);
  struct Real  (*const mul) (struct Real a_lhs, struct Real a_rhs);
  struct Real  (*const div) (struct Real a_lhs, struct Real a_rhs);
};
static struct RealFn const Real = {
  .ctor = Real_ctor,
  .dtor = Real_dtor,
  .init = Real_init,

  .asF64 = Real_asF64,

  .neg = Real_neg,
  .e   = Real_e,

  .add = Real_add,
  .sub = Real_sub,
  .mul = Real_mul,
  .div = Real_div,
};