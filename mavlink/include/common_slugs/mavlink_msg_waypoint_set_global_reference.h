// MESSAGE WAYPOINT_SET_GLOBAL_REFERENCE PACKING

#define MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE 48
#define MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN 34
#define MAVLINK_MSG_48_LEN 34

typedef struct __mavlink_waypoint_set_global_reference_t 
{
	uint8_t target_system; ///< System ID
	uint8_t target_component; ///< Component ID
	float global_x; ///< global x position
	float global_y; ///< global y position
	float global_z; ///< global z position
	float global_yaw; ///< global yaw orientation in radians, 0 = NORTH
	float local_x; ///< local x position that matches the global x position
	float local_y; ///< local y position that matches the global y position
	float local_z; ///< local z position that matches the global z position
	float local_yaw; ///< local yaw that matches the global yaw orientation
} mavlink_waypoint_set_global_reference_t;


/**
 * @brief Pack a waypoint_set_global_reference message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param global_x global x position
 * @param global_y global y position
 * @param global_z global z position
 * @param global_yaw global yaw orientation in radians, 0 = NORTH
 * @param local_x local x position that matches the global x position
 * @param local_y local y position that matches the global y position
 * @param local_z local z position that matches the global z position
 * @param local_yaw local yaw that matches the global yaw orientation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_waypoint_set_global_reference_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t target_system, uint8_t target_component, float global_x, float global_y, float global_z, float global_yaw, float local_x, float local_y, float local_z, float local_yaw)
{
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE;

	p->target_system = target_system; // uint8_t:System ID
	p->target_component = target_component; // uint8_t:Component ID
	p->global_x = global_x; // float:global x position
	p->global_y = global_y; // float:global y position
	p->global_z = global_z; // float:global z position
	p->global_yaw = global_yaw; // float:global yaw orientation in radians, 0 = NORTH
	p->local_x = local_x; // float:local x position that matches the global x position
	p->local_y = local_y; // float:local y position that matches the global y position
	p->local_z = local_z; // float:local z position that matches the global z position
	p->local_yaw = local_yaw; // float:local yaw that matches the global yaw orientation

	return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
}

/**
 * @brief Pack a waypoint_set_global_reference message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param global_x global x position
 * @param global_y global y position
 * @param global_z global z position
 * @param global_yaw global yaw orientation in radians, 0 = NORTH
 * @param local_x local x position that matches the global x position
 * @param local_y local y position that matches the global y position
 * @param local_z local z position that matches the global z position
 * @param local_yaw local yaw that matches the global yaw orientation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_waypoint_set_global_reference_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint8_t target_system, uint8_t target_component, float global_x, float global_y, float global_z, float global_yaw, float local_x, float local_y, float local_z, float local_yaw)
{
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE;

	p->target_system = target_system; // uint8_t:System ID
	p->target_component = target_component; // uint8_t:Component ID
	p->global_x = global_x; // float:global x position
	p->global_y = global_y; // float:global y position
	p->global_z = global_z; // float:global z position
	p->global_yaw = global_yaw; // float:global yaw orientation in radians, 0 = NORTH
	p->local_x = local_x; // float:local x position that matches the global x position
	p->local_y = local_y; // float:local y position that matches the global y position
	p->local_z = local_z; // float:local z position that matches the global z position
	p->local_yaw = local_yaw; // float:local yaw that matches the global yaw orientation

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN);
}

/**
 * @brief Encode a waypoint_set_global_reference struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param waypoint_set_global_reference C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_waypoint_set_global_reference_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_waypoint_set_global_reference_t* waypoint_set_global_reference)
{
	return mavlink_msg_waypoint_set_global_reference_pack(system_id, component_id, msg, waypoint_set_global_reference->target_system, waypoint_set_global_reference->target_component, waypoint_set_global_reference->global_x, waypoint_set_global_reference->global_y, waypoint_set_global_reference->global_z, waypoint_set_global_reference->global_yaw, waypoint_set_global_reference->local_x, waypoint_set_global_reference->local_y, waypoint_set_global_reference->local_z, waypoint_set_global_reference->local_yaw);
}

/**
 * @brief Send a waypoint_set_global_reference message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param global_x global x position
 * @param global_y global y position
 * @param global_z global z position
 * @param global_yaw global yaw orientation in radians, 0 = NORTH
 * @param local_x local x position that matches the global x position
 * @param local_y local y position that matches the global y position
 * @param local_z local z position that matches the global z position
 * @param local_yaw local yaw that matches the global yaw orientation
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
static inline void mavlink_msg_waypoint_set_global_reference_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, float global_x, float global_y, float global_z, float global_yaw, float local_x, float local_y, float local_z, float local_yaw)
{
	mavlink_message_t msg;
	uint16_t checksum;
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg.payload[0];

	p->target_system = target_system; // uint8_t:System ID
	p->target_component = target_component; // uint8_t:Component ID
	p->global_x = global_x; // float:global x position
	p->global_y = global_y; // float:global y position
	p->global_z = global_z; // float:global z position
	p->global_yaw = global_yaw; // float:global yaw orientation in radians, 0 = NORTH
	p->local_x = local_x; // float:local x position that matches the global x position
	p->local_y = local_y; // float:local y position that matches the global y position
	p->local_z = local_z; // float:local z position that matches the global z position
	p->local_yaw = local_yaw; // float:local yaw that matches the global yaw orientation

	msg.STX = MAVLINK_STX;
	msg.len = MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN;
	msg.msgid = MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE;
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
static inline void mavlink_msg_waypoint_set_global_reference_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, float global_x, float global_y, float global_z, float global_yaw, float local_x, float local_y, float local_z, float local_yaw)
{
	mavlink_header_t hdr;
	mavlink_waypoint_set_global_reference_t payload;
	uint16_t checksum;
	mavlink_waypoint_set_global_reference_t *p = &payload;

	p->target_system = target_system; // uint8_t:System ID
	p->target_component = target_component; // uint8_t:Component ID
	p->global_x = global_x; // float:global x position
	p->global_y = global_y; // float:global y position
	p->global_z = global_z; // float:global z position
	p->global_yaw = global_yaw; // float:global yaw orientation in radians, 0 = NORTH
	p->local_x = local_x; // float:local x position that matches the global x position
	p->local_y = local_y; // float:local y position that matches the global y position
	p->local_z = local_z; // float:local z position that matches the global z position
	p->local_yaw = local_yaw; // float:local yaw that matches the global yaw orientation

	hdr.STX = MAVLINK_STX;
	hdr.len = MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE_LEN;
	hdr.msgid = MAVLINK_MSG_ID_WAYPOINT_SET_GLOBAL_REFERENCE;
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
// MESSAGE WAYPOINT_SET_GLOBAL_REFERENCE UNPACKING

/**
 * @brief Get field target_system from waypoint_set_global_reference message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_waypoint_set_global_reference_get_target_system(const mavlink_message_t* msg)
{
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg->payload[0];
	return (uint8_t)(p->target_system);
}

/**
 * @brief Get field target_component from waypoint_set_global_reference message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_waypoint_set_global_reference_get_target_component(const mavlink_message_t* msg)
{
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg->payload[0];
	return (uint8_t)(p->target_component);
}

/**
 * @brief Get field global_x from waypoint_set_global_reference message
 *
 * @return global x position
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_global_x(const mavlink_message_t* msg)
{
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg->payload[0];
	return (float)(p->global_x);
}

/**
 * @brief Get field global_y from waypoint_set_global_reference message
 *
 * @return global y position
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_global_y(const mavlink_message_t* msg)
{
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg->payload[0];
	return (float)(p->global_y);
}

/**
 * @brief Get field global_z from waypoint_set_global_reference message
 *
 * @return global z position
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_global_z(const mavlink_message_t* msg)
{
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg->payload[0];
	return (float)(p->global_z);
}

/**
 * @brief Get field global_yaw from waypoint_set_global_reference message
 *
 * @return global yaw orientation in radians, 0 = NORTH
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_global_yaw(const mavlink_message_t* msg)
{
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg->payload[0];
	return (float)(p->global_yaw);
}

/**
 * @brief Get field local_x from waypoint_set_global_reference message
 *
 * @return local x position that matches the global x position
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_local_x(const mavlink_message_t* msg)
{
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg->payload[0];
	return (float)(p->local_x);
}

/**
 * @brief Get field local_y from waypoint_set_global_reference message
 *
 * @return local y position that matches the global y position
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_local_y(const mavlink_message_t* msg)
{
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg->payload[0];
	return (float)(p->local_y);
}

/**
 * @brief Get field local_z from waypoint_set_global_reference message
 *
 * @return local z position that matches the global z position
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_local_z(const mavlink_message_t* msg)
{
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg->payload[0];
	return (float)(p->local_z);
}

/**
 * @brief Get field local_yaw from waypoint_set_global_reference message
 *
 * @return local yaw that matches the global yaw orientation
 */
static inline float mavlink_msg_waypoint_set_global_reference_get_local_yaw(const mavlink_message_t* msg)
{
	mavlink_waypoint_set_global_reference_t *p = (mavlink_waypoint_set_global_reference_t *)&msg->payload[0];
	return (float)(p->local_yaw);
}

/**
 * @brief Decode a waypoint_set_global_reference message into a struct
 *
 * @param msg The message to decode
 * @param waypoint_set_global_reference C-struct to decode the message contents into
 */
static inline void mavlink_msg_waypoint_set_global_reference_decode(const mavlink_message_t* msg, mavlink_waypoint_set_global_reference_t* waypoint_set_global_reference)
{
	memcpy( waypoint_set_global_reference, msg->payload, sizeof(mavlink_waypoint_set_global_reference_t));
}
