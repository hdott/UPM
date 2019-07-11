public class OpMatrici
{
    public static int[] AddVector(int v1[], int size1, int v2[], int size2)
    {
        int s1, s2;
        boolean which;

        if(size1 > size2)
        {
            s2 = size1;
            s1 = size2;
            which = 0;
        }
        else if(size2 > size1)
        {
            s1 = size1;
            s2 = size2;
            which = 1;
        }
        else    s1 = s2 = size1;

        int v3[] = new int[s2], i = 0;

        for(i=0; i<s1; ++i)     v3[i] = v1[i] + v2[i];
        
        if(!which)  for( ; i<s2; ++i)       v3[i] = v1[i];
        else        for( ; i<s2; ++i)       v3[i] = v2[i];


        return v3;
    }

    public static int[] SubstractVector(int v1[], int size1, int v2[], int size2)
    {
        int s1, s2;
        boolean which;

        if(size1 > size2)
        {
            s2 = size1;
            s1 = size2;
            which = 0;
        }
        else if(size2 > size1)
        {
            s1 = size1;
            s2 = size2;
            which = 1;
        }
        else    s1 = s2 = size1;

        int v3[] = new int[s2], i = 0;

        for(i=0; i<s1; ++i)     v3[i] = v1[i] - v2[i];

        if(!which)  for( ; i<s2; ++i)       v3[i] = v1[i];
        else        for( ; i<s2; ++i)       v3[i] = v2[i];


        return v3;
    }

    public static int[] VectorMultiplication(int v1[], int size1, int v2[], int size2)
    {
        int s1, s2;
        boolean which;

        if(size1 > size2)
        {
            s2 = size1;
            s1 = size2;
            which = 0;
        }
        else if(size2 > size1)
        {
            s1 = size1;
            s2 = size2;
            which = 1;
        }
        else    s1 = s2 = size1;

        int v3[] = new int[s2], i = 0;

        for(i=0; i<s1; ++i)     v3[i] = v1[i] * v2[i];

        if(!which)  for( ; i<s2; ++i)       v3[i] = v1[i];
        else        for( ; i<s2; ++i)       v3[i] = v2[i];


        return v3;
    }

    public static int[] VectorDivision(int v1[], int size1, int v2[], int size2)
    {
        int s1, s2;
        boolean which;

        if(size1 > size2)
        {
            s2 = size1;
            s1 = size2;
            which = 0;
        }
        else if(size2 > size1)
        {
            s1 = size1;
            s2 = size2;
            which = 1;
        }
        else    s1 = s2 = size1;

        int v3[] = new int[s2], i = 0;

        for(i=0; i<s1; ++i)     v3[i] = v1[i] / v2[i];

        if(!which)  for( ; i<s2; ++i)       v3[i] = v1[i];
        else        for( ; i<s2; ++i)       v3[i] = v2[i];


        return v3;
    }
}