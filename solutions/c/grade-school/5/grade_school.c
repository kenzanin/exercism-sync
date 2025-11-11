#include "grade_school.h"
#include "string.h"
#include <stdlib.h>

int compar(const void *a, const void *b);

int compar(const void *a, const void *b) {
  student_t aa = *(student_t *)a;
  student_t bb = *(student_t *)b;

  if (aa.grade > bb.grade)
    return 1;
  if (aa.grade < bb.grade)
    return -1;
  return strcmp(aa.name, bb.name);
}

static roster_t class = {0};

int add_student(char *name, int grade) {
  size_t i = 0;
  for (i = 0; i < class.count; i++) {
    if (strcmp(name, class.students[i].name) == 0) {
      break;
    }
  }
  if (i == class.count) {
    class.students[class.count].grade = grade;
    strcpy(class.students[class.count].name, name);
    class.count++;
  }
  return class.count;
}

roster_t get_roster(void) {
  qsort(class.students, class.count, sizeof(student_t), compar);
  return class;
}

roster_t get_grade(uint8_t num) {
  roster_t tmp = get_roster();
  static roster_t result = {0};
  int count = 0;
  for (size_t i = 0; i < tmp.count; i++) {
    if (tmp.students[i].grade == num) {
      strcpy(result.students[count].name, tmp.students[i].name);
      result.students[count].grade = num;
      count++;
    }
  }
  result.count = count;
  return result;
}

void clear_roster() { memset(&class, 0, (sizeof(roster_t))); }
