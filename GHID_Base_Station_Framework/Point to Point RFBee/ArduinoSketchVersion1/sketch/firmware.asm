C:\Users\francis-ccs\AppData\Local\VMicro\Arduino\Builds\sketch\mega2560\sketch.elf:     file format elf32-avr

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .data         00000236  00800200  00001de6  00001e7a  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  1 .text         00001de6  00000000  00000000  00000094  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  2 .bss          000003b1  00800436  00800436  000020b0  2**0
                  ALLOC
  3 .debug_aranges 00000a88  00000000  00000000  000020b0  2**0
                  CONTENTS, READONLY, DEBUGGING
  4 .debug_pubnames 00001d1d  00000000  00000000  00002b38  2**0
                  CONTENTS, READONLY, DEBUGGING
  5 .debug_info   0000f873  00000000  00000000  00004855  2**0
                  CONTENTS, READONLY, DEBUGGING
  6 .debug_abbrev 00002f40  00000000  00000000  000140c8  2**0
                  CONTENTS, READONLY, DEBUGGING
  7 .debug_line   000075e7  00000000  00000000  00017008  2**0
                  CONTENTS, READONLY, DEBUGGING
  8 .debug_frame  00001210  00000000  00000000  0001e5f0  2**2
                  CONTENTS, READONLY, DEBUGGING
  9 .debug_str    000038da  00000000  00000000  0001f800  2**0
                  CONTENTS, READONLY, DEBUGGING
 10 .debug_loc    0000572a  00000000  00000000  000230da  2**0
                  CONTENTS, READONLY, DEBUGGING
 11 .debug_ranges 000009e0  00000000  00000000  00028804  2**0
                  CONTENTS, READONLY, DEBUGGING

Disassembly of section .text:

00000000 <__vectors>:
COMMAND_PARSER::COMMAND_PARSER(NVRAM* nvram_object, PACKET_HANDLER* packet_decoder){
			
	this->command_buffer = 0;
	this->nvram_object = nvram_object;
	this->packet_decoder = packet_decoder;
}
       0:	73 c0       	rjmp	.+230    	; 0xe8 <__ctors_end>
		for(;;);
	#endif
		reset_device();
	}
	
	byte main_defines::check_context(){
       2:	00 00       	nop
	this->_packet_id 		= 0;
	this->_packet_ver 		= 0;
	this->_sum_A			= 0;
	this->_sum_B 			= 0;
	this->_guard_bool		= false;
}
       4:	0c 94 0a 08 	jmp	0x1014	; 0x1014 <__vector_1>

// --------------------------------------------------------------------
//! Default constructor
PACKET_PARSER::PACKET_PARSER(SENSOR* db){
	this->db = db;
}
       8:	0c 94 3b 08 	jmp	0x1076	; 0x1076 <__vector_2>
}

/**
 * The check watchdog method.
 */
void WATCHDOG::check_watchdog(void){
       c:	0c 94 6c 08 	jmp	0x10d8	; 0x10d8 <__vector_3>
// Init class
RFBEE_STACK::RFBEE_STACK(NVRAM* nvram_object){

	this->nvram_object = nvram_object;
	this->error_flag = true;
}
      10:	0c 94 9d 08 	jmp	0x113a	; 0x113a <__vector_4>
	_init_scheduler();
	_start_scheduler();
}

// sorts the sensro priorities
void SCHEDULER::sort_priority(){
      14:	0c 94 ce 08 	jmp	0x119c	; 0x119c <__vector_5>

#include "Sensor.h"

// default constructor
SENSOR::SENSOR(){
} //Sensor
      18:	0c 94 ff 08 	jmp	0x11fe	; 0x11fe <__vector_6>
/**
 * This function configures the device with NVRAM stored
 * parameters.
 * @param nvram_object - NVRAM
 */
void configure_device(NVRAM* nvram_object){
      1c:	0c 94 30 09 	jmp	0x1260	; 0x1260 <__vector_7>
    #endif
      break;
#endif
    }
      
    intFunc[interruptNum] = 0;
      20:	0c 94 61 09 	jmp	0x12c2	; 0x12c2 <__vector_8>
	SREG = oldSREG;

	return m;
}

unsigned long micros() {
      24:	8e c0       	rjmp	.+284    	; 0x142 <__bad_interrupt>
#if !defined(USART_RX_vect) && !defined(USART0_RX_vect) && \
    !defined(USART_RXC_vect)
  #error "Don't know what the Data Received vector is called for the first UART"
#else
  void serialEvent() __attribute__((weak));
  void serialEvent() {}
      26:	00 00       	nop
    n += write(*buffer++);
  }
  return n;
}

size_t Print::print(const __FlashStringHelper *ifsh)
      28:	8c c0       	rjmp	.+280    	; 0x142 <__bad_interrupt>
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

unsigned int makeWord(unsigned int w) { return w; }
      2a:	00 00       	nop
      2c:	8a c0       	rjmp	.+276    	; 0x142 <__bad_interrupt>
      2e:	00 00       	nop
      30:	88 c0       	rjmp	.+272    	; 0x142 <__bad_interrupt>
      32:	00 00       	nop
      34:	86 c0       	rjmp	.+268    	; 0x142 <__bad_interrupt>
      36:	00 00       	nop
      38:	84 c0       	rjmp	.+264    	; 0x142 <__bad_interrupt>
      3a:	00 00       	nop
      3c:	82 c0       	rjmp	.+260    	; 0x142 <__bad_interrupt>
      3e:	00 00       	nop
      40:	80 c0       	rjmp	.+256    	; 0x142 <__bad_interrupt>
      42:	00 00       	nop
      44:	7e c0       	rjmp	.+252    	; 0x142 <__bad_interrupt>
      46:	00 00       	nop
      48:	7c c0       	rjmp	.+248    	; 0x142 <__bad_interrupt>
      4a:	00 00       	nop
      4c:	7a c0       	rjmp	.+244    	; 0x142 <__bad_interrupt>
      4e:	00 00       	nop
      50:	9d c7       	rjmp	.+3898   	; 0xf8c <__vector_20>
      52:	00 00       	nop
      54:	76 c0       	rjmp	.+236    	; 0x142 <__bad_interrupt>
      56:	00 00       	nop
      58:	74 c0       	rjmp	.+232    	; 0x142 <__bad_interrupt>
      5a:	00 00       	nop
      5c:	0c 94 92 09 	jmp	0x1324	; 0x1324 <__vector_23>
      60:	70 c0       	rjmp	.+224    	; 0x142 <__bad_interrupt>
      62:	00 00       	nop
      64:	0c 94 e8 09 	jmp	0x13d0	; 0x13d0 <__vector_25>
      68:	0c 94 e4 0a 	jmp	0x15c8	; 0x15c8 <__vector_26>
      6c:	6a c0       	rjmp	.+212    	; 0x142 <__bad_interrupt>
      6e:	00 00       	nop
      70:	68 c0       	rjmp	.+208    	; 0x142 <__bad_interrupt>
      72:	00 00       	nop
      74:	66 c0       	rjmp	.+204    	; 0x142 <__bad_interrupt>
      76:	00 00       	nop
      78:	64 c0       	rjmp	.+200    	; 0x142 <__bad_interrupt>
      7a:	00 00       	nop
      7c:	62 c0       	rjmp	.+196    	; 0x142 <__bad_interrupt>
      7e:	00 00       	nop
      80:	60 c0       	rjmp	.+192    	; 0x142 <__bad_interrupt>
      82:	00 00       	nop
      84:	5e c0       	rjmp	.+188    	; 0x142 <__bad_interrupt>
      86:	00 00       	nop
      88:	5c c0       	rjmp	.+184    	; 0x142 <__bad_interrupt>
      8a:	00 00       	nop
      8c:	5a c0       	rjmp	.+180    	; 0x142 <__bad_interrupt>
      8e:	00 00       	nop
      90:	0c 94 27 0a 	jmp	0x144e	; 0x144e <__vector_36>
      94:	0c 94 23 0b 	jmp	0x1646	; 0x1646 <__vector_37>
      98:	54 c0       	rjmp	.+168    	; 0x142 <__bad_interrupt>
      9a:	00 00       	nop
      9c:	52 c0       	rjmp	.+164    	; 0x142 <__bad_interrupt>
      9e:	00 00       	nop
      a0:	50 c0       	rjmp	.+160    	; 0x142 <__bad_interrupt>
      a2:	00 00       	nop
      a4:	4e c0       	rjmp	.+156    	; 0x142 <__bad_interrupt>
      a6:	00 00       	nop
      a8:	4c c0       	rjmp	.+152    	; 0x142 <__bad_interrupt>
      aa:	00 00       	nop
      ac:	4a c0       	rjmp	.+148    	; 0x142 <__bad_interrupt>
      ae:	00 00       	nop
      b0:	48 c0       	rjmp	.+144    	; 0x142 <__bad_interrupt>
      b2:	00 00       	nop
      b4:	46 c0       	rjmp	.+140    	; 0x142 <__bad_interrupt>
      b6:	00 00       	nop
      b8:	44 c0       	rjmp	.+136    	; 0x142 <__bad_interrupt>
      ba:	00 00       	nop
      bc:	42 c0       	rjmp	.+132    	; 0x142 <__bad_interrupt>
      be:	00 00       	nop
      c0:	40 c0       	rjmp	.+128    	; 0x142 <__bad_interrupt>
      c2:	00 00       	nop
      c4:	3e c0       	rjmp	.+124    	; 0x142 <__bad_interrupt>
      c6:	00 00       	nop
      c8:	3c c0       	rjmp	.+120    	; 0x142 <__bad_interrupt>
      ca:	00 00       	nop
      cc:	0c 94 66 0a 	jmp	0x14cc	; 0x14cc <__vector_51>
      d0:	0c 94 62 0b 	jmp	0x16c4	; 0x16c4 <__vector_52>
      d4:	36 c0       	rjmp	.+108    	; 0x142 <__bad_interrupt>
      d6:	00 00       	nop
      d8:	0c 94 a5 0a 	jmp	0x154a	; 0x154a <__vector_54>
      dc:	0c 94 a1 0b 	jmp	0x1742	; 0x1742 <__vector_55>
      e0:	30 c0       	rjmp	.+96     	; 0x142 <__bad_interrupt>
	...

000000e4 <__ctors_start>:
      e4:	8f 07       	cpc	r24, r31
      e6:	8a 0c       	add	r8, r10

000000e8 <__ctors_end>:
      e8:	11 24       	eor	r1, r1
      ea:	1f be       	out	0x3f, r1	; 63
      ec:	cf ef       	ldi	r28, 0xFF	; 255
      ee:	d1 e2       	ldi	r29, 0x21	; 33
      f0:	de bf       	out	0x3e, r29	; 62
      f2:	cd bf       	out	0x3d, r28	; 61
      f4:	00 e0       	ldi	r16, 0x00	; 0
      f6:	0c bf       	out	0x3c, r16	; 60

000000f8 <__do_copy_data>:
      f8:	14 e0       	ldi	r17, 0x04	; 4
      fa:	a0 e0       	ldi	r26, 0x00	; 0
      fc:	b2 e0       	ldi	r27, 0x02	; 2
      fe:	e6 ee       	ldi	r30, 0xE6	; 230
     100:	fd e1       	ldi	r31, 0x1D	; 29
     102:	00 e0       	ldi	r16, 0x00	; 0
     104:	0b bf       	out	0x3b, r16	; 59
     106:	02 c0       	rjmp	.+4      	; 0x10c <__do_copy_data+0x14>
     108:	07 90       	elpm	r0, Z+
     10a:	0d 92       	st	X+, r0
     10c:	a6 33       	cpi	r26, 0x36	; 54
     10e:	b1 07       	cpc	r27, r17
     110:	d9 f7       	brne	.-10     	; 0x108 <__do_copy_data+0x10>
     112:	1b be       	out	0x3b, r1	; 59

00000114 <__do_clear_bss>:
     114:	17 e0       	ldi	r17, 0x07	; 7
     116:	a6 e3       	ldi	r26, 0x36	; 54
     118:	b4 e0       	ldi	r27, 0x04	; 4
     11a:	01 c0       	rjmp	.+2      	; 0x11e <.do_clear_bss_start>

0000011c <.do_clear_bss_loop>:
     11c:	1d 92       	st	X+, r1

0000011e <.do_clear_bss_start>:
     11e:	a7 3e       	cpi	r26, 0xE7	; 231
     120:	b1 07       	cpc	r27, r17
     122:	e1 f7       	brne	.-8      	; 0x11c <.do_clear_bss_loop>

00000124 <__do_global_ctors>:
     124:	10 e0       	ldi	r17, 0x00	; 0
     126:	c8 ee       	ldi	r28, 0xE8	; 232
     128:	d0 e0       	ldi	r29, 0x00	; 0
     12a:	04 c0       	rjmp	.+8      	; 0x134 <.do_global_ctors_start>

0000012c <.do_global_ctors_loop>:
     12c:	22 97       	sbiw	r28, 0x02	; 2
     12e:	fe 01       	movw	r30, r28
     130:	0e 94 b6 0e 	call	0x1d6c	; 0x1d6c <__tablejump__>

00000134 <.do_global_ctors_start>:
     134:	c4 3e       	cpi	r28, 0xE4	; 228
     136:	d1 07       	cpc	r29, r17
     138:	c9 f7       	brne	.-14     	; 0x12c <.do_global_ctors_loop>
     13a:	0e 94 00 00 	call	0	; 0x0 <__vectors>
     13e:	0c 94 f1 0e 	jmp	0x1de2	; 0x1de2 <_exit>

00000142 <__bad_interrupt>:
     142:	5e cf       	rjmp	.-324    	; 0x0 <__vectors>

00000144 <do_random>:
     144:	a0 e0       	ldi	r26, 0x00	; 0
     146:	b0 e0       	ldi	r27, 0x00	; 0
     148:	e8 ea       	ldi	r30, 0xA8	; 168
     14a:	f0 e0       	ldi	r31, 0x00	; 0
     14c:	0c 94 c2 0e 	jmp	0x1d84	; 0x1d84 <__prologue_saves__+0x10>
     150:	ec 01       	movw	r28, r24
     152:	a8 80       	ld	r10, Y
     154:	b9 80       	ldd	r11, Y+1	; 0x01
     156:	ca 80       	ldd	r12, Y+2	; 0x02
     158:	db 80       	ldd	r13, Y+3	; 0x03
     15a:	a1 14       	cp	r10, r1
     15c:	b1 04       	cpc	r11, r1
     15e:	c1 04       	cpc	r12, r1
     160:	d1 04       	cpc	r13, r1
     162:	41 f4       	brne	.+16     	; 0x174 <do_random+0x30>
     164:	84 e2       	ldi	r24, 0x24	; 36
     166:	a8 2e       	mov	r10, r24
     168:	89 ed       	ldi	r24, 0xD9	; 217
     16a:	b8 2e       	mov	r11, r24
     16c:	8b e5       	ldi	r24, 0x5B	; 91
     16e:	c8 2e       	mov	r12, r24
     170:	87 e0       	ldi	r24, 0x07	; 7
     172:	d8 2e       	mov	r13, r24
     174:	c6 01       	movw	r24, r12
     176:	b5 01       	movw	r22, r10
     178:	2d e1       	ldi	r18, 0x1D	; 29
     17a:	33 ef       	ldi	r19, 0xF3	; 243
     17c:	41 e0       	ldi	r20, 0x01	; 1
     17e:	50 e0       	ldi	r21, 0x00	; 0
     180:	0e 94 99 0e 	call	0x1d32	; 0x1d32 <__divmodsi4>
     184:	27 ea       	ldi	r18, 0xA7	; 167
     186:	31 e4       	ldi	r19, 0x41	; 65
     188:	40 e0       	ldi	r20, 0x00	; 0
     18a:	50 e0       	ldi	r21, 0x00	; 0
     18c:	0e 94 58 0e 	call	0x1cb0	; 0x1cb0 <__mulsi3>
     190:	7b 01       	movw	r14, r22
     192:	8c 01       	movw	r16, r24
     194:	c6 01       	movw	r24, r12
     196:	b5 01       	movw	r22, r10
     198:	2d e1       	ldi	r18, 0x1D	; 29
     19a:	33 ef       	ldi	r19, 0xF3	; 243
     19c:	41 e0       	ldi	r20, 0x01	; 1
     19e:	50 e0       	ldi	r21, 0x00	; 0
     1a0:	0e 94 99 0e 	call	0x1d32	; 0x1d32 <__divmodsi4>
     1a4:	ca 01       	movw	r24, r20
     1a6:	b9 01       	movw	r22, r18
     1a8:	2c ee       	ldi	r18, 0xEC	; 236
     1aa:	34 ef       	ldi	r19, 0xF4	; 244
     1ac:	4f ef       	ldi	r20, 0xFF	; 255
     1ae:	5f ef       	ldi	r21, 0xFF	; 255
     1b0:	0e 94 58 0e 	call	0x1cb0	; 0x1cb0 <__mulsi3>
     1b4:	6e 0d       	add	r22, r14
     1b6:	7f 1d       	adc	r23, r15
     1b8:	80 1f       	adc	r24, r16
     1ba:	91 1f       	adc	r25, r17
     1bc:	97 ff       	sbrs	r25, 7
     1be:	04 c0       	rjmp	.+8      	; 0x1c8 <do_random+0x84>
     1c0:	61 50       	subi	r22, 0x01	; 1
     1c2:	70 40       	sbci	r23, 0x00	; 0
     1c4:	80 40       	sbci	r24, 0x00	; 0
     1c6:	90 48       	sbci	r25, 0x80	; 128
     1c8:	68 83       	st	Y, r22
     1ca:	79 83       	std	Y+1, r23	; 0x01
     1cc:	8a 83       	std	Y+2, r24	; 0x02
     1ce:	9b 83       	std	Y+3, r25	; 0x03
     1d0:	9b 01       	movw	r18, r22
     1d2:	ac 01       	movw	r20, r24
     1d4:	5f 77       	andi	r21, 0x7F	; 127
     1d6:	b9 01       	movw	r22, r18
     1d8:	ca 01       	movw	r24, r20
     1da:	cd b7       	in	r28, 0x3d	; 61
     1dc:	de b7       	in	r29, 0x3e	; 62
     1de:	ea e0       	ldi	r30, 0x0A	; 10
     1e0:	0c 94 de 0e 	jmp	0x1dbc	; 0x1dbc <__epilogue_restores__+0x10>

000001e4 <random_r>:
     1e4:	af cf       	rjmp	.-162    	; 0x144 <do_random>

000001e6 <random>:
     1e6:	89 ef       	ldi	r24, 0xF9	; 249
     1e8:	93 e0       	ldi	r25, 0x03	; 3
     1ea:	ac cf       	rjmp	.-168    	; 0x144 <do_random>

000001ec <srandom>:
     1ec:	60 93 f9 03 	sts	0x03F9, r22
     1f0:	70 93 fa 03 	sts	0x03FA, r23
     1f4:	80 93 fb 03 	sts	0x03FB, r24
     1f8:	90 93 fc 03 	sts	0x03FC, r25
     1fc:	08 95       	ret

000001fe <sprintf>:
     1fe:	ae e0       	ldi	r26, 0x0E	; 14
     200:	b0 e0       	ldi	r27, 0x00	; 0
     202:	e5 e0       	ldi	r30, 0x05	; 5
     204:	f1 e0       	ldi	r31, 0x01	; 1
     206:	0c 94 c8 0e 	jmp	0x1d90	; 0x1d90 <__prologue_saves__+0x1c>
     20a:	0e 89       	ldd	r16, Y+22	; 0x16
     20c:	1f 89       	ldd	r17, Y+23	; 0x17
     20e:	86 e0       	ldi	r24, 0x06	; 6
     210:	8c 83       	std	Y+4, r24	; 0x04
     212:	1a 83       	std	Y+2, r17	; 0x02
     214:	09 83       	std	Y+1, r16	; 0x01
     216:	8f ef       	ldi	r24, 0xFF	; 255
     218:	9f e7       	ldi	r25, 0x7F	; 127
     21a:	9e 83       	std	Y+6, r25	; 0x06
     21c:	8d 83       	std	Y+5, r24	; 0x05
     21e:	9e 01       	movw	r18, r28
     220:	26 5e       	subi	r18, 0xE6	; 230
     222:	3f 4f       	sbci	r19, 0xFF	; 255
     224:	ce 01       	movw	r24, r28
     226:	01 96       	adiw	r24, 0x01	; 1
     228:	68 8d       	ldd	r22, Y+24	; 0x18
     22a:	79 8d       	ldd	r23, Y+25	; 0x19
     22c:	a9 01       	movw	r20, r18
     22e:	0a d0       	rcall	.+20     	; 0x244 <vfprintf>
     230:	2f 81       	ldd	r18, Y+7	; 0x07
     232:	38 85       	ldd	r19, Y+8	; 0x08
     234:	02 0f       	add	r16, r18
     236:	13 1f       	adc	r17, r19
     238:	f8 01       	movw	r30, r16
     23a:	10 82       	st	Z, r1
     23c:	2e 96       	adiw	r28, 0x0e	; 14
     23e:	e4 e0       	ldi	r30, 0x04	; 4
     240:	0c 94 e4 0e 	jmp	0x1dc8	; 0x1dc8 <__epilogue_restores__+0x1c>

