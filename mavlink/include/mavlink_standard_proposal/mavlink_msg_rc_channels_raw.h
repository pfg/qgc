// MESSAGE RC_CHANNELS_RAW PACKING

#define MAVLINK_MSG_ID_RC_CHANNELS_RAW 56
#define MAVLINK_MSG_ID_RC_CHANNELS_RAW_LEN 24
#define MAVLINK_MSG_56_LEN 24

typedef struct __mavlink_rc_channels_raw_t 
{
	uint16_t chan1; ///< RC channel 1 value, in microseconds
	uint16_t chan2; ///< RC channel 2 value, in microseconds
	uint16_t chan3; ///< RC channel 3 value, in microseconds
	uint16_t chan4; ///< RC channel 4 value, in microseconds
	uint16_t chan5; ///< RC channel 5 value, in microseconds
	uint16_t chan6; ///< RC channel 6 value, in microseconds
	uint16_t chan7; ///< RC channel 7 value, in microseconds
	uint16_t chan8; ///< RC channel 8 value, in microseconds
	uint16_t chan9; ///< RC channel 9 value, in microseconds
	uint16_t chan10; ///< RC channel 10 value, in microseconds
	uint16_t chan11; ///< RC channel 11 value, in microseconds
	uint16_t chan12; ///< RC channel 12 value, in microseconds
} mavlink_rc_channels_raw_t;


