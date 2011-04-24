// MESSAGE RC_CHANNELS_MAPPING PACKING

#define MAVLINK_MSG_ID_RC_CHANNELS_MAPPING 36
#define MAVLINK_MSG_ID_RC_CHANNELS_MAPPING_LEN 2
#define MAVLINK_MSG_36_LEN 2

typedef struct __mavlink_rc_channels_mapping_t 
{
	uint8_t chan_id; ///< RC channel id
	uint8_t chan_function; ///< RC channel function, as defined in ENUM MAVLINK_RC_CHAN_MAPPING in mavlink/include/mavlink_types.h
} mavlink_rc_channels_mapping_t;


/**
 * @brief Pack a rc_channels_mapping message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param chan_id RC channel id
 * @param chan_function RC channel function, as defined in ENUM MAVLINK_RC_CHAN_MAPPING in mavlink/include/mavlink_types.h
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rc_channels_mapping_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t chan_id, uint8_t chan_function)
{
	mavlink_rc_channels_mapping_t *p = (mavlink_rc_channels_mapping_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_RC_CHANNELS_MAPPING;

	p->chan_id = chan_id; // uint8_t:RC channel id
	p->chan_function = chan_function; // uint8_t:RC channel function, as defined in ENUM MAVLINK_RC_CHAN_MAPPING in mavlink/include/mavlink_types.h

	return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RC_CHANNELS_MAPPING_LEN);
}

/**
 * @brief Pack a rc_channels_mapping message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param chan_id RC channel id
 * @param chan_function RC channel function, as defined in ENUM MAVLINK_RC_CHAN_MAPPING in mavlink/include/mavlink_types.h
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rc_channels_mapping_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint8_t chan_id, uint8_t chan_function)
{
	mavlink_rc_channels_mapping_t *p = (mavlink_rc_channels_mapping_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_RC_CHANNELS_MAPPING;

	p->chan_id = chan_id; // uint8_t:RC channel id
	p->chan_function = chan_function; // uint8_t:RC channel function, as defined in ENUM MAVLINK_RC_CHAN_MAPPING in mavlink/include/mavlink_types.h

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RC_CHANNELS_MAPPING_LEN);
}

/**
 * @brief Encode a rc_channels_mapping struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rc_channels_mapping C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rc_channels_mapping_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rc_channels_mapping_t* rc_channels_mapping)
{
	return mavlink_msg_rc_channels_mapping_pack(system_id, component_id, msg, rc_channels_mapping->chan_id, rc_channels_mapping->chan_function);
}

/**
 * @brief Send a rc_channels_mapping message
 * @param chan MAVLink channel to send the message
 *
 * @param chan_id RC channel id
 * @param chan_function RC channel function, as defined in ENUM MAVLINK_RC_CHAN_MAPPING in mavlink/include/mavlink_types.h
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
static inline void mavlink_msg_rc_channels_mapping_send(mavlink_channel_t chan, uint8_t chan_id, uint8_t chan_function)
{
	mavlink_message_t msg;
	uint16_t checksum;
	mavlink_rc_channels_mapping_t *p = (mavlink_rc_channels_mapping_t *)&msg.payload[0];

	p->chan_id = chan_id; // uint8_t:RC channel id
	p->chan_function = chan_function; // uint8_t:RC channel function, as defined in ENUM MAVLINK_RC_CHAN_MAPPING in mavlink/include/mavlink_types.h

	msg.STX = MAVLINK_STX;
	msg.len = MAVLINK_MSG_ID_RC_CHANNELS_MAPPING_LEN;
	msg.msgid = MAVLINK_MSG_ID_RC_CHANNELS_MAPPING;
	msg.sysid = mavlink_system.sysid;
	msg.compid = mavlink_system.compid;
	msg.seq = mavlink_get_channel_status(chan)->current_tx_seq;
	mavlink_get_channel_status(chan)->current_tx_seq = msg.seq + 1;
	checksum = crc_calculate_msg(&msg, msg.len + MAVLINK_CORE_HEADER_LEN);
	msg.ck_a = (uint8_t)(checksum & 0xFF); ///< Low byte
	msg.ck_b = (uint8_t)(checksum >> 8); ///< High byte

	mavlink_send_msg(chan, &msg);
}

#endif

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS_SMALL
static inline void mavlink_msg_rc_channels_mapping_send(mavlink_channel_t chan, uint8_t chan_id, uint8_t chan_function)
{
	mavlink_header_t hdr;
	mavlink_rc_channels_mapping_t payload;
	uint16_t checksum;
	mavlink_rc_channels_mapping_t *p = &payload;

	p->chan_id = chan_id; // uint8_t:RC channel id
	p->chan_function = chan_function; // uint8_t:RC channel function, as defined in ENUM MAVLINK_RC_CHAN_MAPPING in mavlink/include/mavlink_types.h

	hdr.STX = MAVLINK_STX;
	hdr.len = MAVLINK_MSG_ID_RC_CHANNELS_MAPPING_LEN;
	hdr.msgid = MAVLINK_MSG_ID_RC_CHANNELS_MAPPING;
	hdr.sysid = mavlink_system.sysid;
	hdr.compid = mavlink_system.compid;
	hdr.seq = mavlink_get_channel_status(chan)->current_tx_seq;
	mavlink_get_channel_status(chan)->current_tx_seq = hdr.seq + 1;
	mavlink_send_mem(chan, (uint8_t *)&hdr.STX, MAVLINK_NUM_HEADER_BYTES );

	crc_init(&checksum);
	checksum = crc_calculate_mem((uint8_t *)&hdr.len, &checksum, MAVLINK_CORE_HEADER_LEN);
	checksum = crc_calculate_mem((uint8_t *)&payload, &checksum, hdr.len );
	hdr.ck_a = (uint8_t)(checksum & 0xFF); ///< Low byte
	hdr.ck_b = (uint8_t)(checksum >> 8); ///< High byte

	mavlink_send_mem(chan, (uint8_t *)&payload, hdr.len);
	mavlink_send_mem(chan, (uint8_t *)&hdr.ck_a, MAVLINK_NUM_CHECKSUM_BYTES);
}

#endif
// MESSAGE RC_CHANNELS_MAPPING UNPACKING

/**
 * @brief Get field chan_id from rc_channels_mapping message
 *
 * @return RC channel id
 */
static inline uint8_t mavlink_msg_rc_channels_mapping_get_chan_id(const mavlink_message_t* msg)
{
	mavlink_rc_channels_mapping_t *p = (mavlink_rc_channels_mapping_t *)&msg->payload[0];
	return (uint8_t)(p->chan_id);
}

/**
 * @brief Get field chan_function from rc_channels_mapping message
 *
 * @return RC channel function, as defined in ENUM MAVLINK_RC_CHAN_MAPPING in mavlink/include/mavlink_types.h
 */
static inline uint8_t mavlink_msg_rc_channels_mapping_get_chan_function(const mavlink_message_t* msg)
{
	mavlink_rc_channels_mapping_t *p = (mavlink_rc_channels_mapping_t *)&msg->payload[0];
	return (uint8_t)(p->chan_function);
}

/**
 * @brief Decode a rc_channels_mapping message into a struct
 *
 * @param msg The message to decode
 * @param rc_channels_mapping C-struct to decode the message contents into
 */
static inline void mavlink_msg_rc_channels_mapping_decode(const mavlink_message_t* msg, mavlink_rc_channels_mapping_t* rc_channels_mapping)
{
	memcpy( rc_channels_mapping, msg->payload, sizeof(mavlink_rc_channels_mapping_t));
}