00000244 <vfprintf>:
     244:	ab e0       	ldi	r26, 0x0B	; 11
     246:	b0 e0       	ldi	r27, 0x00	; 0
     248:	e8 e2       	ldi	r30, 0x28	; 40
     24a:	f1 e0       	ldi	r31, 0x01	; 1
     24c:	0c 94 ba 0e 	jmp	0x1d74	; 0x1d74 <__prologue_saves__>
     250:	3c 01       	movw	r6, r24
     252:	2b 01       	movw	r4, r22
     254:	5a 01       	movw	r10, r20
     256:	fc 01       	movw	r30, r24
     258:	17 82       	std	Z+7, r1	; 0x07
     25a:	16 82       	std	Z+6, r1	; 0x06
     25c:	83 81       	ldd	r24, Z+3	; 0x03
     25e:	81 fd       	sbrc	r24, 1
     260:	03 c0       	rjmp	.+6      	; 0x268 <vfprintf+0x24>
     262:	6f ef       	ldi	r22, 0xFF	; 255
     264:	7f ef       	ldi	r23, 0xFF	; 255
     266:	b9 c1       	rjmp	.+882    	; 0x5da <vfprintf+0x396>
     268:	9a e0       	ldi	r25, 0x0A	; 10
     26a:	89 2e       	mov	r8, r25
     26c:	1e 01       	movw	r2, r28
     26e:	08 94       	sec
     270:	21 1c       	adc	r2, r1
     272:	31 1c       	adc	r3, r1
     274:	f3 01       	movw	r30, r6
     276:	23 81       	ldd	r18, Z+3	; 0x03
     278:	f2 01       	movw	r30, r4
     27a:	23 fd       	sbrc	r18, 3
     27c:	85 91       	lpm	r24, Z+
     27e:	23 ff       	sbrs	r18, 3
     280:	81 91       	ld	r24, Z+
     282:	2f 01       	movw	r4, r30
     284:	88 23       	and	r24, r24
     286:	09 f4       	brne	.+2      	; 0x28a <vfprintf+0x46>
     288:	a5 c1       	rjmp	.+842    	; 0x5d4 <vfprintf+0x390>
     28a:	85 32       	cpi	r24, 0x25	; 37
     28c:	39 f4       	brne	.+14     	; 0x29c <vfprintf+0x58>
     28e:	23 fd       	sbrc	r18, 3
     290:	85 91       	lpm	r24, Z+
     292:	23 ff       	sbrs	r18, 3
     294:	81 91       	ld	r24, Z+
     296:	2f 01       	movw	r4, r30
     298:	85 32       	cpi	r24, 0x25	; 37
     29a:	21 f4       	brne	.+8      	; 0x2a4 <vfprintf+0x60>
     29c:	90 e0       	ldi	r25, 0x00	; 0
     29e:	b3 01       	movw	r22, r6
     2a0:	b7 d1       	rcall	.+878    	; 0x610 <fputc>
     2a2:	e8 cf       	rjmp	.-48     	; 0x274 <vfprintf+0x30>
     2a4:	98 2f       	mov	r25, r24
     2a6:	ff 24       	eor	r15, r15
     2a8:	ee 24       	eor	r14, r14
     2aa:	99 24       	eor	r9, r9
     2ac:	ff e1       	ldi	r31, 0x1F	; 31
     2ae:	ff 15       	cp	r31, r15
     2b0:	d0 f0       	brcs	.+52     	; 0x2e6 <vfprintf+0xa2>
     2b2:	9b 32       	cpi	r25, 0x2B	; 43
     2b4:	69 f0       	breq	.+26     	; 0x2d0 <vfprintf+0x8c>
     2b6:	9c 32       	cpi	r25, 0x2C	; 44
     2b8:	28 f4       	brcc	.+10     	; 0x2c4 <vfprintf+0x80>
     2ba:	90 32       	cpi	r25, 0x20	; 32
     2bc:	59 f0       	breq	.+22     	; 0x2d4 <vfprintf+0x90>
     2be:	93 32       	cpi	r25, 0x23	; 35
     2c0:	91 f4       	brne	.+36     	; 0x2e6 <vfprintf+0xa2>
     2c2:	0e c0       	rjmp	.+28     	; 0x2e0 <vfprintf+0x9c>
     2c4:	9d 32       	cpi	r25, 0x2D	; 45
     2c6:	49 f0       	breq	.+18     	; 0x2da <vfprintf+0x96>
     2c8:	90 33       	cpi	r25, 0x30	; 48
     2ca:	69 f4       	brne	.+26     	; 0x2e6 <vfprintf+0xa2>
     2cc:	41 e0       	ldi	r20, 0x01	; 1
     2ce:	24 c0       	rjmp	.+72     	; 0x318 <vfprintf+0xd4>
     2d0:	52 e0       	ldi	r21, 0x02	; 2
     2d2:	f5 2a       	or	r15, r21
     2d4:	84 e0       	ldi	r24, 0x04	; 4
     2d6:	f8 2a       	or	r15, r24
     2d8:	28 c0       	rjmp	.+80     	; 0x32a <vfprintf+0xe6>
     2da:	98 e0       	ldi	r25, 0x08	; 8
     2dc:	f9 2a       	or	r15, r25
     2de:	25 c0       	rjmp	.+74     	; 0x32a <vfprintf+0xe6>
     2e0:	e0 e1       	ldi	r30, 0x10	; 16
     2e2:	fe 2a       	or	r15, r30
     2e4:	22 c0       	rjmp	.+68     	; 0x32a <vfprintf+0xe6>
     2e6:	f7 fc       	sbrc	r15, 7
     2e8:	29 c0       	rjmp	.+82     	; 0x33c <vfprintf+0xf8>
     2ea:	89 2f       	mov	r24, r25
     2ec:	80 53       	subi	r24, 0x30	; 48
     2ee:	8a 30       	cpi	r24, 0x0A	; 10
     2f0:	70 f4       	brcc	.+28     	; 0x30e <vfprintf+0xca>
     2f2:	f6 fe       	sbrs	r15, 6
     2f4:	05 c0       	rjmp	.+10     	; 0x300 <vfprintf+0xbc>
     2f6:	98 9c       	mul	r9, r8
     2f8:	90 2c       	mov	r9, r0
     2fa:	11 24       	eor	r1, r1
     2fc:	98 0e       	add	r9, r24
     2fe:	15 c0       	rjmp	.+42     	; 0x32a <vfprintf+0xe6>
     300:	e8 9c       	mul	r14, r8
     302:	e0 2c       	mov	r14, r0
     304:	11 24       	eor	r1, r1
     306:	e8 0e       	add	r14, r24
     308:	f0 e2       	ldi	r31, 0x20	; 32
     30a:	ff 2a       	or	r15, r31
     30c:	0e c0       	rjmp	.+28     	; 0x32a <vfprintf+0xe6>
     30e:	9e 32       	cpi	r25, 0x2E	; 46
     310:	29 f4       	brne	.+10     	; 0x31c <vfprintf+0xd8>
     312:	f6 fc       	sbrc	r15, 6
     314:	5f c1       	rjmp	.+702    	; 0x5d4 <vfprintf+0x390>
     316:	40 e4       	ldi	r20, 0x40	; 64
     318:	f4 2a       	or	r15, r20
     31a:	07 c0       	rjmp	.+14     	; 0x32a <vfprintf+0xe6>
     31c:	9c 36       	cpi	r25, 0x6C	; 108
     31e:	19 f4       	brne	.+6      	; 0x326 <vfprintf+0xe2>
     320:	50 e8       	ldi	r21, 0x80	; 128
     322:	f5 2a       	or	r15, r21
     324:	02 c0       	rjmp	.+4      	; 0x32a <vfprintf+0xe6>
     326:	98 36       	cpi	r25, 0x68	; 104
     328:	49 f4       	brne	.+18     	; 0x33c <vfprintf+0xf8>
     32a:	f2 01       	movw	r30, r4
     32c:	23 fd       	sbrc	r18, 3
     32e:	95 91       	lpm	r25, Z+
     330:	23 ff       	sbrs	r18, 3
     332:	91 91       	ld	r25, Z+
     334:	2f 01       	movw	r4, r30
     336:	99 23       	and	r25, r25
     338:	09 f0       	breq	.+2      	; 0x33c <vfprintf+0xf8>
     33a:	b8 cf       	rjmp	.-144    	; 0x2ac <vfprintf+0x68>
     33c:	89 2f       	mov	r24, r25
     33e:	85 54       	subi	r24, 0x45	; 69
     340:	83 30       	cpi	r24, 0x03	; 3
     342:	18 f0       	brcs	.+6      	; 0x34a <vfprintf+0x106>
     344:	80 52       	subi	r24, 0x20	; 32
     346:	83 30       	cpi	r24, 0x03	; 3
     348:	38 f4       	brcc	.+14     	; 0x358 <vfprintf+0x114>
     34a:	44 e0       	ldi	r20, 0x04	; 4
     34c:	50 e0       	ldi	r21, 0x00	; 0
     34e:	a4 0e       	add	r10, r20
     350:	b5 1e       	adc	r11, r21
     352:	5f e3       	ldi	r21, 0x3F	; 63
     354:	59 83       	std	Y+1, r21	; 0x01
     356:	0f c0       	rjmp	.+30     	; 0x376 <vfprintf+0x132>
     358:	93 36       	cpi	r25, 0x63	; 99
     35a:	31 f0       	breq	.+12     	; 0x368 <vfprintf+0x124>
     35c:	93 37       	cpi	r25, 0x73	; 115
     35e:	79 f0       	breq	.+30     	; 0x37e <vfprintf+0x13a>
     360:	93 35       	cpi	r25, 0x53	; 83
     362:	09 f0       	breq	.+2      	; 0x366 <vfprintf+0x122>
     364:	52 c0       	rjmp	.+164    	; 0x40a <vfprintf+0x1c6>
     366:	1f c0       	rjmp	.+62     	; 0x3a6 <vfprintf+0x162>
     368:	f5 01       	movw	r30, r10
     36a:	80 81       	ld	r24, Z
     36c:	89 83       	std	Y+1, r24	; 0x01
     36e:	42 e0       	ldi	r20, 0x02	; 2
     370:	50 e0       	ldi	r21, 0x00	; 0
     372:	a4 0e       	add	r10, r20
     374:	b5 1e       	adc	r11, r21
     376:	61 01       	movw	r12, r2
     378:	01 e0       	ldi	r16, 0x01	; 1
     37a:	10 e0       	ldi	r17, 0x00	; 0
     37c:	11 c0       	rjmp	.+34     	; 0x3a0 <vfprintf+0x15c>
     37e:	f5 01       	movw	r30, r10
     380:	c0 80       	ld	r12, Z
     382:	d1 80       	ldd	r13, Z+1	; 0x01
     384:	f6 fc       	sbrc	r15, 6
     386:	03 c0       	rjmp	.+6      	; 0x38e <vfprintf+0x14a>
     388:	6f ef       	ldi	r22, 0xFF	; 255
     38a:	7f ef       	ldi	r23, 0xFF	; 255
     38c:	02 c0       	rjmp	.+4      	; 0x392 <vfprintf+0x14e>
     38e:	69 2d       	mov	r22, r9
     390:	70 e0       	ldi	r23, 0x00	; 0
     392:	42 e0       	ldi	r20, 0x02	; 2
     394:	50 e0       	ldi	r21, 0x00	; 0
     396:	a4 0e       	add	r10, r20
     398:	b5 1e       	adc	r11, r21
     39a:	c6 01       	movw	r24, r12
     39c:	2e d1       	rcall	.+604    	; 0x5fa <strnlen>
     39e:	8c 01       	movw	r16, r24
     3a0:	5f e7       	ldi	r21, 0x7F	; 127
     3a2:	f5 22       	and	r15, r21
     3a4:	13 c0       	rjmp	.+38     	; 0x3cc <vfprintf+0x188>
     3a6:	f5 01       	movw	r30, r10
     3a8:	c0 80       	ld	r12, Z
     3aa:	d1 80       	ldd	r13, Z+1	; 0x01
     3ac:	f6 fc       	sbrc	r15, 6
     3ae:	03 c0       	rjmp	.+6      	; 0x3b6 <vfprintf+0x172>
     3b0:	6f ef       	ldi	r22, 0xFF	; 255
     3b2:	7f ef       	ldi	r23, 0xFF	; 255
     3b4:	02 c0       	rjmp	.+4      	; 0x3ba <vfprintf+0x176>
     3b6:	69 2d       	mov	r22, r9
     3b8:	70 e0       	ldi	r23, 0x00	; 0
     3ba:	42 e0       	ldi	r20, 0x02	; 2
     3bc:	50 e0       	ldi	r21, 0x00	; 0
     3be:	a4 0e       	add	r10, r20
     3c0:	b5 1e       	adc	r11, r21
     3c2:	c6 01       	movw	r24, r12
     3c4:	0f d1       	rcall	.+542    	; 0x5e4 <strnlen_P>
     3c6:	8c 01       	movw	r16, r24
     3c8:	50 e8       	ldi	r21, 0x80	; 128
     3ca:	f5 2a       	or	r15, r21
     3cc:	f3 fe       	sbrs	r15, 3
     3ce:	06 c0       	rjmp	.+12     	; 0x3dc <vfprintf+0x198>
     3d0:	18 c0       	rjmp	.+48     	; 0x402 <vfprintf+0x1be>
     3d2:	80 e2       	ldi	r24, 0x20	; 32
     3d4:	90 e0       	ldi	r25, 0x00	; 0
     3d6:	b3 01       	movw	r22, r6
     3d8:	1b d1       	rcall	.+566    	; 0x610 <fputc>
     3da:	ea 94       	dec	r14
     3dc:	8e 2d       	mov	r24, r14
     3de:	90 e0       	ldi	r25, 0x00	; 0
     3e0:	08 17       	cp	r16, r24
     3e2:	19 07       	cpc	r17, r25
     3e4:	b0 f3       	brcs	.-20     	; 0x3d2 <vfprintf+0x18e>
     3e6:	0d c0       	rjmp	.+26     	; 0x402 <vfprintf+0x1be>
     3e8:	f6 01       	movw	r30, r12
     3ea:	f7 fc       	sbrc	r15, 7
     3ec:	85 91       	lpm	r24, Z+
     3ee:	f7 fe       	sbrs	r15, 7
     3f0:	81 91       	ld	r24, Z+
     3f2:	6f 01       	movw	r12, r30
     3f4:	90 e0       	ldi	r25, 0x00	; 0
     3f6:	b3 01       	movw	r22, r6
     3f8:	0b d1       	rcall	.+534    	; 0x610 <fputc>
     3fa:	e1 10       	cpse	r14, r1
     3fc:	ea 94       	dec	r14
     3fe:	01 50       	subi	r16, 0x01	; 1
     400:	10 40       	sbci	r17, 0x00	; 0
     402:	01 15       	cp	r16, r1
     404:	11 05       	cpc	r17, r1
     406:	81 f7       	brne	.-32     	; 0x3e8 <vfprintf+0x1a4>
     408:	e2 c0       	rjmp	.+452    	; 0x5ce <vfprintf+0x38a>
     40a:	94 36       	cpi	r25, 0x64	; 100
     40c:	11 f0       	breq	.+4      	; 0x412 <vfprintf+0x1ce>
     40e:	99 36       	cpi	r25, 0x69	; 105
     410:	61 f5       	brne	.+88     	; 0x46a <vfprintf+0x226>
     412:	f7 fe       	sbrs	r15, 7
     414:	08 c0       	rjmp	.+16     	; 0x426 <vfprintf+0x1e2>
     416:	f5 01       	movw	r30, r10
     418:	20 81       	ld	r18, Z
     41a:	31 81       	ldd	r19, Z+1	; 0x01
     41c:	42 81       	ldd	r20, Z+2	; 0x02
     41e:	53 81       	ldd	r21, Z+3	; 0x03
     420:	84 e0       	ldi	r24, 0x04	; 4
     422:	90 e0       	ldi	r25, 0x00	; 0
     424:	0a c0       	rjmp	.+20     	; 0x43a <vfprintf+0x1f6>
     426:	f5 01       	movw	r30, r10
     428:	80 81       	ld	r24, Z
     42a:	91 81       	ldd	r25, Z+1	; 0x01
     42c:	9c 01       	movw	r18, r24
     42e:	44 27       	eor	r20, r20
     430:	37 fd       	sbrc	r19, 7
     432:	40 95       	com	r20
     434:	54 2f       	mov	r21, r20
     436:	82 e0       	ldi	r24, 0x02	; 2
     438:	90 e0       	ldi	r25, 0x00	; 0
     43a:	a8 0e       	add	r10, r24
     43c:	b9 1e       	adc	r11, r25
     43e:	9f e6       	ldi	r25, 0x6F	; 111
     440:	f9 22       	and	r15, r25
     442:	57 ff       	sbrs	r21, 7
     444:	09 c0       	rjmp	.+18     	; 0x458 <vfprintf+0x214>
     446:	50 95       	com	r21
     448:	40 95       	com	r20
     44a:	30 95       	com	r19
     44c:	21 95       	neg	r18
     44e:	3f 4f       	sbci	r19, 0xFF	; 255
     450:	4f 4f       	sbci	r20, 0xFF	; 255
     452:	5f 4f       	sbci	r21, 0xFF	; 255
     454:	e0 e8       	ldi	r30, 0x80	; 128
     456:	fe 2a       	or	r15, r30
     458:	ca 01       	movw	r24, r20
     45a:	b9 01       	movw	r22, r18
     45c:	a1 01       	movw	r20, r2
     45e:	2a e0       	ldi	r18, 0x0A	; 10
     460:	30 e0       	ldi	r19, 0x00	; 0
     462:	02 d1       	rcall	.+516    	; 0x668 <__ultoa_invert>
     464:	d8 2e       	mov	r13, r24
     466:	d2 18       	sub	r13, r2
     468:	3f c0       	rjmp	.+126    	; 0x4e8 <vfprintf+0x2a4>
     46a:	95 37       	cpi	r25, 0x75	; 117
     46c:	29 f4       	brne	.+10     	; 0x478 <vfprintf+0x234>
     46e:	1f 2d       	mov	r17, r15
     470:	1f 7e       	andi	r17, 0xEF	; 239
     472:	2a e0       	ldi	r18, 0x0A	; 10
     474:	30 e0       	ldi	r19, 0x00	; 0
     476:	1d c0       	rjmp	.+58     	; 0x4b2 <vfprintf+0x26e>
     478:	1f 2d       	mov	r17, r15
     47a:	19 7f       	andi	r17, 0xF9	; 249
     47c:	9f 36       	cpi	r25, 0x6F	; 111
     47e:	61 f0       	breq	.+24     	; 0x498 <vfprintf+0x254>
     480:	90 37       	cpi	r25, 0x70	; 112
     482:	20 f4       	brcc	.+8      	; 0x48c <vfprintf+0x248>
     484:	98 35       	cpi	r25, 0x58	; 88
     486:	09 f0       	breq	.+2      	; 0x48a <vfprintf+0x246>
     488:	a5 c0       	rjmp	.+330    	; 0x5d4 <vfprintf+0x390>
     48a:	0f c0       	rjmp	.+30     	; 0x4aa <vfprintf+0x266>
     48c:	90 37       	cpi	r25, 0x70	; 112
     48e:	39 f0       	breq	.+14     	; 0x49e <vfprintf+0x25a>
     490:	98 37       	cpi	r25, 0x78	; 120
     492:	09 f0       	breq	.+2      	; 0x496 <vfprintf+0x252>
     494:	9f c0       	rjmp	.+318    	; 0x5d4 <vfprintf+0x390>
     496:	04 c0       	rjmp	.+8      	; 0x4a0 <vfprintf+0x25c>
     498:	28 e0       	ldi	r18, 0x08	; 8
     49a:	30 e0       	ldi	r19, 0x00	; 0
     49c:	0a c0       	rjmp	.+20     	; 0x4b2 <vfprintf+0x26e>
     49e:	10 61       	ori	r17, 0x10	; 16
     4a0:	14 fd       	sbrc	r17, 4
     4a2:	14 60       	ori	r17, 0x04	; 4
     4a4:	20 e1       	ldi	r18, 0x10	; 16
     4a6:	30 e0       	ldi	r19, 0x00	; 0
     4a8:	04 c0       	rjmp	.+8      	; 0x4b2 <vfprintf+0x26e>
     4aa:	14 fd       	sbrc	r17, 4
     4ac:	16 60       	ori	r17, 0x06	; 6
     4ae:	20 e1       	ldi	r18, 0x10	; 16
     4b0:	32 e0       	ldi	r19, 0x02	; 2
     4b2:	17 ff       	sbrs	r17, 7
     4b4:	08 c0       	rjmp	.+16     	; 0x4c6 <vfprintf+0x282>
     4b6:	f5 01       	movw	r30, r10
     4b8:	60 81       	ld	r22, Z
     4ba:	71 81       	ldd	r23, Z+1	; 0x01
     4bc:	82 81       	ldd	r24, Z+2	; 0x02
     4be:	93 81       	ldd	r25, Z+3	; 0x03
     4c0:	44 e0       	ldi	r20, 0x04	; 4
     4c2:	50 e0       	ldi	r21, 0x00	; 0
     4c4:	08 c0       	rjmp	.+16     	; 0x4d6 <vfprintf+0x292>
     4c6:	f5 01       	movw	r30, r10
     4c8:	80 81       	ld	r24, Z
     4ca:	91 81       	ldd	r25, Z+1	; 0x01
     4cc:	bc 01       	movw	r22, r24
     4ce:	80 e0       	ldi	r24, 0x00	; 0
     4d0:	90 e0       	ldi	r25, 0x00	; 0
     4d2:	42 e0       	ldi	r20, 0x02	; 2
     4d4:	50 e0       	ldi	r21, 0x00	; 0
     4d6:	a4 0e       	add	r10, r20
     4d8:	b5 1e       	adc	r11, r21
     4da:	a1 01       	movw	r20, r2
     4dc:	c5 d0       	rcall	.+394    	; 0x668 <__ultoa_invert>
     4de:	d8 2e       	mov	r13, r24
     4e0:	d2 18       	sub	r13, r2
     4e2:	8f e7       	ldi	r24, 0x7F	; 127
     4e4:	f8 2e       	mov	r15, r24
     4e6:	f1 22       	and	r15, r17
     4e8:	f6 fe       	sbrs	r15, 6
     4ea:	0b c0       	rjmp	.+22     	; 0x502 <vfprintf+0x2be>
     4ec:	5e ef       	ldi	r21, 0xFE	; 254
     4ee:	f5 22       	and	r15, r21
     4f0:	d9 14       	cp	r13, r9
     4f2:	38 f4       	brcc	.+14     	; 0x502 <vfprintf+0x2be>
     4f4:	f4 fe       	sbrs	r15, 4
     4f6:	07 c0       	rjmp	.+14     	; 0x506 <vfprintf+0x2c2>
     4f8:	f2 fc       	sbrc	r15, 2
     4fa:	05 c0       	rjmp	.+10     	; 0x506 <vfprintf+0x2c2>
     4fc:	8f ee       	ldi	r24, 0xEF	; 239
     4fe:	f8 22       	and	r15, r24
     500:	02 c0       	rjmp	.+4      	; 0x506 <vfprintf+0x2c2>
     502:	1d 2d       	mov	r17, r13
     504:	01 c0       	rjmp	.+2      	; 0x508 <vfprintf+0x2c4>
     506:	19 2d       	mov	r17, r9
     508:	f4 fe       	sbrs	r15, 4
     50a:	0d c0       	rjmp	.+26     	; 0x526 <vfprintf+0x2e2>
     50c:	fe 01       	movw	r30, r28
     50e:	ed 0d       	add	r30, r13
     510:	f1 1d       	adc	r31, r1
     512:	80 81       	ld	r24, Z
     514:	80 33       	cpi	r24, 0x30	; 48
     516:	19 f4       	brne	.+6      	; 0x51e <vfprintf+0x2da>
     518:	99 ee       	ldi	r25, 0xE9	; 233
     51a:	f9 22       	and	r15, r25
     51c:	08 c0       	rjmp	.+16     	; 0x52e <vfprintf+0x2ea>
     51e:	1f 5f       	subi	r17, 0xFF	; 255
     520:	f2 fe       	sbrs	r15, 2
     522:	05 c0       	rjmp	.+10     	; 0x52e <vfprintf+0x2ea>
     524:	03 c0       	rjmp	.+6      	; 0x52c <vfprintf+0x2e8>
     526:	8f 2d       	mov	r24, r15
     528:	86 78       	andi	r24, 0x86	; 134
     52a:	09 f0       	breq	.+2      	; 0x52e <vfprintf+0x2ea>
     52c:	1f 5f       	subi	r17, 0xFF	; 255
     52e:	0f 2d       	mov	r16, r15
     530:	f3 fc       	sbrc	r15, 3
     532:	13 c0       	rjmp	.+38     	; 0x55a <vfprintf+0x316>
     534:	f0 fe       	sbrs	r15, 0
     536:	0e c0       	rjmp	.+28     	; 0x554 <vfprintf+0x310>
     538:	1e 15       	cp	r17, r14
     53a:	10 f0       	brcs	.+4      	; 0x540 <vfprintf+0x2fc>
     53c:	9d 2c       	mov	r9, r13
     53e:	0a c0       	rjmp	.+20     	; 0x554 <vfprintf+0x310>
     540:	9d 2c       	mov	r9, r13
     542:	9e 0c       	add	r9, r14
     544:	91 1a       	sub	r9, r17
     546:	1e 2d       	mov	r17, r14
     548:	05 c0       	rjmp	.+10     	; 0x554 <vfprintf+0x310>
     54a:	80 e2       	ldi	r24, 0x20	; 32
     54c:	90 e0       	ldi	r25, 0x00	; 0
     54e:	b3 01       	movw	r22, r6
     550:	5f d0       	rcall	.+190    	; 0x610 <fputc>
     552:	1f 5f       	subi	r17, 0xFF	; 255
     554:	1e 15       	cp	r17, r14
     556:	c8 f3       	brcs	.-14     	; 0x54a <vfprintf+0x306>
     558:	04 c0       	rjmp	.+8      	; 0x562 <vfprintf+0x31e>
     55a:	1e 15       	cp	r17, r14
     55c:	10 f4       	brcc	.+4      	; 0x562 <vfprintf+0x31e>
     55e:	e1 1a       	sub	r14, r17
     560:	01 c0       	rjmp	.+2      	; 0x564 <vfprintf+0x320>
     562:	ee 24       	eor	r14, r14
     564:	04 ff       	sbrs	r16, 4
     566:	0e c0       	rjmp	.+28     	; 0x584 <vfprintf+0x340>
     568:	80 e3       	ldi	r24, 0x30	; 48
     56a:	90 e0       	ldi	r25, 0x00	; 0
     56c:	b3 01       	movw	r22, r6
     56e:	50 d0       	rcall	.+160    	; 0x610 <fputc>
     570:	02 ff       	sbrs	r16, 2
     572:	1b c0       	rjmp	.+54     	; 0x5aa <vfprintf+0x366>
     574:	01 fd       	sbrc	r16, 1
     576:	03 c0       	rjmp	.+6      	; 0x57e <vfprintf+0x33a>
     578:	88 e7       	ldi	r24, 0x78	; 120
     57a:	90 e0       	ldi	r25, 0x00	; 0
     57c:	0e c0       	rjmp	.+28     	; 0x59a <vfprintf+0x356>
     57e:	88 e5       	ldi	r24, 0x58	; 88
     580:	90 e0       	ldi	r25, 0x00	; 0
     582:	0b c0       	rjmp	.+22     	; 0x59a <vfprintf+0x356>
     584:	80 2f       	mov	r24, r16
     586:	86 78       	andi	r24, 0x86	; 134
     588:	81 f0       	breq	.+32     	; 0x5aa <vfprintf+0x366>
     58a:	01 ff       	sbrs	r16, 1
     58c:	02 c0       	rjmp	.+4      	; 0x592 <vfprintf+0x34e>
     58e:	8b e2       	ldi	r24, 0x2B	; 43
     590:	01 c0       	rjmp	.+2      	; 0x594 <vfprintf+0x350>
     592:	80 e2       	ldi	r24, 0x20	; 32
     594:	f7 fc       	sbrc	r15, 7
     596:	8d e2       	ldi	r24, 0x2D	; 45
     598:	90 e0       	ldi	r25, 0x00	; 0
     59a:	b3 01       	movw	r22, r6
     59c:	39 d0       	rcall	.+114    	; 0x610 <fputc>
     59e:	05 c0       	rjmp	.+10     	; 0x5aa <vfprintf+0x366>
     5a0:	80 e3       	ldi	r24, 0x30	; 48
     5a2:	90 e0       	ldi	r25, 0x00	; 0
     5a4:	b3 01       	movw	r22, r6
     5a6:	34 d0       	rcall	.+104    	; 0x610 <fputc>
     5a8:	9a 94       	dec	r9
     5aa:	d9 14       	cp	r13, r9
     5ac:	c8 f3       	brcs	.-14     	; 0x5a0 <vfprintf+0x35c>
     5ae:	da 94       	dec	r13
     5b0:	f1 01       	movw	r30, r2
     5b2:	ed 0d       	add	r30, r13
     5b4:	f1 1d       	adc	r31, r1
     5b6:	80 81       	ld	r24, Z
     5b8:	90 e0       	ldi	r25, 0x00	; 0
     5ba:	b3 01       	movw	r22, r6
     5bc:	29 d0       	rcall	.+82     	; 0x610 <fputc>
     5be:	dd 20       	and	r13, r13
     5c0:	b1 f7       	brne	.-20     	; 0x5ae <vfprintf+0x36a>
     5c2:	05 c0       	rjmp	.+10     	; 0x5ce <vfprintf+0x38a>
     5c4:	80 e2       	ldi	r24, 0x20	; 32
     5c6:	90 e0       	ldi	r25, 0x00	; 0
     5c8:	b3 01       	movw	r22, r6
     5ca:	22 d0       	rcall	.+68     	; 0x610 <fputc>
     5cc:	ea 94       	dec	r14
     5ce:	ee 20       	and	r14, r14
     5d0:	c9 f7       	brne	.-14     	; 0x5c4 <vfprintf+0x380>
     5d2:	50 ce       	rjmp	.-864    	; 0x274 <vfprintf+0x30>
     5d4:	f3 01       	movw	r30, r6
     5d6:	66 81       	ldd	r22, Z+6	; 0x06
     5d8:	77 81       	ldd	r23, Z+7	; 0x07
     5da:	cb 01       	movw	r24, r22
     5dc:	2b 96       	adiw	r28, 0x0b	; 11
     5de:	e2 e1       	ldi	r30, 0x12	; 18
     5e0:	0c 94 d6 0e 	jmp	0x1dac	; 0x1dac <__epilogue_restores__>

000005e4 <strnlen_P>:
     5e4:	fc 01       	movw	r30, r24
     5e6:	05 90       	lpm	r0, Z+
     5e8:	61 50       	subi	r22, 0x01	; 1
     5ea:	70 40       	sbci	r23, 0x00	; 0
     5ec:	01 10       	cpse	r0, r1
     5ee:	d8 f7       	brcc	.-10     	; 0x5e6 <strnlen_P+0x2>
     5f0:	80 95       	com	r24
     5f2:	90 95       	com	r25
     5f4:	8e 0f       	add	r24, r30
     5f6:	9f 1f       	adc	r25, r31
     5f8:	08 95       	ret

000005fa <strnlen>:
     5fa:	fc 01       	movw	r30, r24
     5fc:	61 50       	subi	r22, 0x01	; 1
     5fe:	70 40       	sbci	r23, 0x00	; 0
     600:	01 90       	ld	r0, Z+
     602:	01 10       	cpse	r0, r1
     604:	d8 f7       	brcc	.-10     	; 0x5fc <strnlen+0x2>
     606:	80 95       	com	r24
     608:	90 95       	com	r25
     60a:	8e 0f       	add	r24, r30
     60c:	9f 1f       	adc	r25, r31
     60e:	08 95       	ret

00000610 <fputc>:
     610:	0f 93       	push	r16
     612:	1f 93       	push	r17
     614:	cf 93       	push	r28
     616:	df 93       	push	r29
     618:	8c 01       	movw	r16, r24
     61a:	eb 01       	movw	r28, r22
     61c:	8b 81       	ldd	r24, Y+3	; 0x03
     61e:	81 ff       	sbrs	r24, 1
     620:	1b c0       	rjmp	.+54     	; 0x658 <fputc+0x48>
     622:	82 ff       	sbrs	r24, 2
     624:	0d c0       	rjmp	.+26     	; 0x640 <fputc+0x30>
     626:	2e 81       	ldd	r18, Y+6	; 0x06
     628:	3f 81       	ldd	r19, Y+7	; 0x07
     62a:	8c 81       	ldd	r24, Y+4	; 0x04
     62c:	9d 81       	ldd	r25, Y+5	; 0x05
     62e:	28 17       	cp	r18, r24
     630:	39 07       	cpc	r19, r25
     632:	64 f4       	brge	.+24     	; 0x64c <fputc+0x3c>
     634:	e8 81       	ld	r30, Y
     636:	f9 81       	ldd	r31, Y+1	; 0x01
     638:	01 93       	st	Z+, r16
     63a:	f9 83       	std	Y+1, r31	; 0x01
     63c:	e8 83       	st	Y, r30
     63e:	06 c0       	rjmp	.+12     	; 0x64c <fputc+0x3c>
     640:	e8 85       	ldd	r30, Y+8	; 0x08
     642:	f9 85       	ldd	r31, Y+9	; 0x09
     644:	80 2f       	mov	r24, r16
     646:	19 95       	eicall
     648:	89 2b       	or	r24, r25
     64a:	31 f4       	brne	.+12     	; 0x658 <fputc+0x48>
     64c:	8e 81       	ldd	r24, Y+6	; 0x06
     64e:	9f 81       	ldd	r25, Y+7	; 0x07
     650:	01 96       	adiw	r24, 0x01	; 1
     652:	9f 83       	std	Y+7, r25	; 0x07
     654:	8e 83       	std	Y+6, r24	; 0x06
     656:	02 c0       	rjmp	.+4      	; 0x65c <fputc+0x4c>
     658:	0f ef       	ldi	r16, 0xFF	; 255
     65a:	1f ef       	ldi	r17, 0xFF	; 255
     65c:	c8 01       	movw	r24, r16
     65e:	df 91       	pop	r29
     660:	cf 91       	pop	r28
     662:	1f 91       	pop	r17
     664:	0f 91       	pop	r16
     666:	08 95       	ret

00000668 <__ultoa_invert>:
     668:	fa 01       	movw	r30, r20
     66a:	aa 27       	eor	r26, r26
     66c:	28 30       	cpi	r18, 0x08	; 8
     66e:	51 f1       	breq	.+84     	; 0x6c4 <__ultoa_invert+0x5c>
     670:	20 31       	cpi	r18, 0x10	; 16
     672:	81 f1       	breq	.+96     	; 0x6d4 <__ultoa_invert+0x6c>
     674:	e8 94       	clt
     676:	6f 93       	push	r22
     678:	6e 7f       	andi	r22, 0xFE	; 254
     67a:	6e 5f       	subi	r22, 0xFE	; 254
     67c:	7f 4f       	sbci	r23, 0xFF	; 255
     67e:	8f 4f       	sbci	r24, 0xFF	; 255
     680:	9f 4f       	sbci	r25, 0xFF	; 255
     682:	af 4f       	sbci	r26, 0xFF	; 255
     684:	b1 e0       	ldi	r27, 0x01	; 1
     686:	3e d0       	rcall	.+124    	; 0x704 <__ultoa_invert+0x9c>
     688:	b4 e0       	ldi	r27, 0x04	; 4
     68a:	3c d0       	rcall	.+120    	; 0x704 <__ultoa_invert+0x9c>
     68c:	67 0f       	add	r22, r23
     68e:	78 1f       	adc	r23, r24
     690:	89 1f       	adc	r24, r25
     692:	9a 1f       	adc	r25, r26
     694:	a1 1d       	adc	r26, r1
     696:	68 0f       	add	r22, r24
     698:	79 1f       	adc	r23, r25
     69a:	8a 1f       	adc	r24, r26
     69c:	91 1d       	adc	r25, r1
     69e:	a1 1d       	adc	r26, r1
     6a0:	6a 0f       	add	r22, r26
     6a2:	71 1d       	adc	r23, r1
     6a4:	81 1d       	adc	r24, r1
     6a6:	91 1d       	adc	r25, r1
     6a8:	a1 1d       	adc	r26, r1
     6aa:	20 d0       	rcall	.+64     	; 0x6ec <__ultoa_invert+0x84>
     6ac:	09 f4       	brne	.+2      	; 0x6b0 <__ultoa_invert+0x48>
     6ae:	68 94       	set
     6b0:	3f 91       	pop	r19
     6b2:	2a e0       	ldi	r18, 0x0A	; 10
     6b4:	26 9f       	mul	r18, r22
     6b6:	11 24       	eor	r1, r1
     6b8:	30 19       	sub	r19, r0
     6ba:	30 5d       	subi	r19, 0xD0	; 208
     6bc:	31 93       	st	Z+, r19
     6be:	de f6       	brtc	.-74     	; 0x676 <__ultoa_invert+0xe>
     6c0:	cf 01       	movw	r24, r30
     6c2:	08 95       	ret
     6c4:	46 2f       	mov	r20, r22
     6c6:	47 70       	andi	r20, 0x07	; 7
     6c8:	40 5d       	subi	r20, 0xD0	; 208
     6ca:	41 93       	st	Z+, r20
     6cc:	b3 e0       	ldi	r27, 0x03	; 3
     6ce:	0f d0       	rcall	.+30     	; 0x6ee <__ultoa_invert+0x86>
     6d0:	c9 f7       	brne	.-14     	; 0x6c4 <__ultoa_invert+0x5c>
     6d2:	f6 cf       	rjmp	.-20     	; 0x6c0 <__ultoa_invert+0x58>
     6d4:	46 2f       	mov	r20, r22
     6d6:	4f 70       	andi	r20, 0x0F	; 15
     6d8:	40 5d       	subi	r20, 0xD0	; 208
     6da:	4a 33       	cpi	r20, 0x3A	; 58
     6dc:	18 f0       	brcs	.+6      	; 0x6e4 <__ultoa_invert+0x7c>
     6de:	49 5d       	subi	r20, 0xD9	; 217
     6e0:	31 fd       	sbrc	r19, 1
     6e2:	40 52       	subi	r20, 0x20	; 32
     6e4:	41 93       	st	Z+, r20
     6e6:	02 d0       	rcall	.+4      	; 0x6ec <__ultoa_invert+0x84>
     6e8:	a9 f7       	brne	.-22     	; 0x6d4 <__ultoa_invert+0x6c>
     6ea:	ea cf       	rjmp	.-44     	; 0x6c0 <__ultoa_invert+0x58>
     6ec:	b4 e0       	ldi	r27, 0x04	; 4
     6ee:	a6 95       	lsr	r26
     6f0:	97 95       	ror	r25
     6f2:	87 95       	ror	r24
     6f4:	77 95       	ror	r23
     6f6:	67 95       	ror	r22
     6f8:	ba 95       	dec	r27
     6fa:	c9 f7       	brne	.-14     	; 0x6ee <__ultoa_invert+0x86>
     6fc:	00 97       	sbiw	r24, 0x00	; 0
     6fe:	61 05       	cpc	r22, r1
     700:	71 05       	cpc	r23, r1
     702:	08 95       	ret
     704:	9b 01       	movw	r18, r22
     706:	ac 01       	movw	r20, r24
     708:	0a 2e       	mov	r0, r26
     70a:	06 94       	lsr	r0
     70c:	57 95       	ror	r21
     70e:	47 95       	ror	r20
     710:	37 95       	ror	r19
     712:	27 95       	ror	r18
     714:	ba 95       	dec	r27
     716:	c9 f7       	brne	.-14     	; 0x70a <__ultoa_invert+0xa2>
     718:	62 0f       	add	r22, r18
     71a:	73 1f       	adc	r23, r19
     71c:	84 1f       	adc	r24, r20
     71e:	95 1f       	adc	r25, r21
     720:	a0 1d       	adc	r26, r0
     722:	08 95       	ret

00000724 <_ZN14COMMAND_PARSERC1EP5NVRAMP14PACKET_HANDLER>:
#define ENABLE	1
#define DISABLE 0

// --------------------------------------------------------------------
//! Sets up our non volatile nvram object, our command db.
COMMAND_PARSER::COMMAND_PARSER(NVRAM* nvram_object, PACKET_HANDLER* packet_decoder){
     724:	fc 01       	movw	r30, r24
			
	this->command_buffer = 0;
     726:	13 82       	std	Z+3, r1	; 0x03
     728:	12 82       	std	Z+2, r1	; 0x02
	this->nvram_object = nvram_object;
     72a:	71 87       	std	Z+9, r23	; 0x09
     72c:	60 87       	std	Z+8, r22	; 0x08
	this->packet_decoder = packet_decoder;
     72e:	55 83       	std	Z+5, r21	; 0x05
     730:	44 83       	std	Z+4, r20	; 0x04
}
     732:	08 95       	ret

00000734 <_ZN12main_defines5errorEv>:
		command_interpreter.send_cmd(USB_DEVICE_CMD, (void*)PAUSE_ROUTER);
		DEBUG_SERIAL.println("REBOOTING DEVICE.");
	#endif

	// We send a stop to the network
	error();
     734:	ff df       	rcall	.-2      	; 0x734 <_ZN12main_defines5errorEv>
     736:	ff cf       	rjmp	.-2      	; 0x736 <_ZN12main_defines5errorEv+0x2>