/**
 * @brief Pack a rc_channels_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param chan1 RC channel 1 value, in microseconds
 * @param chan2 RC channel 2 value, in microseconds
 * @param chan3 RC channel 3 value, in microseconds
 * @param chan4 RC channel 4 value, in microseconds
 * @param chan5 RC channel 5 value, in microseconds
 * @param chan6 RC channel 6 value, in microseconds
 * @param chan7 RC channel 7 value, in microseconds
 * @param chan8 RC channel 8 value, in microseconds
 * @param chan9 RC channel 9 value, in microseconds
 * @param chan10 RC channel 10 value, in microseconds
 * @param chan11 RC channel 11 value, in microseconds
 * @param chan12 RC channel 12 value, in microseconds
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rc_channels_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint16_t chan1, uint16_t chan2, uint16_t chan3, uint16_t chan4, uint16_t chan5, uint16_t chan6, uint16_t chan7, uint16_t chan8, uint16_t chan9, uint16_t chan10, uint16_t chan11, uint16_t chan12)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_RC_CHANNELS_RAW;

	p->chan1 = chan1; // uint16_t:RC channel 1 value, in microseconds
	p->chan2 = chan2; // uint16_t:RC channel 2 value, in microseconds
	p->chan3 = chan3; // uint16_t:RC channel 3 value, in microseconds
	p->chan4 = chan4; // uint16_t:RC channel 4 value, in microseconds
	p->chan5 = chan5; // uint16_t:RC channel 5 value, in microseconds
	p->chan6 = chan6; // uint16_t:RC channel 6 value, in microseconds
	p->chan7 = chan7; // uint16_t:RC channel 7 value, in microseconds
	p->chan8 = chan8; // uint16_t:RC channel 8 value, in microseconds
	p->chan9 = chan9; // uint16_t:RC channel 9 value, in microseconds
	p->chan10 = chan10; // uint16_t:RC channel 10 value, in microseconds
	p->chan11 = chan11; // uint16_t:RC channel 11 value, in microseconds
	p->chan12 = chan12; // uint16_t:RC channel 12 value, in microseconds

	return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RC_CHANNELS_RAW_LEN);
}

/**
 * @brief Pack a rc_channels_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param chan1 RC channel 1 value, in microseconds
 * @param chan2 RC channel 2 value, in microseconds
 * @param chan3 RC channel 3 value, in microseconds
 * @param chan4 RC channel 4 value, in microseconds
 * @param chan5 RC channel 5 value, in microseconds
 * @param chan6 RC channel 6 value, in microseconds
 * @param chan7 RC channel 7 value, in microseconds
 * @param chan8 RC channel 8 value, in microseconds
 * @param chan9 RC channel 9 value, in microseconds
 * @param chan10 RC channel 10 value, in microseconds
 * @param chan11 RC channel 11 value, in microseconds
 * @param chan12 RC channel 12 value, in microseconds
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rc_channels_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint16_t chan1, uint16_t chan2, uint16_t chan3, uint16_t chan4, uint16_t chan5, uint16_t chan6, uint16_t chan7, uint16_t chan8, uint16_t chan9, uint16_t chan10, uint16_t chan11, uint16_t chan12)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_RC_CHANNELS_RAW;

	p->chan1 = chan1; // uint16_t:RC channel 1 value, in microseconds
	p->chan2 = chan2; // uint16_t:RC channel 2 value, in microseconds
	p->chan3 = chan3; // uint16_t:RC channel 3 value, in microseconds
	p->chan4 = chan4; // uint16_t:RC channel 4 value, in microseconds
	p->chan5 = chan5; // uint16_t:RC channel 5 value, in microseconds
	p->chan6 = chan6; // uint16_t:RC channel 6 value, in microseconds
	p->chan7 = chan7; // uint16_t:RC channel 7 value, in microseconds
	p->chan8 = chan8; // uint16_t:RC channel 8 value, in microseconds
	p->chan9 = chan9; // uint16_t:RC channel 9 value, in microseconds
	p->chan10 = chan10; // uint16_t:RC channel 10 value, in microseconds
	p->chan11 = chan11; // uint16_t:RC channel 11 value, in microseconds
	p->chan12 = chan12; // uint16_t:RC channel 12 value, in microseconds

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RC_CHANNELS_RAW_LEN);
}

/**
 * @brief Encode a rc_channels_raw struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rc_channels_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rc_channels_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rc_channels_raw_t* rc_channels_raw)
{
	return mavlink_msg_rc_channels_raw_pack(system_id, component_id, msg, rc_channels_raw->chan1, rc_channels_raw->chan2, rc_channels_raw->chan3, rc_channels_raw->chan4, rc_channels_raw->chan5, rc_channels_raw->chan6, rc_channels_raw->chan7, rc_channels_raw->chan8, rc_channels_raw->chan9, rc_channels_raw->chan10, rc_channels_raw->chan11, rc_channels_raw->chan12);
}

/**
 * @brief Send a rc_channels_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param chan1 RC channel 1 value, in microseconds
 * @param chan2 RC channel 2 value, in microseconds
 * @param chan3 RC channel 3 value, in microseconds
 * @param chan4 RC channel 4 value, in microseconds
 * @param chan5 RC channel 5 value, in microseconds
 * @param chan6 RC channel 6 value, in microseconds
 * @param chan7 RC channel 7 value, in microseconds
 * @param chan8 RC channel 8 value, in microseconds
 * @param chan9 RC channel 9 value, in microseconds
 * @param chan10 RC channel 10 value, in microseconds
 * @param chan11 RC channel 11 value, in microseconds
 * @param chan12 RC channel 12 value, in microseconds
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
static inline void mavlink_msg_rc_channels_raw_send(mavlink_channel_t chan, uint16_t chan1, uint16_t chan2, uint16_t chan3, uint16_t chan4, uint16_t chan5, uint16_t chan6, uint16_t chan7, uint16_t chan8, uint16_t chan9, uint16_t chan10, uint16_t chan11, uint16_t chan12)
{
	mavlink_message_t msg;
	uint16_t checksum;
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg.payload[0];

	p->chan1 = chan1; // uint16_t:RC channel 1 value, in microseconds
	p->chan2 = chan2; // uint16_t:RC channel 2 value, in microseconds
	p->chan3 = chan3; // uint16_t:RC channel 3 value, in microseconds
	p->chan4 = chan4; // uint16_t:RC channel 4 value, in microseconds
	p->chan5 = chan5; // uint16_t:RC channel 5 value, in microseconds
	p->chan6 = chan6; // uint16_t:RC channel 6 value, in microseconds
	p->chan7 = chan7; // uint16_t:RC channel 7 value, in microseconds
	p->chan8 = chan8; // uint16_t:RC channel 8 value, in microseconds
	p->chan9 = chan9; // uint16_t:RC channel 9 value, in microseconds
	p->chan10 = chan10; // uint16_t:RC channel 10 value, in microseconds
	p->chan11 = chan11; // uint16_t:RC channel 11 value, in microseconds
	p->chan12 = chan12; // uint16_t:RC channel 12 value, in microseconds

	msg.STX = MAVLINK_STX;
	msg.len = MAVLINK_MSG_ID_RC_CHANNELS_RAW_LEN;
	msg.msgid = MAVLINK_MSG_ID_RC_CHANNELS_RAW;
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
static inline void mavlink_msg_rc_channels_raw_send(mavlink_channel_t chan, uint16_t chan1, uint16_t chan2, uint16_t chan3, uint16_t chan4, uint16_t chan5, uint16_t chan6, uint16_t chan7, uint16_t chan8, uint16_t chan9, uint16_t chan10, uint16_t chan11, uint16_t chan12)
{
	mavlink_header_t hdr;
	mavlink_rc_channels_raw_t payload;
	uint16_t checksum;
	mavlink_rc_channels_raw_t *p = &payload;

	p->chan1 = chan1; // uint16_t:RC channel 1 value, in microseconds
	p->chan2 = chan2; // uint16_t:RC channel 2 value, in microseconds
	p->chan3 = chan3; // uint16_t:RC channel 3 value, in microseconds
	p->chan4 = chan4; // uint16_t:RC channel 4 value, in microseconds
	p->chan5 = chan5; // uint16_t:RC channel 5 value, in microseconds
	p->chan6 = chan6; // uint16_t:RC channel 6 value, in microseconds
	p->chan7 = chan7; // uint16_t:RC channel 7 value, in microseconds
	p->chan8 = chan8; // uint16_t:RC channel 8 value, in microseconds
	p->chan9 = chan9; // uint16_t:RC channel 9 value, in microseconds
	p->chan10 = chan10; // uint16_t:RC channel 10 value, in microseconds
	p->chan11 = chan11; // uint16_t:RC channel 11 value, in microseconds
	p->chan12 = chan12; // uint16_t:RC channel 12 value, in microseconds

	hdr.STX = MAVLINK_STX;
	hdr.len = MAVLINK_MSG_ID_RC_CHANNELS_RAW_LEN;
	hdr.msgid = MAVLINK_MSG_ID_RC_CHANNELS_RAW;
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
// MESSAGE RC_CHANNELS_RAW UNPACKING

/**
 * @brief Get field chan1 from rc_channels_raw message
 *
 * @return RC channel 1 value, in microseconds
 */
