#ifndef _BIT_ORDER_H_
#define _BIT_ORDER_H_

#include <stdint.h>
#include <endian.h>
#include <byteswap.h>

# if __BYTE_ORDER == __BIG_ENDIAN

#define hton_int16(x) (x)
#define hton_int32(x) (x)
#define hton_int64(x) (x)

#define ntoh_int16(x) (x)
#define ntoh_int32(x) (x)
#define ntoh_int64(x) (x)

#else

#define hton_int16(x) bswap_16(x)
#define hton_int32(x) bswap_32(x)
#define hton_int64(x) bswap_64(x)

#define ntoh_int16(x) bswap_16(x)
#define ntoh_int32(x) bswap_32(x)
#define ntoh_int64(x) bswap_64(x)

#endif




#endif
