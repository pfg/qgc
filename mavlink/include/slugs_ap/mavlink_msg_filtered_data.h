// MESSAGE FILTERED_DATA PACKING

#define MAVLINK_MSG_ID_FILTERED_DATA 178
#define MAVLINK_MSG_ID_FILTERED_DATA_LEN 36
#define MAVLINK_MSG_178_LEN 36

typedef struct __mavlink_filtered_data_t 
{
	float aX; ///< Accelerometer X value (m/s^2) 
	float aY; ///< Accelerometer Y value (m/s^2)
	float aZ; ///< Accelerometer Z value (m/s^2)
	float gX; ///< Gyro X value (rad/s) 
	float gY; ///< Gyro Y value (rad/s)
	float gZ; ///< Gyro Z value (rad/s)
	float mX; ///< Magnetometer X (normalized to 1) 
	float mY; ///< Magnetometer Y (normalized to 1) 
	float mZ; ///< Magnetometer Z (normalized to 1) 
} mavlink_filtered_data_t;


/**
 * @brief Pack a filtered_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param aX Accelerometer X value (m/s^2) 
 * @param aY Accelerometer Y value (m/s^2)
 * @param aZ Accelerometer Z value (m/s^2)
 * @param gX Gyro X value (rad/s) 
 * @param gY Gyro Y value (rad/s)
 * @param gZ Gyro Z value (rad/s)
 * @param mX Magnetometer X (normalized to 1) 
 * @param mY Magnetometer Y (normalized to 1) 
 * @param mZ Magnetometer Z (normalized to 1) 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_filtered_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, float aX, float aY, float aZ, float gX, float gY, float gZ, float mX, float mY, float mZ)
{
	mavlink_filtered_data_t *p = (mavlink_filtered_data_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_FILTERED_DATA;

	p->aX = aX; // float:Accelerometer X value (m/s^2) 
	p->aY = aY; // float:Accelerometer Y value (m/s^2)
	p->aZ = aZ; // float:Accelerometer Z value (m/s^2)
	p->gX = gX; // float:Gyro X value (rad/s) 
	p->gY = gY; // float:Gyro Y value (rad/s)
	p->gZ = gZ; // float:Gyro Z value (rad/s)
	p->mX = mX; // float:Magnetometer X (normalized to 1) 
	p->mY = mY; // float:Magnetometer Y (normalized to 1) 
	p->mZ = mZ; // float:Magnetometer Z (normalized to 1) 

	return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FILTERED_DATA_LEN);
}

/**
 * @brief Pack a filtered_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param aX Accelerometer X value (m/s^2) 
 * @param aY Accelerometer Y value (m/s^2)
 * @param aZ Accelerometer Z value (m/s^2)
 * @param gX Gyro X value (rad/s) 
 * @param gY Gyro Y value (rad/s)
 * @param gZ Gyro Z value (rad/s)
 * @param mX Magnetometer X (normalized to 1) 
 * @param mY Magnetometer Y (normalized to 1) 
 * @param mZ Magnetometer Z (normalized to 1) 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_filtered_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, float aX, float aY, float aZ, float gX, float gY, float gZ, float mX, float mY, float mZ)
{
	mavlink_filtered_data_t *p = (mavlink_filtered_data_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_FILTERED_DATA;

	p->aX = aX; // float:Accelerometer X value (m/s^2) 
	p->aY = aY; // float:Accelerometer Y value (m/s^2)
	p->aZ = aZ; // float:Accelerometer Z value (m/s^2)
	p->gX = gX; // float:Gyro X value (rad/s) 
	p->gY = gY; // float:Gyro Y value (rad/s)
	p->gZ = gZ; // float:Gyro Z value (rad/s)
	p->mX = mX; // float:Magnetometer X (normalized to 1) 
	p->mY = mY; // float:Magnetometer Y (normalized to 1) 
	p->mZ = mZ; // float:Magnetometer Z (normalized to 1) 

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FILTERED_DATA_LEN);
}

/**
 * @brief Encode a filtered_data struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param filtered_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_filtered_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_filtered_data_t* filtered_data)
{
	return mavlink_msg_filtered_data_pack(system_id, component_id, msg, filtered_data->aX, filtered_data->aY, filtered_data->aZ, filtered_data->gX, filtered_data->gY, filtered_data->gZ, filtered_data->mX, filtered_data->mY, filtered_data->mZ);
}

/**
 * @brief Send a filtered_data message
 * @param chan MAVLink channel to send the message
 *
 * @param aX Accelerometer X value (m/s^2) 
 * @param aY Accelerometer Y value (m/s^2)
 * @param aZ Accelerometer Z value (m/s^2)
 * @param gX Gyro X value (rad/s) 
 * @param gY Gyro Y value (rad/s)
 * @param gZ Gyro Z value (rad/s)
 * @param mX Magnetometer X (normalized to 1) 
 * @param mY Magnetometer Y (normalized to 1) 
 * @param mZ Magnetometer Z (normalized to 1) 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
static inline void mavlink_msg_filtered_data_send(mavlink_channel_t chan, float aX, float aY, float aZ, float gX, float gY, float gZ, float mX, float mY, float mZ)
{
	mavlink_message_t msg;
	uint16_t checksum;
	mavlink_filtered_data_t *p = (mavlink_filtered_data_t *)&msg.payload[0];

	p->aX = aX; // float:Accelerometer X value (m/s^2) 
	p->aY = aY; // float:Accelerometer Y value (m/s^2)
	p->aZ = aZ; // float:Accelerometer Z value (m/s^2)
	p->gX = gX; // float:Gyro X value (rad/s) 
	p->gY = gY; // float:Gyro Y value (rad/s)
	p->gZ = gZ; // float:Gyro Z value (rad/s)
	p->mX = mX; // float:Magnetometer X (normalized to 1) 
	p->mY = mY; // float:Magnetometer Y (normalized to 1) 
	p->mZ = mZ; // float:Magnetometer Z (normalized to 1) 

	msg.STX = MAVLINK_STX;
	msg.len = MAVLINK_MSG_ID_FILTERED_DATA_LEN;
	msg.msgid = MAVLINK_MSG_ID_FILTERED_DATA;
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
static inline void mavlink_msg_filtered_data_send(mavlink_channel_t chan, float aX, float aY, float aZ, float gX, float gY, float gZ, float mX, float mY, float mZ)
{
	mavlink_header_t hdr;
	mavlink_filtered_data_t payload;
	uint16_t checksum;
	mavlink_filtered_data_t *p = &payload;

	p->aX = aX; // float:Accelerometer X value (m/s^2) 
	p->aY = aY; // float:Accelerometer Y value (m/s^2)
	p->aZ = aZ; // float:Accelerometer Z value (m/s^2)
	p->gX = gX; // float:Gyro X value (rad/s) 
	p->gY = gY; // float:Gyro Y value (rad/s)
	p->gZ = gZ; // float:Gyro Z value (rad/s)
	p->mX = mX; // float:Magnetometer X (normalized to 1) 
	p->mY = mY; // float:Magnetometer Y (normalized to 1) 
	p->mZ = mZ; // float:Magnetometer Z (normalized to 1) 

	hdr.STX = MAVLINK_STX;
	hdr.len = MAVLINK_MSG_ID_FILTERED_DATA_LEN;
	hdr.msgid = MAVLINK_MSG_ID_FILTERED_DATA;
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
// MESSAGE FILTERED_DATA UNPACKING

/**
 * @brief Get field aX from filtered_data message
 *
 * @return Accelerometer X value (m/s^2) 
 */
