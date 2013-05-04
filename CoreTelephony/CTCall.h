/*
 * CoreTelephony calling support.
 */

#ifndef _CTCall_H_
#define _CTCall_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

/*
 * Opaque structure definition.
 */

typedef struct __CTCall *CTCallRef;

typedef enum {
    kCTCallStatusUnknown = 0,
    kCTCallStatusAnswered,
    kCTCallStatusDroppedInterrupted,
    kCTCallStatusOutgoingInitiated,
    kCTCallStatusIncomingCall,
    kCTCallStatusIncomingCallEnded
} kCTCallStatus;

#pragma mark - API

CFArrayRef CTCopyCurrentCalls(CFAllocatorRef allocator);

CFStringRef CTCallCopyAddress(CFAllocatorRef allocator, CTCallRef call);
CFStringRef CTCallCopyName(CFAllocatorRef allocator, CTCallRef call);

double CTCallGetDuration(CTCallRef call);
double CTCallGetStartTime(CTCallRef call);

kCTCallStatus CTCallGetStatus(CTCallRef call);

void CTCallHold(CTCallRef call);
void CTCallResume(CTCallRef call);
void CTCallDisconnect(CTCallRef call);

Boolean CTCallIsConferenced(CTCallRef call);
Boolean CTCallIsAlerting(CTCallRef call);
Boolean CTCallIsToVoicemail(CTCallRef call);
Boolean CTCallIsOutgoing(CTCallRef call);

/*
 * The phone number passed in the dial functions must be normalized.
 * E.g. +1 (555) 555-5555 would become 15555555555.
 * One can use CPPhoneNumberCopyNormalized from AppSupport.framework to normalize phone numbers.
 */

CTCallRef CTCallDial(CFStringRef number);
CTCallRef CTCallDialEmergency(CFStringRef number);

__END_DECLS

#endif /* _CTCall_H_ */