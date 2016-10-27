/* A program to perform selection sort on a 10 element array of floats. */

float x[10];

int minloc(float a[], int low, int high)
{
    int i; int x; int k;

    k = low;
    x = a[low];
    i = low + 1;

    while (i < high)
    {
        if (a[i] < x)
        {
            x = a[i];
            k = i;
        }

        i = i + 1;
    }

    return k;
}

void sort(float a[], int low, int high)
{
    int i; int k;
    i = low;

    while (i < (high-1))
    {
        float t;
        k = minloc(a,i,high);
        t = a[k];
        a[k] = a[i];
        a[i] = t;
        i = i + 1;
    }
}

void main(void)
{
    int i;
    i = 0;

    while (i < 10)
    {
        x[i] = input();
        i = i + 1;
    }

    sort(x, 0, 10);
    i = 0;

    while (i < 10)
    {
        output(x[i]);
        i = i + 1;
    }
}
