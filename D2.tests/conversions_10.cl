__kernel void test_convert_uchar4_rte_uchar4( __global uchar4 *src, __global uchar4 *dest )
{
   size_t i = get_global_id(0);
   dest[i] = convert_uchar4_rte( src[i] );
}
