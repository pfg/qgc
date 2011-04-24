// MESSAGE ACKNOWLEDGE PACKING

#define MAVLINK_MSG_ID_ACKNOWLEDGE 30
#define MAVLINK_MSG_ID_ACKNOWLEDGE_LEN 3
#define MAVLINK_MSG_30_LEN 3

typedef struct __mavlink_acknowledge_t 
{
	uint8_t target_system; ///< The system executing the action
	uint8_t target_component; ///< Component ID
	uint8_t akn_id; ///< The id of the action being successfully executed and acknowledged
} mavlink_acknowledge_t;


/**
 * @brief Pack a acknowledge message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system The system executing the action
 * @param target_component Component ID
 * @param akn_id The id of the action being successfully executed and acknowledged
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_acknowledge_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t target_system, uint8_t target_component, uint8_t akn_id)
{
	mavlink_acknowledge_t *p = (mavlink_acknowledge_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_ACKNOWLEDGE;

	p->target_system = target_system; // uint8_t:The system executing the action
	p->target_component = target_component; // uint8_t:Component ID
	p->akn_id = akn_id; // uint8_t:The id of the action being successfully executed and acknowledged

	return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ACKNOWLEDGE_LEN);
}

/**
 * @brief Pack a acknowledge message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system The system executing the action
 * @param target_component Component ID
 * @param akn_id The id of the action being successfully executed and acknowledged
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_acknowledge_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint8_t target_system, uint8_t target_component, uint8_t akn_id)
{
	mavlink_acknowledge_t *p = (mavlink_acknowledge_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_ACKNOWLEDGE;

	p->target_system = target_system; // uint8_t:The system executing the action
	p->target_component = target_component; // uint8_t:Component ID
	p->akn_id = akn_id; // uint8_t:The id of the action being successfully executed and acknowledged

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ACKNOWLEDGE_LEN);
}

/**
 * @brief Encode a acknowledge struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param acknowledge C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_acknowledge_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_acknowledge_t* acknowledge)
{
	return mavlink_msg_acknowledge_pack(system_id, component_id, msg, acknowledge->target_system, acknowledge->target_component, acknowledge->akn_id);
}

/**
 * @brief Send a acknowledge message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system The system executing the action
 * @param target_component Component ID
 * @param akn_id The id of the action being successfully executed and acknowledged
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
static inline void mavlink_msg_acknowledge_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t akn_id)
{
	mavlink_message_t msg;
	uint16_t checksum;
	mavlink_acknowledge_t *p = (mavlink_acknowledge_t *)&msg.payload[0];

	p->target_system = target_system; // uint8_t:The system executing the action
	p->target_component = target_component; // uint8_t:Component ID
	p->akn_id = akn_id; // uint8_t:The id of the action being successfully executed and acknowledged

	msg.STX = MAVLINK_STX;
	msg.len = MAVLINK_MSG_ID_ACKNOWLEDGE_LEN;
	msg.msgid = MAVLINK_MSG_ID_ACKNOWLEDGE;
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
static inline void mavlink_msg_acknowledge_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t akn_id)
{
	mavlink_header_t hdr;
	mavlink_acknowledge_t payload;
	uint16_t checksum;
	mavlink_acknowledge_t *p = &payload;

	p->target_system = target_system; // uint8_t:The system executing the action
	p->target_component = target_component; // uint8_t:Component ID
	p->akn_id = akn_id; // uint8_t:The id of the action being successfully executed and acknowledged

	hdr.STX = MAVLINK_STX;
	hdr.len = MAVLINK_MSG_ID_ACKNOWLEDGE_LEN;
	hdr.msgid = MAVLINK_MSG_ID_ACKNOWLEDGE;
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
// MESSAGE ACKNOWLEDGE UNPACKING

/**
 * @brief Get field target_system from acknowledge message
 *
 * @return The system executing the action
 */
static inline uint8_t mavlink_msg_acknowledge_get_target_system(const mavlink_message_t* msg)
{
	mavlink_acknowledge_t *p = (mavlink_acknowledge_t *)&msg->payload[0];
	return (uint8_t)(p->target_system);
}

/**
 * @brief Get field target_component from acknowledge message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_acknowledge_get_target_component(const mavlink_message_t* msg)
{
	mavlink_acknowledge_t *p = (mavlink_acknowledge_t *)&msg->payload[0];
	return (uint8_t)(p->target_component);
}

/**
 * @brief Get field akn_id from acknowledge message
 *
 * @return The id of the action being successfully executed and acknowledged
 */
static inline uint8_t mavlink_msg_acknowledge_get_akn_id(const mavlink_message_t* msg)
{
	mavlink_acknowledge_t *p = (mavlink_acknowledge_t *)&msg->payload[0];
	return (uint8_t)(p->akn_id);
}

/**
 * @brief Decode a acknowledge message into a struct
 *
 * @param msg The message to decode
 * @param acknowledge C-struct to decode the message contents into
 */
static inline void mavlink_msg_acknowledge_decode(const mavlink_message_t* msg, mavlink_acknowledge_t* acknowledge)
{
	memcpy( acknowledge, msg->payload, sizeof(mavlink_acknowledge_t));
}
