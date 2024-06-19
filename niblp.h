#ifndef _VRE_APP_WIZARDTEMPLATE_
#define	_VRE_APP_WIZARDTEMPLATE_
#define		SUPPORT_BG

#include "vmsys.h"
#include "vmio.h"
#include "string.h"
#include "stdint.h"
#include "vmtimer.h"
#include "vmpromng.h"
#include "vmstdlib.h"
#include "vmmm.h"

void checkFileExist(void);
void timer(int a);
void create_app_txt_path(VMWSTR text, VMSTR extt);
void create_app_new_path(VMWSTR text, VMSTR My_vxp);
#endif