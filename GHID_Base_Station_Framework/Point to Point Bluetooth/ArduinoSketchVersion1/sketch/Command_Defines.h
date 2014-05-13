
#ifndef __COMMANDS__
#define __COMMANDS__

#define WII_BOARD_ID						"Nintendo RVL-WBC-01"

#define TAIL_COMMAND						'\r','\n'
#define AT_COMMAND							'A', 'T'
#define RESET_COMMAND						'+', 'R', 'E', 'S', 'E', 'T'
#define VERSION_COMMAND						'+', 'V', 'E', 'R', 'S', 'I', 'O', 'N', '?'
#define RESTORE_DEFAULTS_COMAMND			'+', 'O', 'R', 'G', 'L'
#define POLL_ADDRESS_COMMAND				'+', 'A', 'D', 'D', 'R', '?'

#define SET_DEVICE_NAME_COMMAND				'+', 'N', 'A', 'M', 'E', '='
#define GET_DEVICE_NAME_COMMAND				'+', 'N', 'A', 'M', 'E', '?'

#define GET_REMOTE_DEVICE_NAME_COMMAND		'+', 'R', 'N', 'A', 'M', 'E', '?'

#define SET_DEVICE_ROLE_COMMAND				'+', 'R', 'O', 'L', 'E', '='
#define GET_DEVICE_ROLE_COMAMND				'+', 'R', 'O', 'L', 'E', '?'

#define SET_DEVICE_TYPE_COMMAND				'+', 'C', 'L', 'A', 'S', 'S', '='
#define GET_DEVICE_TYPE_COMMAND				'+', 'C', 'L', 'A', 'S', 'S', '?'

#define SET_DEVICE_ACCESS_CODE_COMMAND		'+', 'I', 'A', 'C', '='
#define GET_DEVICE_ACCESS_CODE_COMMAND		'+', 'I', 'A', 'C', '?'

#define SET_DEVICE_INQUIRY_MODE_COMMAND		'+', 'I', 'N','Q', 'M', '='
#define GET_DEVICE_INQUIRY_MODE_COMMAND		'+', 'I', 'N','Q', 'M', '?'

#define SET_PAIRING_PASSWORD_COMMAND		'+', 'P', 'S', 'W', 'D', '='
#define GET_PAIRING_PASSWORD_COMMAND		'+', 'P', 'S', 'W', 'D', '?'

#define SET_SERIAL_PORT_COMMAND				'+', 'U', 'A', 'R', 'T', '='
#define GET_SERIAL_PORT_COMMAND				'+', 'U', 'A', 'R', 'T', '?'

#define SET_CONNECTION_MODE_COMMAND			'+', 'C', 'M', 'O', 'D', 'E', '='
#define GET_CONNECTION_MODE_COMMAND			'+', 'C', 'M', 'O', 'D', 'E', '?'

#define SET_BINDING_ADDRESS_COMMAND			'+', 'B', 'I', 'N', 'D', =
#define GET_BINDING_ADDRESS_COMMAND			'+', 'B', 'I', 'N', 'D', '?'

#define SET_POLARITY_LED_COMMAND			'+', 'P', 'O', 'L', 'A', 'R', '='
#define GET_POLARITY_LED_COMMAND			'+', 'P', 'O', 'L', 'A', 'R', '?'

#define SET_POI_COMMNAD						'+', 'P', 'I', 'O', '='
#define SET_MULTIPLE_PIO_COMMAND			'+', 'M', 'P', 'I', 'O', '='
#define GET_PIO_INPUT_COMMAND				'+', 'M', 'P', 'I', 'O', '?'

#define SET_INQUIRY_PARAMETERS_COMMAND		'+', 'I', 'P', 'S', 'C', 'A', 'N', '='
#define GET_INQUIRY_PARAMETERS_COMMAND		'+', 'I', 'P', 'S', 'C', 'A', 'N', '?'

#define SET_POWER_SAVING_PARAMETERS_COMMAND	'+', 'S', 'N', 'I', 'F', 'F', '='
#define GET_POWER_SAVING_PARAMETERS_COMMAND '+', 'S', 'N', 'I', 'F', 'F', '?'

#define SET_ENCRYPTION_COMMAND				'+', 'S', 'E', 'N', 'M', '='
#define GET_ENCRYPTION_COMMAND				'+', 'S', 'E', 'N', 'M', '?'

#define DELETE_DEVICE_ENTRY_FROM_NET_TABLE	'+', 'R', 'M', 'S', 'A', 'D', '='
#define DELETE_ALL_ENTRIES_FROM_NET_TABLE	'+', 'R', 'M', 'S', 'A', 'D'

#define GET_AUTHENTICATED_DEVICE_COMMAND	'+', 'F', 'S', 'A', 'D', '='
#define GET_NETWORK_TABLE_LIST_LENGTH		'+', 'A', 'D', 'C', 'N', '?', '='

#define GET_MOST_RECENTLY_USED_COMAMND		'+', 'M', 'R', 'A', 'D', '?'
#define GET_DEVICE_STATE_COMMAND			'+', 'S', 'T', 'A', 'T', 'E', '?'

#define INIT_DEVICE_COMMAND					'+', 'I', 'N', 'I', 'T'
#define CREATE_NETWORK_MAP_COMMAND			'+', 'I', 'N', 'Q'

#define CANCEL_NETWORK_MAP_COMMAND			'+', 'I', 'N', 'Q', 'C'
#define PAIR_DEVICE_COMMAND					'+', 'P', 'A', 'I', 'R', '='
#define LINK_DEVICE_COMMAND					'+', 'L', 'I', 'N', 'K', '='
#define DISCONNECT_DEVICE_COMMAND			'+', 'D', 'I', 'S', 'C'
#define GO_INTO_ENERGY_SAVING_MODE_COMMAND	'+', 'E', 'N', 'S', 'N', 'I', 'F', 'F', '='
#define EXIT_ENERGY_SAVING_MODE_COMMAND		'+', 'E', 'X', 'S', 'N', 'I', 'F', 'F', '='

#define SOFTWARE_VERSION					"1.0-20090818"

#define INIT								"INITIALIZED"
#define READY								"READY"
#define PAIRABLE 							"PAIRABLE"
#define PAIRED 								"PAIRD"
#define NMAP 								"INQUIRING"
#define CONNECTING 							"CONNECTING"
#define CONNECTED 							"CONNECTED"
#define DISCONNECTED 						"DISCONNECTED"
#define UNKNOWN 							"NUKNOW"

#endif