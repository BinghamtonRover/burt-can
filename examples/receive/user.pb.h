/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7 */

#ifndef PB_EXAMPLES_SEND_USER_PB_H_INCLUDED
#define PB_EXAMPLES_SEND_USER_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _User {
    int32_t id;
} User;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define User_init_default                        {0}
#define User_init_zero                           {0}

/* Field tags (for use in manual encoding/decoding) */
#define User_id_tag                              2

/* Struct field encoding specification for nanopb */
#define User_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    id,                2)
#define User_CALLBACK NULL
#define User_DEFAULT NULL

extern const pb_msgdesc_t User_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define User_fields &User_msg

/* Maximum encoded size of messages (where known) */
#define User_size                                11

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif