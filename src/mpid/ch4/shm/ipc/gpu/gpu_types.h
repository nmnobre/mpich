/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef GPU_TYPES_H_INCLUDED
#define GPU_TYPES_H_INCLUDED

#include "uthash.h"

struct MPIDI_GPUI_map_cache_entry {
    UT_hash_handle hh;
    struct map_key {
        int remote_rank;
        const void *remote_addr;
    } key;
    struct map_data {
        const void *local_base_address;
        MPL_gpu_buffer_id_t remote_buffer_id;
    } mapped[];                 /* array of local base addresses and remote buffer ids indexed by device id */
};

typedef struct {
    int local_device_count;
    int initialized;
    struct MPIDI_GPUI_map_cache_entry *ipc_map_cache;
} MPIDI_GPUI_global_t;

extern MPIDI_GPUI_global_t MPIDI_GPUI_global;

#endif /* GPU_TYPES_H_INCLUDED */
