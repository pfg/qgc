// MESSAGE PWM_COMMANDS PACKING

#define MAVLINK_MSG_ID_PWM_COMMANDS 175
#define MAVLINK_MSG_ID_PWM_COMMANDS_LEN 20
#define MAVLINK_MSG_175_LEN 20

typedef struct __mavlink_pwm_commands_t 
{
	uint16_t dt_c; ///< AutoPilot's throttle command 
	uint16_t dla_c; ///< AutoPilot's left aileron command 
	uint16_t dra_c; ///< AutoPilot's right aileron command 
	uint16_t dr_c; ///< AutoPilot's rudder command 
	uint16_t dle_c; ///< AutoPilot's left elevator command 
	uint16_t dre_c; ///< AutoPilot's right elevator command 
	uint16_t dlf_c; ///< AutoPilot's left  flap command 
	uint16_t drf_c; ///< AutoPilot's right flap command 
	uint16_t aux1; ///< AutoPilot's aux1 command 
	uint16_t aux2; ///< AutoPilot's aux2 command 
} mavlink_pwm_commands_t;


/**
 * @brief Pack a pwm_commands message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dt_c AutoPilot's throttle command 
 * @param dla_c AutoPilot's left aileron command 
 * @param dra_c AutoPilot's right aileron command 
 * @param dr_c AutoPilot's rudder command 
 * @param dle_c AutoPilot's left elevator command 
 * @param dre_c AutoPilot's right elevator command 
 * @param dlf_c AutoPilot's left  flap command 
 * @param drf_c AutoPilot's right flap command 
 * @param aux1 AutoPilot's aux1 command 
 * @param aux2 AutoPilot's aux2 command 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pwm_commands_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint16_t dt_c, uint16_t dla_c, uint16_t dra_c, uint16_t dr_c, uint16_t dle_c, uint16_t dre_c, uint16_t dlf_c, uint16_t drf_c, uint16_t aux1, uint16_t aux2)
{
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_PWM_COMMANDS;

	p->dt_c = dt_c; // uint16_t:AutoPilot's throttle command 
	p->dla_c = dla_c; // uint16_t:AutoPilot's left aileron command 
	p->dra_c = dra_c; // uint16_t:AutoPilot's right aileron command 
	p->dr_c = dr_c; // uint16_t:AutoPilot's rudder command 
	p->dle_c = dle_c; // uint16_t:AutoPilot's left elevator command 
	p->dre_c = dre_c; // uint16_t:AutoPilot's right elevator command 
	p->dlf_c = dlf_c; // uint16_t:AutoPilot's left  flap command 
	p->drf_c = drf_c; // uint16_t:AutoPilot's right flap command 
	p->aux1 = aux1; // uint16_t:AutoPilot's aux1 command 
	p->aux2 = aux2; // uint16_t:AutoPilot's aux2 command 

	return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PWM_COMMANDS_LEN);
}

/**
 * @brief Pack a pwm_commands message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param dt_c AutoPilot's throttle command 
 * @param dla_c AutoPilot's left aileron command 
 * @param dra_c AutoPilot's right aileron command 
 * @param dr_c AutoPilot's rudder command 
 * @param dle_c AutoPilot's left elevator command 
 * @param dre_c AutoPilot's right elevator command 
 * @param dlf_c AutoPilot's left  flap command 
 * @param drf_c AutoPilot's right flap command 
 * @param aux1 AutoPilot's aux1 command 
 * @param aux2 AutoPilot's aux2 command 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pwm_commands_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint16_t dt_c, uint16_t dla_c, uint16_t dra_c, uint16_t dr_c, uint16_t dle_c, uint16_t dre_c, uint16_t dlf_c, uint16_t drf_c, uint16_t aux1, uint16_t aux2)
{
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg->payload[0];
	msg->msgid = MAVLINK_MSG_ID_PWM_COMMANDS;

	p->dt_c = dt_c; // uint16_t:AutoPilot's throttle command 
	p->dla_c = dla_c; // uint16_t:AutoPilot's left aileron command 
	p->dra_c = dra_c; // uint16_t:AutoPilot's right aileron command 
	p->dr_c = dr_c; // uint16_t:AutoPilot's rudder command 
	p->dle_c = dle_c; // uint16_t:AutoPilot's left elevator command 
	p->dre_c = dre_c; // uint16_t:AutoPilot's right elevator command 
	p->dlf_c = dlf_c; // uint16_t:AutoPilot's left  flap command 
	p->drf_c = drf_c; // uint16_t:AutoPilot's right flap command 
	p->aux1 = aux1; // uint16_t:AutoPilot's aux1 command 
	p->aux2 = aux2; // uint16_t:AutoPilot's aux2 command 

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PWM_COMMANDS_LEN);
}

/**
 * @brief Encode a pwm_commands struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pwm_commands C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pwm_commands_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pwm_commands_t* pwm_commands)
{
	return mavlink_msg_pwm_commands_pack(system_id, component_id, msg, pwm_commands->dt_c, pwm_commands->dla_c, pwm_commands->dra_c, pwm_commands->dr_c, pwm_commands->dle_c, pwm_commands->dre_c, pwm_commands->dlf_c, pwm_commands->drf_c, pwm_commands->aux1, pwm_commands->aux2);
}

/**
 * @brief Send a pwm_commands message
 * @param chan MAVLink channel to send the message
 *
 * @param dt_c AutoPilot's throttle command 
 * @param dla_c AutoPilot's left aileron command 
 * @param dra_c AutoPilot's right aileron command 
 * @param dr_c AutoPilot's rudder command 
 * @param dle_c AutoPilot's left elevator command 
 * @param dre_c AutoPilot's right elevator command 
 * @param dlf_c AutoPilot's left  flap command 
 * @param drf_c AutoPilot's right flap command 
 * @param aux1 AutoPilot's aux1 command 
 * @param aux2 AutoPilot's aux2 command 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS
static inline void mavlink_msg_pwm_commands_send(mavlink_channel_t chan, uint16_t dt_c, uint16_t dla_c, uint16_t dra_c, uint16_t dr_c, uint16_t dle_c, uint16_t dre_c, uint16_t dlf_c, uint16_t drf_c, uint16_t aux1, uint16_t aux2)
{
	mavlink_message_t msg;
	uint16_t checksum;
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg.payload[0];

	p->dt_c = dt_c; // uint16_t:AutoPilot's throttle command 
	p->dla_c = dla_c; // uint16_t:AutoPilot's left aileron command 
	p->dra_c = dra_c; // uint16_t:AutoPilot's right aileron command 
	p->dr_c = dr_c; // uint16_t:AutoPilot's rudder command 
	p->dle_c = dle_c; // uint16_t:AutoPilot's left elevator command 
	p->dre_c = dre_c; // uint16_t:AutoPilot's right elevator command 
	p->dlf_c = dlf_c; // uint16_t:AutoPilot's left  flap command 
	p->drf_c = drf_c; // uint16_t:AutoPilot's right flap command 
	p->aux1 = aux1; // uint16_t:AutoPilot's aux1 command 
	p->aux2 = aux2; // uint16_t:AutoPilot's aux2 command 

	msg.STX = MAVLINK_STX;
	msg.len = MAVLINK_MSG_ID_PWM_COMMANDS_LEN;
	msg.msgid = MAVLINK_MSG_ID_PWM_COMMANDS;
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
static inline void mavlink_msg_pwm_commands_send(mavlink_channel_t chan, uint16_t dt_c, uint16_t dla_c, uint16_t dra_c, uint16_t dr_c, uint16_t dle_c, uint16_t dre_c, uint16_t dlf_c, uint16_t drf_c, uint16_t aux1, uint16_t aux2)
{
	mavlink_header_t hdr;
	mavlink_pwm_commands_t payload;
	uint16_t checksum;
	mavlink_pwm_commands_t *p = &payload;

	p->dt_c = dt_c; // uint16_t:AutoPilot's throttle command 
	p->dla_c = dla_c; // uint16_t:AutoPilot's left aileron command 
	p->dra_c = dra_c; // uint16_t:AutoPilot's right aileron command 
	p->dr_c = dr_c; // uint16_t:AutoPilot's rudder command 
	p->dle_c = dle_c; // uint16_t:AutoPilot's left elevator command 
	p->dre_c = dre_c; // uint16_t:AutoPilot's right elevator command 
	p->dlf_c = dlf_c; // uint16_t:AutoPilot's left  flap command 
	p->drf_c = drf_c; // uint16_t:AutoPilot's right flap command 
	p->aux1 = aux1; // uint16_t:AutoPilot's aux1 command 
	p->aux2 = aux2; // uint16_t:AutoPilot's aux2 command 

	hdr.STX = MAVLINK_STX;
	hdr.len = MAVLINK_MSG_ID_PWM_COMMANDS_LEN;
	hdr.msgid = MAVLINK_MSG_ID_PWM_COMMANDS;
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
// MESSAGE PWM_COMMANDS UNPACKING

/**
 * @brief Get field dt_c from pwm_commands message
 *
 * @return AutoPilot's throttle command 
 */
