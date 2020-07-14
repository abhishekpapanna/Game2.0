#ifndef BULLET_H
#define BULLET_H


class Bullet
{
public:
    Bullet();
    ~Bullet();
    void spawn();
    void drawbullets();

private:
    int bulletsonscreen = 0;
};

#endif // BULLET_H
