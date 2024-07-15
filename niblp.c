#include "niblp.h"

VMCHAR my_string1[100];

void vm_main(void) {

    vm_pmng_set_bg();
    vm_reg_sysevt_callback(handle_sysevt);
    checkFileExist();
}

void handle_sysevt(VMINT message, VMINT param) {

        VMSTR str;
        //VMWSTR wstr;

	if (message == VM_MSG_CREATE){
	   //wstr = (VMWSTR)param;
	   str = (VMSTR)param;
           if (strlen(str) > 0 ) { sprintf(my_string1, "%s", str); }
	}
}

void checkFileExist(void) {

    VMWCHAR f_wname[100];
    //VMWCHAR f_wname1[100];
    VMWCHAR ucs2_data[500];
    VMFILE f_read;
    VMUINT nread;
    VMCHAR MyUrl[500] = "http://www.bing.com";

    vm_process_property property;
    vm_process_property property1;

    vm_pmng_get_process_property(vm_pmng_get_current_handle(),&property);
    vm_pmng_get_process_property(property.pParentHandle, &property1);

    create_app_new_path(f_wname, "271123656.vxp");

    if (property1.appID == 2) {                         // Bing menu - parent process #2
       if (vm_file_get_attributes(f_wname) != -1) {     // find 271123656.vxp file
          if (strlen(my_string1) > 0) {
             vm_start_app_with_para(f_wname, 0, 0, my_string1, strlen(my_string1) + 1);
          } else {
             vm_start_app(f_wname, 0, 0); }
       } else {
          if (strlen(my_string1) > 0) {
             vm_ascii_to_ucs2(ucs2_data, (strlen(my_string1) + 1) * 2, my_string1);
             vm_start_native_browser(ucs2_data);
          } else {
             vm_ascii_to_ucs2(ucs2_data, (strlen(MyUrl) + 1) * 2, MyUrl);
             vm_start_native_browser(ucs2_data);
          }
       }
    }

    if (property1.appID != 2) {                         // Opera == 1

       strcpy(MyUrl, "http://www.google.com/m/search?client=ms-mtk");
       create_app_txt_path(f_wname, "txt");
       f_read = vm_file_open(f_wname, MODE_READ, FALSE);

       if (f_read >= 0) {
          vm_file_read(f_read, MyUrl, 500, &nread);
          MyUrl[nread] = '\0';
       }

       vm_file_close(f_read);
       if (strlen(my_string1) > 0) {strcpy(MyUrl, my_string1);}
       vm_ascii_to_ucs2(ucs2_data, (strlen(MyUrl) + 1) * 2, MyUrl);

       vm_start_native_browser(ucs2_data);

    }

    vm_create_timer_ex(10,timer);

}

void timer(int a) {
     vm_delete_timer_ex(a);
     vm_exit_app();
}

void create_app_txt_path(VMWSTR text, VMSTR extt) {

    VMWCHAR fullPath[100];
    VMWCHAR wfile_extension[4];

    vm_get_exec_filename(fullPath);
    vm_ascii_to_ucs2(wfile_extension, 8, extt);
    vm_wstrncpy(text, fullPath, vm_wstrlen(fullPath) - 3);
    vm_wstrcat(text, wfile_extension);

}

void create_app_new_path(VMWSTR text, VMSTR My_vxp) {

    VMWCHAR fullPath[100];
    VMWCHAR appName[100];
    VMWCHAR wfile_extension[100];

    vm_get_exec_filename(fullPath);
    vm_get_filename(fullPath, appName);
    vm_ascii_to_ucs2(wfile_extension, (strlen(My_vxp) + 1) * 2, My_vxp);
    vm_wstrncpy(text, fullPath, vm_wstrlen(fullPath) - wstrlen(appName));
    vm_wstrcat(text, wfile_extension);

}