#include "hid.h"

//get HID report descriptor

/* WRONG! Endpoint is _ALWAYS_ ZERO for HID! We want the _INTERFACE_ value here!
uint8_t HID::GetReportDescr(uint8_t ep, USBReadParser *parser) {
        const uint8_t constBufLen = 64;
        uint8_t buf[constBufLen];

        uint8_t rcode = pUsb->ctrlReq(bAddress, ep, bmREQ_HIDREPORT, USB_REQUEST_GET_DESCRIPTOR, 0x00,
                HID_DESCRIPTOR_REPORT, 0x0000, 128, constBufLen, buf, (USBReadParser*)parser);

        //return ((rcode != hrSTALL) ? rcode : 0);
        return rcode;
}
 */
// uint8_t HID::GetReportDescr(uint16_t wIndex, USBReadParser *parser) {
//         const uint8_t constBufLen = 64;
//         uint8_t buf[constBufLen];
// 
//         uint8_t rcode = pUsb->ctrlReq(bAddress, 0x00, bmREQ_HIDREPORT, USB_REQUEST_GET_DESCRIPTOR, 0x00,
//                 HID_DESCRIPTOR_REPORT, wIndex, 128, constBufLen, buf, (USBReadParser*)parser);
// 
//         //return ((rcode != hrSTALL) ? rcode : 0);
//         return rcode;
// }

//uint8_t HID::getHidDescr( uint8_t ep, uint16_t nbytes, uint8_t* dataptr )
//{
//    return( pUsb->ctrlReq( bAddress, ep, bmREQ_GET_DESCR, USB_REQUEST_GET_DESCRIPTOR, 0x00, HID_DESCRIPTOR_HID, 0x0000, nbytes, dataptr ));
//}

uint8_t HID::SetReport(uint8_t ep, uint8_t iface, uint8_t report_type, uint8_t report_id, uint16_t nbytes, uint8_t* dataptr) {
        return ( pUsb->write(dataptr, nbytes));/*pUsb->ctrlReq(bAddress, ep, bmREQ_HIDOUT, HID_REQUEST_SET_REPORT, report_id, report_type, iface, nbytes, nbytes, dataptr, NULL));*/
}

uint8_t HID::GetReport(uint8_t ep, uint8_t iface, uint8_t report_type, uint8_t report_id, uint16_t nbytes, uint8_t* dataptr) {
        return ( pUsb->write(dataptr, nbytes));/*pUsb->ctrlReq(bAddress, ep, bmREQ_HIDIN, HID_REQUEST_GET_REPORT, report_id, report_type, iface, nbytes, nbytes, dataptr, NULL));*/
}

uint8_t HID::GetIdle(uint8_t iface, uint8_t reportID, uint8_t* dataptr) {
        return ( 0);/*pUsb->ctrlReq(bAddress, 0, bmREQ_HIDIN, HID_REQUEST_GET_IDLE, reportID, 0, iface, 0x0001, 0x0001, dataptr, NULL));*/
}

uint8_t HID::SetIdle(uint8_t iface, uint8_t reportID, uint8_t duration) {
        return ( 0);//pUsb->ctrlReq(bAddress, 0, bmREQ_HIDOUT, HID_REQUEST_SET_IDLE, reportID, duration, iface, 0x0000, 0x0000, NULL, NULL));
}

uint8_t HID::SetProtocol(uint8_t iface, uint8_t protocol) {
        return ( 0);//pUsb->ctrlReq(bAddress, 0, bmREQ_HIDOUT, HID_REQUEST_SET_PROTOCOL, protocol, 0x00, iface, 0x0000, 0x0000, NULL, NULL));
}

uint8_t HID::GetProtocol(uint8_t iface, uint8_t* dataptr) {
        return ( 0);//pUsb->ctrlReq(bAddress, 0, bmREQ_HIDIN, HID_REQUEST_GET_PROTOCOL, 0x00, 0x00, iface, 0x0001, 0x0001, dataptr, NULL));
}