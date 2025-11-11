#include "high_scores.h"

#include <algorithm>

namespace arcade
{

    std::vector<int> HighScores::list_scores()
    {
        // TODO: Return all scores for this session.
        return scores;
    }

    int HighScores::latest_score()
    {
        // TODO: Return the latest score for this session.
        return *(scores.cend() - 1);
    }

    int HighScores::personal_best()
    {
        // TODO: Return the highest score for this session.
        return *std::max_element(scores.begin(), scores.end());
    }

    std::vector<int> HighScores::top_three()
    {
        // TODO: Return the top 3 scores for this session in descending order.
        std::vector<int> tmp{scores};
        std::sort(tmp.begin(), tmp.end(), std::greater<int>());
        // std::vector<int> ret(scores.begin(), scores.size() >= 3 ? scores.begin() + 3 : scores.end());
        return std::vector<int>(tmp.begin(), tmp.size() >= 3 ? tmp.begin() + 3 : tmp.end());
    }

} // namespace arcade
