#include "robot_simulator.h"
#include "string.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
  return (robot_status_t){
      .direction = direction, .position.x = x, .position.y = y};
}

void robot_move(robot_status_t *robot, const char *commands) {
  for (int i = 0; i < (int)strlen(commands); i++) {
    switch (commands[i]) {
    case 'R': {
      if ((robot->direction += 1) >= DIRECTION_MAX) {
        robot->direction = DIRECTION_DEFAULT;
      };
    } break;
    case 'L': {
      if ((robot->direction -= 1) >= DIRECTION_MAX) {
        robot->direction = DIRECTION_WEST;
      };
      break;
    }
    case 'A': {
      switch (robot->direction) {
      case DIRECTION_NORTH:
        robot->position.y++;
        break;
      case DIRECTION_SOUTH:
        robot->position.y--;
        break;
      case DIRECTION_WEST:
        robot->position.x--;
        break;
      case DIRECTION_EAST:
        robot->position.x++;
        break;
      default:
        break;
      }
    } break;
    default:
      break;
    }
  }
}
