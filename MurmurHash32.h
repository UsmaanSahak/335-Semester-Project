/* 
 * File:   MurmurHash32.h
 * Author: benjamin
 *
 * Created on October 14, 2014, 7:23 PM
 */

#ifndef MURMURHASH32_H
#define	MURMURHASH32_H

#ifdef	__cplusplus
extern "C" {
#endif

    #include <stdint.h>
    uint64_t MurmurHash32( const void * key, int len, uint64_t seed );

#ifdef	__cplusplus
}
#endif

#endif	/* MURMURHASH32_H */


