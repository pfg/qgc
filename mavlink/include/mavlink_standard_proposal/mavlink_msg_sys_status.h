// MESSAGE SYS_STATUS PACKING

#define MAVLINK_MSG_ID_SYS_STATUS 2
#define MAVLINK_MSG_ID_SYS_STATUS_LEN 7
#define MAVLINK_MSG_2_LEN 7

typedef struct __mavlink_sys_status_t 
{
	uint16_t packet_drop; ///< Dropped packets
	uint8_t mode; ///< System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
	uint8_t nav_mode; ///< Navigation mode, see MAV_NAV_MODE ENUM
	uint8_t status; ///< System status flag, see MAV_STATUS ENUM
	uint8_t failure; ///< Failure code description, see MAV_FAILURE ENUM
	uint8_t motor_block; ///< Motor block status flag
} mavlink_sys_status_t;


/**
 * @brief Pack a sys_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param packet_drop Dropped packets
 * @param mode System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
 * @param nav_mode Navigation mode, see MAV_NAV_MODE ENUM
 * @param status System status flag, see MAV_STATUS ENUM
 * @param failure Failure code description, see MAV_FAILURE ENUM
 * @param motor_block Motor block status flag
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint16_t packet_drop, uint8_t mode, uint8_t nav_mode, uint8_t status, uint8_t failure, uint8_t motor_block)
{
	mavlink_sys_status_t *p = (mavlink_sys_status_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_SYS_STATUS;

	p->packet_drop = packet_drop; // uint16_t:Dropped packets
	p->mode = mode; // uint8_t:System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
	p->nav_mode = nav_mode; // uint8_t:Navigation mode, see MAV_NAV_MODE ENUM
	p->status = status; // uint8_t:System status flag, see MAV_STATUS ENUM
	p->failure = failure; // uint8_t:Failure code description, see MAV_FAILURE ENUM
	p->motor_block = motor_block; // uint8_t:Motor block status flag

	return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYS_STATUS_LEN);
}

/**
 * @brief Pack a sys_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param packet_drop Dropped packets
 * @param mode System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
 * @param nav_mode Navigation mode, see MAV_NAV_MODE ENUM
 * @param status System status flag, see MAV_STATUS ENUM
 * @param failure Failure code description, see MAV_FAILURE ENUM
 * @param motor_block Motor block status flag
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sys_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint16_t packet_drop, uint8_t mode, uint8_t nav_mode, uint8_t status, uint8_t failure, uint8_t motor_block)
{
	mavlink_sys_status_t *p = (mavlink_sys_status_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_SYS_STATUS;

	p->packet_drop = packet_drop; // uint16_t:Dropped packets
	p->mode = mode; // uint8_t:System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
	p->nav_mode = nav_mode; // uint8_t:Navigation mode, see MAV_NAV_MODE ENUM
	p->status = status; // uint8_t:System status flag, see MAV_STATUS ENUM
	p->failure = failure; // uint8_t:Failure code description, see MAV_FAILURE ENUM
	p->motor_block = motor_block; // uint8_t:Motor block status flag

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SYS_STATUS_LEN);
}

/**
 * @brief Encode a sys_status struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sys_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sys_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sys_status_t* sys_status)
{
	return mavlink_msg_sys_status_pack(system_id, component_id, msg, sys_status->packet_drop, sys_status->mode, sys_status->nav_mode, sys_status->status, sys_status->failure, sys_status->motor_block);
}

/**
 * @brief Send a sys_status message
 * @param chan MAVLink channel to send the message
 *
 * @param packet_drop Dropped packets
 * @param mode System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
 * @param nav_mode Navigation mode, see MAV_NAV_MODE ENUM
 * @param status System status flag, see MAV_STATUS ENUM
 * @param failure Failure code description, see MAV_FAILURE ENUM
 * @param motor_block Motor block status flag
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
static inline void mavlink_msg_sys_status_send(mavlink_channel_t chan, uint16_t packet_drop, uint8_t mode, uint8_t nav_mode, uint8_t status, uint8_t failure, uint8_t motor_block)
{
	mavlink_message_t msg;
	uint16_t checksum;
	mavlink_sys_status_t *p = (mavlink_sys_status_t *)&msg.payload[0];

	p->packet_drop = packet_drop; // uint16_t:Dropped packets
	p->mode = mode; // uint8_t:System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
	p->nav_mode = nav_mode; // uint8_t:Navigation mode, see MAV_NAV_MODE ENUM
	p->status = status; // uint8_t:System status flag, see MAV_STATUS ENUM
	p->failure = failure; // uint8_t:Failure code description, see MAV_FAILURE ENUM
	p->motor_block = motor_block; // uint8_t:Motor block status flag

	msg.STX = MAVLINK_STX;
	msg.len = MAVLINK_MSG_ID_SYS_STATUS_LEN;
	msg.msgid = MAVLINK_MSG_ID_SYS_STATUS;
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
static inline void mavlink_msg_sys_status_send(mavlink_channel_t chan, uint16_t packet_drop, uint8_t mode, uint8_t nav_mode, uint8_t status, uint8_t failure, uint8_t motor_block)
{
	mavlink_header_t hdr;
	mavlink_sys_status_t payload;
	uint16_t checksum;
	mavlink_sys_status_t *p = &payload;

	p->packet_drop = packet_drop; // uint16_t:Dropped packets
	p->mode = mode; // uint8_t:System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
	p->nav_mode = nav_mode; // uint8_t:Navigation mode, see MAV_NAV_MODE ENUM
	p->status = status; // uint8_t:System status flag, see MAV_STATUS ENUM
	p->failure = failure; // uint8_t:Failure code description, see MAV_FAILURE ENUM
	p->motor_block = motor_block; // uint8_t:Motor block status flag

	hdr.STX = MAVLINK_STX;
	hdr.len = MAVLINK_MSG_ID_SYS_STATUS_LEN;
	hdr.msgid = MAVLINK_MSG_ID_SYS_STATUS;
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
// MESSAGE SYS_STATUS UNPACKING

/**
 * @brief Get field packet_drop from sys_status message
 *
 * @return Dropped packets
 */