00000738 <_ZN12main_defines12memory_checkEv>:

	/**
	 * This does a memory check of the whole system, and checks
	 * to see how much free mem there is.
	 */
	word main_defines::memory_check(){
     738:	df 93       	push	r29
     73a:	cf 93       	push	r28
     73c:	0f 92       	push	r0
     73e:	0f 92       	push	r0
     740:	cd b7       	in	r28, 0x3d	; 61
     742:	de b7       	in	r29, 0x3e	; 62
        #ifdef DEBUG
			DEBUG_SERIAL.println("EXEC MEM CHECK");
     744:	8f e5       	ldi	r24, 0x5F	; 95
     746:	97 e0       	ldi	r25, 0x07	; 7
     748:	60 e0       	ldi	r22, 0x00	; 0
     74a:	72 e0       	ldi	r23, 0x02	; 2
     74c:	0e 94 26 0e 	call	0x1c4c	; 0x1c4c <_ZN5Print7printlnEPKc>
     750:	9e 01       	movw	r18, r28
     752:	26 5e       	subi	r18, 0xE6	; 230
     754:	37 40       	sbci	r19, 0x07	; 7
        #endif
		word freemem;
		freemem = ((word)&freemem) - ((word)&__bss_end);
		return freemem;
	}
     756:	c9 01       	movw	r24, r18
     758:	0f 90       	pop	r0
     75a:	0f 90       	pop	r0
     75c:	cf 91       	pop	r28
     75e:	df 91       	pop	r29
     760:	08 95       	ret

00000762 <_ZN14PACKET_HANDLERC1EPv>:
/**
 * This is the packet decoder, over written with a past handler_table
 * structure.
 * @param handler_table - packet_handler_t
 */
PACKET_HANDLER::PACKET_HANDLER(void* handler_table){
     762:	fc 01       	movw	r30, r24

	//! Assign the default variables.
	this->_phase 			= PACKET_WAIT_PHASE_1;
     764:	10 82       	st	Z, r1
	this->_handler_table 	= (packet_handler_t*) handler_table;
     766:	77 83       	std	Z+7, r23	; 0x07
     768:	66 83       	std	Z+6, r22	; 0x06

	//! Set to 0
	this->_data_expected 	= 0;
     76a:	12 82       	std	Z+2, r1	; 0x02
	this->_data_in 			= 0;
     76c:	11 82       	std	Z+1, r1	; 0x01
	this->_last_received 	= 0;
     76e:	12 8a       	std	Z+18, r1	; 0x12
     770:	13 8a       	std	Z+19, r1	; 0x13
     772:	14 8a       	std	Z+20, r1	; 0x14
     774:	15 8a       	std	Z+21, r1	; 0x15
	this->_packet_id 		= 0;
     776:	10 8a       	std	Z+16, r1	; 0x10
	this->_packet_ver 		= 0;
     778:	15 82       	std	Z+5, r1	; 0x05
	this->_sum_A			= 0;
     77a:	13 82       	std	Z+3, r1	; 0x03
	this->_sum_B 			= 0;
     77c:	14 82       	std	Z+4, r1	; 0x04
	this->_guard_bool		= false;
     77e:	11 8a       	std	Z+17, r1	; 0x11
}
     780:	08 95       	ret

00000782 <_ZN13PACKET_PARSERC1EP6SENSOR>:
#include "Packet_Parser.h"

// --------------------------------------------------------------------
//! Default constructor
PACKET_PARSER::PACKET_PARSER(SENSOR* db){
	this->db = db;
     782:	fc 01       	movw	r30, r24
     784:	75 83       	std	Z+5, r23	; 0x05
     786:	64 83       	std	Z+4, r22	; 0x04
}
     788:	08 95       	ret

0000078a <_ZN13PACKET_PARSER19_get_sensor_configsEv>:
	}
}

// --------------------------------------------------------------------
//! Gets the sensor configs
void PACKET_PARSER::_get_sensor_configs() {
     78a:	fc 01       	movw	r30, r24
	
	//! Set the sensor data type
	memcpy(&db[_header.sensor_id].sensor_config, &_configs.sensor_type, sizeof(_configs));
     78c:	85 85       	ldd	r24, Z+13	; 0x0d
     78e:	2b e0       	ldi	r18, 0x0B	; 11
     790:	82 9f       	mul	r24, r18
     792:	c0 01       	movw	r24, r0
     794:	11 24       	eor	r1, r1
     796:	a4 81       	ldd	r26, Z+4	; 0x04
     798:	b5 81       	ldd	r27, Z+5	; 0x05
     79a:	a8 0f       	add	r26, r24
     79c:	b9 1f       	adc	r27, r25
     79e:	12 96       	adiw	r26, 0x02	; 2
     7a0:	79 96       	adiw	r30, 0x19	; 25
     7a2:	83 e0       	ldi	r24, 0x03	; 3
     7a4:	01 90       	ld	r0, Z+
     7a6:	0d 92       	st	X+, r0
     7a8:	81 50       	subi	r24, 0x01	; 1
     7aa:	e1 f7       	brne	.-8      	; 0x7a4 <_ZN13PACKET_PARSER19_get_sensor_configsEv+0x1a>
}
     7ac:	08 95       	ret

000007ae <_ZN13PACKET_PARSER18_check_sensor_syncEv>:

// --------------------------------------------------------------------
//! Checks the sync signal from the sensor
void PACKET_PARSER::_check_sensor_sync(){
     7ae:	0f 93       	push	r16
     7b0:	1f 93       	push	r17
     7b2:	cf 93       	push	r28
     7b4:	df 93       	push	r29
     7b6:	ec 01       	movw	r28, r24
	
	//! Check the interrupt number
	if(_sync.interrupt_number != 
     7b8:	4d 85       	ldd	r20, Y+13	; 0x0d
     7ba:	8b e0       	ldi	r24, 0x0B	; 11
     7bc:	48 9f       	mul	r20, r24
     7be:	c0 01       	movw	r24, r0
     7c0:	11 24       	eor	r1, r1
     7c2:	ec 81       	ldd	r30, Y+4	; 0x04
     7c4:	fd 81       	ldd	r31, Y+5	; 0x05
     7c6:	e8 0f       	add	r30, r24
     7c8:	f9 1f       	adc	r31, r25
     7ca:	9e 8d       	ldd	r25, Y+30	; 0x1e
     7cc:	87 81       	ldd	r24, Z+7	; 0x07
     7ce:	98 17       	cp	r25, r24
     7d0:	81 f0       	breq	.+32     	; 0x7f2 <_ZN13PACKET_PARSER18_check_sensor_syncEv+0x44>
		#ifdef DEBUG_LEDs
			debug_api.set_leds(INFO_ERROR);
		#endif
		#ifdef DEBUG
			char* debug_info;
			sprintf(debug_info, "[SENSOR %d]: Interrupt issue.", _header.sensor_id);
     7d2:	00 d0       	rcall	.+0      	; 0x7d4 <_ZN13PACKET_PARSER18_check_sensor_syncEv+0x26>
     7d4:	00 d0       	rcall	.+0      	; 0x7d6 <_ZN13PACKET_PARSER18_check_sensor_syncEv+0x28>
     7d6:	ed b7       	in	r30, 0x3d	; 61
     7d8:	fe b7       	in	r31, 0x3e	; 62
     7da:	31 96       	adiw	r30, 0x01	; 1
     7dc:	00 e0       	ldi	r16, 0x00	; 0
     7de:	10 e0       	ldi	r17, 0x00	; 0
     7e0:	ad b7       	in	r26, 0x3d	; 61
     7e2:	be b7       	in	r27, 0x3e	; 62
     7e4:	12 96       	adiw	r26, 0x02	; 2
     7e6:	1c 93       	st	X, r17
     7e8:	0e 93       	st	-X, r16
     7ea:	11 97       	sbiw	r26, 0x01	; 1
     7ec:	8f e0       	ldi	r24, 0x0F	; 15
     7ee:	92 e0       	ldi	r25, 0x02	; 2
     7f0:	29 c0       	rjmp	.+82     	; 0x844 <_ZN13PACKET_PARSER18_check_sensor_syncEv+0x96>
		#endif
		goto error_label;
		}
	
	//! Check the priority
	if(_sync.priority != 
     7f2:	2f 8d       	ldd	r18, Y+31	; 0x1f
     7f4:	86 81       	ldd	r24, Z+6	; 0x06
     7f6:	28 17       	cp	r18, r24
     7f8:	81 f0       	breq	.+32     	; 0x81a <_ZN13PACKET_PARSER18_check_sensor_syncEv+0x6c>
		#ifdef DEBUG_LEDs
			debug_api.set_leds(INFO_ERROR);
		#endif
		#ifdef DEBUG
			char* debug_info;
			sprintf(debug_info, "[SENSOR %d]: Priority issue", _header.sensor_id);
     7fa:	00 d0       	rcall	.+0      	; 0x7fc <_ZN13PACKET_PARSER18_check_sensor_syncEv+0x4e>
     7fc:	00 d0       	rcall	.+0      	; 0x7fe <_ZN13PACKET_PARSER18_check_sensor_syncEv+0x50>
     7fe:	ed b7       	in	r30, 0x3d	; 61
     800:	fe b7       	in	r31, 0x3e	; 62
     802:	31 96       	adiw	r30, 0x01	; 1
     804:	00 e0       	ldi	r16, 0x00	; 0
     806:	10 e0       	ldi	r17, 0x00	; 0
     808:	ad b7       	in	r26, 0x3d	; 61
     80a:	be b7       	in	r27, 0x3e	; 62
     80c:	12 96       	adiw	r26, 0x02	; 2
     80e:	1c 93       	st	X, r17
     810:	0e 93       	st	-X, r16
     812:	11 97       	sbiw	r26, 0x01	; 1
     814:	8d e2       	ldi	r24, 0x2D	; 45
     816:	92 e0       	ldi	r25, 0x02	; 2
     818:	15 c0       	rjmp	.+42     	; 0x844 <_ZN13PACKET_PARSER18_check_sensor_syncEv+0x96>
		#endif
		goto error_label;
		}
		
	//! Check the sync time
	if(_sync.sync_time != 
     81a:	30 e0       	ldi	r19, 0x00	; 0
     81c:	8c 8d       	ldd	r24, Y+28	; 0x1c
     81e:	9d 8d       	ldd	r25, Y+29	; 0x1d
     820:	82 17       	cp	r24, r18
     822:	93 07       	cpc	r25, r19
     824:	09 f1       	breq	.+66     	; 0x868 <_ZN13PACKET_PARSER18_check_sensor_syncEv+0xba>
		#ifdef DEBUG_LEDs
			debug_api.set_leds(INFO_ERROR);
		#endif
		#ifdef DEBUG
			char* debug_info;
			sprintf(debug_info, "[SENSOR %d]: Sync. time issue", _header.sensor_id);
     826:	00 d0       	rcall	.+0      	; 0x828 <_ZN13PACKET_PARSER18_check_sensor_syncEv+0x7a>
     828:	00 d0       	rcall	.+0      	; 0x82a <_ZN13PACKET_PARSER18_check_sensor_syncEv+0x7c>
     82a:	ed b7       	in	r30, 0x3d	; 61
     82c:	fe b7       	in	r31, 0x3e	; 62
     82e:	31 96       	adiw	r30, 0x01	; 1
     830:	00 e0       	ldi	r16, 0x00	; 0
     832:	10 e0       	ldi	r17, 0x00	; 0
     834:	ad b7       	in	r26, 0x3d	; 61
     836:	be b7       	in	r27, 0x3e	; 62
     838:	12 96       	adiw	r26, 0x02	; 2
     83a:	1c 93       	st	X, r17
     83c:	0e 93       	st	-X, r16
     83e:	11 97       	sbiw	r26, 0x01	; 1
     840:	89 e4       	ldi	r24, 0x49	; 73
     842:	92 e0       	ldi	r25, 0x02	; 2
     844:	93 83       	std	Z+3, r25	; 0x03
     846:	82 83       	std	Z+2, r24	; 0x02
     848:	44 83       	std	Z+4, r20	; 0x04
     84a:	15 82       	std	Z+5, r1	; 0x05
     84c:	d8 dc       	rcall	.-1616   	; 0x1fe <sprintf>
			DEBUG_SERIAL.println(debug_info);
     84e:	8d b7       	in	r24, 0x3d	; 61
     850:	9e b7       	in	r25, 0x3e	; 62
     852:	06 96       	adiw	r24, 0x06	; 6
     854:	0f b6       	in	r0, 0x3f	; 63
     856:	f8 94       	cli
     858:	9e bf       	out	0x3e, r25	; 62
     85a:	0f be       	out	0x3f, r0	; 63
     85c:	8d bf       	out	0x3d, r24	; 61
     85e:	8f e5       	ldi	r24, 0x5F	; 95
     860:	97 e0       	ldi	r25, 0x07	; 7
     862:	b8 01       	movw	r22, r16
     864:	0e 94 26 0e 	call	0x1c4c	; 0x1c4c <_ZN5Print7printlnEPKc>
		goto error_label;
		}
		
	// We have an error and we need to reboot the network.
	error_label:
		error();
     868:	ce 01       	movw	r24, r28
     86a:	64 df       	rcall	.-312    	; 0x734 <_ZN12main_defines5errorEv>
}
     86c:	df 91       	pop	r29
     86e:	cf 91       	pop	r28
     870:	1f 91       	pop	r17
     872:	0f 91       	pop	r16
     874:	08 95       	ret

00000876 <_ZN13PACKET_PARSER20_check_packet_headerEv>:
	_check_packet_header();
}

// --------------------------------------------------------------------
//! Checks Packet header
void PACKET_PARSER::_check_packet_header() {
     876:	0f 93       	push	r16
     878:	1f 93       	push	r17
     87a:	cf 93       	push	r28
     87c:	df 93       	push	r29
     87e:	ec 01       	movw	r28, r24

	// Check the size value
	if (_header.message_size < 1) {
     880:	8b 85       	ldd	r24, Y+11	; 0x0b
     882:	88 23       	and	r24, r24
     884:	21 f5       	brne	.+72     	; 0x8ce <_ZN13PACKET_PARSER20_check_packet_headerEv+0x58>
#ifdef DEBUG_LEDs
		debug_api.set_leds(INFO_ERROR);
#endif
#ifdef DEBUG
		char* debug_info;
		sprintf(debug_info, "[SENSOR %d]: Packet size < 1", _header.sensor_id);
     886:	00 d0       	rcall	.+0      	; 0x888 <_ZN13PACKET_PARSER20_check_packet_headerEv+0x12>
     888:	00 d0       	rcall	.+0      	; 0x88a <_ZN13PACKET_PARSER20_check_packet_headerEv+0x14>
     88a:	ed b7       	in	r30, 0x3d	; 61
     88c:	fe b7       	in	r31, 0x3e	; 62
     88e:	31 96       	adiw	r30, 0x01	; 1
     890:	00 e0       	ldi	r16, 0x00	; 0
     892:	10 e0       	ldi	r17, 0x00	; 0
     894:	ad b7       	in	r26, 0x3d	; 61
     896:	be b7       	in	r27, 0x3e	; 62
     898:	12 96       	adiw	r26, 0x02	; 2
     89a:	1c 93       	st	X, r17
     89c:	0e 93       	st	-X, r16
     89e:	11 97       	sbiw	r26, 0x01	; 1
     8a0:	87 e6       	ldi	r24, 0x67	; 103
     8a2:	92 e0       	ldi	r25, 0x02	; 2
     8a4:	93 83       	std	Z+3, r25	; 0x03
     8a6:	82 83       	std	Z+2, r24	; 0x02
     8a8:	8d 85       	ldd	r24, Y+13	; 0x0d
     8aa:	84 83       	std	Z+4, r24	; 0x04
     8ac:	15 82       	std	Z+5, r1	; 0x05
     8ae:	a7 dc       	rcall	.-1714   	; 0x1fe <sprintf>
		DEBUG_SERIAL.println(debug_info);
     8b0:	8d b7       	in	r24, 0x3d	; 61
     8b2:	9e b7       	in	r25, 0x3e	; 62
     8b4:	06 96       	adiw	r24, 0x06	; 6
     8b6:	0f b6       	in	r0, 0x3f	; 63
     8b8:	f8 94       	cli
     8ba:	9e bf       	out	0x3e, r25	; 62
     8bc:	0f be       	out	0x3f, r0	; 63
     8be:	8d bf       	out	0x3d, r24	; 61
     8c0:	8f e5       	ldi	r24, 0x5F	; 95
     8c2:	97 e0       	ldi	r25, 0x07	; 7
     8c4:	b8 01       	movw	r22, r16
     8c6:	0e 94 26 0e 	call	0x1c4c	; 0x1c4c <_ZN5Print7printlnEPKc>
#endif
	
	// we have a net error if we reach this.
		error();
     8ca:	ce 01       	movw	r24, r28
     8cc:	33 df       	rcall	.-410    	; 0x734 <_ZN12main_defines5errorEv>
	}
	
	// Check the message size
	if(_header.message_size != this->packet_size){
     8ce:	9b 85       	ldd	r25, Y+11	; 0x0b
     8d0:	8a 85       	ldd	r24, Y+10	; 0x0a
     8d2:	98 17       	cp	r25, r24
     8d4:	11 f1       	breq	.+68     	; 0x91a <_ZN13PACKET_PARSER20_check_packet_headerEv+0xa4>
#ifdef DEBUG_LEDs
		debug_api.set_leds(DEBUG_ERROR);
#endif
#ifdef DEBUG
		char* debug_info;
		sprintf(debug_info, "[BASESTATION]: Packet size issue", _header.packet_version);
     8d6:	00 d0       	rcall	.+0      	; 0x8d8 <_ZN13PACKET_PARSER20_check_packet_headerEv+0x62>
     8d8:	00 d0       	rcall	.+0      	; 0x8da <_ZN13PACKET_PARSER20_check_packet_headerEv+0x64>
     8da:	ed b7       	in	r30, 0x3d	; 61
     8dc:	fe b7       	in	r31, 0x3e	; 62
     8de:	31 96       	adiw	r30, 0x01	; 1
     8e0:	00 e0       	ldi	r16, 0x00	; 0
     8e2:	10 e0       	ldi	r17, 0x00	; 0
     8e4:	ad b7       	in	r26, 0x3d	; 61
     8e6:	be b7       	in	r27, 0x3e	; 62
     8e8:	12 96       	adiw	r26, 0x02	; 2
     8ea:	1c 93       	st	X, r17
     8ec:	0e 93       	st	-X, r16
     8ee:	11 97       	sbiw	r26, 0x01	; 1
     8f0:	84 e8       	ldi	r24, 0x84	; 132
     8f2:	92 e0       	ldi	r25, 0x02	; 2
     8f4:	93 83       	std	Z+3, r25	; 0x03
     8f6:	82 83       	std	Z+2, r24	; 0x02
     8f8:	8a 89       	ldd	r24, Y+18	; 0x12
     8fa:	84 83       	std	Z+4, r24	; 0x04
     8fc:	15 82       	std	Z+5, r1	; 0x05
     8fe:	7f dc       	rcall	.-1794   	; 0x1fe <sprintf>
		DEBUG_SERIAL.println(debug_info);
     900:	8d b7       	in	r24, 0x3d	; 61
     902:	9e b7       	in	r25, 0x3e	; 62
     904:	06 96       	adiw	r24, 0x06	; 6
     906:	0f b6       	in	r0, 0x3f	; 63
     908:	f8 94       	cli
     90a:	9e bf       	out	0x3e, r25	; 62
     90c:	0f be       	out	0x3f, r0	; 63
     90e:	8d bf       	out	0x3d, r24	; 61
     910:	8f e5       	ldi	r24, 0x5F	; 95
     912:	97 e0       	ldi	r25, 0x07	; 7
     914:	b8 01       	movw	r22, r16
     916:	0e 94 26 0e 	call	0x1c4c	; 0x1c4c <_ZN5Print7printlnEPKc>
	
	// We discard the packet... we don't use it
	}

	// Check the packet version
	if (_header.packet_version != 0x01) {
     91a:	2a 89       	ldd	r18, Y+18	; 0x12
     91c:	21 30       	cpi	r18, 0x01	; 1
     91e:	09 f1       	breq	.+66     	; 0x962 <_ZN13PACKET_PARSER20_check_packet_headerEv+0xec>
#ifdef DEBUG_LEDs
		debug_api.set_leds(DEBUG_ERROR);
#endif
#ifdef DEBUG
		char* debug_info;
		sprintf(debug_info, "[BASESTATION]: Packet ver (%d) not supported", _header.packet_version);
     920:	00 d0       	rcall	.+0      	; 0x922 <_ZN13PACKET_PARSER20_check_packet_headerEv+0xac>
     922:	00 d0       	rcall	.+0      	; 0x924 <_ZN13PACKET_PARSER20_check_packet_headerEv+0xae>
     924:	ed b7       	in	r30, 0x3d	; 61
     926:	fe b7       	in	r31, 0x3e	; 62
     928:	31 96       	adiw	r30, 0x01	; 1
     92a:	00 e0       	ldi	r16, 0x00	; 0
     92c:	10 e0       	ldi	r17, 0x00	; 0
     92e:	ad b7       	in	r26, 0x3d	; 61
     930:	be b7       	in	r27, 0x3e	; 62
     932:	12 96       	adiw	r26, 0x02	; 2
     934:	1c 93       	st	X, r17
     936:	0e 93       	st	-X, r16
     938:	11 97       	sbiw	r26, 0x01	; 1
     93a:	85 ea       	ldi	r24, 0xA5	; 165
     93c:	92 e0       	ldi	r25, 0x02	; 2
     93e:	93 83       	std	Z+3, r25	; 0x03
     940:	82 83       	std	Z+2, r24	; 0x02
     942:	24 83       	std	Z+4, r18	; 0x04
     944:	15 82       	std	Z+5, r1	; 0x05
     946:	5b dc       	rcall	.-1866   	; 0x1fe <sprintf>
		DEBUG_SERIAL.println(debug_info);
     948:	8d b7       	in	r24, 0x3d	; 61
     94a:	9e b7       	in	r25, 0x3e	; 62
     94c:	06 96       	adiw	r24, 0x06	; 6
     94e:	0f b6       	in	r0, 0x3f	; 63
     950:	f8 94       	cli
     952:	9e bf       	out	0x3e, r25	; 62
     954:	0f be       	out	0x3f, r0	; 63
     956:	8d bf       	out	0x3d, r24	; 61
     958:	8f e5       	ldi	r24, 0x5F	; 95
     95a:	97 e0       	ldi	r25, 0x07	; 7
     95c:	b8 01       	movw	r22, r16
     95e:	0e 94 26 0e 	call	0x1c4c	; 0x1c4c <_ZN5Print7printlnEPKc>
#endif
	}
	
	// Check the timestamp
	if(_header.sensor_run_time < this->old_sensor_time_stamp){
     962:	2e 85       	ldd	r18, Y+14	; 0x0e
     964:	3f 85       	ldd	r19, Y+15	; 0x0f
     966:	48 89       	ldd	r20, Y+16	; 0x10
     968:	59 89       	ldd	r21, Y+17	; 0x11
     96a:	8e 81       	ldd	r24, Y+6	; 0x06
     96c:	9f 81       	ldd	r25, Y+7	; 0x07
     96e:	a8 85       	ldd	r26, Y+8	; 0x08
     970:	b9 85       	ldd	r27, Y+9	; 0x09
     972:	28 17       	cp	r18, r24
     974:	39 07       	cpc	r19, r25
     976:	4a 07       	cpc	r20, r26
     978:	5b 07       	cpc	r21, r27
     97a:	10 f5       	brcc	.+68     	; 0x9c0 <_ZN13PACKET_PARSER20_check_packet_headerEv+0x14a>
#ifdef DEBUG_LEDs
		debug_api.set_leds(DEBUG_ERROR);
#endif
#ifdef DEBUG
		char* debug_info;
		sprintf(debug_info, "[BASESTATION]: Packet timestamp is wrong.", _header.packet_version);
     97c:	00 d0       	rcall	.+0      	; 0x97e <_ZN13PACKET_PARSER20_check_packet_headerEv+0x108>
     97e:	00 d0       	rcall	.+0      	; 0x980 <_ZN13PACKET_PARSER20_check_packet_headerEv+0x10a>
     980:	ed b7       	in	r30, 0x3d	; 61
     982:	fe b7       	in	r31, 0x3e	; 62
     984:	31 96       	adiw	r30, 0x01	; 1
     986:	00 e0       	ldi	r16, 0x00	; 0
     988:	10 e0       	ldi	r17, 0x00	; 0
     98a:	ad b7       	in	r26, 0x3d	; 61
     98c:	be b7       	in	r27, 0x3e	; 62
     98e:	12 96       	adiw	r26, 0x02	; 2
     990:	1c 93       	st	X, r17
     992:	0e 93       	st	-X, r16
     994:	11 97       	sbiw	r26, 0x01	; 1
     996:	82 ed       	ldi	r24, 0xD2	; 210
     998:	92 e0       	ldi	r25, 0x02	; 2
     99a:	93 83       	std	Z+3, r25	; 0x03
     99c:	82 83       	std	Z+2, r24	; 0x02
     99e:	8a 89       	ldd	r24, Y+18	; 0x12
     9a0:	84 83       	std	Z+4, r24	; 0x04
     9a2:	15 82       	std	Z+5, r1	; 0x05
     9a4:	2c dc       	rcall	.-1960   	; 0x1fe <sprintf>
		DEBUG_SERIAL.println(debug_info);
     9a6:	8d b7       	in	r24, 0x3d	; 61
     9a8:	9e b7       	in	r25, 0x3e	; 62
     9aa:	06 96       	adiw	r24, 0x06	; 6
     9ac:	0f b6       	in	r0, 0x3f	; 63
     9ae:	f8 94       	cli
     9b0:	9e bf       	out	0x3e, r25	; 62
     9b2:	0f be       	out	0x3f, r0	; 63
     9b4:	8d bf       	out	0x3d, r24	; 61
     9b6:	8f e5       	ldi	r24, 0x5F	; 95
     9b8:	97 e0       	ldi	r25, 0x07	; 7
     9ba:	b8 01       	movw	r22, r16
     9bc:	0e 94 26 0e 	call	0x1c4c	; 0x1c4c <_ZN5Print7printlnEPKc>
#endif	
	}
}
     9c0:	df 91       	pop	r29
     9c2:	cf 91       	pop	r28
     9c4:	1f 91       	pop	r17
     9c6:	0f 91       	pop	r16
     9c8:	08 95       	ret

000009ca <_ZN13PACKET_PARSER16_check_heartbeatEv>:
	}
}

// --------------------------------------------------------------------
//! Checks the heartbeat signal
void PACKET_PARSER::_check_heartbeat() {
     9ca:	0f 93       	push	r16
     9cc:	1f 93       	push	r17
     9ce:	cf 93       	push	r28
     9d0:	df 93       	push	r29
     9d2:	ec 01       	movw	r28, r24

	//! Checks to see if the sensor mode is in the ok states
	if((_heartbeat.sensor_mode == SENSOR_ERROR_TAG) || 
     9d4:	8c 89       	ldd	r24, Y+20	; 0x14
     9d6:	87 50       	subi	r24, 0x07	; 7
     9d8:	82 30       	cpi	r24, 0x02	; 2
     9da:	20 f5       	brcc	.+72     	; 0xa24 <_ZN13PACKET_PARSER16_check_heartbeatEv+0x5a>
#ifdef DEBUG_LEDs
		debug_api.set_leds(INFO_ERROR);
#endif
#ifdef DEBUG
		char* debug_info;
		sprintf(debug_info, "[SENSOR %d]: Sensor state error.", _header.sensor_id);
     9dc:	00 d0       	rcall	.+0      	; 0x9de <_ZN13PACKET_PARSER16_check_heartbeatEv+0x14>
     9de:	00 d0       	rcall	.+0      	; 0x9e0 <_ZN13PACKET_PARSER16_check_heartbeatEv+0x16>
     9e0:	ed b7       	in	r30, 0x3d	; 61
     9e2:	fe b7       	in	r31, 0x3e	; 62
     9e4:	31 96       	adiw	r30, 0x01	; 1
     9e6:	00 e0       	ldi	r16, 0x00	; 0
     9e8:	10 e0       	ldi	r17, 0x00	; 0
     9ea:	ad b7       	in	r26, 0x3d	; 61
     9ec:	be b7       	in	r27, 0x3e	; 62
     9ee:	12 96       	adiw	r26, 0x02	; 2
     9f0:	1c 93       	st	X, r17
     9f2:	0e 93       	st	-X, r16
     9f4:	11 97       	sbiw	r26, 0x01	; 1
     9f6:	8c ef       	ldi	r24, 0xFC	; 252
     9f8:	92 e0       	ldi	r25, 0x02	; 2
     9fa:	93 83       	std	Z+3, r25	; 0x03
     9fc:	82 83       	std	Z+2, r24	; 0x02
     9fe:	8d 85       	ldd	r24, Y+13	; 0x0d
     a00:	84 83       	std	Z+4, r24	; 0x04
     a02:	15 82       	std	Z+5, r1	; 0x05
     a04:	fc db       	rcall	.-2056   	; 0x1fe <sprintf>
		DEBUG_SERIAL.println(debug_info);
     a06:	8d b7       	in	r24, 0x3d	; 61
     a08:	9e b7       	in	r25, 0x3e	; 62
     a0a:	06 96       	adiw	r24, 0x06	; 6
     a0c:	0f b6       	in	r0, 0x3f	; 63
     a0e:	f8 94       	cli
     a10:	9e bf       	out	0x3e, r25	; 62
     a12:	0f be       	out	0x3f, r0	; 63
     a14:	8d bf       	out	0x3d, r24	; 61
     a16:	8f e5       	ldi	r24, 0x5F	; 95
     a18:	97 e0       	ldi	r25, 0x07	; 7
     a1a:	b8 01       	movw	r22, r16
     a1c:	0e 94 26 0e 	call	0x1c4c	; 0x1c4c <_ZN5Print7printlnEPKc>
#endif
		
		// Reboot network
		error();
     a20:	ce 01       	movw	r24, r28
     a22:	88 de       	rcall	.-752    	; 0x734 <_ZN12main_defines5errorEv>
	}
	//! Checks the heartbeat of the remote device.
	if (_heartbeat.battery_voltage < MIN_BATT_LEVEL) {
     a24:	8d 89       	ldd	r24, Y+21	; 0x15
     a26:	9e 89       	ldd	r25, Y+22	; 0x16
     a28:	84 36       	cpi	r24, 0x64	; 100
     a2a:	91 05       	cpc	r25, r1
     a2c:	10 f5       	brcc	.+68     	; 0xa72 <_ZN13PACKET_PARSER16_check_heartbeatEv+0xa8>
#ifdef DEBUG_LEDs
		debug_api.set_leds(INFO_ERROR);
#endif
#ifdef DEBUG
		char* debug_info;
		sprintf(debug_info, "[SENSOR %d]: Battery level low", _header.sensor_id);
     a2e:	00 d0       	rcall	.+0      	; 0xa30 <_ZN13PACKET_PARSER16_check_heartbeatEv+0x66>
     a30:	00 d0       	rcall	.+0      	; 0xa32 <_ZN13PACKET_PARSER16_check_heartbeatEv+0x68>
     a32:	ed b7       	in	r30, 0x3d	; 61
     a34:	fe b7       	in	r31, 0x3e	; 62
     a36:	31 96       	adiw	r30, 0x01	; 1
     a38:	00 e0       	ldi	r16, 0x00	; 0
     a3a:	10 e0       	ldi	r17, 0x00	; 0
     a3c:	ad b7       	in	r26, 0x3d	; 61
     a3e:	be b7       	in	r27, 0x3e	; 62
     a40:	12 96       	adiw	r26, 0x02	; 2
     a42:	1c 93       	st	X, r17
     a44:	0e 93       	st	-X, r16
     a46:	11 97       	sbiw	r26, 0x01	; 1
     a48:	8d e1       	ldi	r24, 0x1D	; 29
     a4a:	93 e0       	ldi	r25, 0x03	; 3
     a4c:	93 83       	std	Z+3, r25	; 0x03
     a4e:	82 83       	std	Z+2, r24	; 0x02
     a50:	8d 85       	ldd	r24, Y+13	; 0x0d
     a52:	84 83       	std	Z+4, r24	; 0x04
     a54:	15 82       	std	Z+5, r1	; 0x05
     a56:	d3 db       	rcall	.-2138   	; 0x1fe <sprintf>
		DEBUG_SERIAL.println(debug_info);
     a58:	8d b7       	in	r24, 0x3d	; 61
     a5a:	9e b7       	in	r25, 0x3e	; 62
     a5c:	06 96       	adiw	r24, 0x06	; 6
     a5e:	0f b6       	in	r0, 0x3f	; 63
     a60:	f8 94       	cli
     a62:	9e bf       	out	0x3e, r25	; 62
     a64:	0f be       	out	0x3f, r0	; 63
     a66:	8d bf       	out	0x3d, r24	; 61
     a68:	8f e5       	ldi	r24, 0x5F	; 95
     a6a:	97 e0       	ldi	r25, 0x07	; 7
     a6c:	b8 01       	movw	r22, r16
     a6e:	0e 94 26 0e 	call	0x1c4c	; 0x1c4c <_ZN5Print7printlnEPKc>
#endif
	}
}
     a72:	df 91       	pop	r29
     a74:	cf 91       	pop	r28
     a76:	1f 91       	pop	r17
     a78:	0f 91       	pop	r16
     a7a:	08 95       	ret

