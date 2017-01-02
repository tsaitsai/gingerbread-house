#include <stdint.h>
#include "ubt/bg_gattdb_def.h"

#ifdef __GNUC__
#define GATT_HEADER(F) F __attribute__ ((section (".gatt_header"))) 
#define GATT_DATA(F) F __attribute__ ((section (".gatt_data"))) 
#else
#ifdef __ICCARM__
#define GATT_HEADER(F) _Pragma("location=\".gatt_header\"") F 
#define GATT_DATA(F) _Pragma("location=\".gatt_data\"") F 
#else
#define GATT_HEADER(F) F 
#define GATT_DATA(F) F 
#endif
#endif

GATT_DATA(const uint16_t bg_gattdb_uuidtable_16_map [])=
{
    0x2800,
    0x2801,
    0x2803,
    0x1800,
    0x2a00,
    0x2a01,
    0x180a,
    0x2a29,
    0x2a24,
    0x2a23,
    0x2901,
    0x2902,
};

GATT_DATA(const uint8_t bg_gattdb_uuidtable_128_map [])=
{
0x1e, 0x31, 0xc5, 0xde, 0x2d, 0x76, 0xf4, 0xaa, 0xea, 0x4e, 0xe3, 0x63, 0x08, 0xf4, 0x09, 0x84, 
0x6b, 0x24, 0x03, 0x62, 0x57, 0x5b, 0xc6, 0xb5, 0x92, 0x48, 0xe7, 0xae, 0x08, 0x2b, 0x40, 0xc5, 
0x6e, 0xdf, 0xe3, 0xfb, 0x3c, 0xb6, 0xfa, 0x9a, 0xf9, 0x4d, 0xac, 0xa5, 0x02, 0x91, 0xde, 0x53, 
0x66, 0xdf, 0xe3, 0xfb, 0x3c, 0xb6, 0xfa, 0x9a, 0xf9, 0x4d, 0xac, 0xa5, 0x02, 0x91, 0xde, 0x53, 
};




GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_22 ) = {
	.len=6,
	.data={0x6d,0x79,0x64,0x61,0x74,0x61,}
};
uint8_t bg_gattdb_attribute_field_21_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_21 ) = {
	.properties=0x0a,
	.index=2,
	.max_len=1,
	.data=bg_gattdb_attribute_field_21_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_20 ) = {
	.len=19,
	.data={0x0a,0x16,0x00,0x66,0xdf,0xe3,0xfb,0x3c,0xb6,0xfa,0x9a,0xf9,0x4d,0xac,0xa5,0x02,0x91,0xde,0x53,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_19 ) = {
	.len=13,
	.data={0x53,0x74,0x61,0x74,0x75,0x73,0x20,0x76,0x65,0x63,0x74,0x6f,0x72,}
};
uint8_t bg_gattdb_attribute_field_17_data[21];
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_17 ) = {
	.properties=0x10,
	.index=1,
	.max_len=20,
	.data_varlen=(struct bg_gattdb_buffer_with_len*)bg_gattdb_attribute_field_17_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_16 ) = {
	.len=19,
	.data={0x10,0x12,0x00,0x6e,0xdf,0xe3,0xfb,0x3c,0xb6,0xfa,0x9a,0xf9,0x4d,0xac,0xa5,0x02,0x91,0xde,0x53,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_15 ) = {
	.len=12,
	.data={0x43,0x6f,0x6e,0x74,0x72,0x6f,0x6c,0x20,0x62,0x79,0x74,0x65,}
};
uint8_t bg_gattdb_attribute_field_14_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_14 ) = {
	.properties=0x0a,
	.index=0,
	.max_len=1,
	.data=bg_gattdb_attribute_field_14_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_13 ) = {
	.len=19,
	.data={0x0a,0x0f,0x00,0x6b,0x24,0x03,0x62,0x57,0x5b,0xc6,0xb5,0x92,0x48,0xe7,0xae,0x08,0x2b,0x40,0xc5,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_12 ) = {
	.len=16,
	.data={0x1e,0x31,0xc5,0xde,0x2d,0x76,0xf4,0xaa,0xea,0x4e,0xe3,0x63,0x08,0xf4,0x09,0x84,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_11 ) = {
	.len=6,
	.data={0x00,0x01,0x02,0x03,0x04,0x05,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_10 ) = {
	.len=5,
	.data={0x02,0x0c,0x00,0x23,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_9 ) = {
	.len=6,
	.data={0x42,0x47,0x4d,0x31,0x31,0x31,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_8 ) = {
	.len=5,
	.data={0x02,0x0a,0x00,0x24,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_7 ) = {
	.len=12,
	.data={0x53,0x69,0x6c,0x69,0x63,0x6f,0x6e,0x20,0x4c,0x61,0x62,0x73,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_6 ) = {
	.len=5,
	.data={0x02,0x08,0x00,0x29,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_5 ) = {
	.len=2,
	.data={0x0a,0x18,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_4 ) = {
	.len=2,
	.data={0x00,0x00,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_3 ) = {
	.len=5,
	.data={0x02,0x05,0x00,0x01,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_2 ) = {
	.len=7,
	.data={0x53,0x53,0x31,0x20,0x54,0x6f,0x70,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_1 ) = {
	.len=5,
	.data={0x02,0x03,0x00,0x00,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_0 ) = {
	.len=2,
	.data={0x00,0x18,}
};
GATT_DATA(const struct bg_gattdb_attribute bg_gattdb_attributes_map[])={
    {.uuid=0x0000,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_0},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_1},
    {.uuid=0x0004,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_2},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_3},
    {.uuid=0x0005,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_4},
    {.uuid=0x0000,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_5},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_6},
    {.uuid=0x0007,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_7},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_8},
    {.uuid=0x0008,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_9},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_10},
    {.uuid=0x0009,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_11},
    {.uuid=0x0000,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_12},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_13},
    {.uuid=0x8001,.permissions=0x03,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_14},
    {.uuid=0x000a,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_15},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_16},
    {.uuid=0x8002,.permissions=0x00,.datatype=0x02,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_17},
    {.uuid=0x000b,.permissions=0x07,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x01}},
    {.uuid=0x000a,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_19},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_20},
    {.uuid=0x8003,.permissions=0x03,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_21},
    {.uuid=0x000a,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_22},
};

GATT_DATA(const uint16_t bg_gattdb_attributes_dynamic_mapping_map[])={
	0x000f,
	0x0012,
	0x0016,
};

GATT_DATA(const uint8_t bg_gattdb_adv_uuid16_map[])={0x0};
GATT_DATA(const uint8_t bg_gattdb_adv_uuid128_map[])={0x1e, 0x31, 0xc5, 0xde, 0x2d, 0x76, 0xf4, 0xaa, 0xea, 0x4e, 0xe3, 0x63, 0x08, 0xf4, 0x09, 0x84, };
GATT_HEADER(const struct bg_gattdb_def bg_gattdb_data )={
    .attributes=bg_gattdb_attributes_map,
    .attributes_max=23,
    .uuidtable_16_size=12,
    .uuidtable_16=bg_gattdb_uuidtable_16_map,
    .uuidtable_128_size=4,
    .uuidtable_128=bg_gattdb_uuidtable_128_map,
    .attributes_dynamic_max=3,
    .attributes_dynamic_mapping=bg_gattdb_attributes_dynamic_mapping_map,
    .adv_uuid16=bg_gattdb_adv_uuid16_map,
    .adv_uuid16_num=0,
    .adv_uuid128=bg_gattdb_adv_uuid128_map,
    .adv_uuid128_num=1,
};

const struct bg_gattdb_def *bg_gattdb=&bg_gattdb_data;
