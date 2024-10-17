class bar3d
{
public:
    float width;
    float height;
    float depth;

    bar3d()
    {
        width = 0;
        height = 0;
        depth = 0;

    }

    bar3d(float w, float h, float d)
    {
        if((w>0&&w<1000)&&(h>0 && h<1000)&&(d>0 && d<1000))
        {
            width = w;
            height = h;
            depth = d;
        }

        else
        {
            width = 0;
            height = 0;
            depth = 0;
        }
    }

    float getVolume()
    {
        return width*height*depth;
    }

    void scale(float x)
    {
        width = width*x;
        height =height *x;
        depth = depth*x;
    }
};