00000a7c <_ZN13PACKET_PARSER10_check_ackEv>:
	return false;
}

// --------------------------------------------------------------------
//! Checks the ack signal
void PACKET_PARSER::_check_ack() {
     a7c:	fc 01       	movw	r30, r24
	if (this->_ack.ack) {
     a7e:	83 89       	ldd	r24, Z+19	; 0x13
     a80:	88 23       	and	r24, r24
     a82:	11 f4       	brne	.+4      	; 0xa88 <_ZN13PACKET_PARSER10_check_ackEv+0xc>
		return;
	} else {
#ifdef DEBUG_LEDs
		debug_api.set_leds(REBOOT_ERROR);
#endif
		error();
     a84:	cf 01       	movw	r24, r30
     a86:	56 ce       	rjmp	.-852    	; 0x734 <_ZN12main_defines5errorEv>
     a88:	08 95       	ret

00000a8a <_ZN13PACKET_PARSER20_check_sensor_statusEv>:
	}
}

// --------------------------------------------------------------------
//! Checks the router status.
void PACKET_PARSER::_check_sensor_status() {
     a8a:	ff 92       	push	r15
     a8c:	0f 93       	push	r16
     a8e:	1f 93       	push	r17
     a90:	cf 93       	push	r28
     a92:	df 93       	push	r29
     a94:	8c 01       	movw	r16, r24
	#ifdef DEBUG
		char* debug_info;
	#endif

	// Switch on the received state
	switch(_status.state){
     a96:	dc 01       	movw	r26, r24
     a98:	57 96       	adiw	r26, 0x17	; 23
     a9a:	8c 91       	ld	r24, X
     a9c:	84 30       	cpi	r24, 0x04	; 4
     a9e:	30 f4       	brcc	.+12     	; 0xaac <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x22>
     aa0:	82 30       	cpi	r24, 0x02	; 2
     aa2:	40 f5       	brcc	.+80     	; 0xaf4 <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x6a>
     aa4:	81 30       	cpi	r24, 0x01	; 1
     aa6:	09 f0       	breq	.+2      	; 0xaaa <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x20>
     aa8:	e0 c0       	rjmp	.+448    	; 0xc6a <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x1e0>
     aaa:	07 c0       	rjmp	.+14     	; 0xaba <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x30>
     aac:	84 30       	cpi	r24, 0x04	; 4
     aae:	09 f4       	brne	.+2      	; 0xab2 <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x28>
     ab0:	9a c0       	rjmp	.+308    	; 0xbe6 <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x15c>
     ab2:	87 30       	cpi	r24, 0x07	; 7
     ab4:	08 f0       	brcs	.+2      	; 0xab8 <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x2e>
     ab6:	d9 c0       	rjmp	.+434    	; 0xc6a <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x1e0>
     ab8:	b7 c0       	rjmp	.+366    	; 0xc28 <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x19e>
		
		// The sensor is ok
		case SENSOR_STATE_OK:
			
			db[_header.sensor_id].set_state(OK_SENSOR_STATE);
     aba:	f8 01       	movw	r30, r16
     abc:	25 85       	ldd	r18, Z+13	; 0x0d
     abe:	8b e0       	ldi	r24, 0x0B	; 11
     ac0:	28 9f       	mul	r18, r24
     ac2:	90 01       	movw	r18, r0
     ac4:	11 24       	eor	r1, r1
     ac6:	84 81       	ldd	r24, Z+4	; 0x04
     ac8:	95 81       	ldd	r25, Z+5	; 0x05
     aca:	82 0f       	add	r24, r18
     acc:	93 1f       	adc	r25, r19
     ace:	63 e0       	ldi	r22, 0x03	; 3
     ad0:	70 e0       	ldi	r23, 0x00	; 0
     ad2:	1a d2       	rcall	.+1076   	; 0xf08 <_ZN6SENSOR9set_stateE14sensor_state_t>
			#ifdef DEBUG
				sprintf(debug_info, "[SENSOR %d]: MODE == OK", _header.sensor_id);
     ad4:	00 d0       	rcall	.+0      	; 0xad6 <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x4c>
     ad6:	00 d0       	rcall	.+0      	; 0xad8 <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x4e>
     ad8:	ed b7       	in	r30, 0x3d	; 61
     ada:	fe b7       	in	r31, 0x3e	; 62
     adc:	31 96       	adiw	r30, 0x01	; 1
     ade:	c0 e0       	ldi	r28, 0x00	; 0
     ae0:	d0 e0       	ldi	r29, 0x00	; 0
     ae2:	ad b7       	in	r26, 0x3d	; 61
     ae4:	be b7       	in	r27, 0x3e	; 62
     ae6:	12 96       	adiw	r26, 0x02	; 2
     ae8:	dc 93       	st	X, r29
     aea:	ce 93       	st	-X, r28
     aec:	11 97       	sbiw	r26, 0x01	; 1
     aee:	8c e3       	ldi	r24, 0x3C	; 60
     af0:	93 e0       	ldi	r25, 0x03	; 3
     af2:	ca c0       	rjmp	.+404    	; 0xc88 <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x1fe>
			
		// Something went wrong
		case SENSOR_STATE_FAIL:
		case SENSOR_STATE_ERROR:
				
			db[_header.sensor_id].set_state(ERROR_SENSOR_STATE);
     af4:	d8 01       	movw	r26, r16
     af6:	1d 96       	adiw	r26, 0x0d	; 13
     af8:	2c 91       	ld	r18, X
     afa:	1d 97       	sbiw	r26, 0x0d	; 13
     afc:	8b e0       	ldi	r24, 0x0B	; 11
     afe:	f8 2e       	mov	r15, r24
     b00:	2f 9d       	mul	r18, r15
     b02:	90 01       	movw	r18, r0
     b04:	11 24       	eor	r1, r1
     b06:	14 96       	adiw	r26, 0x04	; 4
     b08:	8d 91       	ld	r24, X+
     b0a:	9c 91       	ld	r25, X
     b0c:	15 97       	sbiw	r26, 0x05	; 5
     b0e:	82 0f       	add	r24, r18
     b10:	93 1f       	adc	r25, r19
     b12:	67 e0       	ldi	r22, 0x07	; 7
     b14:	70 e0       	ldi	r23, 0x00	; 0
     b16:	f8 d1       	rcall	.+1008   	; 0xf08 <_ZN6SENSOR9set_stateE14sensor_state_t>
			#ifdef DEBUG_LEDs
				debug_api.set_leds(INFO_ERROR);
			#endif
			#ifdef DEBUG
				sprintf(debug_info, "[SENSOR %d]: MODE == ERROR", _header.sensor_id);
     b18:	00 d0       	rcall	.+0      	; 0xb1a <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x90>
     b1a:	00 d0       	rcall	.+0      	; 0xb1c <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x92>
     b1c:	ed b7       	in	r30, 0x3d	; 61
     b1e:	fe b7       	in	r31, 0x3e	; 62
     b20:	31 96       	adiw	r30, 0x01	; 1
     b22:	c0 e0       	ldi	r28, 0x00	; 0
     b24:	d0 e0       	ldi	r29, 0x00	; 0
     b26:	ad b7       	in	r26, 0x3d	; 61
     b28:	be b7       	in	r27, 0x3e	; 62
     b2a:	12 96       	adiw	r26, 0x02	; 2
     b2c:	dc 93       	st	X, r29
     b2e:	ce 93       	st	-X, r28
     b30:	11 97       	sbiw	r26, 0x01	; 1
     b32:	84 e5       	ldi	r24, 0x54	; 84
     b34:	93 e0       	ldi	r25, 0x03	; 3
     b36:	93 83       	std	Z+3, r25	; 0x03
     b38:	82 83       	std	Z+2, r24	; 0x02
     b3a:	d8 01       	movw	r26, r16
     b3c:	1d 96       	adiw	r26, 0x0d	; 13
     b3e:	8c 91       	ld	r24, X
     b40:	84 83       	std	Z+4, r24	; 0x04
     b42:	15 82       	std	Z+5, r1	; 0x05
     b44:	5c db       	rcall	.-2376   	; 0x1fe <sprintf>
				DEBUG_SERIAL.println(debug_info);
     b46:	ed b7       	in	r30, 0x3d	; 61
     b48:	fe b7       	in	r31, 0x3e	; 62
     b4a:	36 96       	adiw	r30, 0x06	; 6
     b4c:	0f b6       	in	r0, 0x3f	; 63
     b4e:	f8 94       	cli
     b50:	fe bf       	out	0x3e, r31	; 62
     b52:	0f be       	out	0x3f, r0	; 63
     b54:	ed bf       	out	0x3d, r30	; 61
     b56:	8f e5       	ldi	r24, 0x5F	; 95
     b58:	97 e0       	ldi	r25, 0x07	; 7
     b5a:	be 01       	movw	r22, r28
     b5c:	0e 94 26 0e 	call	0x1c4c	; 0x1c4c <_ZN5Print7printlnEPKc>
			#endif
			
			if(_status.state == SENSOR_STATE_ERROR){
     b60:	d8 01       	movw	r26, r16
     b62:	57 96       	adiw	r26, 0x17	; 23
     b64:	8c 91       	ld	r24, X
     b66:	57 97       	sbiw	r26, 0x17	; 23
     b68:	83 30       	cpi	r24, 0x03	; 3
     b6a:	d1 f5       	brne	.+116    	; 0xbe0 <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x156>
				db[_header.sensor_id].set_error_code(_error.error_code);
     b6c:	1d 96       	adiw	r26, 0x0d	; 13
     b6e:	2c 91       	ld	r18, X
     b70:	1d 97       	sbiw	r26, 0x0d	; 13
     b72:	2f 9d       	mul	r18, r15
     b74:	90 01       	movw	r18, r0
     b76:	11 24       	eor	r1, r1
     b78:	14 96       	adiw	r26, 0x04	; 4
     b7a:	8d 91       	ld	r24, X+
     b7c:	9c 91       	ld	r25, X
     b7e:	15 97       	sbiw	r26, 0x05	; 5
     b80:	82 0f       	add	r24, r18
     b82:	93 1f       	adc	r25, r19
     b84:	58 96       	adiw	r26, 0x18	; 24
     b86:	6c 91       	ld	r22, X
     b88:	c3 d1       	rcall	.+902    	; 0xf10 <_ZN6SENSOR14set_error_codeEh>
				
				#ifdef DEBUG_LEDs
					debug_api.set_leds(INFO_ERROR);
				#endif
				#ifdef DEBUG
					sprintf(debug_info, "[SENSOR %d]: MODE == ERROR code: %d", _header.sensor_id, _error.error_code);
     b8a:	ed b7       	in	r30, 0x3d	; 61
     b8c:	fe b7       	in	r31, 0x3e	; 62
     b8e:	38 97       	sbiw	r30, 0x08	; 8
     b90:	0f b6       	in	r0, 0x3f	; 63
     b92:	f8 94       	cli
     b94:	fe bf       	out	0x3e, r31	; 62
     b96:	0f be       	out	0x3f, r0	; 63
     b98:	ed bf       	out	0x3d, r30	; 61
     b9a:	31 96       	adiw	r30, 0x01	; 1
     b9c:	ad b7       	in	r26, 0x3d	; 61
     b9e:	be b7       	in	r27, 0x3e	; 62
     ba0:	12 96       	adiw	r26, 0x02	; 2
     ba2:	dc 93       	st	X, r29
     ba4:	ce 93       	st	-X, r28
     ba6:	11 97       	sbiw	r26, 0x01	; 1
     ba8:	8f e6       	ldi	r24, 0x6F	; 111
     baa:	93 e0       	ldi	r25, 0x03	; 3
     bac:	93 83       	std	Z+3, r25	; 0x03
     bae:	82 83       	std	Z+2, r24	; 0x02
     bb0:	d8 01       	movw	r26, r16
     bb2:	1d 96       	adiw	r26, 0x0d	; 13
     bb4:	8c 91       	ld	r24, X
     bb6:	1d 97       	sbiw	r26, 0x0d	; 13
     bb8:	84 83       	std	Z+4, r24	; 0x04
     bba:	15 82       	std	Z+5, r1	; 0x05
     bbc:	58 96       	adiw	r26, 0x18	; 24
     bbe:	8c 91       	ld	r24, X
     bc0:	86 83       	std	Z+6, r24	; 0x06
     bc2:	17 82       	std	Z+7, r1	; 0x07
     bc4:	1c db       	rcall	.-2504   	; 0x1fe <sprintf>
					DEBUG_SERIAL.println(debug_info);
     bc6:	ed b7       	in	r30, 0x3d	; 61
     bc8:	fe b7       	in	r31, 0x3e	; 62
     bca:	38 96       	adiw	r30, 0x08	; 8
     bcc:	0f b6       	in	r0, 0x3f	; 63
     bce:	f8 94       	cli
     bd0:	fe bf       	out	0x3e, r31	; 62
     bd2:	0f be       	out	0x3f, r0	; 63
     bd4:	ed bf       	out	0x3d, r30	; 61
     bd6:	8f e5       	ldi	r24, 0x5F	; 95
     bd8:	97 e0       	ldi	r25, 0x07	; 7
     bda:	be 01       	movw	r22, r28
     bdc:	0e 94 26 0e 	call	0x1c4c	; 0x1c4c <_ZN5Print7printlnEPKc>
				#endif
			}
			
			//! Reboot the network
			error();
     be0:	c8 01       	movw	r24, r16
     be2:	a8 dd       	rcall	.-1200   	; 0x734 <_ZN12main_defines5errorEv>
     be4:	65 c0       	rjmp	.+202    	; 0xcb0 <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x226>
			break;
			
		// The sensor is on a boot mode
		case SENSOR_STATE_BOOT:
		
			db[_header.sensor_id].set_state(ERROR_SENSOR_STATE);
     be6:	d8 01       	movw	r26, r16
     be8:	1d 96       	adiw	r26, 0x0d	; 13
     bea:	2c 91       	ld	r18, X
     bec:	1d 97       	sbiw	r26, 0x0d	; 13
     bee:	8b e0       	ldi	r24, 0x0B	; 11
     bf0:	28 9f       	mul	r18, r24
     bf2:	90 01       	movw	r18, r0
     bf4:	11 24       	eor	r1, r1
     bf6:	14 96       	adiw	r26, 0x04	; 4
     bf8:	8d 91       	ld	r24, X+
     bfa:	9c 91       	ld	r25, X
     bfc:	15 97       	sbiw	r26, 0x05	; 5
     bfe:	82 0f       	add	r24, r18
     c00:	93 1f       	adc	r25, r19
     c02:	67 e0       	ldi	r22, 0x07	; 7
     c04:	70 e0       	ldi	r23, 0x00	; 0
     c06:	80 d1       	rcall	.+768    	; 0xf08 <_ZN6SENSOR9set_stateE14sensor_state_t>
			#ifdef DEBUG
				sprintf(debug_info, "[SENSOR %d]: MODE == BOOT", _header.sensor_id);
     c08:	00 d0       	rcall	.+0      	; 0xc0a <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x180>
     c0a:	00 d0       	rcall	.+0      	; 0xc0c <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x182>
     c0c:	ed b7       	in	r30, 0x3d	; 61
     c0e:	fe b7       	in	r31, 0x3e	; 62
     c10:	31 96       	adiw	r30, 0x01	; 1
     c12:	c0 e0       	ldi	r28, 0x00	; 0
     c14:	d0 e0       	ldi	r29, 0x00	; 0
     c16:	ad b7       	in	r26, 0x3d	; 61
     c18:	be b7       	in	r27, 0x3e	; 62
     c1a:	12 96       	adiw	r26, 0x02	; 2
     c1c:	dc 93       	st	X, r29
     c1e:	ce 93       	st	-X, r28
     c20:	11 97       	sbiw	r26, 0x01	; 1
     c22:	83 e9       	ldi	r24, 0x93	; 147
     c24:	93 e0       	ldi	r25, 0x03	; 3
     c26:	30 c0       	rjmp	.+96     	; 0xc88 <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x1fe>
			
		// The sensor is rebooting or resetting
		case SENSOR_STATE_REBOOT:
		case SENSOR_STATE_RESET:
			
			db[_header.sensor_id].set_state(ERROR_SENSOR_STATE);
     c28:	d8 01       	movw	r26, r16
     c2a:	1d 96       	adiw	r26, 0x0d	; 13
     c2c:	2c 91       	ld	r18, X
     c2e:	1d 97       	sbiw	r26, 0x0d	; 13
     c30:	8b e0       	ldi	r24, 0x0B	; 11
     c32:	28 9f       	mul	r18, r24
     c34:	90 01       	movw	r18, r0
     c36:	11 24       	eor	r1, r1
     c38:	14 96       	adiw	r26, 0x04	; 4
     c3a:	8d 91       	ld	r24, X+
     c3c:	9c 91       	ld	r25, X
     c3e:	15 97       	sbiw	r26, 0x05	; 5
     c40:	82 0f       	add	r24, r18
     c42:	93 1f       	adc	r25, r19
     c44:	67 e0       	ldi	r22, 0x07	; 7
     c46:	70 e0       	ldi	r23, 0x00	; 0
     c48:	5f d1       	rcall	.+702    	; 0xf08 <_ZN6SENSOR9set_stateE14sensor_state_t>
			#ifdef DEBUG_LEDs
				debug_api.set_leds(INFO_ERROR);
			#endif
			#ifdef DEBUG
				sprintf(debug_info, "[SENSOR %d]: MODE == REBOOT/RESET", _header.sensor_id);
     c4a:	00 d0       	rcall	.+0      	; 0xc4c <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x1c2>
     c4c:	00 d0       	rcall	.+0      	; 0xc4e <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x1c4>
     c4e:	ed b7       	in	r30, 0x3d	; 61
     c50:	fe b7       	in	r31, 0x3e	; 62
     c52:	31 96       	adiw	r30, 0x01	; 1
     c54:	c0 e0       	ldi	r28, 0x00	; 0
     c56:	d0 e0       	ldi	r29, 0x00	; 0
     c58:	ad b7       	in	r26, 0x3d	; 61
     c5a:	be b7       	in	r27, 0x3e	; 62
     c5c:	12 96       	adiw	r26, 0x02	; 2
     c5e:	dc 93       	st	X, r29
     c60:	ce 93       	st	-X, r28
     c62:	11 97       	sbiw	r26, 0x01	; 1
     c64:	8d ea       	ldi	r24, 0xAD	; 173
     c66:	93 e0       	ldi	r25, 0x03	; 3
     c68:	0f c0       	rjmp	.+30     	; 0xc88 <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x1fe>
		default:
			#ifdef DEBUG_LEDs
				debug_api.set_leds(INFO_ERROR);
			#endif
			#ifdef DEBUG
				sprintf(debug_info, "[SENSOR %d]: INVALID PACKET", _header.sensor_id);
     c6a:	00 d0       	rcall	.+0      	; 0xc6c <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x1e2>
     c6c:	00 d0       	rcall	.+0      	; 0xc6e <_ZN13PACKET_PARSER20_check_sensor_statusEv+0x1e4>
     c6e:	ed b7       	in	r30, 0x3d	; 61
     c70:	fe b7       	in	r31, 0x3e	; 62
     c72:	31 96       	adiw	r30, 0x01	; 1
     c74:	c0 e0       	ldi	r28, 0x00	; 0
     c76:	d0 e0       	ldi	r29, 0x00	; 0
     c78:	ad b7       	in	r26, 0x3d	; 61
     c7a:	be b7       	in	r27, 0x3e	; 62
     c7c:	12 96       	adiw	r26, 0x02	; 2
     c7e:	dc 93       	st	X, r29
     c80:	ce 93       	st	-X, r28
     c82:	11 97       	sbiw	r26, 0x01	; 1
     c84:	8f ec       	ldi	r24, 0xCF	; 207
     c86:	93 e0       	ldi	r25, 0x03	; 3
     c88:	93 83       	std	Z+3, r25	; 0x03
     c8a:	82 83       	std	Z+2, r24	; 0x02
     c8c:	d8 01       	movw	r26, r16
     c8e:	1d 96       	adiw	r26, 0x0d	; 13
     c90:	8c 91       	ld	r24, X
     c92:	84 83       	std	Z+4, r24	; 0x04
     c94:	15 82       	std	Z+5, r1	; 0x05
     c96:	b3 da       	rcall	.-2714   	; 0x1fe <sprintf>
				DEBUG_SERIAL.println(debug_info);
     c98:	ed b7       	in	r30, 0x3d	; 61
     c9a:	fe b7       	in	r31, 0x3e	; 62
     c9c:	36 96       	adiw	r30, 0x06	; 6
     c9e:	0f b6       	in	r0, 0x3f	; 63
     ca0:	f8 94       	cli
     ca2:	fe bf       	out	0x3e, r31	; 62
     ca4:	0f be       	out	0x3f, r0	; 63
     ca6:	ed bf       	out	0x3d, r30	; 61
     ca8:	8f e5       	ldi	r24, 0x5F	; 95
     caa:	97 e0       	ldi	r25, 0x07	; 7
     cac:	be 01       	movw	r22, r28
     cae:	ce d7       	rcall	.+3996   	; 0x1c4c <_ZN5Print7printlnEPKc>
			#endif
			break;
	}
	
	// Check header by recursivity
	_check_packet_header();
     cb0:	c8 01       	movw	r24, r16
     cb2:	e1 dd       	rcall	.-1086   	; 0x876 <_ZN13PACKET_PARSER20_check_packet_headerEv>
}
     cb4:	df 91       	pop	r29
     cb6:	cf 91       	pop	r28
     cb8:	1f 91       	pop	r17
     cba:	0f 91       	pop	r16
     cbc:	ff 90       	pop	r15
     cbe:	08 95       	ret

00000cc0 <_ZN13PACKET_PARSER19_check_memory_spaceEj>:
	return true;
}

// --------------------------------------------------------------------
//! Check the memory space
void PACKET_PARSER::_check_memory_space(size_t mem_space) {
     cc0:	ef 92       	push	r14
     cc2:	ff 92       	push	r15
     cc4:	0f 93       	push	r16
     cc6:	1f 93       	push	r17
     cc8:	f8 2e       	mov	r15, r24
     cca:	e9 2e       	mov	r14, r25
     ccc:	8b 01       	movw	r16, r22

	//! Check memory integrity
	if (memory_check() <= mem_space)
     cce:	34 dd       	rcall	.-1432   	; 0x738 <_ZN12main_defines12memory_checkEv>
     cd0:	08 17       	cp	r16, r24
     cd2:	19 07       	cpc	r17, r25
     cd4:	18 f0       	brcs	.+6      	; 0xcdc <_ZN13PACKET_PARSER19_check_memory_spaceEj+0x1c>
#ifdef DEBUG_LEDs
		debug_api.set_leds(MEMORY_ERROR);
#endif
		error();
     cd6:	8f 2d       	mov	r24, r15
     cd8:	9e 2d       	mov	r25, r14
     cda:	2c dd       	rcall	.-1448   	; 0x734 <_ZN12main_defines5errorEv>
}
     cdc:	1f 91       	pop	r17
     cde:	0f 91       	pop	r16
     ce0:	ff 90       	pop	r15
     ce2:	ef 90       	pop	r14
     ce4:	08 95       	ret

00000ce6 <_ZN13PACKET_PARSER6_parseEhhPv>:
void PACKET_PARSER::_alloc_mem(void* dest_pointer, size_t size, void* buf) {
	memcpy(dest_pointer, buf, size);
}

