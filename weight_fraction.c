#include "weight_fraction.h"
#include "real.h"

// struct WeightFraction* WeightFraction_ctor(void);
//                 void  WeightFraction_dtor(struct WeightFraction* a_this);
struct WeightFraction* WeightFraction_init(struct WeightFraction* a_this,
                                           struct Real* a_value) {
  a_this->t = a_value[0];
  return a_this;
}

struct Real WeightFraction_asReal(struct WeightFraction a_this) {
  return a_this.t;
}

struct WeightFraction WeightFraction_loiter(struct Time*          a_time,
                                            struct Sfc*           a_sfc,
                                            struct LiftDragRatio* a_ld) {
  //struct Real E_neg = Real.neg(&a_time->t);
  //struct Real top = Real.mul(&E_neg, &a_sfc->t);
  //struct Real bot = a_ld->t;
  //struct Real exponent = Real.div(&top, &bot);
  return (struct WeightFraction){.t = 
    Real.e(
      Real.div(
        Real.mul(Real.neg(a_time->t), a_sfc->t),
        a_ld->t
      )
    )
  };
}