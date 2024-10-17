class bar3d
{
public:
    int width;
    int height;
    int depth;

    bar3d(int w, int h, int d)
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
};