/** @file
 *	@brief MAVLink comm protocol.
 *	@see http://pixhawk.ethz.ch/software/mavlink
 *	 Generated on Monday, April 18 2011, 23:54 UTC
 */
#ifndef MAVLINK_STANDARD_PROPOSAL_H
#define MAVLINK_STANDARD_PROPOSAL_H

#ifdef __cplusplus
extern "C" {
#endif


#include "../protocol.h"

#define MAVLINK_ENABLED_MAVLINK_STANDARD_PROPOSAL

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 0
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 0
#endif

// ENUM DEFINITIONS


// MESSAGE DEFINITIONS

#include "./mavlink_msg_heartbeat.h"
#include "./mavlink_msg_ping.h"
#include "./mavlink_msg_sys_status.h"
#include "./mavlink_msg_set_mode.h"
#include "./mavlink_msg_set_nav_mode.h"
#include "./mavlink_msg_param_set.h"
#include "./mavlink_msg_param_write_storage.h"
#include "./mavlink_msg_pid_set.h"
#include "./mavlink_msg_rc_channels_trim_set.h"
#include "./mavlink_msg_rc_channels_mapping_set.h"
#include "./mavlink_msg_waypoint_set.h"
#include "./mavlink_msg_waypoint_set_current.h"
#include "./mavlink_msg_waypoint_clear_all.h"
#include "./mavlink_msg_action.h"
#include "./mavlink_msg_acknowledge.h"
#include "./mavlink_msg_param_request_read.h"
#include "./mavlink_msg_param_value.h"
#include "./mavlink_msg_param_request_list.h"
#include "./mavlink_msg_pid.h"
#include "./mavlink_msg_rc_channels_trim.h"
#include "./mavlink_msg_rc_channels_mapping.h"
#include "./mavlink_msg_waypoint.h"
#include "./mavlink_msg_waypoint_status.h"
#include "./mavlink_msg_raw_imu.h"
#include "./mavlink_msg_raw_pressure.h"
#include "./mavlink_msg_gps_raw.h"
#include "./mavlink_msg_gps_sat_status.h"
#include "./mavlink_msg_attitude.h"
#include "./mavlink_msg_position.h"
#include "./mavlink_msg_rc_channels_raw.h"
#include "./mavlink_msg_statustext.h"
#include "./mavlink_msg_debug.h"
#include "./mavlink_msg_memory_vect.h"
#ifdef __cplusplus
}
#endif
#endif
