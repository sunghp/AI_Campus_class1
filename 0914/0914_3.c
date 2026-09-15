#include <stdio.h>

typedef struct
{
    double left;
    double right;
} WheelSpeed;

typedef struct
{
    double linear;
    double angular;
} RobotSpeed;

RobotSpeed computeSpeed(WheelSpeed, double, double);

int main(void)
{
    WheelSpeed speed_W;
    RobotSpeed speed_R;
    double rad, dist;
    double v, w;

    printf("왼쪽 바퀴 속도(rad/s): ");
    scanf("%lf", &speed_W.left);
    printf("오른쪽 바퀴 속도(rad/s): ");
    scanf("%lf", &speed_W.right);
    printf("바퀴 반지름(m): ");
    scanf("%lf", &rad);
    printf("바퀴 간 거리(m): ");
    scanf("%lf", &dist);

    speed_R = computeSpeed(speed_W, rad, dist);
    printf("선속도: %.2lf m/s\n", speed_R.linear);
    printf("각속도: %.2lf rad/s\n", speed_R.angular);
}

RobotSpeed computeSpeed(WheelSpeed speed_W, double rad, double dist)
{
    RobotSpeed bot;
    bot.linear = rad * (speed_W.left + speed_W.right) / 2;
    if (speed_W.right > speed_W.left) bot.angular = rad * (speed_W.right - speed_W.left) / dist;
    else bot.angular = rad * (speed_W.left - speed_W.right) / dist;

    return bot;
}