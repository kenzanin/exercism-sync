#include <algorithm>
#include <array>
#include <cmath>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
  // TODO: Implement round_down_scores
  std::vector<int> ret(student_scores.size());
  std::transform(student_scores.begin(), student_scores.end(), ret.begin(),
                 [](auto e) -> int { return std::floor(e); });
  return ret;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
  // TODO: Implement count_failed_students
  int ret{};
  std::for_each(student_scores.begin(), student_scores.end(),
                [&ret](auto e) -> void { ret += e > 40 ? 0 : 1; });
  return ret;
}

// Determine how many of the provided student scores were 'the best' based on
// the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores,
                                 int threshold) {
  // TODO: Implement above_threshold
  std::vector<int> ret{};
  std::for_each(student_scores.begin(), student_scores.end(),
                [&ret, threshold](auto e) -> void {
                  if (e >= threshold) {
                    ret.push_back(e);
                  }
                });
  return ret;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
  // TODO: Implement letter_grades
  const int step = (highest_score - 40) / 4;
  return {41, 41 + step, 41 + (step * 2), 41 + (step * 3)};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
  // TODO: Implement student_ranking
  std::vector<std::string> ret{};
  std::for_each(
      student_names.begin(), student_names.end(),
      [&ret, &student_names, student_scores](std::string const &e) -> void {
        const int index = &e - &student_names[0];
        ret.push_back(std::to_string(index + 1) + ". " + e + ": " +
                      std::to_string(student_scores[index]));
      });
  return ret;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
  // TODO: Implement perfect_score
  std::string ret{};
  for (int i = 0; i < student_names.size(); i++) {
    if (student_scores[i] == 100) {
      ret = student_names[i];
      break;
    }
  }
  return ret;
}