static inline uint16_t mavlink_msg_rc_channels_raw_get_chan1(const mavlink_message_t* msg)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	return (uint16_t)(p->chan1);
}

/**
 * @brief Get field chan2 from rc_channels_raw message
 *
 * @return RC channel 2 value, in microseconds
 */
static inline uint16_t mavlink_msg_rc_channels_raw_get_chan2(const mavlink_message_t* msg)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	return (uint16_t)(p->chan2);
}

/**
 * @brief Get field chan3 from rc_channels_raw message
 *
 * @return RC channel 3 value, in microseconds
 */
static inline uint16_t mavlink_msg_rc_channels_raw_get_chan3(const mavlink_message_t* msg)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	return (uint16_t)(p->chan3);
}

/**
 * @brief Get field chan4 from rc_channels_raw message
 *
 * @return RC channel 4 value, in microseconds
 */
static inline uint16_t mavlink_msg_rc_channels_raw_get_chan4(const mavlink_message_t* msg)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	return (uint16_t)(p->chan4);
}

/**
 * @brief Get field chan5 from rc_channels_raw message
 *
 * @return RC channel 5 value, in microseconds
 */
static inline uint16_t mavlink_msg_rc_channels_raw_get_chan5(const mavlink_message_t* msg)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	return (uint16_t)(p->chan5);
}

/**
 * @brief Get field chan6 from rc_channels_raw message
 *
 * @return RC channel 6 value, in microseconds
 */
static inline uint16_t mavlink_msg_rc_channels_raw_get_chan6(const mavlink_message_t* msg)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	return (uint16_t)(p->chan6);
}

/**
 * @brief Get field chan7 from rc_channels_raw message
 *
 * @return RC channel 7 value, in microseconds
 */
static inline uint16_t mavlink_msg_rc_channels_raw_get_chan7(const mavlink_message_t* msg)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	return (uint16_t)(p->chan7);
}

/**
 * @brief Get field chan8 from rc_channels_raw message
 *
 * @return RC channel 8 value, in microseconds
 */
static inline uint16_t mavlink_msg_rc_channels_raw_get_chan8(const mavlink_message_t* msg)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	return (uint16_t)(p->chan8);
}

/**
 * @brief Get field chan9 from rc_channels_raw message
 *
 * @return RC channel 9 value, in microseconds
 */
static inline uint16_t mavlink_msg_rc_channels_raw_get_chan9(const mavlink_message_t* msg)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	return (uint16_t)(p->chan9);
}

/**
 * @brief Get field chan10 from rc_channels_raw message
 *
 * @return RC channel 10 value, in microseconds
 */
static inline uint16_t mavlink_msg_rc_channels_raw_get_chan10(const mavlink_message_t* msg)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	return (uint16_t)(p->chan10);
}

/**
 * @brief Get field chan11 from rc_channels_raw message
 *
 * @return RC channel 11 value, in microseconds
 */
static inline uint16_t mavlink_msg_rc_channels_raw_get_chan11(const mavlink_message_t* msg)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	return (uint16_t)(p->chan11);
}

/**
 * @brief Get field chan12 from rc_channels_raw message
 *
 * @return RC channel 12 value, in microseconds
 */
static inline uint16_t mavlink_msg_rc_channels_raw_get_chan12(const mavlink_message_t* msg)
{
	mavlink_rc_channels_raw_t *p = (mavlink_rc_channels_raw_t *)&msg->payload[0];
	return (uint16_t)(p->chan12);
}

/**
 * @brief Decode a rc_channels_raw message into a struct
 *
 * @param msg The message to decode
 * @param rc_channels_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_rc_channels_raw_decode(const mavlink_message_t* msg, mavlink_rc_channels_raw_t* rc_channels_raw)
{
	memcpy( rc_channels_raw, msg->payload, sizeof(mavlink_rc_channels_raw_t));
}
