//
// File:       HID_Config_Utilities.h
//
// Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple Inc. ("Apple")
//             in consideration of your agreement to the following terms, and your use,
//             installation, modification or redistribution of this Apple software
//             constitutes acceptance of these terms.  If you do not agree with these
//             terms, please do not use, install, modify or redistribute this Apple
//             software.
//
//             In consideration of your agreement to abide by the following terms, and
//             subject to these terms, Apple grants you a personal, non - exclusive
//             license, under Apple's copyrights in this original Apple software ( the
//             "Apple Software" ), to use, reproduce, modify and redistribute the Apple
//             Software, with or without modifications, in source and / or binary forms;
//             provided that if you redistribute the Apple Software in its entirety and
//             without modifications, you must retain this notice and the following text
//             and disclaimers in all such redistributions of the Apple Software. Neither
//             the name, trademarks, service marks or logos of Apple Inc. may be used to
//             endorse or promote products derived from the Apple Software without specific
//             prior written permission from Apple.  Except as expressly stated in this
//             notice, no other rights or licenses, express or implied, are granted by
//             Apple herein, including but not limited to any patent rights that may be
//             infringed by your derivative works or by other works in which the Apple
//             Software may be incorporated.
//
//             The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO
//             WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
//             WARRANTIES OF NON - INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A
//             PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION
//             ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
//
//             IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR
//             CONSEQUENTIAL DAMAGES ( INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//             SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//             INTERRUPTION ) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION
//             AND / OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER
//             UNDER THEORY OF CONTRACT, TORT ( INCLUDING NEGLIGENCE ), STRICT LIABILITY OR
//             OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Copyright ( C ) 2001-2008 Apple Inc. All Rights Reserved.
//

#ifndef _HID_Config_Utilities_h_
#define _HID_Config_Utilities_h_

#if 0000	// do we need this file?
#include <stdio.h>

#include "HID_Utilities.h"

enum
{
    kPercentMove = 10 // precent of overall range a element must move to register
};

struct recSaveHID
{
    int actionCookie;
    // device
	struct {
		int vendorID;
		int productID;
		int locID;
		int usage;
		int usagePage;
		// need to add serial number when I have a test case
	} device;

    // elements
	struct {
		int usagePage;
		int usage;
		int minReport; 						// min returned value
		int maxReport; 						// max returned value (calibrate call)
		void * cookie;
	} element;
	
};
typedef struct recSaveHID recSaveHID;
typedef recSaveHID * pRecSaveHID;

// polls all devices and elements for a change greater than kPercentMove.  Times out after given time
// returns true and pointer to device and element if found
// returns false and NULL for both parameters if not found
unsigned char HIDConfigureAction (IOHIDDeviceRef * outIOHIDDeviceRef, IOHIDElementRef * outIOHIDElementRef, float timeout);

// take input records, save required info
// assume file is open and at correct position.
void HIDSaveElementConfig (FILE * fileRef, IOHIDDeviceRef inIOHIDDeviceRef, IOHIDElementRef inIOHIDElementRef, int actionCookie);

// take file, read one record (assume file position is correct and file is open)
// search for matching device
// return pDevice, pElement and cookie for action
int HIDRestoreElementConfig (FILE * fileRef, IOHIDDeviceRef * outIOHIDDeviceRef, IOHIDElementRef * outIOHIDElementRef);

#endif	//  0000	// do we need this file?

#endif	// _HID_Config_Utilities_h_

