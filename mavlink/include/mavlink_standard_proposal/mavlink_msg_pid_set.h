// MESSAGE PID_SET PACKING

#define MAVLINK_MSG_ID_PID_SET 13
#define MAVLINK_MSG_ID_PID_SET_LEN 15
#define MAVLINK_MSG_13_LEN 15

typedef struct __mavlink_pid_set_t 
{
	uint8_t target_system; ///< System ID
	uint8_t target_component; ///< Component ID
	float k_p; ///< P
	float k_i; ///< I
	float k_d; ///< D
	uint8_t pid_id; ///< PID ID
} mavlink_pid_set_t;


/**
 * @brief Pack a pid_set message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param k_p P
 * @param k_i I
 * @param k_d D
 * @param pid_id PID ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_set_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t target_system, uint8_t target_component, float k_p, float k_i, float k_d, uint8_t pid_id)
{
	mavlink_pid_set_t *p = (mavlink_pid_set_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_PID_SET;

	p->target_system = target_system; // uint8_t:System ID
	p->target_component = target_component; // uint8_t:Component ID
	p->k_p = k_p; // float:P
	p->k_i = k_i; // float:I
	p->k_d = k_d; // float:D
	p->pid_id = pid_id; // uint8_t:PID ID

	return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PID_SET_LEN);
}

/**
 * @brief Pack a pid_set message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param k_p P
 * @param k_i I
 * @param k_d D
 * @param pid_id PID ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_set_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint8_t target_system, uint8_t target_component, float k_p, float k_i, float k_d, uint8_t pid_id)
{
	mavlink_pid_set_t *p = (mavlink_pid_set_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_PID_SET;

	p->target_system = target_system; // uint8_t:System ID
	p->target_component = target_component; // uint8_t:Component ID
	p->k_p = k_p; // float:P
	p->k_i = k_i; // float:I
	p->k_d = k_d; // float:D
	p->pid_id = pid_id; // uint8_t:PID ID

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PID_SET_LEN);
}

/**
 * @brief Encode a pid_set struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pid_set C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_set_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pid_set_t* pid_set)
{
	return mavlink_msg_pid_set_pack(system_id, component_id, msg, pid_set->target_system, pid_set->target_component, pid_set->k_p, pid_set->k_i, pid_set->k_d, pid_set->pid_id);
}

/**
 * @brief Send a pid_set message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param k_p P
 * @param k_i I
 * @param k_d D
 * @param pid_id PID ID
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
static inline void mavlink_msg_pid_set_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, float k_p, float k_i, float k_d, uint8_t pid_id)
{
	mavlink_message_t msg;
	uint16_t checksum;
	mavlink_pid_set_t *p = (mavlink_pid_set_t *)&msg.payload[0];

	p->target_system = target_system; // uint8_t:System ID
	p->target_component = target_component; // uint8_t:Component ID
	p->k_p = k_p; // float:P
	p->k_i = k_i; // float:I
	p->k_d = k_d; // float:D
	p->pid_id = pid_id; // uint8_t:PID ID

	msg.STX = MAVLINK_STX;
	msg.len = MAVLINK_MSG_ID_PID_SET_LEN;
	msg.msgid = MAVLINK_MSG_ID_PID_SET;
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
static inline void mavlink_msg_pid_set_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, float k_p, float k_i, float k_d, uint8_t pid_id)
{
	mavlink_header_t hdr;
	mavlink_pid_set_t payload;
	uint16_t checksum;
	mavlink_pid_set_t *p = &payload;

	p->target_system = target_system; // uint8_t:System ID
	p->target_component = target_component; // uint8_t:Component ID
	p->k_p = k_p; // float:P
	p->k_i = k_i; // float:I
	p->k_d = k_d; // float:D
	p->pid_id = pid_id; // uint8_t:PID ID

	hdr.STX = MAVLINK_STX;
	hdr.len = MAVLINK_MSG_ID_PID_SET_LEN;
	hdr.msgid = MAVLINK_MSG_ID_PID_SET;
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
// MESSAGE PID_SET UNPACKING

/**
 * @brief Get field target_system from pid_set message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_pid_set_get_target_system(const mavlink_message_t* msg)
{
	mavlink_pid_set_t *p = (mavlink_pid_set_t *)&msg->payload[0];
	return (uint8_t)(p->target_system);
}

/**
 * @brief Get field target_component from pid_set message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_pid_set_get_target_component(const mavlink_message_t* msg)
{
	mavlink_pid_set_t *p = (mavlink_pid_set_t *)&msg->payload[0];
	return (uint8_t)(p->target_component);
}

/**
 * @brief Get field k_p from pid_set message
 *
 * @return P
 */
static inline float mavlink_msg_pid_set_get_k_p(const mavlink_message_t* msg)
{
	mavlink_pid_set_t *p = (mavlink_pid_set_t *)&msg->payload[0];
	return (float)(p->k_p);
}

/**
 * @brief Get field k_i from pid_set message
 *
 * @return I
 */
static inline float mavlink_msg_pid_set_get_k_i(const mavlink_message_t* msg)
{
	mavlink_pid_set_t *p = (mavlink_pid_set_t *)&msg->payload[0];
	return (float)(p->k_i);
}

/**
 * @brief Get field k_d from pid_set message
 *
 * @return D
 */
static inline float mavlink_msg_pid_set_get_k_d(const mavlink_message_t* msg)
{
	mavlink_pid_set_t *p = (mavlink_pid_set_t *)&msg->payload[0];
	return (float)(p->k_d);
}

/**
 * @brief Get field pid_id from pid_set message
 *
 * @return PID ID
 */
static inline uint8_t mavlink_msg_pid_set_get_pid_id(const mavlink_message_t* msg)
{
	mavlink_pid_set_t *p = (mavlink_pid_set_t *)&msg->payload[0];
	return (uint8_t)(p->pid_id);
}

/**
 * @brief Decode a pid_set message into a struct
 *
 * @param msg The message to decode
 * @param pid_set C-struct to decode the message contents into
 */
static inline void mavlink_msg_pid_set_decode(const mavlink_message_t* msg, mavlink_pid_set_t* pid_set)
{
	memcpy( pid_set, msg->payload, sizeof(mavlink_pid_set_t));
}
