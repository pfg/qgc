// MESSAGE PID PACKING

#define MAVLINK_MSG_ID_PID 182
#define MAVLINK_MSG_ID_PID_LEN 14
#define MAVLINK_MSG_182_LEN 14

typedef struct __mavlink_pid_t 
{
	uint8_t target; ///< The system setting the PID values
	float pVal; ///< Proportional gain
	float iVal; ///< Integral gain
	float dVal; ///< Derivative gain
	uint8_t idx; ///< PID loop index
} mavlink_pid_t;


/**
 * @brief Pack a pid message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target The system setting the PID values
 * @param pVal Proportional gain
 * @param iVal Integral gain
 * @param dVal Derivative gain
 * @param idx PID loop index
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t target, float pVal, float iVal, float dVal, uint8_t idx)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_PID;

	p->target = target; // uint8_t:The system setting the PID values
	p->pVal = pVal; // float:Proportional gain
	p->iVal = iVal; // float:Integral gain
	p->dVal = dVal; // float:Derivative gain
	p->idx = idx; // uint8_t:PID loop index

	return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PID_LEN);
}

/**
 * @brief Pack a pid message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target The system setting the PID values
 * @param pVal Proportional gain
 * @param iVal Integral gain
 * @param dVal Derivative gain
 * @param idx PID loop index
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint8_t target, float pVal, float iVal, float dVal, uint8_t idx)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_PID;

	p->target = target; // uint8_t:The system setting the PID values
	p->pVal = pVal; // float:Proportional gain
	p->iVal = iVal; // float:Integral gain
	p->dVal = dVal; // float:Derivative gain
	p->idx = idx; // uint8_t:PID loop index

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
	return mavlink_msg_pid_pack(system_id, component_id, msg, pid->target, pid->pVal, pid->iVal, pid->dVal, pid->idx);
}

/**
 * @brief Send a pid message
 * @param chan MAVLink channel to send the message
 *
 * @param target The system setting the PID values
 * @param pVal Proportional gain
 * @param iVal Integral gain
 * @param dVal Derivative gain
 * @param idx PID loop index
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
static inline void mavlink_msg_pid_send(mavlink_channel_t chan, uint8_t target, float pVal, float iVal, float dVal, uint8_t idx)
{
	mavlink_message_t msg;
	uint16_t checksum;
	mavlink_pid_t *p = (mavlink_pid_t *)&msg.payload[0];

	p->target = target; // uint8_t:The system setting the PID values
	p->pVal = pVal; // float:Proportional gain
	p->iVal = iVal; // float:Integral gain
	p->dVal = dVal; // float:Derivative gain
	p->idx = idx; // uint8_t:PID loop index

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
static inline void mavlink_msg_pid_send(mavlink_channel_t chan, uint8_t target, float pVal, float iVal, float dVal, uint8_t idx)
{
	mavlink_header_t hdr;
	mavlink_pid_t payload;
	uint16_t checksum;
	mavlink_pid_t *p = &payload;

	p->target = target; // uint8_t:The system setting the PID values
	p->pVal = pVal; // float:Proportional gain
	p->iVal = iVal; // float:Integral gain
	p->dVal = dVal; // float:Derivative gain
	p->idx = idx; // uint8_t:PID loop index

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
 * @brief Get field target from pid message
 *
 * @return The system setting the PID values
 */
static inline uint8_t mavlink_msg_pid_get_target(const mavlink_message_t* msg)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	return (uint8_t)(p->target);
}

/**
 * @brief Get field pVal from pid message
 *
 * @return Proportional gain
 */
static inline float mavlink_msg_pid_get_pVal(const mavlink_message_t* msg)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	return (float)(p->pVal);
}

/**
 * @brief Get field iVal from pid message
 *
 * @return Integral gain
 */
static inline float mavlink_msg_pid_get_iVal(const mavlink_message_t* msg)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	return (float)(p->iVal);
}

/**
 * @brief Get field dVal from pid message
 *
 * @return Derivative gain
 */
static inline float mavlink_msg_pid_get_dVal(const mavlink_message_t* msg)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	return (float)(p->dVal);
}

/**
 * @brief Get field idx from pid message
 *
 * @return PID loop index
 */
static inline uint8_t mavlink_msg_pid_get_idx(const mavlink_message_t* msg)
{
	mavlink_pid_t *p = (mavlink_pid_t *)&msg->payload[0];
	return (uint8_t)(p->idx);
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