//! Parse the packet
void PACKET_PARSER::_parse(byte packet_id, byte packet_ver, void *buf) {
     ce6:	ff 92       	push	r15
     ce8:	0f 93       	push	r16
     cea:	1f 93       	push	r17
     cec:	cf 93       	push	r28
     cee:	df 93       	push	r29
     cf0:	ec 01       	movw	r28, r24
     cf2:	f6 2e       	mov	r15, r22

	char* buffer = (char*) buf;
     cf4:	89 01       	movw	r16, r18
    char* debug_info;

	//! Check if there is space left
	_check_memory_space();
     cf6:	6a e0       	ldi	r22, 0x0A	; 10
     cf8:	70 e0       	ldi	r23, 0x00	; 0
     cfa:	e2 df       	rcall	.-60     	; 0xcc0 <_ZN13PACKET_PARSER19_check_memory_spaceEj>

	//! Check if the string is ok to process.
	this->_check_packet_integrity((char*) buf);

	//! Assigns the new construct
	memcpy(&_header, buffer, sizeof(sensor_packet_header_t));
     cfc:	de 01       	movw	r26, r28
     cfe:	1b 96       	adiw	r26, 0x0b	; 11
     d00:	f8 01       	movw	r30, r16
     d02:	88 e0       	ldi	r24, 0x08	; 8
     d04:	01 90       	ld	r0, Z+
     d06:	0d 92       	st	X+, r0
     d08:	81 50       	subi	r24, 0x01	; 1
     d0a:	e1 f7       	brne	.-8      	; 0xd04 <_ZN13PACKET_PARSER6_parseEhhPv+0x1e>
	_check_packet_header();
     d0c:	ce 01       	movw	r24, r28
     d0e:	b3 dd       	rcall	.-1178   	; 0x876 <_ZN13PACKET_PARSER20_check_packet_headerEv>

	buffer += sizeof(sensor_packet_header_t);
     d10:	08 5f       	subi	r16, 0xF8	; 248
     d12:	1f 4f       	sbci	r17, 0xFF	; 255

	switch (packet_id) {
     d14:	87 e1       	ldi	r24, 0x17	; 23
     d16:	f8 16       	cp	r15, r24
     d18:	09 f4       	brne	.+2      	; 0xd1c <_ZN13PACKET_PARSER6_parseEhhPv+0x36>
     d1a:	3d c0       	rjmp	.+122    	; 0xd96 <_ZN13PACKET_PARSER6_parseEhhPv+0xb0>
     d1c:	8f 15       	cp	r24, r15
     d1e:	50 f0       	brcs	.+20     	; 0xd34 <_ZN13PACKET_PARSER6_parseEhhPv+0x4e>
     d20:	95 e1       	ldi	r25, 0x15	; 21
     d22:	f9 16       	cp	r15, r25
     d24:	49 f1       	breq	.+82     	; 0xd78 <_ZN13PACKET_PARSER6_parseEhhPv+0x92>
     d26:	9f 15       	cp	r25, r15
     d28:	08 f1       	brcs	.+66     	; 0xd6c <_ZN13PACKET_PARSER6_parseEhhPv+0x86>
     d2a:	a4 e1       	ldi	r26, 0x14	; 20
     d2c:	fa 16       	cp	r15, r26
     d2e:	09 f0       	breq	.+2      	; 0xd32 <_ZN13PACKET_PARSER6_parseEhhPv+0x4c>
     d30:	7e c0       	rjmp	.+252    	; 0xe2e <_ZN13PACKET_PARSER6_parseEhhPv+0x148>
     d32:	0b c0       	rjmp	.+22     	; 0xd4a <_ZN13PACKET_PARSER6_parseEhhPv+0x64>
     d34:	b9 e1       	ldi	r27, 0x19	; 25
     d36:	fb 16       	cp	r15, r27
     d38:	71 f0       	breq	.+28     	; 0xd56 <_ZN13PACKET_PARSER6_parseEhhPv+0x70>
     d3a:	fb 16       	cp	r15, r27
     d3c:	08 f4       	brcc	.+2      	; 0xd40 <_ZN13PACKET_PARSER6_parseEhhPv+0x5a>
     d3e:	6c c0       	rjmp	.+216    	; 0xe18 <_ZN13PACKET_PARSER6_parseEhhPv+0x132>
     d40:	e0 e2       	ldi	r30, 0x20	; 32
     d42:	fe 16       	cp	r15, r30
     d44:	09 f0       	breq	.+2      	; 0xd48 <_ZN13PACKET_PARSER6_parseEhhPv+0x62>
     d46:	73 c0       	rjmp	.+230    	; 0xe2e <_ZN13PACKET_PARSER6_parseEhhPv+0x148>
     d48:	33 c0       	rjmp	.+102    	; 0xdb0 <_ZN13PACKET_PARSER6_parseEhhPv+0xca>
}

// --------------------------------------------------------------------
//! Allocate buffer
void PACKET_PARSER::_alloc_mem(void* dest_pointer, size_t size, void* buf) {
	memcpy(dest_pointer, buf, size);
     d4a:	d8 01       	movw	r26, r16
     d4c:	8c 91       	ld	r24, X
     d4e:	8b 8b       	std	Y+19, r24	; 0x13

	switch (packet_id) {

	case SENSOR_ACK:
		_alloc_mem(&_ack, sizeof(_ack), buffer);
		_check_ack();
     d50:	ce 01       	movw	r24, r28
     d52:	94 de       	rcall	.-728    	; 0xa7c <_ZN13PACKET_PARSER10_check_ackEv>
     d54:	6c c0       	rjmp	.+216    	; 0xe2e <_ZN13PACKET_PARSER6_parseEhhPv+0x148>
}

// --------------------------------------------------------------------
//! Allocate buffer
void PACKET_PARSER::_alloc_mem(void* dest_pointer, size_t size, void* buf) {
	memcpy(dest_pointer, buf, size);
     d56:	de 01       	movw	r26, r28
     d58:	54 96       	adiw	r26, 0x14	; 20
     d5a:	f8 01       	movw	r30, r16
     d5c:	83 e0       	ldi	r24, 0x03	; 3
     d5e:	01 90       	ld	r0, Z+
     d60:	0d 92       	st	X+, r0
     d62:	81 50       	subi	r24, 0x01	; 1
     d64:	e1 f7       	brne	.-8      	; 0xd5e <_ZN13PACKET_PARSER6_parseEhhPv+0x78>
		_check_ack();
		return;

	case SENSOR_HEARTBEAT_REPORT:
		_alloc_mem(&_heartbeat, sizeof(_heartbeat), buffer);
		_check_heartbeat();
     d66:	ce 01       	movw	r24, r28
     d68:	30 de       	rcall	.-928    	; 0x9ca <_ZN13PACKET_PARSER16_check_heartbeatEv>
     d6a:	61 c0       	rjmp	.+194    	; 0xe2e <_ZN13PACKET_PARSER6_parseEhhPv+0x148>
}

// --------------------------------------------------------------------
//! Allocate buffer
void PACKET_PARSER::_alloc_mem(void* dest_pointer, size_t size, void* buf) {
	memcpy(dest_pointer, buf, size);
     d6c:	f8 01       	movw	r30, r16
     d6e:	80 81       	ld	r24, Z
     d70:	8f 8b       	std	Y+23, r24	; 0x17
		_check_heartbeat();
		return;

	case SENSOR_STATUS_REPORT:
		_alloc_mem(&_status, sizeof(_status), buffer);
		_check_sensor_status();
     d72:	ce 01       	movw	r24, r28
     d74:	8a de       	rcall	.-748    	; 0xa8a <_ZN13PACKET_PARSER20_check_sensor_statusEv>
     d76:	5b c0       	rjmp	.+182    	; 0xe2e <_ZN13PACKET_PARSER6_parseEhhPv+0x148>
		return;

	case SENSOR_CONFIG_REPORT:
		_check_memory_space(sizeof(sensor_configs_t));
     d78:	ce 01       	movw	r24, r28
     d7a:	63 e0       	ldi	r22, 0x03	; 3
     d7c:	70 e0       	ldi	r23, 0x00	; 0
     d7e:	a0 df       	rcall	.-192    	; 0xcc0 <_ZN13PACKET_PARSER19_check_memory_spaceEj>
}

// --------------------------------------------------------------------
//! Allocate buffer
void PACKET_PARSER::_alloc_mem(void* dest_pointer, size_t size, void* buf) {
	memcpy(dest_pointer, buf, size);
     d80:	de 01       	movw	r26, r28
     d82:	59 96       	adiw	r26, 0x19	; 25
     d84:	f8 01       	movw	r30, r16
     d86:	83 e0       	ldi	r24, 0x03	; 3
     d88:	01 90       	ld	r0, Z+
     d8a:	0d 92       	st	X+, r0
     d8c:	81 50       	subi	r24, 0x01	; 1
     d8e:	e1 f7       	brne	.-8      	; 0xd88 <_ZN13PACKET_PARSER6_parseEhhPv+0xa2>
		return;

	case SENSOR_CONFIG_REPORT:
		_check_memory_space(sizeof(sensor_configs_t));
		_alloc_mem(&_configs, sizeof(sensor_configs_t), buffer);
		_get_sensor_configs();
     d90:	ce 01       	movw	r24, r28
     d92:	fb dc       	rcall	.-1546   	; 0x78a <_ZN13PACKET_PARSER19_get_sensor_configsEv>
     d94:	4c c0       	rjmp	.+152    	; 0xe2e <_ZN13PACKET_PARSER6_parseEhhPv+0x148>
		return;

	case SENSOR_DATA_REPORT:
		_check_memory_space(sizeof(sensor_data_struct_t));
     d96:	ce 01       	movw	r24, r28
     d98:	68 e0       	ldi	r22, 0x08	; 8
     d9a:	70 e0       	ldi	r23, 0x00	; 0
     d9c:	91 df       	rcall	.-222    	; 0xcc0 <_ZN13PACKET_PARSER19_check_memory_spaceEj>
}

// --------------------------------------------------------------------
//! Allocate buffer
void PACKET_PARSER::_alloc_mem(void* dest_pointer, size_t size, void* buf) {
	memcpy(dest_pointer, buf, size);
     d9e:	de 01       	movw	r26, r28
     da0:	90 96       	adiw	r26, 0x20	; 32
     da2:	f8 01       	movw	r30, r16
     da4:	88 e0       	ldi	r24, 0x08	; 8
     da6:	01 90       	ld	r0, Z+
     da8:	0d 92       	st	X+, r0
     daa:	81 50       	subi	r24, 0x01	; 1
     dac:	e1 f7       	brne	.-8      	; 0xda6 <_ZN13PACKET_PARSER6_parseEhhPv+0xc0>
     dae:	3f c0       	rjmp	.+126    	; 0xe2e <_ZN13PACKET_PARSER6_parseEhhPv+0x148>
	case SENSOR_ERROR_REPORT:
		_alloc_mem(&_error, sizeof(_error), buffer);

#ifdef DEBUG
		sprintf(debug_info, "[%d] %d -> %d", _header.sensor_id, _error.error_code,
				_header.sensor_run_time);
     db0:	d8 01       	movw	r26, r16
     db2:	8c 91       	ld	r24, X
     db4:	88 8f       	std	Y+24, r24	; 0x18
     db6:	ed b7       	in	r30, 0x3d	; 61
     db8:	fe b7       	in	r31, 0x3e	; 62
     dba:	3c 97       	sbiw	r30, 0x0c	; 12
     dbc:	0f b6       	in	r0, 0x3f	; 63
     dbe:	f8 94       	cli
     dc0:	fe bf       	out	0x3e, r31	; 62
     dc2:	0f be       	out	0x3f, r0	; 63
     dc4:	ed bf       	out	0x3d, r30	; 61
     dc6:	31 96       	adiw	r30, 0x01	; 1
     dc8:	00 e0       	ldi	r16, 0x00	; 0
     dca:	10 e0       	ldi	r17, 0x00	; 0
     dcc:	ad b7       	in	r26, 0x3d	; 61
     dce:	be b7       	in	r27, 0x3e	; 62
     dd0:	12 96       	adiw	r26, 0x02	; 2
     dd2:	1c 93       	st	X, r17
     dd4:	0e 93       	st	-X, r16
     dd6:	11 97       	sbiw	r26, 0x01	; 1
     dd8:	8b ee       	ldi	r24, 0xEB	; 235
     dda:	93 e0       	ldi	r25, 0x03	; 3
     ddc:	93 83       	std	Z+3, r25	; 0x03
     dde:	82 83       	std	Z+2, r24	; 0x02
     de0:	8d 85       	ldd	r24, Y+13	; 0x0d
     de2:	84 83       	std	Z+4, r24	; 0x04
     de4:	15 82       	std	Z+5, r1	; 0x05
     de6:	88 8d       	ldd	r24, Y+24	; 0x18
     de8:	86 83       	std	Z+6, r24	; 0x06
     dea:	17 82       	std	Z+7, r1	; 0x07
     dec:	8e 85       	ldd	r24, Y+14	; 0x0e
     dee:	9f 85       	ldd	r25, Y+15	; 0x0f
     df0:	a8 89       	ldd	r26, Y+16	; 0x10
     df2:	b9 89       	ldd	r27, Y+17	; 0x11
     df4:	80 87       	std	Z+8, r24	; 0x08
     df6:	91 87       	std	Z+9, r25	; 0x09
     df8:	a2 87       	std	Z+10, r26	; 0x0a
     dfa:	b3 87       	std	Z+11, r27	; 0x0b
     dfc:	00 da       	rcall	.-3072   	; 0x1fe <sprintf>
		DEBUG_SERIAL.println(debug_info);
     dfe:	ed b7       	in	r30, 0x3d	; 61
     e00:	fe b7       	in	r31, 0x3e	; 62
     e02:	3c 96       	adiw	r30, 0x0c	; 12
     e04:	0f b6       	in	r0, 0x3f	; 63
     e06:	f8 94       	cli
     e08:	fe bf       	out	0x3e, r31	; 62
     e0a:	0f be       	out	0x3f, r0	; 63
     e0c:	ed bf       	out	0x3d, r30	; 61
     e0e:	8f e5       	ldi	r24, 0x5F	; 95
     e10:	97 e0       	ldi	r25, 0x07	; 7
     e12:	b8 01       	movw	r22, r16
     e14:	1b d7       	rcall	.+3638   	; 0x1c4c <_ZN5Print7printlnEPKc>
     e16:	0b c0       	rjmp	.+22     	; 0xe2e <_ZN13PACKET_PARSER6_parseEhhPv+0x148>
}

// --------------------------------------------------------------------
//! Allocate buffer
void PACKET_PARSER::_alloc_mem(void* dest_pointer, size_t size, void* buf) {
	memcpy(dest_pointer, buf, size);
     e18:	f8 01       	movw	r30, r16
     e1a:	80 81       	ld	r24, Z
     e1c:	91 81       	ldd	r25, Z+1	; 0x01
     e1e:	a2 81       	ldd	r26, Z+2	; 0x02
     e20:	b3 81       	ldd	r27, Z+3	; 0x03
     e22:	8c 8f       	std	Y+28, r24	; 0x1c
     e24:	9d 8f       	std	Y+29, r25	; 0x1d
     e26:	ae 8f       	std	Y+30, r26	; 0x1e
     e28:	bf 8f       	std	Y+31, r27	; 0x1f
#endif
		return;

	case SENSOR_SYNC_REPORT:
		_alloc_mem(&_sync, sizeof(_sync), buffer);
		_check_sensor_sync();
     e2a:	ce 01       	movw	r24, r28
     e2c:	c0 dc       	rcall	.-1664   	; 0x7ae <_ZN13PACKET_PARSER18_check_sensor_syncEv>
		return;

	default: //! Nothing done here -- discard the packet.
		return;
	}
}
     e2e:	df 91       	pop	r29
     e30:	cf 91       	pop	r28
     e32:	1f 91       	pop	r17
     e34:	0f 91       	pop	r16
     e36:	ff 90       	pop	r15
     e38:	08 95       	ret

00000e3a <_ZN13PACKET_PARSER5parseEPvhhS0_>:
//! Parse the structures.
void PACKET_PARSER::parse(void *arg, byte packet_id, byte packet_ver,
		void *buf) {
	
	//! Process String
	((PACKET_PARSER*) arg)->_parse(packet_id, packet_ver, buf);
     e3a:	55 cf       	rjmp	.-342    	; 0xce6 <_ZN13PACKET_PARSER6_parseEhhPv>
}
     e3c:	08 95       	ret

00000e3e <_ZN8WATCHDOG6_resetEv>:
                }
        }
}

//! Reset the watchog timer.
void WATCHDOG::_reset(void){
     e3e:	cf 93       	push	r28
     e40:	df 93       	push	r29
     e42:	ec 01       	movw	r28, r24
        //! Kill the alarm if it's going and swap the bug character back
        if (EMPTY != _last_alarm) {
     e44:	8c 81       	ldd	r24, Y+4	; 0x04
     e46:	9d 81       	ldd	r25, Y+5	; 0x05
     e48:	ae 81       	ldd	r26, Y+6	; 0x06
     e4a:	bf 81       	ldd	r27, Y+7	; 0x07
     e4c:	00 97       	sbiw	r24, 0x00	; 0
     e4e:	a1 05       	cpc	r26, r1
     e50:	b1 05       	cpc	r27, r1
     e52:	21 f0       	breq	.+8      	; 0xe5c <_ZN8WATCHDOG6_resetEv+0x1e>
                _last_alarm = 0;
     e54:	1c 82       	std	Y+4, r1	; 0x04
     e56:	1d 82       	std	Y+5, r1	; 0x05
     e58:	1e 82       	std	Y+6, r1	; 0x06
     e5a:	1f 82       	std	Y+7, r1	; 0x07
        }

        //! Remember when we saw this packet
        _last_time_stamp = millis();
     e5c:	ab d2       	rcall	.+1366   	; 0x13b4 <millis>
     e5e:	68 83       	st	Y, r22
     e60:	79 83       	std	Y+1, r23	; 0x01
     e62:	8a 83       	std	Y+2, r24	; 0x02
     e64:	9b 83       	std	Y+3, r25	; 0x03
}
     e66:	df 91       	pop	r29
     e68:	cf 91       	pop	r28
     e6a:	08 95       	ret

00000e6c <_ZN8WATCHDOG5resetEPvhhS0_>:
// Define the empty state
#define EMPTY		0x00

//! Reset the timer, accessible publicly.
void WATCHDOG::reset(void *arg, uint8_t packet_id, uint8_t pakcet_ver, void *packet_data) {
        ((WATCHDOG *)arg)->_reset();
     e6c:	e8 cf       	rjmp	.-48     	; 0xe3e <_ZN8WATCHDOG6_resetEv>
}
     e6e:	08 95       	ret

00000e70 <_ZN11RFBEE_STACKC1EP5NVRAM>:
#define MATCH		0x00
#define RX_BUF		0x01
#define TIMEOUT		10000

// Init class
RFBEE_STACK::RFBEE_STACK(NVRAM* nvram_object){
     e70:	fc 01       	movw	r30, r24

	this->nvram_object = nvram_object;
     e72:	73 83       	std	Z+3, r23	; 0x03
     e74:	62 83       	std	Z+2, r22	; 0x02
	this->error_flag = true;
     e76:	81 e0       	ldi	r24, 0x01	; 1
     e78:	84 83       	std	Z+4, r24	; 0x04
}
     e7a:	08 95       	ret

00000e7c <_ZN11RFBEE_STACK17check_rfbee_stateEv>:

// Check rfbee intergrity
boolean RFBEE_STACK::check_rfbee_state(){
     e7c:	20 e0       	ldi	r18, 0x00	; 0
     e7e:	fc 01       	movw	r30, r24
     e80:	84 81       	ldd	r24, Z+4	; 0x04
     e82:	88 23       	and	r24, r24
     e84:	09 f4       	brne	.+2      	; 0xe88 <_ZN11RFBEE_STACK17check_rfbee_stateEv+0xc>
     e86:	21 e0       	ldi	r18, 0x01	; 1
	
	if(this->error_flag)
		return false;
		
	return true;
}
     e88:	82 2f       	mov	r24, r18
     e8a:	08 95       	ret

00000e8c <_ZN9SCHEDULER22_check_scheduler_stateEv>:
	// We go back to the init scheduler
	_init_scheduler();
}

// This checks the status of the scheduler
boolean SCHEDULER::_check_scheduler_state(){
     e8c:	20 e0       	ldi	r18, 0x00	; 0
     e8e:	fc 01       	movw	r30, r24
     e90:	85 85       	ldd	r24, Z+13	; 0x0d
     e92:	96 85       	ldd	r25, Z+14	; 0x0e
     e94:	05 97       	sbiw	r24, 0x05	; 5
     e96:	02 97       	sbiw	r24, 0x02	; 2
     e98:	08 f0       	brcs	.+2      	; 0xe9c <_ZN9SCHEDULER22_check_scheduler_stateEv+0x10>
     e9a:	21 e0       	ldi	r18, 0x01	; 1
	
	if((this->state == RESET_STATE) || (this->state == ERROR_STATE))
		return false;
		
	return true;
}
     e9c:	82 2f       	mov	r24, r18
     e9e:	08 95       	ret

00000ea0 <_ZN9SCHEDULERC1EP6SENSORP14COMMAND_PARSERP14PACKET_HANDLER>:
#include "Scheduler.h"


// default constructor
SCHEDULER::SCHEDULER(SENSOR* sensors, COMMAND_PARSER* command_int, 
	PACKET_HANDLER* handler){
     ea0:	af 92       	push	r10
     ea2:	bf 92       	push	r11
     ea4:	cf 92       	push	r12
     ea6:	df 92       	push	r13
     ea8:	ef 92       	push	r14
     eaa:	ff 92       	push	r15
     eac:	0f 93       	push	r16
     eae:	1f 93       	push	r17
     eb0:	8c 01       	movw	r16, r24
     eb2:	7b 01       	movw	r14, r22
     eb4:	6a 01       	movw	r12, r20
     eb6:	59 01       	movw	r10, r18
	
	this->state = INIT_STATE;
     eb8:	fc 01       	movw	r30, r24
     eba:	16 86       	std	Z+14, r1	; 0x0e
     ebc:	15 86       	std	Z+13, r1	; 0x0d
	this->uuid = random(255);
     ebe:	6f ef       	ldi	r22, 0xFF	; 255
     ec0:	70 e0       	ldi	r23, 0x00	; 0
     ec2:	80 e0       	ldi	r24, 0x00	; 0
     ec4:	90 e0       	ldi	r25, 0x00	; 0
     ec6:	d3 d6       	rcall	.+3494   	; 0x1c6e <_Z6randoml>
     ec8:	f8 01       	movw	r30, r16
     eca:	64 87       	std	Z+12, r22	; 0x0c
	this->sensors = sensors;
     ecc:	f0 8a       	std	Z+16, r15	; 0x10
     ece:	e7 86       	std	Z+15, r14	; 0x0f
	this->command_int = command_int;
     ed0:	d2 8a       	std	Z+18, r13	; 0x12
     ed2:	c1 8a       	std	Z+17, r12	; 0x11
	this->handler = handler;
     ed4:	b6 8a       	std	Z+22, r11	; 0x16
     ed6:	a5 8a       	std	Z+21, r10	; 0x15

	
} //Scheduler
     ed8:	1f 91       	pop	r17
     eda:	0f 91       	pop	r16
     edc:	ff 90       	pop	r15
     ede:	ef 90       	pop	r14
     ee0:	df 90       	pop	r13
     ee2:	cf 90       	pop	r12
     ee4:	bf 90       	pop	r11
     ee6:	af 90       	pop	r10
     ee8:	08 95       	ret

00000eea <_ZN6SENSORC1Ev>:
     eea:	08 95       	ret

00000eec <_ZN6SENSOR24check_sensor_environmentEv>:
		return true;
	else
		return false;	
}
	
boolean SENSOR::check_sensor_environment(){
     eec:	fc 01       	movw	r30, r24
	
	// we check the error code field first
	if(this->sensor_error_code > 0){
     eee:	80 85       	ldd	r24, Z+8	; 0x08
     ef0:	88 23       	and	r24, r24
     ef2:	11 f0       	breq	.+4      	; 0xef8 <_ZN6SENSOR24check_sensor_environmentEv+0xc>
     ef4:	20 e0       	ldi	r18, 0x00	; 0
     ef6:	06 c0       	rjmp	.+12     	; 0xf04 <_ZN6SENSOR24check_sensor_environmentEv+0x18>
     ef8:	20 e0       	ldi	r18, 0x00	; 0
     efa:	81 85       	ldd	r24, Z+9	; 0x09
     efc:	92 85       	ldd	r25, Z+10	; 0x0a
     efe:	07 97       	sbiw	r24, 0x07	; 7
     f00:	09 f0       	breq	.+2      	; 0xf04 <_ZN6SENSOR24check_sensor_environmentEv+0x18>
     f02:	21 e0       	ldi	r18, 0x01	; 1
		#ifdef DEBUG
			DEBUG_SERIAL.println("[SENSOR %d] Error", this->sensor_id);
		#endif
		
	return true;
}
     f04:	82 2f       	mov	r24, r18
     f06:	08 95       	ret

00000f08 <_ZN6SENSOR9set_stateE14sensor_state_t>:

// Sets the state externally
void SENSOR::set_state(sensor_state_t state){
	this->state = state;
     f08:	fc 01       	movw	r30, r24
     f0a:	72 87       	std	Z+10, r23	; 0x0a
     f0c:	61 87       	std	Z+9, r22	; 0x09
}
     f0e:	08 95       	ret

00000f10 <_ZN6SENSOR14set_error_codeEh>:

sensor_state_t SENSOR::get_state(){
	return this->state;
}

void SENSOR::set_error_code(byte error_code){
     f10:	fc 01       	movw	r30, r24
	this->sensor_error_code = error_code;
     f12:	60 87       	std	Z+8, r22	; 0x08
	this->state = ERROR_SENSOR_STATE;
     f14:	87 e0       	ldi	r24, 0x07	; 7
     f16:	90 e0       	ldi	r25, 0x00	; 0
     f18:	92 87       	std	Z+10, r25	; 0x0a
     f1a:	81 87       	std	Z+9, r24	; 0x09
     f1c:	08 95       	ret

00000f1e <_GLOBAL__I_eeprom>:
	base_station_mode = nvram_object->nv.device_mode;
	
	#ifdef DEBUG
		DEBUG_SERIAL.println("NVRAM READ");
	#endif
}
     f1e:	af 92       	push	r10
     f20:	bf 92       	push	r11
     f22:	cf 92       	push	r12
     f24:	df 92       	push	r13
     f26:	ef 92       	push	r14
     f28:	ff 92       	push	r15
     f2a:	0f 93       	push	r16
     f2c:	1f 93       	push	r17
     f2e:	2e e9       	ldi	r18, 0x9E	; 158
     f30:	c2 2e       	mov	r12, r18
     f32:	24 e0       	ldi	r18, 0x04	; 4
     f34:	d2 2e       	mov	r13, r18
     f36:	c6 01       	movw	r24, r12
     f38:	d8 df       	rcall	.-80     	; 0xeea <_ZN6SENSORC1Ev>
     f3a:	89 ea       	ldi	r24, 0xA9	; 169
     f3c:	94 e0       	ldi	r25, 0x04	; 4
     f3e:	b6 01       	movw	r22, r12
     f40:	20 dc       	rcall	.-1984   	; 0x782 <_ZN13PACKET_PARSERC1EP6SENSOR>
     f42:	01 ed       	ldi	r16, 0xD1	; 209
     f44:	14 e0       	ldi	r17, 0x04	; 4
     f46:	c8 01       	movw	r24, r16
     f48:	6d ef       	ldi	r22, 0xFD	; 253
     f4a:	73 e0       	ldi	r23, 0x03	; 3
     f4c:	0a dc       	rcall	.-2028   	; 0x762 <_ZN14PACKET_HANDLERC1EPv>
     f4e:	97 ee       	ldi	r25, 0xE7	; 231
     f50:	a9 2e       	mov	r10, r25
     f52:	94 e0       	ldi	r25, 0x04	; 4
     f54:	b9 2e       	mov	r11, r25
     f56:	8f e3       	ldi	r24, 0x3F	; 63
     f58:	e8 2e       	mov	r14, r24
     f5a:	84 e0       	ldi	r24, 0x04	; 4
     f5c:	f8 2e       	mov	r15, r24
     f5e:	c5 01       	movw	r24, r10
     f60:	b7 01       	movw	r22, r14
     f62:	a8 01       	movw	r20, r16
     f64:	df db       	rcall	.-2114   	; 0x724 <_ZN14COMMAND_PARSERC1EP5NVRAMP14PACKET_HANDLER>
     f66:	81 ef       	ldi	r24, 0xF1	; 241
     f68:	94 e0       	ldi	r25, 0x04	; 4
     f6a:	b7 01       	movw	r22, r14
     f6c:	81 df       	rcall	.-254    	; 0xe70 <_ZN11RFBEE_STACKC1EP5NVRAM>
     f6e:	8a e0       	ldi	r24, 0x0A	; 10
     f70:	95 e0       	ldi	r25, 0x05	; 5
     f72:	b6 01       	movw	r22, r12
     f74:	a5 01       	movw	r20, r10
     f76:	98 01       	movw	r18, r16
     f78:	93 df       	rcall	.-218    	; 0xea0 <_ZN9SCHEDULERC1EP6SENSORP14COMMAND_PARSERP14PACKET_HANDLER>
     f7a:	1f 91       	pop	r17
     f7c:	0f 91       	pop	r16
     f7e:	ff 90       	pop	r15
     f80:	ef 90       	pop	r14
     f82:	df 90       	pop	r13
     f84:	cf 90       	pop	r12
     f86:	bf 90       	pop	r11
     f88:	af 90       	pop	r10
     f8a:	08 95       	ret

00000f8c <__vector_20>:
     f8c:	1f 92       	push	r1
     f8e:	0f 92       	push	r0
     f90:	0f b6       	in	r0, 0x3f	; 63
     f92:	0f 92       	push	r0
     f94:	0b b6       	in	r0, 0x3b	; 59
     f96:	0f 92       	push	r0
     f98:	11 24       	eor	r1, r1
     f9a:	2f 93       	push	r18
     f9c:	3f 93       	push	r19
     f9e:	4f 93       	push	r20
     fa0:	5f 93       	push	r21
     fa2:	6f 93       	push	r22
     fa4:	7f 93       	push	r23
     fa6:	8f 93       	push	r24
     fa8:	9f 93       	push	r25
     faa:	af 93       	push	r26
     fac:	bf 93       	push	r27
     fae:	ef 93       	push	r30
     fb0:	ff 93       	push	r31
     fb2:	88 e9       	ldi	r24, 0x98	; 152
     fb4:	96 e7       	ldi	r25, 0x76	; 118
     fb6:	90 93 85 00 	sts	0x0085, r25
     fba:	80 93 84 00 	sts	0x0084, r24
     fbe:	8e e9       	ldi	r24, 0x9E	; 158
     fc0:	94 e0       	ldi	r25, 0x04	; 4
     fc2:	94 df       	rcall	.-216    	; 0xeec <_ZN6SENSOR24check_sensor_environmentEv>
     fc4:	88 23       	and	r24, r24
     fc6:	19 f4       	brne	.+6      	; 0xfce <__vector_20+0x42>
     fc8:	81 e0       	ldi	r24, 0x01	; 1
     fca:	80 93 25 05 	sts	0x0525, r24
     fce:	8a e0       	ldi	r24, 0x0A	; 10
     fd0:	95 e0       	ldi	r25, 0x05	; 5
     fd2:	5c df       	rcall	.-328    	; 0xe8c <_ZN9SCHEDULER22_check_scheduler_stateEv>
     fd4:	88 23       	and	r24, r24
     fd6:	19 f4       	brne	.+6      	; 0xfde <__vector_20+0x52>
     fd8:	81 e0       	ldi	r24, 0x01	; 1
     fda:	80 93 25 05 	sts	0x0525, r24
     fde:	81 ef       	ldi	r24, 0xF1	; 241
     fe0:	94 e0       	ldi	r25, 0x04	; 4
     fe2:	4c df       	rcall	.-360    	; 0xe7c <_ZN11RFBEE_STACK17check_rfbee_stateEv>
     fe4:	88 23       	and	r24, r24
     fe6:	19 f4       	brne	.+6      	; 0xfee <__vector_20+0x62>
     fe8:	81 e0       	ldi	r24, 0x01	; 1
     fea:	80 93 25 05 	sts	0x0525, r24
     fee:	ff 91       	pop	r31
     ff0:	ef 91       	pop	r30
     ff2:	bf 91       	pop	r27
     ff4:	af 91       	pop	r26
     ff6:	9f 91       	pop	r25
     ff8:	8f 91       	pop	r24
     ffa:	7f 91       	pop	r23
     ffc:	6f 91       	pop	r22
     ffe:	5f 91       	pop	r21
    1000:	4f 91       	pop	r20
    1002:	3f 91       	pop	r19
    1004:	2f 91       	pop	r18
    1006:	0f 90       	pop	r0
    1008:	0b be       	out	0x3b, r0	; 59
    100a:	0f 90       	pop	r0
    100c:	0f be       	out	0x3f, r0	; 63
    100e:	0f 90       	pop	r0
    1010:	1f 90       	pop	r1
    1012:	18 95       	reti

00001014 <__vector_1>:
		intFunc[EXTERNAL_INT_4]();
}

#elif defined(EICRA) && defined(EICRB)

ISR(INT0_vect) {
    1014:	1f 92       	push	r1
    1016:	0f 92       	push	r0
    1018:	0f b6       	in	r0, 0x3f	; 63
    101a:	0f 92       	push	r0
    101c:	0b b6       	in	r0, 0x3b	; 59
    101e:	0f 92       	push	r0
    1020:	11 24       	eor	r1, r1
    1022:	2f 93       	push	r18
    1024:	3f 93       	push	r19
    1026:	4f 93       	push	r20
    1028:	5f 93       	push	r21
    102a:	6f 93       	push	r22
    102c:	7f 93       	push	r23
    102e:	8f 93       	push	r24
    1030:	9f 93       	push	r25
    1032:	af 93       	push	r26
    1034:	bf 93       	push	r27
    1036:	ef 93       	push	r30
    1038:	ff 93       	push	r31
  if(intFunc[EXTERNAL_INT_2])
    103a:	80 91 2a 05 	lds	r24, 0x052A
    103e:	90 91 2b 05 	lds	r25, 0x052B
    1042:	89 2b       	or	r24, r25
    1044:	29 f0       	breq	.+10     	; 0x1050 <__vector_1+0x3c>
    intFunc[EXTERNAL_INT_2]();
    1046:	e0 91 2a 05 	lds	r30, 0x052A
    104a:	f0 91 2b 05 	lds	r31, 0x052B
    104e:	19 95       	eicall
}
    1050:	ff 91       	pop	r31
    1052:	ef 91       	pop	r30
    1054:	bf 91       	pop	r27
    1056:	af 91       	pop	r26
    1058:	9f 91       	pop	r25
    105a:	8f 91       	pop	r24
    105c:	7f 91       	pop	r23
    105e:	6f 91       	pop	r22
    1060:	5f 91       	pop	r21
    1062:	4f 91       	pop	r20
    1064:	3f 91       	pop	r19
    1066:	2f 91       	pop	r18
    1068:	0f 90       	pop	r0
    106a:	0b be       	out	0x3b, r0	; 59
    106c:	0f 90       	pop	r0
    106e:	0f be       	out	0x3f, r0	; 63
    1070:	0f 90       	pop	r0
    1072:	1f 90       	pop	r1
    1074:	18 95       	reti

00001076 <__vector_2>:

ISR(INT1_vect) {
    1076:	1f 92       	push	r1
    1078:	0f 92       	push	r0
    107a:	0f b6       	in	r0, 0x3f	; 63
    107c:	0f 92       	push	r0
    107e:	0b b6       	in	r0, 0x3b	; 59
    1080:	0f 92       	push	r0
    1082:	11 24       	eor	r1, r1
    1084:	2f 93       	push	r18
    1086:	3f 93       	push	r19
    1088:	4f 93       	push	r20
    108a:	5f 93       	push	r21
    108c:	6f 93       	push	r22
    108e:	7f 93       	push	r23
    1090:	8f 93       	push	r24
    1092:	9f 93       	push	r25
    1094:	af 93       	push	r26
    1096:	bf 93       	push	r27
    1098:	ef 93       	push	r30
    109a:	ff 93       	push	r31
  if(intFunc[EXTERNAL_INT_3])
    109c:	80 91 2c 05 	lds	r24, 0x052C
    10a0:	90 91 2d 05 	lds	r25, 0x052D
    10a4:	89 2b       	or	r24, r25
    10a6:	29 f0       	breq	.+10     	; 0x10b2 <__vector_2+0x3c>
    intFunc[EXTERNAL_INT_3]();
    10a8:	e0 91 2c 05 	lds	r30, 0x052C
    10ac:	f0 91 2d 05 	lds	r31, 0x052D
    10b0:	19 95       	eicall
}
    10b2:	ff 91       	pop	r31
    10b4:	ef 91       	pop	r30
    10b6:	bf 91       	pop	r27
    10b8:	af 91       	pop	r26
    10ba:	9f 91       	pop	r25
    10bc:	8f 91       	pop	r24
    10be:	7f 91       	pop	r23
    10c0:	6f 91       	pop	r22
    10c2:	5f 91       	pop	r21
    10c4:	4f 91       	pop	r20
    10c6:	3f 91       	pop	r19
    10c8:	2f 91       	pop	r18
    10ca:	0f 90       	pop	r0
    10cc:	0b be       	out	0x3b, r0	; 59
    10ce:	0f 90       	pop	r0
    10d0:	0f be       	out	0x3f, r0	; 63
    10d2:	0f 90       	pop	r0
    10d4:	1f 90       	pop	r1
    10d6:	18 95       	reti

000010d8 <__vector_3>:

ISR(INT2_vect) {
    10d8:	1f 92       	push	r1
    10da:	0f 92       	push	r0
    10dc:	0f b6       	in	r0, 0x3f	; 63
    10de:	0f 92       	push	r0
    10e0:	0b b6       	in	r0, 0x3b	; 59
    10e2:	0f 92       	push	r0
    10e4:	11 24       	eor	r1, r1
    10e6:	2f 93       	push	r18
    10e8:	3f 93       	push	r19
    10ea:	4f 93       	push	r20
    10ec:	5f 93       	push	r21
    10ee:	6f 93       	push	r22
    10f0:	7f 93       	push	r23
    10f2:	8f 93       	push	r24
    10f4:	9f 93       	push	r25
    10f6:	af 93       	push	r26
    10f8:	bf 93       	push	r27
    10fa:	ef 93       	push	r30
    10fc:	ff 93       	push	r31
  if(intFunc[EXTERNAL_INT_4])
    10fe:	80 91 2e 05 	lds	r24, 0x052E
    1102:	90 91 2f 05 	lds	r25, 0x052F
    1106:	89 2b       	or	r24, r25
    1108:	29 f0       	breq	.+10     	; 0x1114 <__vector_3+0x3c>
    intFunc[EXTERNAL_INT_4]();
    110a:	e0 91 2e 05 	lds	r30, 0x052E
    110e:	f0 91 2f 05 	lds	r31, 0x052F
    1112:	19 95       	eicall
}
    1114:	ff 91       	pop	r31
    1116:	ef 91       	pop	r30
    1118:	bf 91       	pop	r27
    111a:	af 91       	pop	r26
    111c:	9f 91       	pop	r25
    111e:	8f 91       	pop	r24
    1120:	7f 91       	pop	r23
    1122:	6f 91       	pop	r22
    1124:	5f 91       	pop	r21
    1126:	4f 91       	pop	r20
    1128:	3f 91       	pop	r19
    112a:	2f 91       	pop	r18
    112c:	0f 90       	pop	r0
    112e:	0b be       	out	0x3b, r0	; 59
    1130:	0f 90       	pop	r0
    1132:	0f be       	out	0x3f, r0	; 63
    1134:	0f 90       	pop	r0
    1136:	1f 90       	pop	r1
    1138:	18 95       	reti

