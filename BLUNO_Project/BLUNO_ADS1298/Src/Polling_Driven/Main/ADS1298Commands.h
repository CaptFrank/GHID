/*
 * ADS1298Commands.h
 *
 *  Created on: 2014-05-15
 *      Author: francispapineau
 */

#ifndef ADS1298COMMANDS_H_
#define ADS1298COMMANDS_H_

/**
 * This document is the definitions of the divers read and write
 * command, registers and setup bits.
 *
 * *** Note: These definitions were taken from:
 * 		- http://www.mit.edu/~gari/CODE/ECG_lab/ecg_ads1292.ino
 */

//! --------------------------------------------------------------

/**
 * The SPI Commands
 */
enum spi_command {

	//! System commands
	WAKEUP 						= 0x02, 							//!< WAKEUP
	STANDBY 					= 0x04,								//!< STANDBY
	RESET 						= 0x06,  							//!< RESET
	START 						= 0x08,  							//!< START
	STOP 						= 0x0A,   							//!< STOP

	//! Read commands
	RDATAC 						= 0x10, 							//!< RDATAC
	SDATAC 						= 0x11, 							//!< SDATAC
	RDATA 						= 0x12,  							//!< RDATA

	//! Register commands
	RREG 						= 0x20,   							//!< RREG
	WREG 						= 0x40,    							//!< WREG
	EMPTY						= 0x00								//!< EMPTY
};

//! -------------------------------------------------------------------------------

/**
 * Register Definitions
 */
enum registers {
	//! Device settings
	ID 								= 0x00,          				//!< ID

	//! Global settings
	CONFIG1 						= 0x01,     					//!< CONFIG1
	CONFIG2 						= 0x02,     					//!< CONFIG2
	CONFIG3 						= 0x03,     					//!< CONFIG3
	LOFF 							= 0x04,        					//!< LOFF

	//! Channel specific settings
	CHnSET 							= 0x04,      					//!< CHnSET
	CH1SET 							= CHnSET + 1,					//!< CH1SET
	CH2SET 							= CHnSET + 2,					//!< CH2SET
	CH3SET 							= CHnSET + 3,					//!< CH3SET
	CH4SET 							= CHnSET + 4,					//!< CH4SET
	CH5SET 							= CHnSET + 5,					//!< CH5SET
	CH6SET 							= CHnSET + 6,					//!< CH6SET
	CH7SET 							= CHnSET + 7,					//!< CH7SET
	CH8SET 							= CHnSET + 8,					//!< CH8SET
	RLD_SENSP 						= 0x0d,   						//!< RLD_SENSP
	RLD_SENSN 						= 0x0e,   						//!< RLD_SENSN
	LOFF_SENSP 						= 0x0f,  						//!< LOFF_SENSP
	LOFF_SENSN 						= 0x10,  						//!< LOFF_SENSN
	LOFF_FLIP 						= 0x11,   						//!< LOFF_FLIP

	//! Lead off status
	LOFF_STATP 						= 0x12,  						//!< LOFF_STATP
	LOFF_STATN 						= 0x13,  						//!< LOFF_STATN

	//! Other
	GPIO 							= 0x14,        					//!< GPIO
	PACE 							= 0x15,        					//!< PACE
	RESP 							= 0x16,       					//!< RESP
	CONFIG4 						= 0x17,    						//!< CONFIG4
	WCT1 							= 0x18,        					//!< WCT1
	WCT2 							= 0x19         					//!< WCT2
};

//! -------------------------------------------------------------------------------

/**
 * The identification bits
 */
enum id_bits {

	DEV_ID7 					= 0x80,                        		//!< DEV_ID7
	DEV_ID6 					= 0x40,                        		//!< DEV_ID6
	DEV_ID5 					= 0x20,                        		//!< DEV_ID5
	DEV_ID2 					= 0x04,                        		//!< DEV_ID2
	DEV_ID1 					= 0x02,                        		//!< DEV_ID1
	DEV_ID0 					= 0x01,                        		//!< DEV_ID0

