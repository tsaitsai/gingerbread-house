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
    0x2901,
    0x2902,
};

GATT_DATA(const uint8_t bg_gattdb_uuidtable_128_map [])=
{
0x07, 0xb9, 0xf9, 0xd7, 0x50, 0xa4, 0x20, 0x89, 0x77, 0x40, 0xcb, 0xfd, 0x2c, 0xc1, 0x80, 0x48, 
0xd6, 0x58, 0xd6, 0x21, 0xbc, 0x55, 0x81, 0x9f, 0x42, 0x44, 0x71, 0x6d, 0xc4, 0x6e, 0xc2, 0xfe, 
};




GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_14 ) = {
	.len=8,
	.data={0x53,0x50,0x50,0x20,0x44,0x61,0x74,0x61,}
};
uint8_t bg_gattdb_attribute_field_12_data[21];
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_12 ) = {
	.properties=0x14,
	.index=0,
	.max_len=20,
	.data_varlen=(struct bg_gattdb_buffer_with_len*)bg_gattdb_attribute_field_12_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_11 ) = {
	.len=19,
	.data={0x14,0x0d,0x00,0xd6,0x58,0xd6,0x21,0xbc,0x55,0x81,0x9f,0x42,0x44,0x71,0x6d,0xc4,0x6e,0xc2,0xfe,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_10 ) = {
	.len=16,
	.data={0x07,0xb9,0xf9,0xd7,0x50,0xa4,0x20,0x89,0x77,0x40,0xcb,0xfd,0x2c,0xc1,0x80,0x48,}
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
	.len=17,
	.data={0x42,0x47,0x4d,0x31,0x31,0x31,0x20,0x53,0x50,0x50,0x20,0x63,0x6c,0x69,0x65,0x6e,0x74,}
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
    {.uuid=0x0000,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_10},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_11},
    {.uuid=0x8001,.permissions=0x04,.datatype=0x02,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_12},
    {.uuid=0x000a,.permissions=0x07,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x00}},
    {.uuid=0x0009,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_14},
};

GATT_DATA(const uint16_t bg_gattdb_attributes_dynamic_mapping_map[])={
	0x000d,
};

GATT_DATA(const uint8_t bg_gattdb_adv_uuid16_map[])={0x0};
GATT_DATA(const uint8_t bg_gattdb_adv_uuid128_map[])={0x07, 0xb9, 0xf9, 0xd7, 0x50, 0xa4, 0x20, 0x89, 0x77, 0x40, 0xcb, 0xfd, 0x2c, 0xc1, 0x80, 0x48, };
GATT_HEADER(const struct bg_gattdb_def bg_gattdb_data )={
    .attributes=bg_gattdb_attributes_map,
    .attributes_max=15,
    .uuidtable_16_size=11,
    .uuidtable_16=bg_gattdb_uuidtable_16_map,
    .uuidtable_128_size=2,
    .uuidtable_128=bg_gattdb_uuidtable_128_map,
    .attributes_dynamic_max=1,
    .attributes_dynamic_mapping=bg_gattdb_attributes_dynamic_mapping_map,
    .adv_uuid16=bg_gattdb_adv_uuid16_map,
    .adv_uuid16_num=0,
    .adv_uuid128=bg_gattdb_adv_uuid128_map,
    .adv_uuid128_num=1,
};

const struct bg_gattdb_def *bg_gattdb=&bg_gattdb_data;
