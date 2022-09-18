#include <time.h>
#include"CParticle.h"

int main()
{
    srand((unsigned)time(NULL));
    CParticle c1(7);
    c1.ShowPosition();
    c1.MoveTrace();
    return 0;
}