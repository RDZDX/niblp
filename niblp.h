#ifndef _VRE_APP_WIZARDTEMPLATE_
#define	_VRE_APP_WIZARDTEMPLATE_
#define		SUPPORT_BG

#include "vmsys.h"
#include "vmio.h"
#include "string.h"
#include "stdint.h"
#include "vmtimer.h"

void checkFileExist(void);
void timer(int a);
void create_app_txt_path(VMWSTR text, VMSTR extt);

#endif