static inline uint16_t mavlink_msg_pwm_commands_get_dt_c(const mavlink_message_t* msg)
{
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg->payload[0];
	return (uint16_t)(p->dt_c);
}

/**
 * @brief Get field dla_c from pwm_commands message
 *
 * @return AutoPilot's left aileron command 
 */
static inline uint16_t mavlink_msg_pwm_commands_get_dla_c(const mavlink_message_t* msg)
{
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg->payload[0];
	return (uint16_t)(p->dla_c);
}

/**
 * @brief Get field dra_c from pwm_commands message
 *
 * @return AutoPilot's right aileron command 
 */
static inline uint16_t mavlink_msg_pwm_commands_get_dra_c(const mavlink_message_t* msg)
{
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg->payload[0];
	return (uint16_t)(p->dra_c);
}

/**
 * @brief Get field dr_c from pwm_commands message
 *
 * @return AutoPilot's rudder command 
 */
static inline uint16_t mavlink_msg_pwm_commands_get_dr_c(const mavlink_message_t* msg)
{
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg->payload[0];
	return (uint16_t)(p->dr_c);
}

/**
 * @brief Get field dle_c from pwm_commands message
 *
 * @return AutoPilot's left elevator command 
 */
static inline uint16_t mavlink_msg_pwm_commands_get_dle_c(const mavlink_message_t* msg)
{
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg->payload[0];
	return (uint16_t)(p->dle_c);
}

