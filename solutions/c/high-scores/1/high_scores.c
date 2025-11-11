#include "high_scores.h"

#include <stdlib.h>
#include <string.h>

int32_t latest(const int32_t* score, size_t scores_len) {
  return score[scores_len - 1];
}

int32_t personal_best(const int32_t* score, size_t score_len) {
  int32_t best = score[0];
  for (int i = 1; i < (int)score_len; i++) {
    if (best < score[i]) {
      best = score[i];
    }
  }
  return best;
}

int cmp(const void* a, const void* b);
int cmp(const void* a, const void* b) { return (*(int32_t*)b - *(int32_t*)a); }

size_t personal_top_three(const int32_t* scores, size_t scores_len,
                          int32_t* output) {
  int32_t tmp[scores_len];
  memcpy(tmp, scores, scores_len * sizeof(int32_t));
  qsort(tmp, scores_len, sizeof(int32_t), cmp);
  memcpy(output, tmp, 3 * sizeof(int32_t));
  return scores_len >= 3 ? 3 : scores_len;
}