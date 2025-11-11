#include "grade_school.h"
#include "string.h"
#include <bits/stdint-uintn.h>
#include <stdlib.h>

int compare_student(const void *a, const void *b);
roster_t roster = {0};
static uint8_t count = 0;

int compare_student(const void *a, const void *b) {
  const student_t *sa = a;
  const student_t *sb = b;

  int result = sa->grade - sb->grade;
  if (!result) {
    result = strcmp(sa->name, sb->name);
  }

  return result;
}

int add_student(char *name, int grade) {
  for (uint8_t i = 0; i < roster.count; i++) {
    if (strcmp(roster.students[i].name, name) == 0) {
      return 0;
    }
  }
  strcpy(roster.students[count].name, name);
  roster.students[count].grade = grade;
  count++;
  roster.count = count;
  return 1;
}

roster_t get_roster(void) {
  qsort(roster.students, roster.count, sizeof(student_t), compare_student);
  count = 0;
  return roster;
}

roster_t get_grade(uint8_t num) {
  roster_t result = {0};
  uint8_t found = 0;
  for (uint8_t i = 0; i < roster.count; i++) {
    if (roster.students[i].grade == num) {
      strcpy(result.students[found].name, roster.students[i].name);
      result.students[found].grade = num;
      found++;
    }
  }
  result.count = found;
  roster = result;
  return get_roster();
}

void clear_roster() {
  roster_t coba = {0};
  roster = coba;
}