	ID_const 					= 0x10,                       		//!< ID_const
	ID_ADS129x 					= DEV_ID7,                  		//!< ID_ADS129x
	ID_ADS129xR 				= (DEV_ID7 | DEV_ID6),     			//!< ID_ADS129xR

	ID_4CHAN 					= 0,                          		//!< ID_4CHAN
	ID_6CHAN 					= DEV_ID0,                    		//!< ID_6CHAN
	ID_8CHAN 					= DEV_ID1,                    		//!< ID_8CHAN

	ID_ADS1294 					= (ID_ADS129x | ID_4CHAN),  		//!< ID_ADS1294
	ID_ADS1296 					= (ID_ADS129x | ID_6CHAN),  		//!< ID_ADS1296
	ID_ADS1298 					= (ID_ADS129x | ID_8CHAN),  		//!< ID_ADS1298
	ID_ADS1294R 				= (ID_ADS129xR | ID_4CHAN),			//!< ID_ADS1294R
	ID_ADS1296R 				= (ID_ADS129xR | ID_6CHAN),			//!< ID_ADS1296R
	ID_ADS1298R 				= (ID_ADS129xR | ID_8CHAN) 			//!< ID_ADS1298R
};

//! -------------------------------------------------------------------------------

/**
 * Config 1 setup bits
 */
enum config1_bits {

	HR 							= 0x80,                            	//!< HR
	DR2 						= 0x04,                            	//!< DR2
	DR1 						= 0x02,                         	//!< DR1
	DR0 						= 0x01,                             //!< DR0
	DAISY_EN 					= 0x40,                             //!< DAISY_EN
	CLK_EN 						= 0x20,                             //!< CLK_EN

	CONFIG1_const 				= 0x00,                            	//!< CONFIG1_const
	HIGH_RES_32k_SPS 			= HR,            					//!< HIGH_RES_32k_SPS
	HIGH_RES_16k_SPS 			= (HR | DR0),      					//!< HIGH_RES_16k_SPS
	HIGH_RES_8k_SPS 			= (HR | DR1),      					//!< HIGH_RES_8k_SPS
	HIGH_RES_4k_SPS 			= (HR | DR1 | DR0), 				//!< HIGH_RES_4k_SPS
	HIGH_RES_2k_SPS 			= (HR | DR2),       				//!< HIGH_RES_2k_SPS
	HIGH_RES_1k_SPS 			= (HR | DR2 | DR0), 				//!< HIGH_RES_1k_SPS
	HIGH_RES_500_SPS 			= (HR | DR2 | DR1),					//!< HIGH_RES_500_SPS
	LOW_POWR_250_SPS 			= (HR | DR1)       					//!< LOW_POWR_250_SPS
};

//! -------------------------------------------------------------------------------

/**
 * Config 2 setup bits
 */
enum config2_bits {

	WCT_CHOP 					= 0x20,                       		//!< WCT_CHOP
	INT_TEST 					= 0x10,                             //!< INT_TEST
	TEST_AMP 					= 0x04,                             //!< TEST_AMP
	TEST_FREQ1 					= 0x02,                             //!< TEST_FREQ1
	TEST_FREQ0 					= 0x01,                             //!< TEST_FREQ0

	CONFIG2_const 				= 0x00,                             //!< CONFIG2_const
	INT_TEST_4HZ 				= INT_TEST,                         //!< INT_TEST_4HZ
	INT_TEST_8HZ 				= (INT_TEST | TEST_FREQ0),          //!< INT_TEST_8HZ
	INT_TEST_DC 				= (INT_TEST | TEST_FREQ1 | TEST_FREQ0) //!< INT_TEST_DC
};

//! -------------------------------------------------------------------------------

/**
 * Config 3 setup bits
 */
enum config3_bits {

	PD_REFBUF 					= 0x80,    							//!< PD_REFBUF
	VREF_4V 					= 0x20,      						//!< VREF_4V
	RLD_MEAS 					= 0x10,     						//!< RLD_MEAS
	RLDREF_INT 					= 0x08,  							//!< RLDREF_INT
	PD_RLD 						= 0x04,       						//!< PD_RLD
	RLD_LOFF_SENS 				= 0x02,								//!< RLD_LOFF_SENS
	RLD_STAT 					= 0x01,     						//!< RLD_STAT