/**
 * @brief Get field dre_c from pwm_commands message
 *
 * @return AutoPilot's right elevator command 
 */
static inline uint16_t mavlink_msg_pwm_commands_get_dre_c(const mavlink_message_t* msg)
{
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg->payload[0];
	return (uint16_t)(p->dre_c);
}

/**
 * @brief Get field dlf_c from pwm_commands message
 *
 * @return AutoPilot's left  flap command 
 */
static inline uint16_t mavlink_msg_pwm_commands_get_dlf_c(const mavlink_message_t* msg)
{
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg->payload[0];
	return (uint16_t)(p->dlf_c);
}

/**
 * @brief Get field drf_c from pwm_commands message
 *
 * @return AutoPilot's right flap command 
 */
static inline uint16_t mavlink_msg_pwm_commands_get_drf_c(const mavlink_message_t* msg)
{
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg->payload[0];
	return (uint16_t)(p->drf_c);
}

/**
 * @brief Get field aux1 from pwm_commands message
 *
 * @return AutoPilot's aux1 command 
 */
static inline uint16_t mavlink_msg_pwm_commands_get_aux1(const mavlink_message_t* msg)
{
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg->payload[0];
	return (uint16_t)(p->aux1);
}

/**
 * @brief Get field aux2 from pwm_commands message
 *
 * @return AutoPilot's aux2 command 
 */
static inline uint16_t mavlink_msg_pwm_commands_get_aux2(const mavlink_message_t* msg)
{
	mavlink_pwm_commands_t *p = (mavlink_pwm_commands_t *)&msg->payload[0];
	return (uint16_t)(p->aux2);
}

/**
 * @brief Decode a pwm_commands message into a struct
 *
 * @param msg The message to decode
 * @param pwm_commands C-struct to decode the message contents into
 */
static inline void mavlink_msg_pwm_commands_decode(const mavlink_message_t* msg, mavlink_pwm_commands_t* pwm_commands)
{
	memcpy( pwm_commands, msg->payload, sizeof(mavlink_pwm_commands_t));
}
