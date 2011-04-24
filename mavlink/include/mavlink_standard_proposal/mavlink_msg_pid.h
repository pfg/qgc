// MESSAGE PID PACKING

#define MAVLINK_MSG_ID_PID 34
#define MAVLINK_MSG_ID_PID_LEN 13
#define MAVLINK_MSG_34_LEN 13

typedef struct __mavlink_pid_t 
{
	float k_p; ///< P
	float k_i; ///< I
	float k_d; ///< D
	uint8_t pid_id; ///< PID ID
} mavlink_pid_t;


/**
 * @brief Pack a pid message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param k_p P
 * @param k_i I
 * @param k_d D
 * @param pid_id PID ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, float k_p, float k_i, float k_d, uint8_t pid_id)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_PID;

	p->k_p = k_p; // float:P
	p->k_i = k_i; // float:I
	p->k_d = k_d; // float:D
	p->pid_id = pid_id; // uint8_t:PID ID

	return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PID_LEN);
}

/**
 * @brief Pack a pid message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param k_p P
 * @param k_i I
 * @param k_d D
 * @param pid_id PID ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, float k_p, float k_i, float k_d, uint8_t pid_id)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_PID;

	p->k_p = k_p; // float:P
	p->k_i = k_i; // float:I
	p->k_d = k_d; // float:D
	p->pid_id = pid_id; // uint8_t:PID ID

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PID_LEN);
}

/**
 * @brief Encode a pid struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pid C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pid_t* pid)
{
	return mavlink_msg_pid_pack(system_id, component_id, msg, pid->k_p, pid->k_i, pid->k_d, pid->pid_id);
}

/**
 * @brief Send a pid message
 * @param chan MAVLink channel to send the message
 *
 * @param k_p P
 * @param k_i I
 * @param k_d D
 * @param pid_id PID ID
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
static inline void mavlink_msg_pid_send(mavlink_channel_t chan, float k_p, float k_i, float k_d, uint8_t pid_id)
{
	mavlink_message_t msg;
	uint16_t checksum;
	mavlink_pid_t *p = (mavlink_pid_t *)&msg.payload[0];

	p->k_p = k_p; // float:P
	p->k_i = k_i; // float:I
	p->k_d = k_d; // float:D
	p->pid_id = pid_id; // uint8_t:PID ID

	msg.STX = MAVLINK_STX;
	msg.len = MAVLINK_MSG_ID_PID_LEN;
	msg.msgid = MAVLINK_MSG_ID_PID;
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
static inline void mavlink_msg_pid_send(mavlink_channel_t chan, float k_p, float k_i, float k_d, uint8_t pid_id)
{
	mavlink_header_t hdr;
	mavlink_pid_t payload;
	uint16_t checksum;
	mavlink_pid_t *p = &payload;

	p->k_p = k_p; // float:P
	p->k_i = k_i; // float:I
	p->k_d = k_d; // float:D
	p->pid_id = pid_id; // uint8_t:PID ID

	hdr.STX = MAVLINK_STX;
	hdr.len = MAVLINK_MSG_ID_PID_LEN;
	hdr.msgid = MAVLINK_MSG_ID_PID;
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
// MESSAGE PID UNPACKING

/**
 * @brief Get field k_p from pid message
 *
 * @return P
 */
static inline float mavlink_msg_pid_get_k_p(const mavlink_message_t* msg)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	return (float)(p->k_p);
}

/**
 * @brief Get field k_i from pid message
 *
 * @return I
 */
static inline float mavlink_msg_pid_get_k_i(const mavlink_message_t* msg)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	return (float)(p->k_i);
}

/**
 * @brief Get field k_d from pid message
 *
 * @return D
 */
static inline float mavlink_msg_pid_get_k_d(const mavlink_message_t* msg)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	return (float)(p->k_d);
}

/**
 * @brief Get field pid_id from pid message
 *
 * @return PID ID
 */
static inline uint8_t mavlink_msg_pid_get_pid_id(const mavlink_message_t* msg)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	return (uint8_t)(p->pid_id);
}

/**
 * @brief Decode a pid message into a struct
 *
 * @param msg The message to decode
 * @param pid C-struct to decode the message contents into
 */
static inline void mavlink_msg_pid_decode(const mavlink_message_t* msg, mavlink_pid_t* pid)
{
	memcpy( pid, msg->payload, sizeof(mavlink_pid_t));
}