static inline uint16_t mavlink_msg_sys_status_get_packet_drop(const mavlink_message_t* msg)
{
	mavlink_sys_status_t *p = (mavlink_sys_status_t *)&msg->payload[0];
	return (uint16_t)(p->packet_drop);
}

/**
 * @brief Get field mode from sys_status message
 *
 * @return System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
 */
static inline uint8_t mavlink_msg_sys_status_get_mode(const mavlink_message_t* msg)
{
	mavlink_sys_status_t *p = (mavlink_sys_status_t *)&msg->payload[0];
	return (uint8_t)(p->mode);
}

/**
 * @brief Get field nav_mode from sys_status message
 *
 * @return Navigation mode, see MAV_NAV_MODE ENUM
 */
static inline uint8_t mavlink_msg_sys_status_get_nav_mode(const mavlink_message_t* msg)
{
	mavlink_sys_status_t *p = (mavlink_sys_status_t *)&msg->payload[0];
	return (uint8_t)(p->nav_mode);
}

/**
 * @brief Get field status from sys_status message
 *
 * @return System status flag, see MAV_STATUS ENUM
 */
static inline uint8_t mavlink_msg_sys_status_get_status(const mavlink_message_t* msg)
{
	mavlink_sys_status_t *p = (mavlink_sys_status_t *)&msg->payload[0];
	return (uint8_t)(p->status);
}

/**
 * @brief Get field failure from sys_status message
 *
 * @return Failure code description, see MAV_FAILURE ENUM
 */
static inline uint8_t mavlink_msg_sys_status_get_failure(const mavlink_message_t* msg)
{
	mavlink_sys_status_t *p = (mavlink_sys_status_t *)&msg->payload[0];
	return (uint8_t)(p->failure);
}

/**
 * @brief Get field motor_block from sys_status message
 *
 * @return Motor block status flag
 */
static inline uint8_t mavlink_msg_sys_status_get_motor_block(const mavlink_message_t* msg)
{
	mavlink_sys_status_t *p = (mavlink_sys_status_t *)&msg->payload[0];
	return (uint8_t)(p->motor_block);
}

/**
 * @brief Decode a sys_status message into a struct
 *
 * @param msg The message to decode
 * @param sys_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_sys_status_decode(const mavlink_message_t* msg, mavlink_sys_status_t* sys_status)
{
	memcpy( sys_status, msg->payload, sizeof(mavlink_sys_status_t));
}