	CONFIG3_const				= 0x40								//!< CONFIG3_const
};

//! -------------------------------------------------------------------------------

/**
 * Config 4 setup bits
 */
enum config4_bits {

	RESP_FREQ2 					= 0x80,                             //!< RESP_FREQ2
	RESP_FREQ1 					= 0x40,                             //!< RESP_FREQ1
	RESP_FREQ0 					= 0x20,                             //!< RESP_FREQ0
	SINGLE_SHOT 				= 0x08,                             //!< SINGLE_SHOT
	WCT_TO_RLD 					= 0x04,                             //!< WCT_TO_RLD
	PD_LOFF_COMP 				= 0x02,                             //!< PD_LOFF_COMP

	CONFIG4_const 				= 0x00,                             //!< CONFIG4_const

	RESP_FREQ_64k_Hz 			= 0x00,                             //!< RESP_FREQ_64k_Hz
	RESP_FREQ_32k_Hz 			= RESP_FREQ0,                       //!< RESP_FREQ_32k_Hz
	RESP_FREQ_16k_Hz 			= RESP_FREQ1,                       //!< RESP_FREQ_16k_Hz
	RESP_FREQ_8k_Hz 			= (RESP_FREQ1 | RESP_FREQ0),        //!< RESP_FREQ_8k_Hz
	RESP_FREQ_4k_Hz 			= RESP_FREQ2,                       //!< RESP_FREQ_4k_Hz
	RESP_FREQ_2k_Hz 			= (RESP_FREQ2 | RESP_FREQ0),        //!< RESP_FREQ_2k_Hz
	RESP_FREQ_1k_Hz 			= (RESP_FREQ2 | RESP_FREQ1),        //!< RESP_FREQ_1k_Hz
	RESP_FREQ_500_Hz 			= (RESP_FREQ2 | RESP_FREQ1 | RESP_FREQ0)//!< RESP_FREQ_500_Hz
};

//! -------------------------------------------------------------------------------

/**
 * The lead off bits
 */
enum loff_bits {

	COMP_TH2 					= 0x80,                         	//!< COMP_TH2
	COMP_TH1 					= 0x40,                             //!< COMP_TH1
	COMP_TH0 					= 0x20,                             //!< COMP_TH0
	VLEAD_OFF_EN 				= 0x10,                          	//!< VLEAD_OFF_EN
	ILEAD_OFF1 					= 0x08,                            	//!< ILEAD_OFF1
	ILEAD_OFF0 					= 0x04,                            	//!< ILEAD_OFF0
	FLEAD_OFF1 					= 0x02,                            	//!< FLEAD_OFF1
	FLEAD_OFF0 					= 0x01,                            	//!< FLEAD_OFF0

	LOFF_const 					= 0x00,                            	//!< LOFF_const

	COMP_TH_95 					= 0x00,                            	//!< COMP_TH_95
	COMP_TH_92_5 				= COMP_TH0,                      	//!< COMP_TH_92_5
	COMP_TH_90 					= COMP_TH1,                        	//!< COMP_TH_90
	COMP_TH_87_5 				= (COMP_TH1 | COMP_TH0),         	//!< COMP_TH_87_5
	COMP_TH_85 					= COMP_TH2,                        	//!< COMP_TH_85
	COMP_TH_80 					= (COMP_TH2 | COMP_TH0),           	//!< COMP_TH_80
	COMP_TH_75 					= (COMP_TH2 | COMP_TH1),           	//!< COMP_TH_75
	COMP_TH_70 					= (COMP_TH2 | COMP_TH1 | COMP_TH0),	//!< COMP_TH_70

	ILEAD_OFF_6nA 				= 0x00,                         	//!< ILEAD_OFF_6nA
	ILEAD_OFF_12nA 				= ILEAD_OFF0,                  		//!< ILEAD_OFF_12nA
	ILEAD_OFF_18nA 				= ILEAD_OFF1,                  		//!< ILEAD_OFF_18nA
	ILEAD_OFF_24nA 				= (ILEAD_OFF1 | ILEAD_OFF0),   		//!< ILEAD_OFF_24nA