static inline float mavlink_msg_filtered_data_get_aX(const mavlink_message_t* msg)
{
	mavlink_filtered_data_t *p = (mavlink_filtered_data_t *)&msg->payload[0];
	return (float)(p->aX);
}

/**
 * @brief Get field aY from filtered_data message
 *
 * @return Accelerometer Y value (m/s^2)
 */
static inline float mavlink_msg_filtered_data_get_aY(const mavlink_message_t* msg)
{
	mavlink_filtered_data_t *p = (mavlink_filtered_data_t *)&msg->payload[0];
	return (float)(p->aY);
}

/**
 * @brief Get field aZ from filtered_data message
 *
 * @return Accelerometer Z value (m/s^2)
 */
static inline float mavlink_msg_filtered_data_get_aZ(const mavlink_message_t* msg)
{
	mavlink_filtered_data_t *p = (mavlink_filtered_data_t *)&msg->payload[0];
	return (float)(p->aZ);
}

/**
 * @brief Get field gX from filtered_data message
 *
 * @return Gyro X value (rad/s) 
 */
static inline float mavlink_msg_filtered_data_get_gX(const mavlink_message_t* msg)
{
	mavlink_filtered_data_t *p = (mavlink_filtered_data_t *)&msg->payload[0];
	return (float)(p->gX);
}

/**
 * @brief Get field gY from filtered_data message
 *
 * @return Gyro Y value (rad/s)
 */
static inline float mavlink_msg_filtered_data_get_gY(const mavlink_message_t* msg)
{
	mavlink_filtered_data_t *p = (mavlink_filtered_data_t *)&msg->payload[0];
	return (float)(p->gY);
}

/**
 * @brief Get field gZ from filtered_data message
 *
 * @return Gyro Z value (rad/s)
 */
static inline float mavlink_msg_filtered_data_get_gZ(const mavlink_message_t* msg)
{
	mavlink_filtered_data_t *p = (mavlink_filtered_data_t *)&msg->payload[0];
	return (float)(p->gZ);
}

/**
 * @brief Get field mX from filtered_data message
 *
 * @return Magnetometer X (normalized to 1) 
 */
static inline float mavlink_msg_filtered_data_get_mX(const mavlink_message_t* msg)
{
	mavlink_filtered_data_t *p = (mavlink_filtered_data_t *)&msg->payload[0];
	return (float)(p->mX);
}

/**
 * @brief Get field mY from filtered_data message
 *
 * @return Magnetometer Y (normalized to 1) 
 */
static inline float mavlink_msg_filtered_data_get_mY(const mavlink_message_t* msg)
{
	mavlink_filtered_data_t *p = (mavlink_filtered_data_t *)&msg->payload[0];
	return (float)(p->mY);
}

/**
 * @brief Get field mZ from filtered_data message
 *
 * @return Magnetometer Z (normalized to 1) 
 */
static inline float mavlink_msg_filtered_data_get_mZ(const mavlink_message_t* msg)
{
	mavlink_filtered_data_t *p = (mavlink_filtered_data_t *)&msg->payload[0];
	return (float)(p->mZ);
}

/**
 * @brief Decode a filtered_data message into a struct
 *
 * @param msg The message to decode
 * @param filtered_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_filtered_data_decode(const mavlink_message_t* msg, mavlink_filtered_data_t* filtered_data)
{
	memcpy( filtered_data, msg->payload, sizeof(mavlink_filtered_data_t));
}
