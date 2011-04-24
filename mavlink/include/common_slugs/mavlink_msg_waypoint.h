// MESSAGE WAYPOINT PACKING

#define MAVLINK_MSG_ID_WAYPOINT 39
#define MAVLINK_MSG_ID_WAYPOINT_LEN 36
#define MAVLINK_MSG_39_LEN 36

typedef struct __mavlink_waypoint_t 
{
	uint8_t target_system; ///< System ID
	uint8_t target_component; ///< Component ID
	uint16_t seq; ///< Sequence
	uint8_t type; ///< 0: global (GPS), 1: local, 2: global orbit, 3: local orbit
	float orbit; ///< Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
	uint8_t orbit_direction; ///< Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
	float param1; ///< For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
	float param2; ///< For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
	uint8_t current; ///< false:0, true:1
	float x; ///< local: x position, global: longitude
	float y; ///< y position: global: latitude
	float z; ///< z position: global: altitude
	float yaw; ///< yaw orientation in radians, 0 = NORTH
	uint8_t autocontinue; ///< autocontinue to next wp
} mavlink_waypoint_t;


/**
 * @brief Pack a waypoint message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param seq Sequence
 * @param type 0: global (GPS), 1: local, 2: global orbit, 3: local orbit
 * @param orbit Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
 * @param orbit_direction Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
 * @param param1 For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
 * @param param2 For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
 * @param current false:0, true:1
 * @param x local: x position, global: longitude
 * @param y y position: global: latitude
 * @param z z position: global: altitude
 * @param yaw yaw orientation in radians, 0 = NORTH
 * @param autocontinue autocontinue to next wp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_waypoint_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t type, float orbit, uint8_t orbit_direction, float param1, float param2, uint8_t current, float x, float y, float z, float yaw, uint8_t autocontinue)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_WAYPOINT;

	p->target_system = target_system; // uint8_t:System ID
	p->target_component = target_component; // uint8_t:Component ID
	p->seq = seq; // uint16_t:Sequence
	p->type = type; // uint8_t:0: global (GPS), 1: local, 2: global orbit, 3: local orbit
	p->orbit = orbit; // float:Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
	p->orbit_direction = orbit_direction; // uint8_t:Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
	p->param1 = param1; // float:For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
	p->param2 = param2; // float:For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
	p->current = current; // uint8_t:false:0, true:1
	p->x = x; // float:local: x position, global: longitude
	p->y = y; // float:y position: global: latitude
	p->z = z; // float:z position: global: altitude
	p->yaw = yaw; // float:yaw orientation in radians, 0 = NORTH
	p->autocontinue = autocontinue; // uint8_t:autocontinue to next wp

	return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WAYPOINT_LEN);
}

/**
 * @brief Pack a waypoint message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param seq Sequence
 * @param type 0: global (GPS), 1: local, 2: global orbit, 3: local orbit
 * @param orbit Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
 * @param orbit_direction Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
 * @param param1 For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
 * @param param2 For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
 * @param current false:0, true:1
 * @param x local: x position, global: longitude
 * @param y y position: global: latitude
 * @param z z position: global: altitude
 * @param yaw yaw orientation in radians, 0 = NORTH
 * @param autocontinue autocontinue to next wp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_waypoint_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t type, float orbit, uint8_t orbit_direction, float param1, float param2, uint8_t current, float x, float y, float z, float yaw, uint8_t autocontinue)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_WAYPOINT;

	p->target_system = target_system; // uint8_t:System ID
	p->target_component = target_component; // uint8_t:Component ID
	p->seq = seq; // uint16_t:Sequence
	p->type = type; // uint8_t:0: global (GPS), 1: local, 2: global orbit, 3: local orbit
	p->orbit = orbit; // float:Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
	p->orbit_direction = orbit_direction; // uint8_t:Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
	p->param1 = param1; // float:For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
	p->param2 = param2; // float:For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
	p->current = current; // uint8_t:false:0, true:1
	p->x = x; // float:local: x position, global: longitude
	p->y = y; // float:y position: global: latitude
	p->z = z; // float:z position: global: altitude
	p->yaw = yaw; // float:yaw orientation in radians, 0 = NORTH
	p->autocontinue = autocontinue; // uint8_t:autocontinue to next wp

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WAYPOINT_LEN);
}

/**
 * @brief Encode a waypoint struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param waypoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_waypoint_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_waypoint_t* waypoint)
{
	return mavlink_msg_waypoint_pack(system_id, component_id, msg, waypoint->target_system, waypoint->target_component, waypoint->seq, waypoint->type, waypoint->orbit, waypoint->orbit_direction, waypoint->param1, waypoint->param2, waypoint->current, waypoint->x, waypoint->y, waypoint->z, waypoint->yaw, waypoint->autocontinue);
}

/**
 * @brief Send a waypoint message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param seq Sequence
 * @param type 0: global (GPS), 1: local, 2: global orbit, 3: local orbit
 * @param orbit Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
 * @param orbit_direction Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
 * @param param1 For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
 * @param param2 For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
 * @param current false:0, true:1
 * @param x local: x position, global: longitude
 * @param y y position: global: latitude
 * @param z z position: global: altitude
 * @param yaw yaw orientation in radians, 0 = NORTH
 * @param autocontinue autocontinue to next wp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
static inline void mavlink_msg_waypoint_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t type, float orbit, uint8_t orbit_direction, float param1, float param2, uint8_t current, float x, float y, float z, float yaw, uint8_t autocontinue)
{
	mavlink_message_t msg;
	uint16_t checksum;
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg.payload[0];

	p->target_system = target_system; // uint8_t:System ID
	p->target_component = target_component; // uint8_t:Component ID
	p->seq = seq; // uint16_t:Sequence
	p->type = type; // uint8_t:0: global (GPS), 1: local, 2: global orbit, 3: local orbit
	p->orbit = orbit; // float:Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
	p->orbit_direction = orbit_direction; // uint8_t:Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
	p->param1 = param1; // float:For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
	p->param2 = param2; // float:For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
	p->current = current; // uint8_t:false:0, true:1
	p->x = x; // float:local: x position, global: longitude
	p->y = y; // float:y position: global: latitude
	p->z = z; // float:z position: global: altitude
	p->yaw = yaw; // float:yaw orientation in radians, 0 = NORTH
	p->autocontinue = autocontinue; // uint8_t:autocontinue to next wp

	msg.STX = MAVLINK_STX;
	msg.len = MAVLINK_MSG_ID_WAYPOINT_LEN;
	msg.msgid = MAVLINK_MSG_ID_WAYPOINT;
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
static inline void mavlink_msg_waypoint_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t type, float orbit, uint8_t orbit_direction, float param1, float param2, uint8_t current, float x, float y, float z, float yaw, uint8_t autocontinue)
{
	mavlink_header_t hdr;
	mavlink_waypoint_t payload;
	uint16_t checksum;
	mavlink_waypoint_t *p = &payload;

	p->target_system = target_system; // uint8_t:System ID
	p->target_component = target_component; // uint8_t:Component ID
	p->seq = seq; // uint16_t:Sequence
	p->type = type; // uint8_t:0: global (GPS), 1: local, 2: global orbit, 3: local orbit
	p->orbit = orbit; // float:Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
	p->orbit_direction = orbit_direction; // uint8_t:Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
	p->param1 = param1; // float:For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
	p->param2 = param2; // float:For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
	p->current = current; // uint8_t:false:0, true:1
	p->x = x; // float:local: x position, global: longitude
	p->y = y; // float:y position: global: latitude
	p->z = z; // float:z position: global: altitude
	p->yaw = yaw; // float:yaw orientation in radians, 0 = NORTH
	p->autocontinue = autocontinue; // uint8_t:autocontinue to next wp

	hdr.STX = MAVLINK_STX;
	hdr.len = MAVLINK_MSG_ID_WAYPOINT_LEN;
	hdr.msgid = MAVLINK_MSG_ID_WAYPOINT;
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
// MESSAGE WAYPOINT UNPACKING

/**
 * @brief Get field target_system from waypoint message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_waypoint_get_target_system(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (uint8_t)(p->target_system);
}

/**
 * @brief Get field target_component from waypoint message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_waypoint_get_target_component(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (uint8_t)(p->target_component);
}

/**
 * @brief Get field seq from waypoint message
 *
 * @return Sequence
 */
