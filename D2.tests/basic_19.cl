__kernel void test_int_sub4(__global int4 *srcA, __global int4 *srcB, __global int4 *dst)
{
    int  tid = get_global_id(0);

    dst[tid] = srcA[tid] - srcB[tid];
}
