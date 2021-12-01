#include <stdio.h>
#include <stdlib.h>
#include "i4/xalloc.h"
#include "weight_fraction.h"
#include "aircraft.h"
#include "gc.h"
#include <assert.h>

#define DREF(m) ((m)[0])

void test1() {
  printf("Test 1: Objects on stack are preserved.\n");
  VM* vm = newVM();
  pushInt(vm, 1);
  pushInt(vm, 2);

  gc(vm);
  assert(vm->numObjects == 2 &&  "Should have preserved objects.");
  freeVM(vm);
}

void test2() {
  printf("Test 2: Unreached objects are collected.\n");
  VM* vm = newVM();
  pushInt(vm, 1);
  pushInt(vm, 2);
  pop(vm);
  pop(vm);

  gc(vm);
  assert(vm->numObjects == 0 && "Should have collected objects.");
  freeVM(vm);
}

void test3() {
  printf("Test 3: Reach nested objects.\n");
  VM* vm = newVM();
  pushInt(vm, 1);
  pushInt(vm, 2);
  pushPair(vm);
  pushInt(vm, 3);
  pushInt(vm, 4);
  pushPair(vm);
  pushPair(vm);

  gc(vm);
  assert(vm->numObjects == 7 && "Should have reached objects.");
  freeVM(vm);
}

void test4() {
  printf("Test 4: Handle cycles.\n");
  VM* vm = newVM();
  pushInt(vm, 1);
  pushInt(vm, 2);
  Object* a = pushPair(vm);
  pushInt(vm, 3);
  pushInt(vm, 4);
  Object* b = pushPair(vm);

  /* Set up a cycle, and also make 2 and 4 unreachable and collectible. */
  a->tail = b;
  b->tail = a;

  gc(vm);
  assert(vm->numObjects == 4 && "Should have collected objects.");
  freeVM(vm);
}

void perfTest() {
  printf("Performance Test.\n");
  VM* vm = newVM();

  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 20; j++) {
      pushInt(vm, i);
    }

    for (int k = 0; k < 20; k++) {
      pop(vm);
    }
  }
  freeVM(vm);
}

int main(void) {
  struct Real r;
  struct Time        time = {.t = DREF(Real.init(&r, 10800.0))};
  struct Sfc          sfc = {.t = DREF(Real.init(&r, 0.0001111))};
  struct LiftDragRatio ld = {.t = DREF(Real.init(&r, 16.0))};

  F64 res = Real.asF64(WeightFraction.asReal(WeightFraction.loiter(&time, &sfc, &ld)));
  printf("Loiter: %f\n", res);

  // test1();
  // test2();
  // test3();
  // test4();
  // perfTest();

  return EXIT_SUCCESS;
}