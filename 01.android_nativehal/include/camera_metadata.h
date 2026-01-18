#pragma once

#include "camera_vendor_tags.h"
#include <stdint.h>

typedef uint32_t metadata_uptrdiff_t;
typedef uint32_t metadata_size_t;

#define METADATA_ALIGNMENT ((size_t)4)
typedef struct camera_metadata {
    metadata_size_t size;
    uint32_t version;
    uint32_t flags;
    metadata_size_t entry_count;
    metadata_size_t entry_capacity;
    metadata_uptrdiff_t entries_start; // Offset from camera_metadata
    metadata_size_t data_count;
    metadata_size_t data_capacity;
    metadata_uptrdiff_t data_start; // Offset from camera_metadata
    uint32_t padding; // padding to 8 bytes boundary
    metadata_vendor_id_t vendor_id;
} camera_metadata_t;