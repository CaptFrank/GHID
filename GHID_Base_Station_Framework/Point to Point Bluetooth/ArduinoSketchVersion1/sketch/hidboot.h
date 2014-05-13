/* Copyright (C) 2011 Circuits At Home, LTD. All rights reserved.

This software may be distributed and modified under the terms of the GNU
General Public License version 2 (GPL2) as published by the Free Software
Foundation and appearing in the file GPL2.TXT included in the packaging of
this file. Please note that GPL2 Section 2[b] requires that all works based
on this software must also be made publicly available under the terms of
the GPL2 ("Copyleft").

Contact information
-------------------

Circuits At Home, LTD
Web      :  http://www.circuitsathome.com
e-mail   :  support@circuitsathome.com
 */
#if !defined(__HIDBOOT_H__)
#define __HIDBOOT_H__

#include "hid.h"

#define UHS_HID_BOOT_KEY_ZERO           0x27
#define UHS_HID_BOOT_KEY_ENTER          0x28
#define UHS_HID_BOOT_KEY_SPACE          0x2c
#define UHS_HID_BOOT_KEY_CAPS_LOCK      0x39
#define UHS_HID_BOOT_KEY_SCROLL_LOCK    0x47
#define UHS_HID_BOOT_KEY_NUM_LOCK       0x53
#define UHS_HID_BOOT_KEY_ZERO2          0x62
#define UHS_HID_BOOT_KEY_PERIOD         0x63

// Don't worry, GCC will optimize the result to a final value.
#define bitsEndpoints(p) ((((p) & HID_PROTOCOL_KEYBOARD)? 2 : 0) | (((p) & HID_PROTOCOL_MOUSE)? 1 : 0))
#define totalEndpoints(p) ((bitsEndpoints(p) == 3) ? 3 : 2)
#define epMUL(p) ((((p) & HID_PROTOCOL_KEYBOARD)? 1 : 0) + (((p) & HID_PROTOCOL_MOUSE)? 1 : 0))

// Already defined in hid.h
// #define HID_MAX_HID_CLASS_DESCRIPTORS 5

struct MOUSEINFO {

        struct {
                uint8_t bmLeftButton : 1;
                uint8_t bmRightButton : 1;
                uint8_t bmMiddleButton : 1;
                uint8_t bmDummy : 5;
        };
        int8_t dX;
        int8_t dY;
};

class MouseReportParser : public HIDReportParser {

        union {
                MOUSEINFO mouseInfo;
                uint8_t bInfo[sizeof (MOUSEINFO)];
        } prevState;

public:
        virtual void Parse(HID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf);

protected:

        virtual void OnMouseMove(MOUSEINFO *mi) {
        };

        virtual void OnLeftButtonUp(MOUSEINFO *mi) {
        };

        virtual void OnLeftButtonDown(MOUSEINFO *mi) {
        };

        virtual void OnRightButtonUp(MOUSEINFO *mi) {
        };

        virtual void OnRightButtonDown(MOUSEINFO *mi) {
        };

        virtual void OnMiddleButtonUp(MOUSEINFO *mi) {
        };

        virtual void OnMiddleButtonDown(MOUSEINFO *mi) {
        };
};

struct MODIFIERKEYS {
        uint8_t bmLeftCtrl : 1;
        uint8_t bmLeftShift : 1;
        uint8_t bmLeftAlt : 1;
        uint8_t bmLeftGUI : 1;
        uint8_t bmRightCtrl : 1;
        uint8_t bmRightShift : 1;
        uint8_t bmRightAlt : 1;
        uint8_t bmRightGUI : 1;
};

struct KBDINFO {

        struct {
                uint8_t bmLeftCtrl : 1;
                uint8_t bmLeftShift : 1;
                uint8_t bmLeftAlt : 1;
                uint8_t bmLeftGUI : 1;
                uint8_t bmRightCtrl : 1;
                uint8_t bmRightShift : 1;
                uint8_t bmRightAlt : 1;
                uint8_t bmRightGUI : 1;
        };
        uint8_t bReserved;
        uint8_t Keys[6];
};

struct KBDLEDS {
        uint8_t bmNumLock : 1;
        uint8_t bmCapsLock : 1;
        uint8_t bmScrollLock : 1;
        uint8_t bmCompose : 1;
        uint8_t bmKana : 1;
        uint8_t bmReserved : 3;
};

class KeyboardReportParser : public HIDReportParser {
        static const uint8_t numKeys[10];
        static const uint8_t symKeysUp[12];
        static const uint8_t symKeysLo[12];
        static const uint8_t padKeys[5];

protected:

        union {
                KBDINFO kbdInfo;
                uint8_t bInfo[sizeof (KBDINFO)];
        } prevState;

        union {
                KBDLEDS kbdLeds;
                uint8_t bLeds;
        } kbdLockingKeys;

        uint8_t OemToAscii(uint8_t mod, uint8_t key);

public:

        KeyboardReportParser() {
                kbdLockingKeys.bLeds = 0;
        };

        virtual void Parse(HID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf);

protected:
        virtual uint8_t HandleLockingKeys(HID* hid, uint8_t key);

        virtual void OnControlKeysChanged(uint8_t before, uint8_t after) {
        };

        virtual void OnKeyDown(uint8_t mod, uint8_t key) {
        };

        virtual void OnKeyUp(uint8_t mod, uint8_t key) {
        };

        virtual const uint8_t *getNumKeys() {
                return numKeys;
        };

        virtual const uint8_t *getSymKeysUp() {
                return symKeysUp;
        };

        virtual const uint8_t *getSymKeysLo() {
                return symKeysLo;
        };

        virtual const uint8_t *getPadKeys() {
                return padKeys;
        };
};

template <const uint8_t BOOT_PROTOCOL>
class HIDBoot : public HID //public USBDeviceConfig, public UsbConfigXtracter
{
        //EpInfo epInfo[totalEndpoints(BOOT_PROTOCOL)];
        HIDReportParser *pRptParser[epMUL(BOOT_PROTOCOL)];

        uint8_t bConfNum; // configuration number
        uint8_t bIfaceNum; // Interface Number
        uint8_t bNumIface; // number of interfaces in the configuration
        uint8_t bNumEP; // total number of EP in the configuration
        uint32_t qNextPollTime; // next poll time
        bool bPollEnable; // poll enable flag
        uint8_t bInterval; // largest interval

        void Initialize();

        virtual HIDReportParser* GetReportParser(uint8_t id) {
                return pRptParser[id];
        };

public:
        HIDBoot(HardwareSerial *p);

        virtual bool SetReportParser(uint8_t id, HIDReportParser *prs) {
                pRptParser[id] = prs;
                return true;
        };

        // USBDeviceConfig implementation
/*        virtual uint8_t Init(uint8_t parent, uint8_t port, bool lowspeed);*/
        virtual uint8_t Release();
        virtual uint8_t Poll();

//         virtual uint8_t GetAddress() {
//                 return bAddress;
//         };
// 
//         // UsbConfigXtracter implementation
//         virtual void EndpointXtract(uint8_t conf, uint8_t iface, uint8_t alt, uint8_t proto, const USB_ENDPOINT_DESCRIPTOR *ep);
};

template <const uint8_t BOOT_PROTOCOL>
HIDBoot<BOOT_PROTOCOL>::HIDBoot(HardwareSerial *p) :
HID(p),
qNextPollTime(0),
bPollEnable(false) {
        Initialize();

        for(int i = 0; i < epMUL(BOOT_PROTOCOL); i++) {
                pRptParser[i] = NULL;
        }
}

template <const uint8_t BOOT_PROTOCOL>
void HIDBoot<BOOT_PROTOCOL>::Initialize() {

        bNumEP = 1;
        bNumIface = 0;
        bConfNum = 0;
}

template <const uint8_t BOOT_PROTOCOL>
uint8_t HIDBoot<BOOT_PROTOCOL>::Release() {

        bConfNum = 0;
        bIfaceNum = 0;
        bNumEP = 1;
        bAddress = 0;
        qNextPollTime = 0;
        bPollEnable = false;

        return 0;
}

template <const uint8_t BOOT_PROTOCOL>
uint8_t HIDBoot<BOOT_PROTOCOL>::Poll() {
        uint8_t rcode = 0;

        if(bPollEnable && qNextPollTime <= millis()) {

                // To-do: optimize manually, using the for loop only if needed.
                for(int i = 0; i < epMUL(BOOT_PROTOCOL); i++) {
                        const uint16_t const_buff_len = 16;
                        uint8_t buf[const_buff_len];

                        uint16_t read = (uint16_t)pUsb->available();

                        rcode = pUsb->readBytes(buf, read);
                        // SOME buggy dongles report extra keys (like sleep) using a 2 byte packet on the wrong endpoint.
                        // Since keyboard and mice must report at least 3 bytes, we ignore the extra data.
                        if(!rcode && read > 2) {
                                if(pRptParser[i])
                                        pRptParser[i]->Parse((HID*)this, 0, (uint8_t)read, buf);
                        }

                }
                qNextPollTime = millis() + bInterval;
        }
        return rcode;
}

#endif // __HIDBOOTMOUSE_H__
