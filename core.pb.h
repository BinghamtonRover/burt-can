/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7 */

#ifndef PB_CORE_PB_H_INCLUDED
#define PB_CORE_PB_H_INCLUDED
#include "pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _Device {
    Device_DEVICE_UNDEFINED = 0,
    Device_DASHBOARD = 1,
    Device_SUBSYSTEMS = 2,
    Device_VIDEO = 3,
    Device_AUTONOMY = 4,
    Device_FIRMWARE = 5,
    Device_ARM = 6,
    Device_GRIPPER = 7,
    Device_SCIENCE = 8,
    Device_ELECTRICAL = 9,
    Device_DRIVE = 10,
    Device_MARS = 11
} Device;

/* / Changes the way the rover listens to incoming commands.
/ 
/ - When IDLE, all subsystems will ignore all commands
/ - When MANUAL, all subsystems will accept all commands
/ - When AUTONOMOUS, the rover will ignore commands from the dashboard */
typedef enum _RoverStatus {
    RoverStatus_DISCONNECTED = 0, /* no signal at all means disconnected */
    RoverStatus_IDLE = 1, /* Yellow button should be lit. */
    RoverStatus_MANUAL = 2, /* Must show blue LEDs. Green button should be lit. */
    RoverStatus_AUTONOMOUS = 3, /* See [AutonomyState] for LED colors */
    RoverStatus_POWER_OFF = 4 /* Press the red button to turn off the Pis on the rover */
} RoverStatus;

/* Struct definitions */
/* Used for a simple handshake between devices. */
typedef struct _Connect {
    Device sender;
    Device receiver;
} Connect;

/* Notifies the recipient that the sender will no longer be connected. */
typedef struct _Disconnect {
    Device sender;
} Disconnect;

/* / Update a sensitive setting, such as the rover's status.
/ 
/ This message must be triggered manually and the recipient (usually the subsystems Pi)
/ must respond with the exact same message to confirm its receipt. */
typedef struct _UpdateSetting {
    RoverStatus status;
} UpdateSetting;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _Device_MIN Device_DEVICE_UNDEFINED
#define _Device_MAX Device_MARS
#define _Device_ARRAYSIZE ((Device)(Device_MARS+1))

#define _RoverStatus_MIN RoverStatus_DISCONNECTED
#define _RoverStatus_MAX RoverStatus_POWER_OFF
#define _RoverStatus_ARRAYSIZE ((RoverStatus)(RoverStatus_POWER_OFF+1))

#define Connect_sender_ENUMTYPE Device
#define Connect_receiver_ENUMTYPE Device

#define Disconnect_sender_ENUMTYPE Device

#define UpdateSetting_status_ENUMTYPE RoverStatus


/* Initializer values for message structs */
#define Connect_init_default                     {_Device_MIN, _Device_MIN}
#define Disconnect_init_default                  {_Device_MIN}
#define UpdateSetting_init_default               {_RoverStatus_MIN}
#define Connect_init_zero                        {_Device_MIN, _Device_MIN}
#define Disconnect_init_zero                     {_Device_MIN}
#define UpdateSetting_init_zero                  {_RoverStatus_MIN}

/* Field tags (for use in manual encoding/decoding) */
#define Connect_sender_tag                       1
#define Connect_receiver_tag                     2
#define Disconnect_sender_tag                    1
#define UpdateSetting_status_tag                 1

/* Struct field encoding specification for nanopb */
#define Connect_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    sender,            1) \
X(a, STATIC,   SINGULAR, UENUM,    receiver,          2)
#define Connect_CALLBACK NULL
#define Connect_DEFAULT NULL

#define Disconnect_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    sender,            1)
#define Disconnect_CALLBACK NULL
#define Disconnect_DEFAULT NULL

#define UpdateSetting_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    status,            1)
#define UpdateSetting_CALLBACK NULL
#define UpdateSetting_DEFAULT NULL

extern const pb_msgdesc_t Connect_msg;
extern const pb_msgdesc_t Disconnect_msg;
extern const pb_msgdesc_t UpdateSetting_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define Connect_fields &Connect_msg
#define Disconnect_fields &Disconnect_msg
#define UpdateSetting_fields &UpdateSetting_msg

/* Maximum encoded size of messages (where known) */
#define Connect_size                             4
#define Disconnect_size                          2
#define UpdateSetting_size                       2

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