0000113a <__vector_4>:

ISR(INT3_vect) {
    113a:	1f 92       	push	r1
    113c:	0f 92       	push	r0
    113e:	0f b6       	in	r0, 0x3f	; 63
    1140:	0f 92       	push	r0
    1142:	0b b6       	in	r0, 0x3b	; 59
    1144:	0f 92       	push	r0
    1146:	11 24       	eor	r1, r1
    1148:	2f 93       	push	r18
    114a:	3f 93       	push	r19
    114c:	4f 93       	push	r20
    114e:	5f 93       	push	r21
    1150:	6f 93       	push	r22
    1152:	7f 93       	push	r23
    1154:	8f 93       	push	r24
    1156:	9f 93       	push	r25
    1158:	af 93       	push	r26
    115a:	bf 93       	push	r27
    115c:	ef 93       	push	r30
    115e:	ff 93       	push	r31
  if(intFunc[EXTERNAL_INT_5])
    1160:	80 91 30 05 	lds	r24, 0x0530
    1164:	90 91 31 05 	lds	r25, 0x0531
    1168:	89 2b       	or	r24, r25
    116a:	29 f0       	breq	.+10     	; 0x1176 <__vector_4+0x3c>
    intFunc[EXTERNAL_INT_5]();
    116c:	e0 91 30 05 	lds	r30, 0x0530
    1170:	f0 91 31 05 	lds	r31, 0x0531
    1174:	19 95       	eicall
}
    1176:	ff 91       	pop	r31
    1178:	ef 91       	pop	r30
    117a:	bf 91       	pop	r27
    117c:	af 91       	pop	r26
    117e:	9f 91       	pop	r25
    1180:	8f 91       	pop	r24
    1182:	7f 91       	pop	r23
    1184:	6f 91       	pop	r22
    1186:	5f 91       	pop	r21
    1188:	4f 91       	pop	r20
    118a:	3f 91       	pop	r19
    118c:	2f 91       	pop	r18
    118e:	0f 90       	pop	r0
    1190:	0b be       	out	0x3b, r0	; 59
    1192:	0f 90       	pop	r0
    1194:	0f be       	out	0x3f, r0	; 63
    1196:	0f 90       	pop	r0
    1198:	1f 90       	pop	r1
    119a:	18 95       	reti

0000119c <__vector_5>:

ISR(INT4_vect) {
    119c:	1f 92       	push	r1
    119e:	0f 92       	push	r0
    11a0:	0f b6       	in	r0, 0x3f	; 63
    11a2:	0f 92       	push	r0
    11a4:	0b b6       	in	r0, 0x3b	; 59
    11a6:	0f 92       	push	r0
    11a8:	11 24       	eor	r1, r1
    11aa:	2f 93       	push	r18
    11ac:	3f 93       	push	r19
    11ae:	4f 93       	push	r20
    11b0:	5f 93       	push	r21
    11b2:	6f 93       	push	r22
    11b4:	7f 93       	push	r23
    11b6:	8f 93       	push	r24
    11b8:	9f 93       	push	r25
    11ba:	af 93       	push	r26
    11bc:	bf 93       	push	r27
    11be:	ef 93       	push	r30
    11c0:	ff 93       	push	r31
  if(intFunc[EXTERNAL_INT_0])
    11c2:	80 91 26 05 	lds	r24, 0x0526
    11c6:	90 91 27 05 	lds	r25, 0x0527
    11ca:	89 2b       	or	r24, r25
    11cc:	29 f0       	breq	.+10     	; 0x11d8 <__vector_5+0x3c>
    intFunc[EXTERNAL_INT_0]();
    11ce:	e0 91 26 05 	lds	r30, 0x0526
    11d2:	f0 91 27 05 	lds	r31, 0x0527
    11d6:	19 95       	eicall
}
    11d8:	ff 91       	pop	r31
    11da:	ef 91       	pop	r30
    11dc:	bf 91       	pop	r27
    11de:	af 91       	pop	r26
    11e0:	9f 91       	pop	r25
    11e2:	8f 91       	pop	r24
    11e4:	7f 91       	pop	r23
    11e6:	6f 91       	pop	r22
    11e8:	5f 91       	pop	r21
    11ea:	4f 91       	pop	r20
    11ec:	3f 91       	pop	r19
    11ee:	2f 91       	pop	r18
    11f0:	0f 90       	pop	r0
    11f2:	0b be       	out	0x3b, r0	; 59
    11f4:	0f 90       	pop	r0
    11f6:	0f be       	out	0x3f, r0	; 63
    11f8:	0f 90       	pop	r0
    11fa:	1f 90       	pop	r1
    11fc:	18 95       	reti

000011fe <__vector_6>:

ISR(INT5_vect) {
    11fe:	1f 92       	push	r1
    1200:	0f 92       	push	r0
    1202:	0f b6       	in	r0, 0x3f	; 63
    1204:	0f 92       	push	r0
    1206:	0b b6       	in	r0, 0x3b	; 59
    1208:	0f 92       	push	r0
    120a:	11 24       	eor	r1, r1
    120c:	2f 93       	push	r18
    120e:	3f 93       	push	r19
    1210:	4f 93       	push	r20
    1212:	5f 93       	push	r21
    1214:	6f 93       	push	r22
    1216:	7f 93       	push	r23
    1218:	8f 93       	push	r24
    121a:	9f 93       	push	r25
    121c:	af 93       	push	r26
    121e:	bf 93       	push	r27
    1220:	ef 93       	push	r30
    1222:	ff 93       	push	r31
  if(intFunc[EXTERNAL_INT_1])
    1224:	80 91 28 05 	lds	r24, 0x0528
    1228:	90 91 29 05 	lds	r25, 0x0529
    122c:	89 2b       	or	r24, r25
    122e:	29 f0       	breq	.+10     	; 0x123a <__vector_6+0x3c>
    intFunc[EXTERNAL_INT_1]();
    1230:	e0 91 28 05 	lds	r30, 0x0528
    1234:	f0 91 29 05 	lds	r31, 0x0529
    1238:	19 95       	eicall
}
    123a:	ff 91       	pop	r31
    123c:	ef 91       	pop	r30
    123e:	bf 91       	pop	r27
    1240:	af 91       	pop	r26
    1242:	9f 91       	pop	r25
    1244:	8f 91       	pop	r24
    1246:	7f 91       	pop	r23
    1248:	6f 91       	pop	r22
    124a:	5f 91       	pop	r21
    124c:	4f 91       	pop	r20
    124e:	3f 91       	pop	r19
    1250:	2f 91       	pop	r18
    1252:	0f 90       	pop	r0
    1254:	0b be       	out	0x3b, r0	; 59
    1256:	0f 90       	pop	r0
    1258:	0f be       	out	0x3f, r0	; 63
    125a:	0f 90       	pop	r0
    125c:	1f 90       	pop	r1
    125e:	18 95       	reti

00001260 <__vector_7>:

ISR(INT6_vect) {
    1260:	1f 92       	push	r1
    1262:	0f 92       	push	r0
    1264:	0f b6       	in	r0, 0x3f	; 63
    1266:	0f 92       	push	r0
    1268:	0b b6       	in	r0, 0x3b	; 59
    126a:	0f 92       	push	r0
    126c:	11 24       	eor	r1, r1
    126e:	2f 93       	push	r18
    1270:	3f 93       	push	r19
    1272:	4f 93       	push	r20
    1274:	5f 93       	push	r21
    1276:	6f 93       	push	r22
    1278:	7f 93       	push	r23
    127a:	8f 93       	push	r24
    127c:	9f 93       	push	r25
    127e:	af 93       	push	r26
    1280:	bf 93       	push	r27
    1282:	ef 93       	push	r30
    1284:	ff 93       	push	r31
  if(intFunc[EXTERNAL_INT_6])
    1286:	80 91 32 05 	lds	r24, 0x0532
    128a:	90 91 33 05 	lds	r25, 0x0533
    128e:	89 2b       	or	r24, r25
    1290:	29 f0       	breq	.+10     	; 0x129c <__vector_7+0x3c>
    intFunc[EXTERNAL_INT_6]();
    1292:	e0 91 32 05 	lds	r30, 0x0532
    1296:	f0 91 33 05 	lds	r31, 0x0533
    129a:	19 95       	eicall
}
    129c:	ff 91       	pop	r31
    129e:	ef 91       	pop	r30
    12a0:	bf 91       	pop	r27
    12a2:	af 91       	pop	r26
    12a4:	9f 91       	pop	r25
    12a6:	8f 91       	pop	r24
    12a8:	7f 91       	pop	r23
    12aa:	6f 91       	pop	r22
    12ac:	5f 91       	pop	r21
    12ae:	4f 91       	pop	r20
    12b0:	3f 91       	pop	r19
    12b2:	2f 91       	pop	r18
    12b4:	0f 90       	pop	r0
    12b6:	0b be       	out	0x3b, r0	; 59
    12b8:	0f 90       	pop	r0
    12ba:	0f be       	out	0x3f, r0	; 63
    12bc:	0f 90       	pop	r0
    12be:	1f 90       	pop	r1
    12c0:	18 95       	reti

000012c2 <__vector_8>:

ISR(INT7_vect) {
    12c2:	1f 92       	push	r1
    12c4:	0f 92       	push	r0
    12c6:	0f b6       	in	r0, 0x3f	; 63
    12c8:	0f 92       	push	r0
    12ca:	0b b6       	in	r0, 0x3b	; 59
    12cc:	0f 92       	push	r0
    12ce:	11 24       	eor	r1, r1
    12d0:	2f 93       	push	r18
    12d2:	3f 93       	push	r19
    12d4:	4f 93       	push	r20
    12d6:	5f 93       	push	r21
    12d8:	6f 93       	push	r22
    12da:	7f 93       	push	r23
    12dc:	8f 93       	push	r24
    12de:	9f 93       	push	r25
    12e0:	af 93       	push	r26
    12e2:	bf 93       	push	r27
    12e4:	ef 93       	push	r30
    12e6:	ff 93       	push	r31
  if(intFunc[EXTERNAL_INT_7])
    12e8:	80 91 34 05 	lds	r24, 0x0534
    12ec:	90 91 35 05 	lds	r25, 0x0535
    12f0:	89 2b       	or	r24, r25
    12f2:	29 f0       	breq	.+10     	; 0x12fe <__vector_8+0x3c>
    intFunc[EXTERNAL_INT_7]();
    12f4:	e0 91 34 05 	lds	r30, 0x0534
    12f8:	f0 91 35 05 	lds	r31, 0x0535
    12fc:	19 95       	eicall
}
    12fe:	ff 91       	pop	r31
    1300:	ef 91       	pop	r30
    1302:	bf 91       	pop	r27
    1304:	af 91       	pop	r26
    1306:	9f 91       	pop	r25
    1308:	8f 91       	pop	r24
    130a:	7f 91       	pop	r23
    130c:	6f 91       	pop	r22
    130e:	5f 91       	pop	r21
    1310:	4f 91       	pop	r20
    1312:	3f 91       	pop	r19
    1314:	2f 91       	pop	r18
    1316:	0f 90       	pop	r0
    1318:	0b be       	out	0x3b, r0	; 59
    131a:	0f 90       	pop	r0
    131c:	0f be       	out	0x3f, r0	; 63
    131e:	0f 90       	pop	r0
    1320:	1f 90       	pop	r1
    1322:	18 95       	reti

00001324 <__vector_23>:
#if defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
ISR(TIM0_OVF_vect)
#else
ISR(TIMER0_OVF_vect)
#endif
{
    1324:	1f 92       	push	r1
    1326:	0f 92       	push	r0
    1328:	0f b6       	in	r0, 0x3f	; 63
    132a:	0f 92       	push	r0
    132c:	11 24       	eor	r1, r1
    132e:	2f 93       	push	r18
    1330:	3f 93       	push	r19
    1332:	8f 93       	push	r24
    1334:	9f 93       	push	r25
    1336:	af 93       	push	r26
    1338:	bf 93       	push	r27
	// copy these to local variables so they can be stored in registers
	// (volatile variables must be read from memory on every access)
	unsigned long m = timer0_millis;
    133a:	80 91 3a 05 	lds	r24, 0x053A
    133e:	90 91 3b 05 	lds	r25, 0x053B
    1342:	a0 91 3c 05 	lds	r26, 0x053C
    1346:	b0 91 3d 05 	lds	r27, 0x053D
	unsigned char f = timer0_fract;
    134a:	30 91 3e 05 	lds	r19, 0x053E

	m += MILLIS_INC;
    134e:	01 96       	adiw	r24, 0x01	; 1
    1350:	a1 1d       	adc	r26, r1
    1352:	b1 1d       	adc	r27, r1
	f += FRACT_INC;
    1354:	23 2f       	mov	r18, r19
    1356:	2d 5f       	subi	r18, 0xFD	; 253
	if (f >= FRACT_MAX) {
    1358:	2d 37       	cpi	r18, 0x7D	; 125
    135a:	20 f0       	brcs	.+8      	; 0x1364 <__vector_23+0x40>
		f -= FRACT_MAX;
    135c:	2d 57       	subi	r18, 0x7D	; 125
		m += 1;
    135e:	01 96       	adiw	r24, 0x01	; 1
    1360:	a1 1d       	adc	r26, r1
    1362:	b1 1d       	adc	r27, r1
	}

	timer0_fract = f;
    1364:	20 93 3e 05 	sts	0x053E, r18
	timer0_millis = m;
    1368:	80 93 3a 05 	sts	0x053A, r24
    136c:	90 93 3b 05 	sts	0x053B, r25
    1370:	a0 93 3c 05 	sts	0x053C, r26
    1374:	b0 93 3d 05 	sts	0x053D, r27
	timer0_overflow_count++;
    1378:	80 91 36 05 	lds	r24, 0x0536
    137c:	90 91 37 05 	lds	r25, 0x0537
    1380:	a0 91 38 05 	lds	r26, 0x0538
    1384:	b0 91 39 05 	lds	r27, 0x0539
    1388:	01 96       	adiw	r24, 0x01	; 1
    138a:	a1 1d       	adc	r26, r1
    138c:	b1 1d       	adc	r27, r1
    138e:	80 93 36 05 	sts	0x0536, r24
    1392:	90 93 37 05 	sts	0x0537, r25
    1396:	a0 93 38 05 	sts	0x0538, r26
    139a:	b0 93 39 05 	sts	0x0539, r27
}
    139e:	bf 91       	pop	r27
    13a0:	af 91       	pop	r26
    13a2:	9f 91       	pop	r25
    13a4:	8f 91       	pop	r24
    13a6:	3f 91       	pop	r19
    13a8:	2f 91       	pop	r18
    13aa:	0f 90       	pop	r0
    13ac:	0f be       	out	0x3f, r0	; 63
    13ae:	0f 90       	pop	r0
    13b0:	1f 90       	pop	r1
    13b2:	18 95       	reti

000013b4 <millis>:

unsigned long millis()
{
	unsigned long m;
	uint8_t oldSREG = SREG;
    13b4:	8f b7       	in	r24, 0x3f	; 63

	// disable interrupts while we read timer0_millis or we might get an
	// inconsistent value (e.g. in the middle of a write to timer0_millis)
	cli();
    13b6:	f8 94       	cli
	m = timer0_millis;
    13b8:	20 91 3a 05 	lds	r18, 0x053A
    13bc:	30 91 3b 05 	lds	r19, 0x053B
    13c0:	40 91 3c 05 	lds	r20, 0x053C
    13c4:	50 91 3d 05 	lds	r21, 0x053D
	SREG = oldSREG;
    13c8:	8f bf       	out	0x3f, r24	; 63

	return m;
}
    13ca:	b9 01       	movw	r22, r18
    13cc:	ca 01       	movw	r24, r20
    13ce:	08 95       	ret

000013d0 <__vector_25>:
  #define serialEvent_implemented
#if defined(USART_RX_vect)
  ISR(USART_RX_vect)
#elif defined(USART0_RX_vect)
  ISR(USART0_RX_vect)
    13d0:	1f 92       	push	r1
    13d2:	0f 92       	push	r0
    13d4:	0f b6       	in	r0, 0x3f	; 63
    13d6:	0f 92       	push	r0
    13d8:	0b b6       	in	r0, 0x3b	; 59
    13da:	0f 92       	push	r0
    13dc:	11 24       	eor	r1, r1
    13de:	2f 93       	push	r18
    13e0:	3f 93       	push	r19
    13e2:	4f 93       	push	r20
    13e4:	8f 93       	push	r24
    13e6:	9f 93       	push	r25
    13e8:	ef 93       	push	r30
    13ea:	ff 93       	push	r31
#elif defined(USART_RXC_vect)
  ISR(USART_RXC_vect) // ATmega8