	FLEAD_OFF_AC 				= FLEAD_OFF0,                    	//!< FLEAD_OFF_AC
	FLEAD_OFF_DC 				= (FLEAD_OFF1 | FLEAD_OFF0)      	//!< FLEAD_OFF_DC
};

//! -------------------------------------------------------------------------------

/**
 * Channel set bits
 */
enum channel_set_bits {

	PDn 						= 0x80,                      		//!< PDn
	PD_n 						= 0x80,                     		//!< PD_n
	GAINn2 						= 0x40,                   			//!< GAINn2
	GAINn1 						= 0x20,                   			//!< GAINn1
	GAINn0 						= 0x10,                   			//!< GAINn0
	MUXn2 						= 0x04,                    			//!< MUXn2
	MUXn1 						= 0x02,                    			//!< MUXn1
	MUXn0 						= 0x01,                    			//!< MUXn0

	CHnSET_const 				= 0x00,             				//!< CHnSET_const

	GAIN_1X 					= GAINn0,                			//!< GAIN_1X
	GAIN_2X 					= GAINn1,                			//!< GAIN_2X
	GAIN_3X 					= (GAINn1 | GAINn0),     			//!< GAIN_3X
	GAIN_4X 					= GAINn2,                			//!< GAIN_4X
	GAIN_6X 					= 0x00,                  			//!< GAIN_6X
	GAIN_8X 					= (GAINn2 | GAINn0),     			//!< GAIN_8X
	GAIN_12X 					= (GAINn2 | GAINn1),    			//!< GAIN_12X

	ELECTRODE_INPUT 			= 0x00,          					//!< ELECTRODE_INPUT
	SHORTED 					= MUXn0,                 			//!< SHORTED
	RLD_INPUT 					= MUXn1,              				//!< RLD_INPUT
	MVDD 						= (MUXn1 | MUXn0),          		//!< MVDD
	TEMP 						= MUXn2,                    		//!< TEMP
	TEST_SIGNAL 				= (MUXn2 | MUXn0),   				//!< TEST_SIGNAL
	RLD_DRP 					= (MUXn2 | MUXn1),       			//!< RLD_DRP
	RLD_DRN 					= (MUXn2 | MUXn1 | MUXn0)			//!< RLD_DRN
};

//! -------------------------------------------------------------------------------

/**
 * Channel 1 set bits
 */
enum channel_1_set_bits {

	PD_1 						= 0x80,       						//!< PD_1
	GAIN12 						= 0x40,     						//!< GAIN12
	GAIN11 						= 0x20,    							//!< GAIN11
	GAIN10 						= 0x10,     						//!< GAIN10
	MUX12 						= 0x04,      						//!< MUX12
	MUX11 						= 0x02,      						//!< MUX11
	MUX10 						= 0x01,      						//!< MUX10

	CH1SET_const 				= 0x00								//!< CH1SET_const
};

//! -------------------------------------------------------------------------------

/**
 * Channel 2 set bits
 */
enum channel_2_set_bits {

	PD_2 						= 0x80,      	 					//!< PD_2
	GAIN22 						= 0x40,     						//!< GAIN22
	GAIN21 						= 0x20,     						//!< GAIN21
	GAIN20 						= 0x10,     						//!< GAIN20
	MUX22 						= 0x04,      						//!< MUX22
	MUX21 						= 0x02,      						//!< MUX21
	MUX20 						= 0x01,      						//!< MUX20

	CH2SET_const 				= 0x00								//!< CH2SET_const
};

//! -------------------------------------------------------------------------------

/**
 * Channel 3 set bits
 */
enum channel_3_set_bits {

	PD_3 						= 0x80,       						//!< PD_3
	GAIN32 						= 0x40,     						//!< GAIN32
	GAIN31 						= 0x20,     						//!< GAIN31
	GAIN30 						= 0x10,     						//!< GAIN30
	MUX32 						= 0x04,      						//!< MUX32
	MUX31 						= 0x02,      						//!< MUX31
	MUX30 						= 0x01,      						//!< MUX30

