__kernel void test_convert_uchar8_rtp_uchar8( __global uchar8 *src, __global uchar8 *dest )
{
   size_t i = get_global_id(0);
   dest[i] = convert_uchar8_rtp( src[i] );
}
