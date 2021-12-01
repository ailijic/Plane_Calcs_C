#include "type.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdnoreturn.h>

void *reallocarray(void *ptr, size_t nmemb, size_t size);

static char const*const err_msg_g = 
  "ERR: Memory alocation failed, aborting program.\n";
static size_t const err_msg_len_g = strlen(err_msg_g);

noreturn void errAndAbort(void) {
  fwrite(err_msg_g, err_msg_len_g, 1, stderr);
  abort();
}

void* xmalloc(IntPtr a_num_bytes) {
  errno = 0;
  void* vp = malloc(a_num_bytes);
  if (vp == NULL && errno != 0) { errAndAbort(); }
  return vp;
}

void  xfree(void* a_ptr) { free(a_ptr); }

void* xcalloc(IntPtr a_nmemb, IntPtr a_size) {
  errno = 0;
  void* vp = calloc(a_nmemb, a_size);
  if (vp == NULL && errno != 0) { errAndAbort(); }
  return vp;
}

void* xrealloc(void* a_ptr, IntPtr a_size) {
  errno = 0;
  void* vp = realloc(a_ptr, a_size);
  if (vp == NULL && errno != 0) { errAndAbort(); }
  return vp;
}

void* xreallocarray(void* a_ptr, IntPtr a_nmemb, IntPtr a_size){
  errno = 0;
  void* vp = reallocarray(a_ptr, a_nmemb, a_size);
  if (vp == NULL && errno != 0) { errAndAbort(); }
  return vp;
}