	CH3SET_const 				= 0x00								//!< CH3SET_const
};

//! -------------------------------------------------------------------------------

/**
 * Channel 4 set bits
 */
enum channel_4_set_bits {

	PD_4 						= 0x80,       						//!< PD_4
	GAIN42 						= 0x40,     						//!< GAIN42
	GAIN41 						= 0x20,     						//!< GAIN41
	GAIN40 						= 0x10,     						//!< GAIN40
	MUX42 						= 0x04,      						//!< MUX42
	MUX41 						= 0x02,      						//!< MUX41
	MUX40 						= 0x01,      						//!< MUX40

	CH4SET_const 				= 0x00								//!< CH4SET_const
};

//! -------------------------------------------------------------------------------

/**
 * Channel 5 set bits
 */
enum channel_5_set_bits {

	PD_5 						= 0x80,       						//!< PD_4
	GAIN52 						= 0x40,     						//!< GAIN42
	GAIN51 						= 0x20,     						//!< GAIN41
	GAIN50 						= 0x10,     						//!< GAIN40
	MUX52 						= 0x04,      						//!< MUX42
	MUX51 						= 0x02,      						//!< MUX41
	MUX50 						= 0x01,      						//!< MUX40

	CH5SET_const 				= 0x00								//!< CH4SET_const
};

//! -------------------------------------------------------------------------------

/**
 * Channel 6 set bits
 */
enum channel_6_set_bits {

	PD_6 						= 0x80,       						//!< PD_4
	GAIN62 						= 0x40,     						//!< GAIN42
	GAIN61 						= 0x20,     						//!< GAIN41
	GAIN60 						= 0x10,     						//!< GAIN40
	MUX62 						= 0x04,      						//!< MUX42
	MUX61 						= 0x02,      						//!< MUX41
	MUX60 						= 0x01,      						//!< MUX40

	CH6SET_const 				= 0x00								//!< CH4SET_const
};

//! -------------------------------------------------------------------------------

/**
 * Channel 7 set bits
 */
enum channel_7_set_bits {

	PD_7 						= 0x80,       						//!< PD_4
	GAIN72 						= 0x40,     						//!< GAIN42
	GAIN71 						= 0x20,     						//!< GAIN41
	GAIN70 						= 0x10,     						//!< GAIN40
	MUX72 						= 0x04,      						//!< MUX42
	MUX71 						= 0x02,      						//!< MUX41
	MUX70 						= 0x01,      						//!< MUX40

	CH7SET_const 				= 0x00								//!< CH4SET_const
};

//! -------------------------------------------------------------------------------

/**
 * Channel 8 set bits
 */
enum channel_8_set_bits {

	PD_8 						= 0x80,       						//!< PD_4
	GAIN82 						= 0x40,     						//!< GAIN42
	GAIN81 						= 0x20,     						//!< GAIN41
	GAIN80 						= 0x10,     						//!< GAIN40
	MUX82 						= 0x04,      						//!< MUX42
	MUX81 						= 0x02,      						//!< MUX41
	MUX80 						= 0x01,      						//!< MUX40

	CH8SET_const 				= 0x00								//!< CH4SET_const
};

//! -------------------------------------------------------------------------------

/**
 * Reload sense positive bits
 */
enum rld_sensop_bits {

	RLD8P 						= 0x80,         					//!< RLD8P
	RLD7P 						= 0x40,         					//!< RLD7P
	RLD6P 						= 0x20,         					//!< RLD6P
	RLD5P 						= 0x10,        						//!< RLD5P
	RLD4P 						= 0x08,        						//!< RLD4P
	RLD3P 						= 0x04,         					//!< RLD3P
	RLD2P 						= 0x02,         					//!< RLD2P
	RLD1P 						= 0x01,         					//!< RLD1P

	RLD_SENSP_const 			= 0x00								//!< RLD_SENSP_const
};

//! -------------------------------------------------------------------------------

/**
 * Reload sense negative bits
 */
enum rld_senson_bits {

