namespace targets
{
    // TODO: Insert the code for the alien class here
    class Alien
    {
    public:
        int x_coordinate;
        int y_coordinate;
        Alien(int x, int y) : x_coordinate(x), y_coordinate(y)
        {
            health = 3;
        }
        int get_health() { return health; }
        bool hit()
        {
            health--;
            return true;
        }
        bool is_alive()
        {
            return health > 0;
        }
        bool teleport(int x, int y)
        {
            x_coordinate = x;
            y_coordinate = y;
            return true;
        }
        bool collision_detection(Alien obj)
        {
            return this->x_coordinate == obj.x_coordinate and
                   this->y_coordinate == obj.y_coordinate;
        }

    protected:
        int health;
    };
} // namespace targets