static inline uint16_t mavlink_msg_waypoint_get_seq(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (uint16_t)(p->seq);
}

/**
 * @brief Get field type from waypoint message
 *
 * @return 0: global (GPS), 1: local, 2: global orbit, 3: local orbit
 */
static inline uint8_t mavlink_msg_waypoint_get_type(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (uint8_t)(p->type);
}

/**
 * @brief Get field orbit from waypoint message
 *
 * @return Orbit to circle around the waypoint, in meters. Set to 0 to fly straight through the waypoint
 */
static inline float mavlink_msg_waypoint_get_orbit(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (float)(p->orbit);
}

/**
 * @brief Get field orbit_direction from waypoint message
 *
 * @return Direction of the orbit circling: 0: clockwise, 1: counter-clockwise
 */
static inline uint8_t mavlink_msg_waypoint_get_orbit_direction(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (uint8_t)(p->orbit_direction);
}

/**
 * @brief Get field param1 from waypoint message
 *
 * @return For waypoints of type 0 and 1: Radius in which the waypoint is accepted as reached, in meters
 */
static inline float mavlink_msg_waypoint_get_param1(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (float)(p->param1);
}

/**
 * @brief Get field param2 from waypoint message
 *
 * @return For waypoints of type 0 and 1: Time that the MAV should stay inside the orbit before advancing, in milliseconds
 */
static inline float mavlink_msg_waypoint_get_param2(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (float)(p->param2);
}

/**
 * @brief Get field current from waypoint message
 *
 * @return false:0, true:1
 */
static inline uint8_t mavlink_msg_waypoint_get_current(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (uint8_t)(p->current);
}

/**
 * @brief Get field x from waypoint message
 *
 * @return local: x position, global: longitude
 */
static inline float mavlink_msg_waypoint_get_x(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (float)(p->x);
}

/**
 * @brief Get field y from waypoint message
 *
 * @return y position: global: latitude
 */
static inline float mavlink_msg_waypoint_get_y(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (float)(p->y);
}

/**
 * @brief Get field z from waypoint message
 *
 * @return z position: global: altitude
 */
static inline float mavlink_msg_waypoint_get_z(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (float)(p->z);
}

/**
 * @brief Get field yaw from waypoint message
 *
 * @return yaw orientation in radians, 0 = NORTH
 */
static inline float mavlink_msg_waypoint_get_yaw(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (float)(p->yaw);
}

/**
 * @brief Get field autocontinue from waypoint message
 *
 * @return autocontinue to next wp
 */
static inline uint8_t mavlink_msg_waypoint_get_autocontinue(const mavlink_message_t* msg)
{
	mavlink_waypoint_t *p = (mavlink_waypoint_t *)&msg->payload[0];
	return (uint8_t)(p->autocontinue);
}

/**
 * @brief Decode a waypoint message into a struct
 *
 * @param msg The message to decode
 * @param waypoint C-struct to decode the message contents into
 */
static inline void mavlink_msg_waypoint_decode(const mavlink_message_t* msg, mavlink_waypoint_t* waypoint)
{
	memcpy( waypoint, msg->payload, sizeof(mavlink_waypoint_t));
}