	RLD8N 						= 0x80,   							//!< RLD8N
	RLD7N 						= 0x40,         					//!< RLD7N
	RLD6N 						= 0x20,        						//!< RLD6N
	RLD5N 						= 0x10,         					//!< RLD5N
	RLD4N 						= 0x08,         					//!< RLD4N
	RLD3N 						= 0x04,         					//!< RLD3N
	RLD2N 						= 0x02,         					//!< RLD2N
	RLD1N 						= 0x01,         					//!< RLD1N

	RLD_SENSN_const 			= 0x00								//!< RLD_SENSN_const
};

//! -------------------------------------------------------------------------------

/**
 * LOFF Sense positive set bits
 */
enum loff_sensp_bits {

	LOFF8P 						= 0x80,         					//!< LOFF8P
	LOFF7P 						= 0x40,         					//!< LOFF7P
	LOFF6P 						= 0x20,         					//!< LOFF6P
	LOFF5P 						= 0x10,         					//!< LOFF5P
	LOFF4P 						= 0x08,         					//!< LOFF4P
	LOFF3P 						= 0x04,         					//!< LOFF3P
	LOFF2P 						= 0x02,         					//!< LOFF2P
	LOFF1P 						= 0x01,        						//!< LOFF1P

	LOFF_SENSP_const 			= 0x00								//!< LOFF_SENSP_const
};

//! -------------------------------------------------------------------------------

/**
 * LOFF Sense negative bits
 */
enum loff_sensn_bits {

	LOFF8N 						= 0x80,         					//!< LOFF8N
	LOFF7N 						= 0x40,         					//!< LOFF7N
	LOFF6N 						= 0x20,         					//!< LOFF6N
	LOFF5N 						= 0x10,         					//!< LOFF5N
	LOFF4N 						= 0x08,         					//!< LOFF4N
	LOFF3N 						= 0x04,         					//!< LOFF3N
	LOFF2N 						= 0x02,         					//!< LOFF2N
	LOFF1N 						= 0x01,         					//!< LOFF1N

	LOFF_SENSN_const 			= 0x00								//!< LOFF_SENSN_const
};

//! -------------------------------------------------------------------------------

/**
 * LOFF Flip bits
 */
enum loff_flip_bits {

	LOFF_FLIP8 					= 0x80,    							//!< LOFF_FLIP8
	LOFF_FLIP7 					= 0x40,    							//!< LOFF_FLIP7
	LOFF_FLIP6 					= 0x20,    							//!< LOFF_FLIP6
	LOFF_FLIP5 					= 0x10,    							//!< LOFF_FLIP5
	LOFF_FLIP4 					= 0x08,    							//!< LOFF_FLIP4
	LOFF_FLIP3 					= 0x04,    							//!< LOFF_FLIP3
	LOFF_FLIP2 					= 0x02,    							//!< LOFF_FLIP2
	LOFF_FLIP1 					= 0x01,   							//!< LOFF_FLIP1

	LOFF_FLIP_const = 0x00											//!< LOFF_FLIP_const
};

//! -------------------------------------------------------------------------------

/**
 * LOFF Stat positive bits
 */
enum loff_statp_bits {

	IN8P_OFF 					= 0x80,       						//!< IN8P_OFF
	IN7P_OFF 					= 0x40,       						//!< IN7P_OFF
	IN6P_OFF 					= 0x20,       						//!< IN6P_OFF
	IN5P_OFF 					= 0x10,       						//!< IN5P_OFF
	IN4P_OFF 					= 0x08,       						//!< IN4P_OFF
	IN3P_OFF 					= 0x04,       						//!< IN3P_OFF
	IN2P_OFF 					= 0x02,       						//!< IN2P_OFF
	IN1P_OFF 					= 0x01,       						//!< IN1P_OFF

	LOFF_STATP_const 			= 0x00								//!< LOFF_STATP_const
};

//! -------------------------------------------------------------------------------

/**
 * LOFF Stat negative bits
 */
enum loff_statn_bits {

