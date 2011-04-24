// MESSAGE PILOT_CONSOLE PACKING

#define MAVLINK_MSG_ID_PILOT_CONSOLE 174
#define MAVLINK_MSG_ID_PILOT_CONSOLE_LEN 10
#define MAVLINK_MSG_174_LEN 10

typedef struct __mavlink_pilot_console_t 
{
	uint16_t dt; ///< Pilot's console throttle command 
	uint16_t dla; ///< Pilot's console left aileron command 
	uint16_t dra; ///< Pilot's console right aileron command 
	uint16_t dr; ///< Pilot's console rudder command 
	uint16_t de; ///< Pilot's console elevator command 
} mavlink_pilot_console_t;


/**
 * @brief Pack a pilot_console message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dt Pilot's console throttle command 
 * @param dla Pilot's console left aileron command 
 * @param dra Pilot's console right aileron command 
 * @param dr Pilot's console rudder command 
 * @param de Pilot's console elevator command 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pilot_console_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint16_t dt, uint16_t dla, uint16_t dra, uint16_t dr, uint16_t de)
{
	mavlink_pilot_console_t *p = (mavlink_pilot_console_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_PILOT_CONSOLE;

	p->dt = dt; // uint16_t:Pilot's console throttle command 
	p->dla = dla; // uint16_t:Pilot's console left aileron command 
	p->dra = dra; // uint16_t:Pilot's console right aileron command 
	p->dr = dr; // uint16_t:Pilot's console rudder command 
	p->de = de; // uint16_t:Pilot's console elevator command 

	return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PILOT_CONSOLE_LEN);
}

/**
 * @brief Pack a pilot_console message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param dt Pilot's console throttle command 
 * @param dla Pilot's console left aileron command 
 * @param dra Pilot's console right aileron command 
 * @param dr Pilot's console rudder command 
 * @param de Pilot's console elevator command 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pilot_console_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint16_t dt, uint16_t dla, uint16_t dra, uint16_t dr, uint16_t de)
{
	mavlink_pilot_console_t *p = (mavlink_pilot_console_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_PILOT_CONSOLE;

	p->dt = dt; // uint16_t:Pilot's console throttle command 
	p->dla = dla; // uint16_t:Pilot's console left aileron command 
	p->dra = dra; // uint16_t:Pilot's console right aileron command 
	p->dr = dr; // uint16_t:Pilot's console rudder command 
	p->de = de; // uint16_t:Pilot's console elevator command 

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PILOT_CONSOLE_LEN);
}

/**
 * @brief Encode a pilot_console struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pilot_console C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pilot_console_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pilot_console_t* pilot_console)
{
	return mavlink_msg_pilot_console_pack(system_id, component_id, msg, pilot_console->dt, pilot_console->dla, pilot_console->dra, pilot_console->dr, pilot_console->de);
}

/**
 * @brief Send a pilot_console message
 * @param chan MAVLink channel to send the message
 *
 * @param dt Pilot's console throttle command 
 * @param dla Pilot's console left aileron command 
 * @param dra Pilot's console right aileron command 
 * @param dr Pilot's console rudder command 
 * @param de Pilot's console elevator command 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
static inline void mavlink_msg_pilot_console_send(mavlink_channel_t chan, uint16_t dt, uint16_t dla, uint16_t dra, uint16_t dr, uint16_t de)
{
	mavlink_message_t msg;
	uint16_t checksum;
	mavlink_pilot_console_t *p = (mavlink_pilot_console_t *)&msg.payload[0];

	p->dt = dt; // uint16_t:Pilot's console throttle command 
	p->dla = dla; // uint16_t:Pilot's console left aileron command 
	p->dra = dra; // uint16_t:Pilot's console right aileron command 
	p->dr = dr; // uint16_t:Pilot's console rudder command 
	p->de = de; // uint16_t:Pilot's console elevator command 

	msg.STX = MAVLINK_STX;
	msg.len = MAVLINK_MSG_ID_PILOT_CONSOLE_LEN;
	msg.msgid = MAVLINK_MSG_ID_PILOT_CONSOLE;
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
static inline void mavlink_msg_pilot_console_send(mavlink_channel_t chan, uint16_t dt, uint16_t dla, uint16_t dra, uint16_t dr, uint16_t de)
{
	mavlink_header_t hdr;
	mavlink_pilot_console_t payload;
	uint16_t checksum;
	mavlink_pilot_console_t *p = &payload;

	p->dt = dt; // uint16_t:Pilot's console throttle command 
	p->dla = dla; // uint16_t:Pilot's console left aileron command 
	p->dra = dra; // uint16_t:Pilot's console right aileron command 
	p->dr = dr; // uint16_t:Pilot's console rudder command 
	p->de = de; // uint16_t:Pilot's console elevator command 

	hdr.STX = MAVLINK_STX;
	hdr.len = MAVLINK_MSG_ID_PILOT_CONSOLE_LEN;
	hdr.msgid = MAVLINK_MSG_ID_PILOT_CONSOLE;
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
// MESSAGE PILOT_CONSOLE UNPACKING

/**
 * @brief Get field dt from pilot_console message
 *
 * @return Pilot's console throttle command 
 */
static inline uint16_t mavlink_msg_pilot_console_get_dt(const mavlink_message_t* msg)
{
	mavlink_pilot_console_t *p = (mavlink_pilot_console_t *)&msg->payload[0];
	return (uint16_t)(p->dt);
}

/**
 * @brief Get field dla from pilot_console message
 *
 * @return Pilot's console left aileron command 
 */
static inline uint16_t mavlink_msg_pilot_console_get_dla(const mavlink_message_t* msg)
{
	mavlink_pilot_console_t *p = (mavlink_pilot_console_t *)&msg->payload[0];
	return (uint16_t)(p->dla);
}

/**
 * @brief Get field dra from pilot_console message
 *
 * @return Pilot's console right aileron command 
 */
static inline uint16_t mavlink_msg_pilot_console_get_dra(const mavlink_message_t* msg)
{
	mavlink_pilot_console_t *p = (mavlink_pilot_console_t *)&msg->payload[0];
	return (uint16_t)(p->dra);
}

/**
 * @brief Get field dr from pilot_console message
 *
 * @return Pilot's console rudder command 
 */
static inline uint16_t mavlink_msg_pilot_console_get_dr(const mavlink_message_t* msg)
{
	mavlink_pilot_console_t *p = (mavlink_pilot_console_t *)&msg->payload[0];
	return (uint16_t)(p->dr);
}

/**
 * @brief Get field de from pilot_console message
 *
 * @return Pilot's console elevator command 
 */
static inline uint16_t mavlink_msg_pilot_console_get_de(const mavlink_message_t* msg)
{
	mavlink_pilot_console_t *p = (mavlink_pilot_console_t *)&msg->payload[0];
	return (uint16_t)(p->de);
}

/**
 * @brief Decode a pilot_console message into a struct
 *
 * @param msg The message to decode
 * @param pilot_console C-struct to decode the message contents into
 */
static inline void mavlink_msg_pilot_console_decode(const mavlink_message_t* msg, mavlink_pilot_console_t* pilot_console)
{
	memcpy( pilot_console, msg->payload, sizeof(mavlink_pilot_console_t));
}
