#pragma once

#include <stdint.h>

typedef uint64_t metadata_vendor_id_t;

typedef struct vendor_tag_ops vendor_tag_ops_t;
struct vendor_tag_ops {
    int (*get_tag_count)(const vendor_tag_ops_t* v);
    void (*get_all_tags)(const vendor_tag_ops_t* v, uint32_t* tag_array);
    const char* (*get_section_name)(const vendor_tag_ops_t* v, uint32_t tag);
    const char* (*get_tag_name)(const vendor_tag_ops_t* v, uint32_t tag);
    int (*get_tag_type)(const vendor_tag_ops_t* v, uint32_t tag);
    void* reserved[8];
};