	IN8N_OFF 					= 0x80,       						//!< IN8N_OFF
	IN7N_OFF 					= 0x40,       						//!< IN7N_OFF
	IN6N_OFF 					= 0x20,       						//!< IN6N_OFF
	IN5N_OFF 					= 0x10,       						//!< IN5N_OFF
	IN4N_OFF 					= 0x08,       						//!< IN4N_OFF
	IN3N_OFF 					= 0x04,       						//!< IN3N_OFF
	IN2N_OFF 					= 0x02,       						//!< IN2N_OFF
	IN1N_OFF 					= 0x01,       						//!< IN1N_OFF

	LOFF_STATN_const 			= 0x00								//!< LOFF_STATN_const
};

//! -------------------------------------------------------------------------------

/**
 * GPIO bits
 */
enum gpio_bits {

	GPIOD4 						= 0x80,   							//!< GPIOD4
	GPIOD3 						= 0x40,   							//!< GPIOD3
	GPIOD2 						= 0x20,   							//!< GPIOD2
	GPIOD1 						= 0x10,   							//!< GPIOD1
	GPIOC4 						= 0x08,   							//!< GPIOC4
	GPIOC3 						= 0x04,   							//!< GPIOC3
	GPIOC2 						= 0x02,   							//!< GPIOC2
	GPIOC1 						= 0x01,   							//!< GPIOC1

	GPIO_const 					= 0x00								//!< GPIO_const
};

//! -------------------------------------------------------------------------------

/**
 * The resp bits
 */
enum resp_bits {

	RESP_DEMOD_EN1 				= 0x80,                      		//!< RESP_DEMOD_EN1
	RESP_MOD_EN1 				= 0x40,                        		//!< RESP_MOD_EN1
	RESP_PH2 					= 0x10,                            	//!< RESP_PH2
	RESP_PH1 					= 0x08,                            	//!< RESP_PH1
	RESP_PH0 					= 0x04,                            	//!< RESP_PH0
	RESP_CTRL1 					= 0x02,                          	//!< RESP_CTRL1
	RESP_CTRL0 					= 0x01,                          	//!< RESP_CTRL0

	RESP_const 					= 0x20,                          	//!< RESP_const

	RESP_PH_22_5 				= 0x00,                        		//!< RESP_PH_22_5
	RESP_PH_45 					= RESP_PH0,                     	//!< RESP_PH_45
	RESP_PH_67_5 				= RESP_PH1,                    		//!< RESP_PH_67_5
	RESP_PH_90 					= (RESP_PH1 | RESP_PH0),         	//!< RESP_PH_90
	RESP_PH_112_5 				= RESP_PH2,                   		//!< RESP_PH_112_5
	RESP_PH_135 				= (RESP_PH2 | RESP_PH0),       		//!< RESP_PH_135
	RESP_PH_157_5 				= (RESP_PH2 | RESP_PH1),      		//!< RESP_PH_157_5

	RESP_NONE 					= 0x00,                           	//!< RESP_NONE
	RESP_EXT 					= RESP_CTRL0,                     	//!< RESP_EXT
	RESP_INT_SIG_INT 			= RESP_CTRL1,              			//!< RESP_INT_SIG_INT
	RESP_INT_SIG_EXT 			= (RESP_CTRL1 | RESP_CTRL0)			//!< RESP_INT_SIG_EXT
};

//! -------------------------------------------------------------------------------

/**
 * The Pace bits
 */
enum pace_bits {

	PACEE1 						= 0x10,                  			//!< PACEE1
	PACEE0 						= 0x08,                  			//!< PACEE0
	PACEO1 						= 0x04,                  			//!< PACEO1
	PACEO0 						= 0x02,                  			//!< PACEO0
	PD_PACE 					= 0x01,                 			//!< PD_PACE

	PACE_const 					= 0x00,              				//!< PACE_const

	PACEE_CHAN2 				= 0x00,             				//!< PACEE_CHAN2
	PACEE_CHAN4 				= PACEE0,           				//!< PACEE_CHAN4
	PACEE_CHAN6 				= PACEE1,           				//!< PACEE_CHAN6
	PACEE_CHAN8 				= (PACEE1 | PACEE0),				//!< PACEE_CHAN8

