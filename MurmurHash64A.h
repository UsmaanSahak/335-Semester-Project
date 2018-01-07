/* 
 * File:   MurmurHash64A.h
 * Author: benjamin
 *
 * Created on October 14, 2014, 7:21 PM
 */

#ifndef MURMURHASH64A_H
#define	MURMURHASH64A_H

#ifdef	__cplusplus
extern "C" {
#endif

    #include <stdint.h>
    uint64_t MurmurHash64A( const void * key, int len, uint64_t seed );

#ifdef	__cplusplus
}
#endif

#endif	/* MURMURHASH64A_H */


