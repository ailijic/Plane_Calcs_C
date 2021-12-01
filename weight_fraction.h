#pragma once

#include "real.h"
#include "aircraft.h"

struct WeightFraction {
  struct Real t;
};

/*
struct WeightFraction* WeightFraction_ctor(void);
                 void  WeightFraction_dtor(struct WeightFraction* a_this);
*/
struct WeightFraction* WeightFraction_init(struct WeightFraction* a_this,
                                           struct Real* a_value);

struct WeightFraction WeightFraction_loiter(struct Time*          a_time,
                                            struct Sfc*           a_sfc,
                                            struct LiftDragRatio* a_ld);

struct Real WeightFraction_asReal(struct WeightFraction a_this);

struct WeightFractionFn {
//struct WeightFraction* (*const ctor)  (void);
//                 void  (*const dtor)  (struct WeightFraction* a_this);
  struct WeightFraction* (*const init)  (struct WeightFraction* a_this,
                                         struct Real*           a_value);
  struct WeightFraction  (*const loiter)(struct Time*           a_time,
                                         struct Sfc*            a_sfc,
                                         struct LiftDragRatio*  a_ld);
  struct Real            (*const asReal)(struct WeightFraction a_this);
};

static struct WeightFractionFn const WeightFraction = {
  //.ctor   = WeightFraction_ctor,
  //.dtor   = WeightFraction_dtor,
  .init   = WeightFraction_init,
  .loiter = WeightFraction_loiter,
  .asReal = WeightFraction_asReal,
};