	PACEO_CHAN1 				= 0x00,             				//!< PACEO_CHAN1
	PACEO_CHAN3 				= PACEE0,           				//!< PACEO_CHAN3
	PACEO_CHAN5 				= PACEE1,           				//!< PACEO_CHAN5
	PACEO_CHAN7 				= (PACEE1 | PACEE0) 				//!< PACEO_CHAN7
};

//! -------------------------------------------------------------------------------

/**
 * WCT 1 setup bits
 */
enum WCT1_bits {

	aVF_CH6 					= 0x80,                    			//!< aVF_CH6
	aVL_CH5 					= 0x40,                    			//!< aVL_CH5
	aVR_CH7 					= 0x20,                    			//!< aVR_CH7
	avR_CH4 					= 0x10,                    			//!< avR_CH4
	PD_WCTA 					= 0x08,                    			//!< PD_WCTA
	WCTA2 						= 0x04,                      		//!< WCTA2
	WCTA1 						= 0x02,                      		//!< WCTA1
	WCTA0 						= 0x01,                      		//!< WCTA0

	WCT1_const 					= 0x00,                 			//!< WCT1_const

	WCTA_CH1P 					= 0x00,                  			//!< WCTA_CH1P
	WCTA_CH1N 					= WCTA0,                 			//!< WCTA_CH1N
	WCTA_CH2P 					= WCTA1,                 			//!< WCTA_CH2P
	WCTA_CH2N 					= (WCTA1 | WCTA0),       			//!< WCTA_CH2N
	WCTA_CH3P 					= WCTA2,                 			//!< WCTA_CH3P
	WCTA_CH3N 					= (WCTA2 | WCTA0),       			//!< WCTA_CH3N
	WCTA_CH4P 					= (WCTA2 | WCTA1),       			//!< WCTA_CH4P
	WCTA_CH4N 					= (WCTA2 | WCTA1 | WCTA0)			//!< WCTA_CH4N
};

//! -------------------------------------------------------------------------------

/**
 * WCT 2 setup bits
 */
enum WCT2_bits {

	PD_WCTC 					= 0x80,                     		//!< PD_WCTC
	PD_WCTB 					= 0x40,                     		//!< PD_WCTB
	WCTB2 						= 0x20,                       		//!< WCTB2
	WCTB1 						= 0x10,                      		//!< WCTB1
	WCTB0 						= 0x08,                       		//!< WCTB0
	WCTC2 						= 0x04,                       		//!< WCTC2
	WCTC1 						= 0x02,                       		//!< WCTC1
	WCTC0 						= 0x01,                       		//!< WCTC0

	WCT2_const 					= 0x00,                  			//!< WCT2_const

	WCTB_CH1P 					= 0x00,                   			//!< WCTB_CH1P
	WCTB_CH1N 					= WCTB0,                  			//!< WCTB_CH1N
	WCTB_CH2P 					= WCTB1,                  			//!< WCTB_CH2P
	WCTB_CH2N 					= (WCTB1 | WCTB0),        			//!< WCTB_CH2N
	WCTB_CH3P 					= WCTB2,                  			//!< WCTB_CH3P
	WCTB_CH3N 					= (WCTB2 | WCTB0),        			//!< WCTB_CH3N
	WCTB_CH4P 					= (WCTB2 | WCTB1),        			//!< WCTB_CH4P
	WCTB_CH4N 					= (WCTB2 | WCTB1 | WCTB0),			//!< WCTB_CH4N

	WCTC_CH1P 					= 0x00,                   			//!< WCTC_CH1P
	WCTC_CH1N 					= WCTC0,                  			//!< WCTC_CH1N
	WCTC_CH2P 					= WCTC1,                  			//!< WCTC_CH2P
	WCTC_CH2N 					= (WCTC1 | WCTC0),        			//!< WCTC_CH2N
	WCTC_CH3P 					= WCTC2,                  			//!< WCTC_CH3P
	WCTC_CH3N 					= (WCTC2 | WCTC0),        			//!< WCTC_CH3N
	WCTC_CH4P 					= (WCTC2 | WCTC1),        			//!< WCTC_CH4P
	WCTC_CH4N 					= (WCTC2 | WCTC1 | WCTC0) 			//!< WCTC_CH4N
};

#endif /* ADS1298COMMANDS_H_ */
