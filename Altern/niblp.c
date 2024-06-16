#include "niblp.h"

void vm_main(void) {

    //vm_pmng_set_bg();
    checkFileExist();

}

void checkFileExist(void) {

    VMWCHAR f_wname[100];
    VMWCHAR ucs2_data[500];
    VMFILE f_read;
    VMUINT nread;
    //VMCHAR MyUrl[500] = "http://www.google.com/m/search?client=ms-mtk";
    VMCHAR MyUrl[500];
    //VMWSTR filename;

    create_app_txt_path(f_wname, "txt");
    f_read = vm_file_open(f_wname, MODE_READ, FALSE);

    if (f_read < 0) {
       vm_file_close(f_read);

       //vm_ascii_to_ucs2(ucs2_data, (strlen(MyUrl) + 1) * 2, MyUrl);
       //vm_start_native_browser(ucs2_data);

       //vm_get_exec_filename(filename); //get current application file name
       //vm_pmng_set_fg(filename);

       vm_ascii_to_ucs2(ucs2_data, 22, "Input URL:");
       vm_input_set_editor_title(ucs2_data);
       vm_input_text3(NULL, 500, 32, f1);

    } else {
      //vm_create_timer_ex(500,timer);
      //strcpy(MyUrl, "");
      vm_file_read(f_read, MyUrl, 500, &nread);
      MyUrl[nread] = '\0';
      vm_file_close(f_read);
      vm_ascii_to_ucs2(ucs2_data, (strlen(MyUrl) + 1) * 2, MyUrl);
      vm_start_native_browser(ucs2_data);
      //vm_exit_app();
      vm_create_timer_ex(10,timer);
    }

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

//void f1(VMINT state, VMWSTR text) {

//    if (state == VM_INPUT_OK && wstrlen(text) > 0) {
//       vm_start_native_browser(text);
//       vm_exit_app();
//       //vm_create_timer_ex(10,timer);
//    }
//    else {vm_exit_app();
//    }
//}

void f1(VMINT state, VMWSTR text) {

    if (state == VM_INPUT_OK && wstrlen(text) > 0) {
       vm_start_native_browser(text);
    }
       vm_exit_app();
}