const unsigned N = 10000;

struct PointAOS
{
    float x, y, z;
};

struct PointSOA
{
    float x[N], y[N], z[N];
};

typedef PointAOS VPoint_1[N];
typedef PointSOA VPoint_2;