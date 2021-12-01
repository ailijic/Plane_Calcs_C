#pragma once

#include <stdint.h>

typedef enum { 
  OBJ_INT,
  OBJ_F64,
  OBJ_PAIR,
} ObjectType;

typedef struct sObject {
  uint8_t marked;
  ObjectType type;

  /* The next object in the list of all objects. */
  struct sObject* next;

  union {
    /* OBJ_INT */
    int value;

    /* OBJ_INT */
    double f64;

    /* OBJ_PAIR */
    struct {
      struct sObject* head;
      struct sObject* tail;
    };
  };
} Object;

enum { STACK_MAX = 256 };

typedef struct {
  /* The first object in the list of all objects. */
  Object* firstObject;

  Object* stack[STACK_MAX];
  int stackSize;

  /* The total number of currently allocated objects. */
  int numObjects;

  /* The number of objects required to trigger a GC. */
  int maxObjects;
} VM;

VM* newVM();
void freeVM(VM* vm);
// Object* newObject(VM* vm, ObjectType type);

void push(VM* vm, Object* value);
Object* pop(VM* vm);

void pushInt(VM* vm, int intValue);
void pushF64(VM* vm, double f64Value);
Object* pushPair(VM* vm);

void mark(Object* object);
void markAll(VM* vm);
void sweep(VM* vm);
void gc(VM* vm);

VM* main_vm;