#endif
  {
  #if defined(UDR0)
    if (bit_is_clear(UCSR0A, UPE0)) {
    13ec:	80 91 c0 00 	lds	r24, 0x00C0
    13f0:	82 fd       	sbrc	r24, 2
    13f2:	1d c0       	rjmp	.+58     	; 0x142e <__vector_25+0x5e>
      unsigned char c = UDR0;
    13f4:	40 91 c6 00 	lds	r20, 0x00C6
  ring_buffer tx_buffer3  =  { { 0 }, 0, 0 };
#endif

inline void store_char(unsigned char c, ring_buffer *buffer)
{
  int i = (unsigned int)(buffer->head + 1) % SERIAL_BUFFER_SIZE;
    13f8:	20 91 7f 05 	lds	r18, 0x057F
    13fc:	30 91 80 05 	lds	r19, 0x0580

  // if we should be storing the received character into the location
  // just before the tail (meaning that the head would advance to the
  // current location of the tail), we're about to overflow the buffer
  // and so we don't write the character or advance the head.
  if (i != buffer->tail) {
    1400:	2f 5f       	subi	r18, 0xFF	; 255
    1402:	3f 4f       	sbci	r19, 0xFF	; 255
    1404:	2f 73       	andi	r18, 0x3F	; 63
    1406:	30 70       	andi	r19, 0x00	; 0
    1408:	80 91 81 05 	lds	r24, 0x0581
    140c:	90 91 82 05 	lds	r25, 0x0582
    1410:	28 17       	cp	r18, r24
    1412:	39 07       	cpc	r19, r25
    1414:	71 f0       	breq	.+28     	; 0x1432 <__vector_25+0x62>
    buffer->buffer[buffer->head] = c;
    1416:	e0 91 7f 05 	lds	r30, 0x057F
    141a:	f0 91 80 05 	lds	r31, 0x0580
    141e:	e1 5c       	subi	r30, 0xC1	; 193
    1420:	fa 4f       	sbci	r31, 0xFA	; 250
    1422:	40 83       	st	Z, r20
    buffer->head = i;
    1424:	30 93 80 05 	sts	0x0580, r19
    1428:	20 93 7f 05 	sts	0x057F, r18
    142c:	02 c0       	rjmp	.+4      	; 0x1432 <__vector_25+0x62>
  #if defined(UDR0)
    if (bit_is_clear(UCSR0A, UPE0)) {
      unsigned char c = UDR0;
      store_char(c, &rx_buffer);
    } else {
      unsigned char c = UDR0;
    142e:	80 91 c6 00 	lds	r24, 0x00C6
      unsigned char c = UDR;
    };
  #else
    #error UDR not defined
  #endif
  }
    1432:	ff 91       	pop	r31
    1434:	ef 91       	pop	r30
    1436:	9f 91       	pop	r25
    1438:	8f 91       	pop	r24
    143a:	4f 91       	pop	r20
    143c:	3f 91       	pop	r19
    143e:	2f 91       	pop	r18
    1440:	0f 90       	pop	r0
    1442:	0b be       	out	0x3b, r0	; 59
    1444:	0f 90       	pop	r0
    1446:	0f be       	out	0x3f, r0	; 63
    1448:	0f 90       	pop	r0
    144a:	1f 90       	pop	r1
    144c:	18 95       	reti

0000144e <__vector_36>:

#if defined(USART1_RX_vect)
  void serialEvent1() __attribute__((weak));
  void serialEvent1() {}
  #define serialEvent1_implemented
  ISR(USART1_RX_vect)
    144e:	1f 92       	push	r1
    1450:	0f 92       	push	r0
    1452:	0f b6       	in	r0, 0x3f	; 63
    1454:	0f 92       	push	r0
    1456:	0b b6       	in	r0, 0x3b	; 59
    1458:	0f 92       	push	r0
    145a:	11 24       	eor	r1, r1
    145c:	2f 93       	push	r18
    145e:	3f 93       	push	r19
    1460:	4f 93       	push	r20
    1462:	8f 93       	push	r24
    1464:	9f 93       	push	r25
    1466:	ef 93       	push	r30
    1468:	ff 93       	push	r31
  {
    if (bit_is_clear(UCSR1A, UPE1)) {
    146a:	80 91 c8 00 	lds	r24, 0x00C8
    146e:	82 fd       	sbrc	r24, 2
    1470:	1d c0       	rjmp	.+58     	; 0x14ac <__vector_36+0x5e>
      unsigned char c = UDR1;
    1472:	40 91 ce 00 	lds	r20, 0x00CE
  ring_buffer tx_buffer3  =  { { 0 }, 0, 0 };
#endif

inline void store_char(unsigned char c, ring_buffer *buffer)
{
  int i = (unsigned int)(buffer->head + 1) % SERIAL_BUFFER_SIZE;
    1476:	20 91 07 06 	lds	r18, 0x0607
    147a:	30 91 08 06 	lds	r19, 0x0608

  // if we should be storing the received character into the location
  // just before the tail (meaning that the head would advance to the
  // current location of the tail), we're about to overflow the buffer
  // and so we don't write the character or advance the head.
  if (i != buffer->tail) {
    147e:	2f 5f       	subi	r18, 0xFF	; 255
    1480:	3f 4f       	sbci	r19, 0xFF	; 255
    1482:	2f 73       	andi	r18, 0x3F	; 63
    1484:	30 70       	andi	r19, 0x00	; 0
    1486:	80 91 09 06 	lds	r24, 0x0609
    148a:	90 91 0a 06 	lds	r25, 0x060A
    148e:	28 17       	cp	r18, r24
    1490:	39 07       	cpc	r19, r25
    1492:	71 f0       	breq	.+28     	; 0x14b0 <__vector_36+0x62>
    buffer->buffer[buffer->head] = c;
    1494:	e0 91 07 06 	lds	r30, 0x0607
    1498:	f0 91 08 06 	lds	r31, 0x0608
    149c:	e9 53       	subi	r30, 0x39	; 57
    149e:	fa 4f       	sbci	r31, 0xFA	; 250
    14a0:	40 83       	st	Z, r20
    buffer->head = i;
    14a2:	30 93 08 06 	sts	0x0608, r19
    14a6:	20 93 07 06 	sts	0x0607, r18
    14aa:	02 c0       	rjmp	.+4      	; 0x14b0 <__vector_36+0x62>
  {
    if (bit_is_clear(UCSR1A, UPE1)) {
      unsigned char c = UDR1;
      store_char(c, &rx_buffer1);
    } else {
      unsigned char c = UDR1;
    14ac:	80 91 ce 00 	lds	r24, 0x00CE
    };
  }
    14b0:	ff 91       	pop	r31
    14b2:	ef 91       	pop	r30
    14b4:	9f 91       	pop	r25
    14b6:	8f 91       	pop	r24
    14b8:	4f 91       	pop	r20
    14ba:	3f 91       	pop	r19
    14bc:	2f 91       	pop	r18
    14be:	0f 90       	pop	r0
    14c0:	0b be       	out	0x3b, r0	; 59
    14c2:	0f 90       	pop	r0
    14c4:	0f be       	out	0x3f, r0	; 63
    14c6:	0f 90       	pop	r0
    14c8:	1f 90       	pop	r1
    14ca:	18 95       	reti

000014cc <__vector_51>:

#if defined(USART2_RX_vect) && defined(UDR2)
  void serialEvent2() __attribute__((weak));
  void serialEvent2() {}
  #define serialEvent2_implemented
  ISR(USART2_RX_vect)
    14cc:	1f 92       	push	r1
    14ce:	0f 92       	push	r0
    14d0:	0f b6       	in	r0, 0x3f	; 63
    14d2:	0f 92       	push	r0
    14d4:	0b b6       	in	r0, 0x3b	; 59
    14d6:	0f 92       	push	r0
    14d8:	11 24       	eor	r1, r1
    14da:	2f 93       	push	r18
    14dc:	3f 93       	push	r19
    14de:	4f 93       	push	r20
    14e0:	8f 93       	push	r24
    14e2:	9f 93       	push	r25
    14e4:	ef 93       	push	r30
    14e6:	ff 93       	push	r31
  {
    if (bit_is_clear(UCSR2A, UPE2)) {
    14e8:	80 91 d0 00 	lds	r24, 0x00D0
    14ec:	82 fd       	sbrc	r24, 2
    14ee:	1d c0       	rjmp	.+58     	; 0x152a <__vector_51+0x5e>
      unsigned char c = UDR2;
    14f0:	40 91 d6 00 	lds	r20, 0x00D6
  ring_buffer tx_buffer3  =  { { 0 }, 0, 0 };
#endif

inline void store_char(unsigned char c, ring_buffer *buffer)
{
  int i = (unsigned int)(buffer->head + 1) % SERIAL_BUFFER_SIZE;
    14f4:	20 91 8f 06 	lds	r18, 0x068F
    14f8:	30 91 90 06 	lds	r19, 0x0690

  // if we should be storing the received character into the location
  // just before the tail (meaning that the head would advance to the
  // current location of the tail), we're about to overflow the buffer
  // and so we don't write the character or advance the head.
  if (i != buffer->tail) {
    14fc:	2f 5f       	subi	r18, 0xFF	; 255
    14fe:	3f 4f       	sbci	r19, 0xFF	; 255
    1500:	2f 73       	andi	r18, 0x3F	; 63
    1502:	30 70       	andi	r19, 0x00	; 0
    1504:	80 91 91 06 	lds	r24, 0x0691
    1508:	90 91 92 06 	lds	r25, 0x0692
    150c:	28 17       	cp	r18, r24
    150e:	39 07       	cpc	r19, r25
    1510:	71 f0       	breq	.+28     	; 0x152e <__vector_51+0x62>
    buffer->buffer[buffer->head] = c;
    1512:	e0 91 8f 06 	lds	r30, 0x068F
    1516:	f0 91 90 06 	lds	r31, 0x0690
    151a:	e1 5b       	subi	r30, 0xB1	; 177
    151c:	f9 4f       	sbci	r31, 0xF9	; 249
    151e:	40 83       	st	Z, r20
    buffer->head = i;
    1520:	30 93 90 06 	sts	0x0690, r19
    1524:	20 93 8f 06 	sts	0x068F, r18
    1528:	02 c0       	rjmp	.+4      	; 0x152e <__vector_51+0x62>
  {
    if (bit_is_clear(UCSR2A, UPE2)) {
      unsigned char c = UDR2;
      store_char(c, &rx_buffer2);
    } else {
      unsigned char c = UDR2;
    152a:	80 91 d6 00 	lds	r24, 0x00D6
    };
  }
    152e:	ff 91       	pop	r31
    1530:	ef 91       	pop	r30
    1532:	9f 91       	pop	r25
    1534:	8f 91       	pop	r24
    1536:	4f 91       	pop	r20
    1538:	3f 91       	pop	r19
    153a:	2f 91       	pop	r18
    153c:	0f 90       	pop	r0
    153e:	0b be       	out	0x3b, r0	; 59
    1540:	0f 90       	pop	r0
    1542:	0f be       	out	0x3f, r0	; 63
    1544:	0f 90       	pop	r0
    1546:	1f 90       	pop	r1
    1548:	18 95       	reti

0000154a <__vector_54>:

#if defined(USART3_RX_vect) && defined(UDR3)
  void serialEvent3() __attribute__((weak));
  void serialEvent3() {}
  #define serialEvent3_implemented
  ISR(USART3_RX_vect)
    154a:	1f 92       	push	r1
    154c:	0f 92       	push	r0
    154e:	0f b6       	in	r0, 0x3f	; 63
    1550:	0f 92       	push	r0
    1552:	0b b6       	in	r0, 0x3b	; 59
    1554:	0f 92       	push	r0
    1556:	11 24       	eor	r1, r1
    1558:	2f 93       	push	r18
    155a:	3f 93       	push	r19
    155c:	4f 93       	push	r20
    155e:	8f 93       	push	r24
    1560:	9f 93       	push	r25
    1562:	ef 93       	push	r30
    1564:	ff 93       	push	r31
  {
    if (bit_is_clear(UCSR3A, UPE3)) {
    1566:	80 91 30 01 	lds	r24, 0x0130
    156a:	82 fd       	sbrc	r24, 2
    156c:	1d c0       	rjmp	.+58     	; 0x15a8 <__vector_54+0x5e>
      unsigned char c = UDR3;
    156e:	40 91 36 01 	lds	r20, 0x0136
  ring_buffer tx_buffer3  =  { { 0 }, 0, 0 };
#endif

inline void store_char(unsigned char c, ring_buffer *buffer)
{
  int i = (unsigned int)(buffer->head + 1) % SERIAL_BUFFER_SIZE;
    1572:	20 91 17 07 	lds	r18, 0x0717
    1576:	30 91 18 07 	lds	r19, 0x0718

  // if we should be storing the received character into the location
  // just before the tail (meaning that the head would advance to the
  // current location of the tail), we're about to overflow the buffer
  // and so we don't write the character or advance the head.
  if (i != buffer->tail) {
    157a:	2f 5f       	subi	r18, 0xFF	; 255
    157c:	3f 4f       	sbci	r19, 0xFF	; 255
    157e:	2f 73       	andi	r18, 0x3F	; 63
    1580:	30 70       	andi	r19, 0x00	; 0
    1582:	80 91 19 07 	lds	r24, 0x0719
    1586:	90 91 1a 07 	lds	r25, 0x071A
    158a:	28 17       	cp	r18, r24
    158c:	39 07       	cpc	r19, r25
    158e:	71 f0       	breq	.+28     	; 0x15ac <__vector_54+0x62>
    buffer->buffer[buffer->head] = c;
    1590:	e0 91 17 07 	lds	r30, 0x0717
    1594:	f0 91 18 07 	lds	r31, 0x0718
    1598:	e9 52       	subi	r30, 0x29	; 41
    159a:	f9 4f       	sbci	r31, 0xF9	; 249
    159c:	40 83       	st	Z, r20
    buffer->head = i;
    159e:	30 93 18 07 	sts	0x0718, r19
    15a2:	20 93 17 07 	sts	0x0717, r18
    15a6:	02 c0       	rjmp	.+4      	; 0x15ac <__vector_54+0x62>
  {
    if (bit_is_clear(UCSR3A, UPE3)) {
      unsigned char c = UDR3;
      store_char(c, &rx_buffer3);
    } else {
      unsigned char c = UDR3;
    15a8:	80 91 36 01 	lds	r24, 0x0136
    };
  }
    15ac:	ff 91       	pop	r31
    15ae:	ef 91       	pop	r30
    15b0:	9f 91       	pop	r25
    15b2:	8f 91       	pop	r24
    15b4:	4f 91       	pop	r20
    15b6:	3f 91       	pop	r19
    15b8:	2f 91       	pop	r18
    15ba:	0f 90       	pop	r0
    15bc:	0b be       	out	0x3b, r0	; 59
    15be:	0f 90       	pop	r0
    15c0:	0f be       	out	0x3f, r0	; 63
    15c2:	0f 90       	pop	r0
    15c4:	1f 90       	pop	r1
    15c6:	18 95       	reti

000015c8 <__vector_26>:
#if defined(UART0_UDRE_vect)
ISR(UART0_UDRE_vect)
#elif defined(UART_UDRE_vect)
ISR(UART_UDRE_vect)
#elif defined(USART0_UDRE_vect)
ISR(USART0_UDRE_vect)
    15c8:	1f 92       	push	r1
    15ca:	0f 92       	push	r0
    15cc:	0f b6       	in	r0, 0x3f	; 63
    15ce:	0f 92       	push	r0
    15d0:	0b b6       	in	r0, 0x3b	; 59
    15d2:	0f 92       	push	r0
    15d4:	11 24       	eor	r1, r1
    15d6:	2f 93       	push	r18
    15d8:	3f 93       	push	r19
    15da:	8f 93       	push	r24
    15dc:	9f 93       	push	r25
    15de:	ef 93       	push	r30
    15e0:	ff 93       	push	r31
#elif defined(USART_UDRE_vect)
ISR(USART_UDRE_vect)
#endif
{
  if (tx_buffer.head == tx_buffer.tail) {
    15e2:	20 91 c3 05 	lds	r18, 0x05C3
    15e6:	30 91 c4 05 	lds	r19, 0x05C4
    15ea:	80 91 c5 05 	lds	r24, 0x05C5
    15ee:	90 91 c6 05 	lds	r25, 0x05C6
    15f2:	28 17       	cp	r18, r24
    15f4:	39 07       	cpc	r19, r25
    15f6:	31 f4       	brne	.+12     	; 0x1604 <__vector_26+0x3c>
	// Buffer empty, so disable interrupts
#if defined(UCSR0B)
    cbi(UCSR0B, UDRIE0);
    15f8:	80 91 c1 00 	lds	r24, 0x00C1
    15fc:	8f 7d       	andi	r24, 0xDF	; 223
    15fe:	80 93 c1 00 	sts	0x00C1, r24
    1602:	14 c0       	rjmp	.+40     	; 0x162c <__vector_26+0x64>
    cbi(UCSRB, UDRIE);
#endif
  }
  else {
    // There is more data in the output buffer. Send the next byte
    unsigned char c = tx_buffer.buffer[tx_buffer.tail];
    1604:	e0 91 c5 05 	lds	r30, 0x05C5
    1608:	f0 91 c6 05 	lds	r31, 0x05C6
    160c:	ed 57       	subi	r30, 0x7D	; 125
    160e:	fa 4f       	sbci	r31, 0xFA	; 250
    1610:	20 81       	ld	r18, Z
    tx_buffer.tail = (tx_buffer.tail + 1) % SERIAL_BUFFER_SIZE;
    1612:	80 91 c5 05 	lds	r24, 0x05C5
    1616:	90 91 c6 05 	lds	r25, 0x05C6
    161a:	01 96       	adiw	r24, 0x01	; 1
    161c:	8f 73       	andi	r24, 0x3F	; 63
    161e:	90 70       	andi	r25, 0x00	; 0
    1620:	90 93 c6 05 	sts	0x05C6, r25
    1624:	80 93 c5 05 	sts	0x05C5, r24
	
  #if defined(UDR0)
    UDR0 = c;
    1628:	20 93 c6 00 	sts	0x00C6, r18
    UDR = c;
  #else
    #error UDR not defined
  #endif
  }
}
    162c:	ff 91       	pop	r31
    162e:	ef 91       	pop	r30
    1630:	9f 91       	pop	r25
    1632:	8f 91       	pop	r24
    1634:	3f 91       	pop	r19
    1636:	2f 91       	pop	r18
    1638:	0f 90       	pop	r0
    163a:	0b be       	out	0x3b, r0	; 59
    163c:	0f 90       	pop	r0
    163e:	0f be       	out	0x3f, r0	; 63
    1640:	0f 90       	pop	r0
    1642:	1f 90       	pop	r1
    1644:	18 95       	reti

00001646 <__vector_37>:
#endif
#endif

#ifdef USART1_UDRE_vect
ISR(USART1_UDRE_vect)
    1646:	1f 92       	push	r1
    1648:	0f 92       	push	r0
    164a:	0f b6       	in	r0, 0x3f	; 63
    164c:	0f 92       	push	r0
    164e:	0b b6       	in	r0, 0x3b	; 59
    1650:	0f 92       	push	r0
    1652:	11 24       	eor	r1, r1
    1654:	2f 93       	push	r18
    1656:	3f 93       	push	r19
    1658:	8f 93       	push	r24
    165a:	9f 93       	push	r25
    165c:	ef 93       	push	r30
    165e:	ff 93       	push	r31
{
  if (tx_buffer1.head == tx_buffer1.tail) {
    1660:	20 91 4b 06 	lds	r18, 0x064B
    1664:	30 91 4c 06 	lds	r19, 0x064C
    1668:	80 91 4d 06 	lds	r24, 0x064D
    166c:	90 91 4e 06 	lds	r25, 0x064E
    1670:	28 17       	cp	r18, r24
    1672:	39 07       	cpc	r19, r25
    1674:	31 f4       	brne	.+12     	; 0x1682 <__vector_37+0x3c>
	// Buffer empty, so disable interrupts
    cbi(UCSR1B, UDRIE1);
    1676:	80 91 c9 00 	lds	r24, 0x00C9
    167a:	8f 7d       	andi	r24, 0xDF	; 223
    167c:	80 93 c9 00 	sts	0x00C9, r24
    1680:	14 c0       	rjmp	.+40     	; 0x16aa <__vector_37+0x64>
  }
  else {
    // There is more data in the output buffer. Send the next byte
    unsigned char c = tx_buffer1.buffer[tx_buffer1.tail];
    1682:	e0 91 4d 06 	lds	r30, 0x064D
    1686:	f0 91 4e 06 	lds	r31, 0x064E
    168a:	e5 5f       	subi	r30, 0xF5	; 245
    168c:	f9 4f       	sbci	r31, 0xF9	; 249
    168e:	20 81       	ld	r18, Z
    tx_buffer1.tail = (tx_buffer1.tail + 1) % SERIAL_BUFFER_SIZE;
    1690:	80 91 4d 06 	lds	r24, 0x064D
    1694:	90 91 4e 06 	lds	r25, 0x064E
    1698:	01 96       	adiw	r24, 0x01	; 1
    169a:	8f 73       	andi	r24, 0x3F	; 63
    169c:	90 70       	andi	r25, 0x00	; 0
    169e:	90 93 4e 06 	sts	0x064E, r25
    16a2:	80 93 4d 06 	sts	0x064D, r24
	
    UDR1 = c;
    16a6:	20 93 ce 00 	sts	0x00CE, r18
  }
}
    16aa:	ff 91       	pop	r31
    16ac:	ef 91       	pop	r30
    16ae:	9f 91       	pop	r25
    16b0:	8f 91       	pop	r24
    16b2:	3f 91       	pop	r19
    16b4:	2f 91       	pop	r18
    16b6:	0f 90       	pop	r0
    16b8:	0b be       	out	0x3b, r0	; 59
    16ba:	0f 90       	pop	r0
    16bc:	0f be       	out	0x3f, r0	; 63
    16be:	0f 90       	pop	r0
    16c0:	1f 90       	pop	r1
    16c2:	18 95       	reti

000016c4 <__vector_52>:
#endif

#ifdef USART2_UDRE_vect
ISR(USART2_UDRE_vect)
    16c4:	1f 92       	push	r1
    16c6:	0f 92       	push	r0
    16c8:	0f b6       	in	r0, 0x3f	; 63
    16ca:	0f 92       	push	r0
    16cc:	0b b6       	in	r0, 0x3b	; 59
    16ce:	0f 92       	push	r0
    16d0:	11 24       	eor	r1, r1
    16d2:	2f 93       	push	r18
    16d4:	3f 93       	push	r19
    16d6:	8f 93       	push	r24
    16d8:	9f 93       	push	r25
    16da:	ef 93       	push	r30
    16dc:	ff 93       	push	r31
{
  if (tx_buffer2.head == tx_buffer2.tail) {
    16de:	20 91 d3 06 	lds	r18, 0x06D3
    16e2:	30 91 d4 06 	lds	r19, 0x06D4
    16e6:	80 91 d5 06 	lds	r24, 0x06D5
    16ea:	90 91 d6 06 	lds	r25, 0x06D6
    16ee:	28 17       	cp	r18, r24
    16f0:	39 07       	cpc	r19, r25
    16f2:	31 f4       	brne	.+12     	; 0x1700 <__vector_52+0x3c>
	// Buffer empty, so disable interrupts
    cbi(UCSR2B, UDRIE2);
    16f4:	80 91 d1 00 	lds	r24, 0x00D1
    16f8:	8f 7d       	andi	r24, 0xDF	; 223
    16fa:	80 93 d1 00 	sts	0x00D1, r24
    16fe:	14 c0       	rjmp	.+40     	; 0x1728 <__vector_52+0x64>
  }
  else {
    // There is more data in the output buffer. Send the next byte
    unsigned char c = tx_buffer2.buffer[tx_buffer2.tail];
    1700:	e0 91 d5 06 	lds	r30, 0x06D5
    1704:	f0 91 d6 06 	lds	r31, 0x06D6
    1708:	ed 56       	subi	r30, 0x6D	; 109
    170a:	f9 4f       	sbci	r31, 0xF9	; 249
    170c:	20 81       	ld	r18, Z
    tx_buffer2.tail = (tx_buffer2.tail + 1) % SERIAL_BUFFER_SIZE;
    170e:	80 91 d5 06 	lds	r24, 0x06D5
    1712:	90 91 d6 06 	lds	r25, 0x06D6
    1716:	01 96       	adiw	r24, 0x01	; 1
    1718:	8f 73       	andi	r24, 0x3F	; 63
    171a:	90 70       	andi	r25, 0x00	; 0
    171c:	90 93 d6 06 	sts	0x06D6, r25
    1720:	80 93 d5 06 	sts	0x06D5, r24
	
    UDR2 = c;
    1724:	20 93 d6 00 	sts	0x00D6, r18
  }
}
    1728:	ff 91       	pop	r31
    172a:	ef 91       	pop	r30
    172c:	9f 91       	pop	r25
    172e:	8f 91       	pop	r24
    1730:	3f 91       	pop	r19
    1732:	2f 91       	pop	r18
    1734:	0f 90       	pop	r0
    1736:	0b be       	out	0x3b, r0	; 59
    1738:	0f 90       	pop	r0
    173a:	0f be       	out	0x3f, r0	; 63
    173c:	0f 90       	pop	r0
    173e:	1f 90       	pop	r1
    1740:	18 95       	reti

00001742 <__vector_55>:
#endif

#ifdef USART3_UDRE_vect
ISR(USART3_UDRE_vect)
    1742:	1f 92       	push	r1
    1744:	0f 92       	push	r0
    1746:	0f b6       	in	r0, 0x3f	; 63
    1748:	0f 92       	push	r0
    174a:	0b b6       	in	r0, 0x3b	; 59
    174c:	0f 92       	push	r0
    174e:	11 24       	eor	r1, r1
    1750:	2f 93       	push	r18
    1752:	3f 93       	push	r19
    1754:	8f 93       	push	r24
    1756:	9f 93       	push	r25
    1758:	ef 93       	push	r30
    175a:	ff 93       	push	r31
{
  if (tx_buffer3.head == tx_buffer3.tail) {
    175c:	20 91 5b 07 	lds	r18, 0x075B
    1760:	30 91 5c 07 	lds	r19, 0x075C
    1764:	80 91 5d 07 	lds	r24, 0x075D
    1768:	90 91 5e 07 	lds	r25, 0x075E
    176c:	28 17       	cp	r18, r24
    176e:	39 07       	cpc	r19, r25
    1770:	31 f4       	brne	.+12     	; 0x177e <__vector_55+0x3c>
	// Buffer empty, so disable interrupts
    cbi(UCSR3B, UDRIE3);
    1772:	80 91 31 01 	lds	r24, 0x0131
    1776:	8f 7d       	andi	r24, 0xDF	; 223
    1778:	80 93 31 01 	sts	0x0131, r24
    177c:	14 c0       	rjmp	.+40     	; 0x17a6 <__vector_55+0x64>
  }
  else {
    // There is more data in the output buffer. Send the next byte
    unsigned char c = tx_buffer3.buffer[tx_buffer3.tail];
    177e:	e0 91 5d 07 	lds	r30, 0x075D
    1782:	f0 91 5e 07 	lds	r31, 0x075E
    1786:	e5 5e       	subi	r30, 0xE5	; 229
    1788:	f8 4f       	sbci	r31, 0xF8	; 248
    178a:	20 81       	ld	r18, Z
    tx_buffer3.tail = (tx_buffer3.tail + 1) % SERIAL_BUFFER_SIZE;
    178c:	80 91 5d 07 	lds	r24, 0x075D
    1790:	90 91 5e 07 	lds	r25, 0x075E
    1794:	01 96       	adiw	r24, 0x01	; 1
    1796:	8f 73       	andi	r24, 0x3F	; 63
    1798:	90 70       	andi	r25, 0x00	; 0
    179a:	90 93 5e 07 	sts	0x075E, r25
    179e:	80 93 5d 07 	sts	0x075D, r24
	
    UDR3 = c;
    17a2:	20 93 36 01 	sts	0x0136, r18
  }
}
    17a6:	ff 91       	pop	r31
    17a8:	ef 91       	pop	r30
    17aa:	9f 91       	pop	r25
    17ac:	8f 91       	pop	r24
    17ae:	3f 91       	pop	r19
    17b0:	2f 91       	pop	r18
    17b2:	0f 90       	pop	r0
    17b4:	0b be       	out	0x3b, r0	; 59
    17b6:	0f 90       	pop	r0
    17b8:	0f be       	out	0x3f, r0	; 63
    17ba:	0f 90       	pop	r0
    17bc:	1f 90       	pop	r1
    17be:	18 95       	reti

000017c0 <_ZN14HardwareSerial9availableEv>:
  _rx_buffer->head = _rx_buffer->tail;
}

int HardwareSerial::available(void)
{
  return (unsigned int)(SERIAL_BUFFER_SIZE + _rx_buffer->head - _rx_buffer->tail) % SERIAL_BUFFER_SIZE;
    17c0:	dc 01       	movw	r26, r24
    17c2:	1c 96       	adiw	r26, 0x0c	; 12
    17c4:	ed 91       	ld	r30, X+
    17c6:	fc 91       	ld	r31, X
    17c8:	1d 97       	sbiw	r26, 0x0d	; 13
    17ca:	e0 5c       	subi	r30, 0xC0	; 192
    17cc:	ff 4f       	sbci	r31, 0xFF	; 255
    17ce:	21 91       	ld	r18, Z+
    17d0:	31 91       	ld	r19, Z+
    17d2:	80 81       	ld	r24, Z
    17d4:	91 81       	ldd	r25, Z+1	; 0x01
    17d6:	28 1b       	sub	r18, r24
    17d8:	39 0b       	sbc	r19, r25
    17da:	2f 73       	andi	r18, 0x3F	; 63
    17dc:	30 70       	andi	r19, 0x00	; 0
}
    17de:	c9 01       	movw	r24, r18
    17e0:	08 95       	ret

000017e2 <_ZN14HardwareSerial4peekEv>:

int HardwareSerial::peek(void)
{
  if (_rx_buffer->head == _rx_buffer->tail) {
    17e2:	dc 01       	movw	r26, r24
    17e4:	1c 96       	adiw	r26, 0x0c	; 12
    17e6:	ed 91       	ld	r30, X+
    17e8:	fc 91       	ld	r31, X
    17ea:	1d 97       	sbiw	r26, 0x0d	; 13
    17ec:	e0 5c       	subi	r30, 0xC0	; 192
    17ee:	ff 4f       	sbci	r31, 0xFF	; 255
    17f0:	20 81       	ld	r18, Z
    17f2:	31 81       	ldd	r19, Z+1	; 0x01
    17f4:	e0 54       	subi	r30, 0x40	; 64
    17f6:	f0 40       	sbci	r31, 0x00	; 0
    17f8:	df 01       	movw	r26, r30
    17fa:	ae 5b       	subi	r26, 0xBE	; 190
    17fc:	bf 4f       	sbci	r27, 0xFF	; 255
    17fe:	8d 91       	ld	r24, X+
    1800:	9c 91       	ld	r25, X
    1802:	11 97       	sbiw	r26, 0x01	; 1
    1804:	28 17       	cp	r18, r24
    1806:	39 07       	cpc	r19, r25
    1808:	19 f4       	brne	.+6      	; 0x1810 <_ZN14HardwareSerial4peekEv+0x2e>
    180a:	2f ef       	ldi	r18, 0xFF	; 255
    180c:	3f ef       	ldi	r19, 0xFF	; 255
    180e:	07 c0       	rjmp	.+14     	; 0x181e <_ZN14HardwareSerial4peekEv+0x3c>
    return -1;
  } else {
    return _rx_buffer->buffer[_rx_buffer->tail];
    1810:	8d 91       	ld	r24, X+
    1812:	9c 91       	ld	r25, X
    1814:	e8 0f       	add	r30, r24
    1816:	f9 1f       	adc	r31, r25
    1818:	80 81       	ld	r24, Z
    181a:	28 2f       	mov	r18, r24
    181c:	30 e0       	ldi	r19, 0x00	; 0
  }
}
    181e:	c9 01       	movw	r24, r18
    1820:	08 95       	ret

00001822 <_ZN14HardwareSerial4readEv>:

int HardwareSerial::read(void)
{
  // if the head isn't ahead of the tail, we don't have any characters
  if (_rx_buffer->head == _rx_buffer->tail) {
    1822:	dc 01       	movw	r26, r24
    1824:	1c 96       	adiw	r26, 0x0c	; 12
    1826:	ed 91       	ld	r30, X+
    1828:	fc 91       	ld	r31, X
    182a:	1d 97       	sbiw	r26, 0x0d	; 13
    182c:	e0 5c       	subi	r30, 0xC0	; 192
    182e:	ff 4f       	sbci	r31, 0xFF	; 255
    1830:	20 81       	ld	r18, Z
    1832:	31 81       	ldd	r19, Z+1	; 0x01
    1834:	e0 54       	subi	r30, 0x40	; 64
    1836:	f0 40       	sbci	r31, 0x00	; 0
    1838:	df 01       	movw	r26, r30
    183a:	ae 5b       	subi	r26, 0xBE	; 190
    183c:	bf 4f       	sbci	r27, 0xFF	; 255
    183e:	8d 91       	ld	r24, X+
    1840:	9c 91       	ld	r25, X
    1842:	11 97       	sbiw	r26, 0x01	; 1
    1844:	28 17       	cp	r18, r24
    1846:	39 07       	cpc	r19, r25
    1848:	19 f4       	brne	.+6      	; 0x1850 <_ZN14HardwareSerial4readEv+0x2e>
    184a:	2f ef       	ldi	r18, 0xFF	; 255
    184c:	3f ef       	ldi	r19, 0xFF	; 255
    184e:	10 c0       	rjmp	.+32     	; 0x1870 <_ZN14HardwareSerial4readEv+0x4e>
    return -1;
  } else {
    unsigned char c = _rx_buffer->buffer[_rx_buffer->tail];
    1850:	8d 91       	ld	r24, X+
    1852:	9c 91       	ld	r25, X
    1854:	11 97       	sbiw	r26, 0x01	; 1
    1856:	e8 0f       	add	r30, r24
    1858:	f9 1f       	adc	r31, r25
    185a:	20 81       	ld	r18, Z
    _rx_buffer->tail = (unsigned int)(_rx_buffer->tail + 1) % SERIAL_BUFFER_SIZE;
    185c:	8d 91       	ld	r24, X+
    185e:	9c 91       	ld	r25, X
    1860:	11 97       	sbiw	r26, 0x01	; 1
    1862:	01 96       	adiw	r24, 0x01	; 1
    1864:	8f 73       	andi	r24, 0x3F	; 63
    1866:	90 70       	andi	r25, 0x00	; 0
    1868:	11 96       	adiw	r26, 0x01	; 1
    186a:	9c 93       	st	X, r25
    186c:	8e 93       	st	-X, r24
    return c;
    186e:	30 e0       	ldi	r19, 0x00	; 0
  }
}
    1870:	c9 01       	movw	r24, r18
    1872:	08 95       	ret

00001874 <_ZN14HardwareSerial5flushEv>:

void HardwareSerial::flush()
    1874:	dc 01       	movw	r26, r24
{
  // UDR is kept full while the buffer is not empty, so TXC triggers when EMPTY && SENT
  while (transmitting && ! (*_ucsra & _BV(TXC0)));
    1876:	91 96       	adiw	r26, 0x21	; 33
    1878:	8c 91       	ld	r24, X
    187a:	91 97       	sbiw	r26, 0x21	; 33
    187c:	88 23       	and	r24, r24
    187e:	39 f0       	breq	.+14     	; 0x188e <_ZN14HardwareSerial5flushEv+0x1a>
    1880:	54 96       	adiw	r26, 0x14	; 20
    1882:	ed 91       	ld	r30, X+
    1884:	fc 91       	ld	r31, X
    1886:	55 97       	sbiw	r26, 0x15	; 21
    1888:	80 81       	ld	r24, Z
    188a:	86 ff       	sbrs	r24, 6
    188c:	f9 cf       	rjmp	.-14     	; 0x1880 <_ZN14HardwareSerial5flushEv+0xc>
  transmitting = false;
    188e:	91 96       	adiw	r26, 0x21	; 33
    1890:	1c 92       	st	X, r1
}
    1892:	08 95       	ret

00001894 <_ZN14HardwareSerial5writeEh>:

size_t HardwareSerial::write(uint8_t c)
    1894:	cf 93       	push	r28
    1896:	df 93       	push	r29
    1898:	ec 01       	movw	r28, r24
{
  int i = (_tx_buffer->head + 1) % SERIAL_BUFFER_SIZE;
    189a:	ee 85       	ldd	r30, Y+14	; 0x0e
    189c:	ff 85       	ldd	r31, Y+15	; 0x0f
    189e:	e0 5c       	subi	r30, 0xC0	; 192
    18a0:	ff 4f       	sbci	r31, 0xFF	; 255
    18a2:	20 81       	ld	r18, Z
    18a4:	31 81       	ldd	r19, Z+1	; 0x01
    18a6:	e0 54       	subi	r30, 0x40	; 64
    18a8:	f0 40       	sbci	r31, 0x00	; 0
    18aa:	2f 5f       	subi	r18, 0xFF	; 255
    18ac:	3f 4f       	sbci	r19, 0xFF	; 255
    18ae:	2f 73       	andi	r18, 0x3F	; 63
    18b0:	30 70       	andi	r19, 0x00	; 0
	
  // If the output buffer is full, there's nothing for it other than to 
  // wait for the interrupt handler to empty it a bit
  // ???: return 0 here instead?
  while (i == _tx_buffer->tail)
    18b2:	df 01       	movw	r26, r30
    18b4:	ae 5b       	subi	r26, 0xBE	; 190
    18b6:	bf 4f       	sbci	r27, 0xFF	; 255
    18b8:	8d 91       	ld	r24, X+
    18ba:	9c 91       	ld	r25, X
    18bc:	11 97       	sbiw	r26, 0x01	; 1
    18be:	28 17       	cp	r18, r24
    18c0:	39 07       	cpc	r19, r25
    18c2:	d1 f3       	breq	.-12     	; 0x18b8 <_ZN14HardwareSerial5writeEh+0x24>
    ;
	
  _tx_buffer->buffer[_tx_buffer->head] = c;
    18c4:	e0 5c       	subi	r30, 0xC0	; 192
    18c6:	ff 4f       	sbci	r31, 0xFF	; 255
    18c8:	80 81       	ld	r24, Z
    18ca:	91 81       	ldd	r25, Z+1	; 0x01
    18cc:	e0 54       	subi	r30, 0x40	; 64
    18ce:	f0 40       	sbci	r31, 0x00	; 0
    18d0:	e8 0f       	add	r30, r24
    18d2:	f9 1f       	adc	r31, r25
    18d4:	60 83       	st	Z, r22
  _tx_buffer->head = i;
    18d6:	ee 85       	ldd	r30, Y+14	; 0x0e
    18d8:	ff 85       	ldd	r31, Y+15	; 0x0f
    18da:	e0 5c       	subi	r30, 0xC0	; 192
    18dc:	ff 4f       	sbci	r31, 0xFF	; 255
    18de:	31 83       	std	Z+1, r19	; 0x01
    18e0:	20 83       	st	Z, r18
	
  sbi(*_ucsrb, _udrie);
    18e2:	ee 89       	ldd	r30, Y+22	; 0x16
    18e4:	ff 89       	ldd	r31, Y+23	; 0x17
    18e6:	20 81       	ld	r18, Z
    18e8:	81 e0       	ldi	r24, 0x01	; 1
    18ea:	90 e0       	ldi	r25, 0x00	; 0
    18ec:	0f 8c       	ldd	r0, Y+31	; 0x1f
    18ee:	02 c0       	rjmp	.+4      	; 0x18f4 <_ZN14HardwareSerial5writeEh+0x60>
    18f0:	88 0f       	add	r24, r24
    18f2:	99 1f       	adc	r25, r25
    18f4:	0a 94       	dec	r0
    18f6:	e2 f7       	brpl	.-8      	; 0x18f0 <_ZN14HardwareSerial5writeEh+0x5c>
    18f8:	28 2b       	or	r18, r24
    18fa:	20 83       	st	Z, r18
  // clear the TXC bit -- "can be cleared by writing a one to its bit location"
  transmitting = true;
    18fc:	81 e0       	ldi	r24, 0x01	; 1
    18fe:	89 a3       	std	Y+33, r24	; 0x21
  sbi(*_ucsra, TXC0);
    1900:	ec 89       	ldd	r30, Y+20	; 0x14
    1902:	fd 89       	ldd	r31, Y+21	; 0x15
    1904:	80 81       	ld	r24, Z
    1906:	80 64       	ori	r24, 0x40	; 64
    1908:	80 83       	st	Z, r24
  
  return 1;
}
    190a:	81 e0       	ldi	r24, 0x01	; 1
    190c:	90 e0       	ldi	r25, 0x00	; 0
    190e:	df 91       	pop	r29
    1910:	cf 91       	pop	r28
    1912:	08 95       	ret

00001914 <_GLOBAL__I_rx_buffer>:
#endif
#if defined(UBRR2H)
  HardwareSerial Serial2(&rx_buffer2, &tx_buffer2, &UBRR2H, &UBRR2L, &UCSR2A, &UCSR2B, &UCSR2C, &UDR2, RXEN2, TXEN2, RXCIE2, UDRIE2, U2X2);
#endif
#if defined(UBRR3H)
  HardwareSerial Serial3(&rx_buffer3, &tx_buffer3, &UBRR3H, &UBRR3L, &UCSR3A, &UCSR3B, &UCSR3C, &UDR3, RXEN3, TXEN3, RXCIE3, UDRIE3, U2X3);
    1914:	1f 93       	push	r17
    1916:	10 92 62 07 	sts	0x0762, r1
    191a:	10 92 61 07 	sts	0x0761, r1
    191e:	28 ee       	ldi	r18, 0xE8	; 232
    1920:	33 e0       	ldi	r19, 0x03	; 3
    1922:	40 e0       	ldi	r20, 0x00	; 0
    1924:	50 e0       	ldi	r21, 0x00	; 0
    1926:	20 93 63 07 	sts	0x0763, r18
    192a:	30 93 64 07 	sts	0x0764, r19
    192e:	40 93 65 07 	sts	0x0765, r20
    1932:	50 93 66 07 	sts	0x0766, r21

HardwareSerial::HardwareSerial(ring_buffer *rx_buffer, ring_buffer *tx_buffer,
  volatile uint8_t *ubrrh, volatile uint8_t *ubrrl,
  volatile uint8_t *ucsra, volatile uint8_t *ucsrb,
  volatile uint8_t *ucsrc, volatile uint8_t *udr,
  uint8_t rxen, uint8_t txen, uint8_t rxcie, uint8_t udrie, uint8_t u2x)
    1936:	69 e2       	ldi	r22, 0x29	; 41
    1938:	74 e0       	ldi	r23, 0x04	; 4
    193a:	70 93 60 07 	sts	0x0760, r23
    193e:	60 93 5f 07 	sts	0x075F, r22
{
  _rx_buffer = rx_buffer;
    1942:	8f e3       	ldi	r24, 0x3F	; 63
    1944:	95 e0       	ldi	r25, 0x05	; 5
    1946:	90 93 6c 07 	sts	0x076C, r25
    194a:	80 93 6b 07 	sts	0x076B, r24
  _tx_buffer = tx_buffer;
    194e:	83 e8       	ldi	r24, 0x83	; 131
    1950:	95 e0       	ldi	r25, 0x05	; 5
    1952:	90 93 6e 07 	sts	0x076E, r25
    1956:	80 93 6d 07 	sts	0x076D, r24
  _ubrrh = ubrrh;
    195a:	85 ec       	ldi	r24, 0xC5	; 197
    195c:	90 e0       	ldi	r25, 0x00	; 0
    195e:	90 93 70 07 	sts	0x0770, r25
    1962:	80 93 6f 07 	sts	0x076F, r24
  _ubrrl = ubrrl;
    1966:	84 ec       	ldi	r24, 0xC4	; 196
    1968:	90 e0       	ldi	r25, 0x00	; 0
    196a:	90 93 72 07 	sts	0x0772, r25
    196e:	80 93 71 07 	sts	0x0771, r24
  _ucsra = ucsra;
    1972:	80 ec       	ldi	r24, 0xC0	; 192
    1974:	90 e0       	ldi	r25, 0x00	; 0
    1976:	90 93 74 07 	sts	0x0774, r25
    197a:	80 93 73 07 	sts	0x0773, r24
  _ucsrb = ucsrb;
    197e:	81 ec       	ldi	r24, 0xC1	; 193
    1980:	90 e0       	ldi	r25, 0x00	; 0
    1982:	90 93 76 07 	sts	0x0776, r25
    1986:	80 93 75 07 	sts	0x0775, r24
  _ucsrc = ucsrc;
    198a:	82 ec       	ldi	r24, 0xC2	; 194
    198c:	90 e0       	ldi	r25, 0x00	; 0
    198e:	90 93 78 07 	sts	0x0778, r25
    1992:	80 93 77 07 	sts	0x0777, r24
  _udr = udr;
    1996:	86 ec       	ldi	r24, 0xC6	; 198
    1998:	90 e0       	ldi	r25, 0x00	; 0
    199a:	90 93 7a 07 	sts	0x077A, r25
    199e:	80 93 79 07 	sts	0x0779, r24
  _rxen = rxen;
    19a2:	14 e0       	ldi	r17, 0x04	; 4
    19a4:	10 93 7b 07 	sts	0x077B, r17
  _txen = txen;
    19a8:	b3 e0       	ldi	r27, 0x03	; 3
    19aa:	b0 93 7c 07 	sts	0x077C, r27
  _rxcie = rxcie;
    19ae:	a7 e0       	ldi	r26, 0x07	; 7
    19b0:	a0 93 7d 07 	sts	0x077D, r26
  _udrie = udrie;
    19b4:	f5 e0       	ldi	r31, 0x05	; 5
    19b6:	f0 93 7e 07 	sts	0x077E, r31
  _u2x = u2x;
    19ba:	e1 e0       	ldi	r30, 0x01	; 1
    19bc:	e0 93 7f 07 	sts	0x077F, r30
    19c0:	10 92 84 07 	sts	0x0784, r1
    19c4:	10 92 83 07 	sts	0x0783, r1
    19c8:	20 93 85 07 	sts	0x0785, r18
    19cc:	30 93 86 07 	sts	0x0786, r19
    19d0:	40 93 87 07 	sts	0x0787, r20
    19d4:	50 93 88 07 	sts	0x0788, r21

HardwareSerial::HardwareSerial(ring_buffer *rx_buffer, ring_buffer *tx_buffer,
  volatile uint8_t *ubrrh, volatile uint8_t *ubrrl,
  volatile uint8_t *ucsra, volatile uint8_t *ucsrb,
  volatile uint8_t *ucsrc, volatile uint8_t *udr,
  uint8_t rxen, uint8_t txen, uint8_t rxcie, uint8_t udrie, uint8_t u2x)
    19d8:	70 93 82 07 	sts	0x0782, r23
    19dc:	60 93 81 07 	sts	0x0781, r22
{
  _rx_buffer = rx_buffer;
    19e0:	87 ec       	ldi	r24, 0xC7	; 199
    19e2:	95 e0       	ldi	r25, 0x05	; 5
    19e4:	90 93 8e 07 	sts	0x078E, r25
    19e8:	80 93 8d 07 	sts	0x078D, r24
  _tx_buffer = tx_buffer;
    19ec:	8b e0       	ldi	r24, 0x0B	; 11
    19ee:	96 e0       	ldi	r25, 0x06	; 6
    19f0:	90 93 90 07 	sts	0x0790, r25
    19f4:	80 93 8f 07 	sts	0x078F, r24
  _ubrrh = ubrrh;
    19f8:	8d ec       	ldi	r24, 0xCD	; 205
    19fa:	90 e0       	ldi	r25, 0x00	; 0
    19fc:	90 93 92 07 	sts	0x0792, r25
    1a00:	80 93 91 07 	sts	0x0791, r24
  _ubrrl = ubrrl;
    1a04:	8c ec       	ldi	r24, 0xCC	; 204
    1a06:	90 e0       	ldi	r25, 0x00	; 0
    1a08:	90 93 94 07 	sts	0x0794, r25
    1a0c:	80 93 93 07 	sts	0x0793, r24
  _ucsra = ucsra;
    1a10:	88 ec       	ldi	r24, 0xC8	; 200
    1a12:	90 e0       	ldi	r25, 0x00	; 0
    1a14:	90 93 96 07 	sts	0x0796, r25
    1a18:	80 93 95 07 	sts	0x0795, r24
  _ucsrb = ucsrb;
    1a1c:	89 ec       	ldi	r24, 0xC9	; 201
    1a1e:	90 e0       	ldi	r25, 0x00	; 0
    1a20:	90 93 98 07 	sts	0x0798, r25
    1a24:	80 93 97 07 	sts	0x0797, r24
  _ucsrc = ucsrc;
    1a28:	8a ec       	ldi	r24, 0xCA	; 202
    1a2a:	90 e0       	ldi	r25, 0x00	; 0
    1a2c:	90 93 9a 07 	sts	0x079A, r25
    1a30:	80 93 99 07 	sts	0x0799, r24
  _udr = udr;
    1a34:	8e ec       	ldi	r24, 0xCE	; 206
    1a36:	90 e0       	ldi	r25, 0x00	; 0
    1a38:	90 93 9c 07 	sts	0x079C, r25
    1a3c:	80 93 9b 07 	sts	0x079B, r24
  _rxen = rxen;
    1a40:	10 93 9d 07 	sts	0x079D, r17
  _txen = txen;
    1a44:	b0 93 9e 07 	sts	0x079E, r27
  _rxcie = rxcie;
    1a48:	a0 93 9f 07 	sts	0x079F, r26
  _udrie = udrie;
    1a4c:	f0 93 a0 07 	sts	0x07A0, r31
  _u2x = u2x;
    1a50:	e0 93 a1 07 	sts	0x07A1, r30
    1a54:	10 92 a6 07 	sts	0x07A6, r1
    1a58:	10 92 a5 07 	sts	0x07A5, r1
    1a5c:	20 93 a7 07 	sts	0x07A7, r18
    1a60:	30 93 a8 07 	sts	0x07A8, r19
    1a64:	40 93 a9 07 	sts	0x07A9, r20
    1a68:	50 93 aa 07 	sts	0x07AA, r21

HardwareSerial::HardwareSerial(ring_buffer *rx_buffer, ring_buffer *tx_buffer,
  volatile uint8_t *ubrrh, volatile uint8_t *ubrrl,
  volatile uint8_t *ucsra, volatile uint8_t *ucsrb,
  volatile uint8_t *ucsrc, volatile uint8_t *udr,
  uint8_t rxen, uint8_t txen, uint8_t rxcie, uint8_t udrie, uint8_t u2x)
    1a6c:	70 93 a4 07 	sts	0x07A4, r23
    1a70:	60 93 a3 07 	sts	0x07A3, r22
{
  _rx_buffer = rx_buffer;
    1a74:	8f e4       	ldi	r24, 0x4F	; 79
    1a76:	96 e0       	ldi	r25, 0x06	; 6
    1a78:	90 93 b0 07 	sts	0x07B0, r25
    1a7c:	80 93 af 07 	sts	0x07AF, r24
  _tx_buffer = tx_buffer;
    1a80:	83 e9       	ldi	r24, 0x93	; 147
    1a82:	96 e0       	ldi	r25, 0x06	; 6
    1a84:	90 93 b2 07 	sts	0x07B2, r25
    1a88:	80 93 b1 07 	sts	0x07B1, r24
  _ubrrh = ubrrh;
    1a8c:	85 ed       	ldi	r24, 0xD5	; 213
    1a8e:	90 e0       	ldi	r25, 0x00	; 0
    1a90:	90 93 b4 07 	sts	0x07B4, r25
    1a94:	80 93 b3 07 	sts	0x07B3, r24
  _ubrrl = ubrrl;
    1a98:	84 ed       	ldi	r24, 0xD4	; 212
    1a9a:	90 e0       	ldi	r25, 0x00	; 0
    1a9c:	90 93 b6 07 	sts	0x07B6, r25
    1aa0:	80 93 b5 07 	sts	0x07B5, r24
  _ucsra = ucsra;
    1aa4:	80 ed       	ldi	r24, 0xD0	; 208
    1aa6:	90 e0       	ldi	r25, 0x00	; 0
    1aa8:	90 93 b8 07 	sts	0x07B8, r25
    1aac:	80 93 b7 07 	sts	0x07B7, r24
  _ucsrb = ucsrb;
    1ab0:	81 ed       	ldi	r24, 0xD1	; 209
    1ab2:	90 e0       	ldi	r25, 0x00	; 0
    1ab4:	90 93 ba 07 	sts	0x07BA, r25
    1ab8:	80 93 b9 07 	sts	0x07B9, r24
  _ucsrc = ucsrc;
    1abc:	82 ed       	ldi	r24, 0xD2	; 210
    1abe:	90 e0       	ldi	r25, 0x00	; 0
    1ac0:	90 93 bc 07 	sts	0x07BC, r25
    1ac4:	80 93 bb 07 	sts	0x07BB, r24
  _udr = udr;
    1ac8:	86 ed       	ldi	r24, 0xD6	; 214
    1aca:	90 e0       	ldi	r25, 0x00	; 0
    1acc:	90 93 be 07 	sts	0x07BE, r25
    1ad0:	80 93 bd 07 	sts	0x07BD, r24
  _rxen = rxen;
    1ad4:	10 93 bf 07 	sts	0x07BF, r17
  _txen = txen;
    1ad8:	b0 93 c0 07 	sts	0x07C0, r27
  _rxcie = rxcie;
    1adc:	a0 93 c1 07 	sts	0x07C1, r26
  _udrie = udrie;
    1ae0:	f0 93 c2 07 	sts	0x07C2, r31
  _u2x = u2x;
    1ae4:	e0 93 c3 07 	sts	0x07C3, r30
    1ae8:	10 92 c8 07 	sts	0x07C8, r1
    1aec:	10 92 c7 07 	sts	0x07C7, r1
    1af0:	20 93 c9 07 	sts	0x07C9, r18
    1af4:	30 93 ca 07 	sts	0x07CA, r19
    1af8:	40 93 cb 07 	sts	0x07CB, r20
    1afc:	50 93 cc 07 	sts	0x07CC, r21

HardwareSerial::HardwareSerial(ring_buffer *rx_buffer, ring_buffer *tx_buffer,
  volatile uint8_t *ubrrh, volatile uint8_t *ubrrl,
  volatile uint8_t *ucsra, volatile uint8_t *ucsrb,
  volatile uint8_t *ucsrc, volatile uint8_t *udr,
  uint8_t rxen, uint8_t txen, uint8_t rxcie, uint8_t udrie, uint8_t u2x)
    1b00:	70 93 c6 07 	sts	0x07C6, r23
    1b04:	60 93 c5 07 	sts	0x07C5, r22
{
  _rx_buffer = rx_buffer;
    1b08:	87 ed       	ldi	r24, 0xD7	; 215
    1b0a:	96 e0       	ldi	r25, 0x06	; 6
    1b0c:	90 93 d2 07 	sts	0x07D2, r25
    1b10:	80 93 d1 07 	sts	0x07D1, r24
  _tx_buffer = tx_buffer;
    1b14:	8b e1       	ldi	r24, 0x1B	; 27
    1b16:	97 e0       	ldi	r25, 0x07	; 7
    1b18:	90 93 d4 07 	sts	0x07D4, r25
    1b1c:	80 93 d3 07 	sts	0x07D3, r24
  _ubrrh = ubrrh;
    1b20:	85 e3       	ldi	r24, 0x35	; 53
    1b22:	91 e0       	ldi	r25, 0x01	; 1
    1b24:	90 93 d6 07 	sts	0x07D6, r25
    1b28:	80 93 d5 07 	sts	0x07D5, r24
  _ubrrl = ubrrl;
    1b2c:	84 e3       	ldi	r24, 0x34	; 52
    1b2e:	91 e0       	ldi	r25, 0x01	; 1
    1b30:	90 93 d8 07 	sts	0x07D8, r25
    1b34:	80 93 d7 07 	sts	0x07D7, r24
  _ucsra = ucsra;
    1b38:	80 e3       	ldi	r24, 0x30	; 48
    1b3a:	91 e0       	ldi	r25, 0x01	; 1
    1b3c:	90 93 da 07 	sts	0x07DA, r25
    1b40:	80 93 d9 07 	sts	0x07D9, r24
  _ucsrb = ucsrb;
    1b44:	81 e3       	ldi	r24, 0x31	; 49
    1b46:	91 e0       	ldi	r25, 0x01	; 1
    1b48:	90 93 dc 07 	sts	0x07DC, r25
    1b4c:	80 93 db 07 	sts	0x07DB, r24
  _ucsrc = ucsrc;
    1b50:	82 e3       	ldi	r24, 0x32	; 50
    1b52:	91 e0       	ldi	r25, 0x01	; 1
    1b54:	90 93 de 07 	sts	0x07DE, r25
    1b58:	80 93 dd 07 	sts	0x07DD, r24
  _udr = udr;
    1b5c:	86 e3       	ldi	r24, 0x36	; 54
    1b5e:	91 e0       	ldi	r25, 0x01	; 1
    1b60:	90 93 e0 07 	sts	0x07E0, r25
    1b64:	80 93 df 07 	sts	0x07DF, r24
  _rxen = rxen;
    1b68:	10 93 e1 07 	sts	0x07E1, r17
  _txen = txen;
    1b6c:	b0 93 e2 07 	sts	0x07E2, r27
  _rxcie = rxcie;
    1b70:	a0 93 e3 07 	sts	0x07E3, r26
  _udrie = udrie;
    1b74:	f0 93 e4 07 	sts	0x07E4, r31
  _u2x = u2x;
    1b78:	e0 93 e5 07 	sts	0x07E5, r30
#endif
#if defined(UBRR2H)
  HardwareSerial Serial2(&rx_buffer2, &tx_buffer2, &UBRR2H, &UBRR2L, &UCSR2A, &UCSR2B, &UCSR2C, &UDR2, RXEN2, TXEN2, RXCIE2, UDRIE2, U2X2);
#endif
#if defined(UBRR3H)
  HardwareSerial Serial3(&rx_buffer3, &tx_buffer3, &UBRR3H, &UBRR3L, &UCSR3A, &UCSR3B, &UCSR3C, &UDR3, RXEN3, TXEN3, RXCIE3, UDRIE3, U2X3);
    1b7c:	1f 91       	pop	r17
    1b7e:	08 95       	ret

00001b80 <_ZN5Print5writeEPKhj>:
#include "Print.h"

// Public Methods //////////////////////////////////////////////////////////////

/* default implementation: may be overridden */
size_t Print::write(const uint8_t *buffer, size_t size)
    1b80:	cf 92       	push	r12
    1b82:	df 92       	push	r13
    1b84:	ef 92       	push	r14
    1b86:	ff 92       	push	r15
    1b88:	0f 93       	push	r16
    1b8a:	1f 93       	push	r17
    1b8c:	cf 93       	push	r28
    1b8e:	df 93       	push	r29
    1b90:	7c 01       	movw	r14, r24
    1b92:	6b 01       	movw	r12, r22
    1b94:	8a 01       	movw	r16, r20
    1b96:	c0 e0       	ldi	r28, 0x00	; 0
    1b98:	d0 e0       	ldi	r29, 0x00	; 0
    1b9a:	0f c0       	rjmp	.+30     	; 0x1bba <_ZN5Print5writeEPKhj+0x3a>
{
  size_t n = 0;
  while (size--) {
    n += write(*buffer++);
    1b9c:	d6 01       	movw	r26, r12
    1b9e:	6d 91       	ld	r22, X+
    1ba0:	6d 01       	movw	r12, r26
    1ba2:	d7 01       	movw	r26, r14
    1ba4:	ed 91       	ld	r30, X+
    1ba6:	fc 91       	ld	r31, X
    1ba8:	01 90       	ld	r0, Z+
    1baa:	f0 81       	ld	r31, Z
    1bac:	e0 2d       	mov	r30, r0
    1bae:	c7 01       	movw	r24, r14
    1bb0:	19 95       	eicall
    1bb2:	c8 0f       	add	r28, r24
    1bb4:	d9 1f       	adc	r29, r25
    1bb6:	01 50       	subi	r16, 0x01	; 1
    1bb8:	10 40       	sbci	r17, 0x00	; 0

/* default implementation: may be overridden */
size_t Print::write(const uint8_t *buffer, size_t size)
{
  size_t n = 0;
  while (size--) {
    1bba:	01 15       	cp	r16, r1
    1bbc:	11 05       	cpc	r17, r1
    1bbe:	71 f7       	brne	.-36     	; 0x1b9c <_ZN5Print5writeEPKhj+0x1c>
    n += write(*buffer++);
  }
  return n;
}
    1bc0:	ce 01       	movw	r24, r28
    1bc2:	df 91       	pop	r29
    1bc4:	cf 91       	pop	r28
    1bc6:	1f 91       	pop	r17
    1bc8:	0f 91       	pop	r16
    1bca:	ff 90       	pop	r15
    1bcc:	ef 90       	pop	r14
    1bce:	df 90       	pop	r13
    1bd0:	cf 90       	pop	r12
    1bd2:	08 95       	ret

00001bd4 <_ZN5Print7printlnEv>:
size_t Print::print(const Printable& x)
{
  return x.printTo(*this);
}

size_t Print::println(void)
    1bd4:	ef 92       	push	r14
    1bd6:	ff 92       	push	r15
    1bd8:	0f 93       	push	r16
    1bda:	1f 93       	push	r17
    1bdc:	8c 01       	movw	r16, r24
  return write(str);
}

size_t Print::print(char c)
{
  return write(c);
    1bde:	dc 01       	movw	r26, r24
    1be0:	ed 91       	ld	r30, X+
    1be2:	fc 91       	ld	r31, X
    1be4:	01 90       	ld	r0, Z+
    1be6:	f0 81       	ld	r31, Z
    1be8:	e0 2d       	mov	r30, r0
    1bea:	6d e0       	ldi	r22, 0x0D	; 13
    1bec:	19 95       	eicall
    1bee:	7c 01       	movw	r14, r24
size_t Print::println(void)
{
  size_t n = print('\r');
  n += print('\n');
  return n;
}
    1bf0:	d8 01       	movw	r26, r16
    1bf2:	ed 91       	ld	r30, X+
    1bf4:	fc 91       	ld	r31, X
    1bf6:	01 90       	ld	r0, Z+
    1bf8:	f0 81       	ld	r31, Z
    1bfa:	e0 2d       	mov	r30, r0
    1bfc:	c8 01       	movw	r24, r16
    1bfe:	6a e0       	ldi	r22, 0x0A	; 10
    1c00:	19 95       	eicall
    1c02:	9c 01       	movw	r18, r24
    1c04:	2e 0d       	add	r18, r14
    1c06:	3f 1d       	adc	r19, r15
    1c08:	c9 01       	movw	r24, r18
    1c0a:	1f 91       	pop	r17
    1c0c:	0f 91       	pop	r16
    1c0e:	ff 90       	pop	r15
    1c10:	ef 90       	pop	r14
    1c12:	08 95       	ret

00001c14 <_ZN5Print5writeEPKc>:
    1c14:	cf 93       	push	r28
    1c16:	df 93       	push	r29
    1c18:	ec 01       	movw	r28, r24
    1c1a:	61 15       	cp	r22, r1
    1c1c:	71 05       	cpc	r23, r1
    1c1e:	19 f4       	brne	.+6      	; 0x1c26 <_ZN5Print5writeEPKc+0x12>
    1c20:	20 e0       	ldi	r18, 0x00	; 0
    1c22:	30 e0       	ldi	r19, 0x00	; 0
    1c24:	0f c0       	rjmp	.+30     	; 0x1c44 <_ZN5Print5writeEPKc+0x30>
    1c26:	db 01       	movw	r26, r22
    1c28:	0d 90       	ld	r0, X+
    1c2a:	00 20       	and	r0, r0
    1c2c:	e9 f7       	brne	.-6      	; 0x1c28 <_ZN5Print5writeEPKc+0x14>
    1c2e:	11 97       	sbiw	r26, 0x01	; 1
    1c30:	a6 1b       	sub	r26, r22
    1c32:	b7 0b       	sbc	r27, r23
    1c34:	e8 81       	ld	r30, Y
    1c36:	f9 81       	ldd	r31, Y+1	; 0x01
    1c38:	02 80       	ldd	r0, Z+2	; 0x02
    1c3a:	f3 81       	ldd	r31, Z+3	; 0x03
    1c3c:	e0 2d       	mov	r30, r0
    1c3e:	ad 01       	movw	r20, r26
    1c40:	19 95       	eicall
    1c42:	9c 01       	movw	r18, r24
    1c44:	c9 01       	movw	r24, r18
    1c46:	df 91       	pop	r29
    1c48:	cf 91       	pop	r28
    1c4a:	08 95       	ret

00001c4c <_ZN5Print7printlnEPKc>:
  size_t n = print(s);
  n += println();
  return n;
}

size_t Print::println(const char c[])
    1c4c:	ef 92       	push	r14
    1c4e:	ff 92       	push	r15
    1c50:	0f 93       	push	r16
    1c52:	1f 93       	push	r17
    1c54:	7c 01       	movw	r14, r24
  return n;
}

size_t Print::print(const char str[])
{
  return write(str);
    1c56:	de df       	rcall	.-68     	; 0x1c14 <_ZN5Print5writeEPKc>
    1c58:	8c 01       	movw	r16, r24
}

size_t Print::println(const char c[])
{
  size_t n = print(c);
  n += println();
    1c5a:	c7 01       	movw	r24, r14
    1c5c:	bb df       	rcall	.-138    	; 0x1bd4 <_ZN5Print7printlnEv>
    1c5e:	08 0f       	add	r16, r24
    1c60:	19 1f       	adc	r17, r25
  return n;
}
    1c62:	c8 01       	movw	r24, r16
    1c64:	1f 91       	pop	r17
    1c66:	0f 91       	pop	r16
    1c68:	ff 90       	pop	r15
    1c6a:	ef 90       	pop	r14
    1c6c:	08 95       	ret

00001c6e <_Z6randoml>:
  if (seed != 0) {
    srandom(seed);
  }
}

long random(long howbig)
    1c6e:	ef 92       	push	r14
    1c70:	ff 92       	push	r15
    1c72:	0f 93       	push	r16
    1c74:	1f 93       	push	r17
    1c76:	7b 01       	movw	r14, r22
    1c78:	8c 01       	movw	r16, r24
{
  if (howbig == 0) {
    1c7a:	61 15       	cp	r22, r1
    1c7c:	71 05       	cpc	r23, r1
    1c7e:	81 05       	cpc	r24, r1
    1c80:	91 05       	cpc	r25, r1
    1c82:	29 f4       	brne	.+10     	; 0x1c8e <_Z6randoml+0x20>
    1c84:	20 e0       	ldi	r18, 0x00	; 0
    1c86:	30 e0       	ldi	r19, 0x00	; 0
    1c88:	40 e0       	ldi	r20, 0x00	; 0
    1c8a:	50 e0       	ldi	r21, 0x00	; 0
    1c8c:	0a c0       	rjmp	.+20     	; 0x1ca2 <_Z6randoml+0x34>
    return 0;
  }
  return random() % howbig;
    1c8e:	0e 94 f3 00 	call	0x1e6	; 0x1e6 <random>
    1c92:	a8 01       	movw	r20, r16
    1c94:	97 01       	movw	r18, r14
    1c96:	4d d0       	rcall	.+154    	; 0x1d32 <__divmodsi4>
    1c98:	ac 01       	movw	r20, r24
    1c9a:	cb 01       	movw	r24, r22
    1c9c:	da 01       	movw	r26, r20
    1c9e:	9c 01       	movw	r18, r24
    1ca0:	ad 01       	movw	r20, r26
}
    1ca2:	b9 01       	movw	r22, r18
    1ca4:	ca 01       	movw	r24, r20
    1ca6:	1f 91       	pop	r17
    1ca8:	0f 91       	pop	r16
    1caa:	ff 90       	pop	r15
    1cac:	ef 90       	pop	r14
    1cae:	08 95       	ret

00001cb0 <__mulsi3>:
    1cb0:	62 9f       	mul	r22, r18
    1cb2:	d0 01       	movw	r26, r0
    1cb4:	73 9f       	mul	r23, r19
    1cb6:	f0 01       	movw	r30, r0
    1cb8:	82 9f       	mul	r24, r18
    1cba:	e0 0d       	add	r30, r0
    1cbc:	f1 1d       	adc	r31, r1
    1cbe:	64 9f       	mul	r22, r20
    1cc0:	e0 0d       	add	r30, r0
    1cc2:	f1 1d       	adc	r31, r1
    1cc4:	92 9f       	mul	r25, r18
    1cc6:	f0 0d       	add	r31, r0
    1cc8:	83 9f       	mul	r24, r19
    1cca:	f0 0d       	add	r31, r0
    1ccc:	74 9f       	mul	r23, r20
    1cce:	f0 0d       	add	r31, r0
    1cd0:	65 9f       	mul	r22, r21
    1cd2:	f0 0d       	add	r31, r0
    1cd4:	99 27       	eor	r25, r25
    1cd6:	72 9f       	mul	r23, r18
    1cd8:	b0 0d       	add	r27, r0
    1cda:	e1 1d       	adc	r30, r1
    1cdc:	f9 1f       	adc	r31, r25
    1cde:	63 9f       	mul	r22, r19
    1ce0:	b0 0d       	add	r27, r0
    1ce2:	e1 1d       	adc	r30, r1
    1ce4:	f9 1f       	adc	r31, r25
    1ce6:	bd 01       	movw	r22, r26
    1ce8:	cf 01       	movw	r24, r30
    1cea:	11 24       	eor	r1, r1
    1cec:	08 95       	ret

00001cee <__udivmodsi4>:
    1cee:	a1 e2       	ldi	r26, 0x21	; 33
    1cf0:	1a 2e       	mov	r1, r26
    1cf2:	aa 1b       	sub	r26, r26
    1cf4:	bb 1b       	sub	r27, r27
    1cf6:	fd 01       	movw	r30, r26
    1cf8:	0d c0       	rjmp	.+26     	; 0x1d14 <__udivmodsi4_ep>

00001cfa <__udivmodsi4_loop>:
    1cfa:	aa 1f       	adc	r26, r26
    1cfc:	bb 1f       	adc	r27, r27
    1cfe:	ee 1f       	adc	r30, r30
    1d00:	ff 1f       	adc	r31, r31
    1d02:	a2 17       	cp	r26, r18
    1d04:	b3 07       	cpc	r27, r19
    1d06:	e4 07       	cpc	r30, r20
    1d08:	f5 07       	cpc	r31, r21
    1d0a:	20 f0       	brcs	.+8      	; 0x1d14 <__udivmodsi4_ep>
    1d0c:	a2 1b       	sub	r26, r18
    1d0e:	b3 0b       	sbc	r27, r19
    1d10:	e4 0b       	sbc	r30, r20
    1d12:	f5 0b       	sbc	r31, r21

00001d14 <__udivmodsi4_ep>:
    1d14:	66 1f       	adc	r22, r22
    1d16:	77 1f       	adc	r23, r23
    1d18:	88 1f       	adc	r24, r24
    1d1a:	99 1f       	adc	r25, r25
    1d1c:	1a 94       	dec	r1
    1d1e:	69 f7       	brne	.-38     	; 0x1cfa <__udivmodsi4_loop>
    1d20:	60 95       	com	r22
    1d22:	70 95       	com	r23
    1d24:	80 95       	com	r24
    1d26:	90 95       	com	r25
    1d28:	9b 01       	movw	r18, r22
    1d2a:	ac 01       	movw	r20, r24
    1d2c:	bd 01       	movw	r22, r26
    1d2e:	cf 01       	movw	r24, r30
    1d30:	08 95       	ret

00001d32 <__divmodsi4>:
    1d32:	97 fb       	bst	r25, 7
    1d34:	09 2e       	mov	r0, r25
    1d36:	05 26       	eor	r0, r21
    1d38:	0e d0       	rcall	.+28     	; 0x1d56 <__divmodsi4_neg1>
    1d3a:	57 fd       	sbrc	r21, 7
    1d3c:	04 d0       	rcall	.+8      	; 0x1d46 <__divmodsi4_neg2>
    1d3e:	d7 df       	rcall	.-82     	; 0x1cee <__udivmodsi4>
    1d40:	0a d0       	rcall	.+20     	; 0x1d56 <__divmodsi4_neg1>
    1d42:	00 1c       	adc	r0, r0
    1d44:	38 f4       	brcc	.+14     	; 0x1d54 <__divmodsi4_exit>

00001d46 <__divmodsi4_neg2>:
    1d46:	50 95       	com	r21
    1d48:	40 95       	com	r20
    1d4a:	30 95       	com	r19
    1d4c:	21 95       	neg	r18
    1d4e:	3f 4f       	sbci	r19, 0xFF	; 255
    1d50:	4f 4f       	sbci	r20, 0xFF	; 255
    1d52:	5f 4f       	sbci	r21, 0xFF	; 255

00001d54 <__divmodsi4_exit>:
    1d54:	08 95       	ret

00001d56 <__divmodsi4_neg1>:
    1d56:	f6 f7       	brtc	.-4      	; 0x1d54 <__divmodsi4_exit>
    1d58:	90 95       	com	r25
    1d5a:	80 95       	com	r24
    1d5c:	70 95       	com	r23
    1d5e:	61 95       	neg	r22
    1d60:	7f 4f       	sbci	r23, 0xFF	; 255
    1d62:	8f 4f       	sbci	r24, 0xFF	; 255
    1d64:	9f 4f       	sbci	r25, 0xFF	; 255
    1d66:	08 95       	ret

00001d68 <__tablejump2__>:
    1d68:	ee 0f       	add	r30, r30
    1d6a:	ff 1f       	adc	r31, r31

00001d6c <__tablejump__>:
    1d6c:	05 90       	lpm	r0, Z+
    1d6e:	f4 91       	lpm	r31, Z+
    1d70:	e0 2d       	mov	r30, r0
    1d72:	19 94       	eijmp

00001d74 <__prologue_saves__>:
    1d74:	2f 92       	push	r2
    1d76:	3f 92       	push	r3
    1d78:	4f 92       	push	r4
    1d7a:	5f 92       	push	r5
    1d7c:	6f 92       	push	r6
    1d7e:	7f 92       	push	r7
    1d80:	8f 92       	push	r8
    1d82:	9f 92       	push	r9
    1d84:	af 92       	push	r10
    1d86:	bf 92       	push	r11
    1d88:	cf 92       	push	r12
    1d8a:	df 92       	push	r13
    1d8c:	ef 92       	push	r14
    1d8e:	ff 92       	push	r15
    1d90:	0f 93       	push	r16
    1d92:	1f 93       	push	r17
    1d94:	cf 93       	push	r28
    1d96:	df 93       	push	r29
    1d98:	cd b7       	in	r28, 0x3d	; 61
    1d9a:	de b7       	in	r29, 0x3e	; 62
    1d9c:	ca 1b       	sub	r28, r26
    1d9e:	db 0b       	sbc	r29, r27
    1da0:	0f b6       	in	r0, 0x3f	; 63
    1da2:	f8 94       	cli
    1da4:	de bf       	out	0x3e, r29	; 62
    1da6:	0f be       	out	0x3f, r0	; 63
    1da8:	cd bf       	out	0x3d, r28	; 61
    1daa:	19 94       	eijmp

00001dac <__epilogue_restores__>:
    1dac:	2a 88       	ldd	r2, Y+18	; 0x12
    1dae:	39 88       	ldd	r3, Y+17	; 0x11
    1db0:	48 88       	ldd	r4, Y+16	; 0x10
    1db2:	5f 84       	ldd	r5, Y+15	; 0x0f
    1db4:	6e 84       	ldd	r6, Y+14	; 0x0e
    1db6:	7d 84       	ldd	r7, Y+13	; 0x0d
    1db8:	8c 84       	ldd	r8, Y+12	; 0x0c
    1dba:	9b 84       	ldd	r9, Y+11	; 0x0b
    1dbc:	aa 84       	ldd	r10, Y+10	; 0x0a
    1dbe:	b9 84       	ldd	r11, Y+9	; 0x09
    1dc0:	c8 84       	ldd	r12, Y+8	; 0x08
    1dc2:	df 80       	ldd	r13, Y+7	; 0x07
    1dc4:	ee 80       	ldd	r14, Y+6	; 0x06
    1dc6:	fd 80       	ldd	r15, Y+5	; 0x05
    1dc8:	0c 81       	ldd	r16, Y+4	; 0x04
    1dca:	1b 81       	ldd	r17, Y+3	; 0x03
    1dcc:	aa 81       	ldd	r26, Y+2	; 0x02
    1dce:	b9 81       	ldd	r27, Y+1	; 0x01
    1dd0:	ce 0f       	add	r28, r30
    1dd2:	d1 1d       	adc	r29, r1
    1dd4:	0f b6       	in	r0, 0x3f	; 63
    1dd6:	f8 94       	cli
    1dd8:	de bf       	out	0x3e, r29	; 62
    1dda:	0f be       	out	0x3f, r0	; 63
    1ddc:	cd bf       	out	0x3d, r28	; 61
    1dde:	ed 01       	movw	r28, r26
    1de0:	08 95       	ret

00001de2 <_exit>:
    1de2:	f8 94       	cli

00001de4 <__stop_program>:
    1de4:	ff cf       	rjmp	.-2      	; 0x1de4 <__stop_program>