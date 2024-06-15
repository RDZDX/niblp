REM Build Bat File
REM Precheck the Resource 
"C:\Program Files\MRE SDK V3.0.00\tools\ResEditor\CmdShell.exe" save  "D:\MyGitHub\niblp\niblp.vcproj"
REM Copmile c file 
"C:\Program Files (x86)\CodeSourcery\Sourcery_CodeBench_Lite_for_ARM_EABI\Bin\arm-none-eabi-gcc" -c -fpic -g -mcpu=arm7tdmi-s -fvisibility=hidden -mthumb -mlittle-endian -O2 -D__MRE_COMPILER_GCC__ -fno-exceptions -fno-non-call-exceptions -o "D:\MyGitHub\niblp\arm\gccmain.o" -c "C:\Program Files\MRE SDK V3.0.00\lib\MRE30\src\gccmain.c"      -D _MINIGUI_LIB_ -D _USE_MINIGUIENTRY -D _NOUNIX_ -D _FOR_WNC -D __MRE_SDK__ -D   __MRE_VENUS_NORMAL__  -D  __MMI_MAINLCD_240X320__ -I "C:\Program Files\MRE SDK V3.0.00\include" -I "C:\Program Files\MRE SDK V3.0.00\include\service" -I "D:\MyGitHub\niblp\include" -I "D:\MyGitHub\niblp\include\service" -I "D:\MyGitHub\niblp\include\component" -I "D:\MyGitHub\niblp\ResID" -I "D:\MyGitHub\niblp\src\app\widget" -I "D:\MyGitHub\niblp\src\app\launcher" -I "D:\MyGitHub\niblp\src\app\wallpaper" -I "D:\MyGitHub\niblp\src\app\screen_lock" -I "D:\MyGitHub\niblp\include\service" -I "D:\MyGitHub\niblp\include\component" -I "D:\MyGitHub\niblp\include\service" -I "D:\MyGitHub\niblp\src\framework" -I "D:\MyGitHub\niblp\src\framework\ui_core\base" -I "D:\MyGitHub\niblp\src\framework\ui_core\mvc" -I "D:\MyGitHub\niblp\src\framework\ui_core\pme" -I "D:\MyGitHub\niblp\src\framework\mmi_core" -I "D:\MyGitHub\niblp\src\ui_engine\vrt\interface" -I "D:\MyGitHub\niblp\src\component" -I "D:\MyGitHub\niblp\src\ui_engine\framework\xml" -I "D:\MyGitHub\niblp"
REM Copmile c file 
"C:\Program Files (x86)\CodeSourcery\Sourcery_CodeBench_Lite_for_ARM_EABI\Bin\arm-none-eabi-gcc" -c -fpic -g -mcpu=arm7tdmi-s -fvisibility=hidden -mthumb -mlittle-endian -O2 -D__MRE_COMPILER_GCC__ -fno-exceptions -fno-non-call-exceptions -o "D:\MyGitHub\niblp\arm\niblp.o" -c "d:\MyGitHub\niblp\niblp.c"      -D _MINIGUI_LIB_ -D _USE_MINIGUIENTRY -D _NOUNIX_ -D _FOR_WNC -D __MRE_SDK__ -D   __MRE_VENUS_NORMAL__  -D  __MMI_MAINLCD_240X320__ -I "C:\Program Files\MRE SDK V3.0.00\include" -I "C:\Program Files\MRE SDK V3.0.00\include\service" -I "D:\MyGitHub\niblp\include" -I "D:\MyGitHub\niblp\include\service" -I "D:\MyGitHub\niblp\include\component" -I "D:\MyGitHub\niblp\ResID" -I "D:\MyGitHub\niblp\src\app\widget" -I "D:\MyGitHub\niblp\src\app\launcher" -I "D:\MyGitHub\niblp\src\app\wallpaper" -I "D:\MyGitHub\niblp\src\app\screen_lock" -I "D:\MyGitHub\niblp\include\service" -I "D:\MyGitHub\niblp\include\component" -I "D:\MyGitHub\niblp\include\service" -I "D:\MyGitHub\niblp\src\framework" -I "D:\MyGitHub\niblp\src\framework\ui_core\base" -I "D:\MyGitHub\niblp\src\framework\ui_core\mvc" -I "D:\MyGitHub\niblp\src\framework\ui_core\pme" -I "D:\MyGitHub\niblp\src\framework\mmi_core" -I "D:\MyGitHub\niblp\src\ui_engine\vrt\interface" -I "D:\MyGitHub\niblp\src\component" -I "D:\MyGitHub\niblp\src\ui_engine\framework\xml" -I "D:\MyGitHub\niblp"
REM Link app 
"C:\Program Files (x86)\CodeSourcery\Sourcery_CodeBench_Lite_for_ARM_EABI\Bin\arm-none-eabi-gcc" -o "D:\MyGitHub\niblp\niblp.axf"  "D:\MyGitHub\niblp\arm\gccmain.o"  "D:\MyGitHub\niblp\arm\niblp.o" -fpic -msvr4-struct-return -pie  -T "C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\scat.ld" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\percommon.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\perpro.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\perfile.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\persysstorage.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\persysfile.a"
REM Pack resource to app 
"C:\Program Files\MRE SDK V3.0.00\tools\ResEditor\CmdShell.exe" pack -silent -resolution 240x320 -o "D:\MyGitHub\niblp\niblp.pkd" -e AXF "D:\MyGitHub\niblp\niblp.vcproj" "D:\MyGitHub\niblp\niblp.axf"
REM Add tag infromation 
"C:\Program Files\MRE SDK V3.0.00\tools\PackDigist.exe" "D:\MyGitHub\niblp\niblp.vcproj" "Niblp" "0.1.0" "RDZDX" "0" "supportBg" "Not Support rotate" "Niblp" "Niblp" "Niblp" "9246012102087182" "content" " ProMng File SysStorage SysFile" "vxp" "GCC" "PKD" "UnCompress" "NoVPI" "Adaptable" "15728960" "UnSysMemAble" "
    " "-1" "UNPUSH" "-1" ""  "UnAutoStart"  "UnTransferImg" "NoIdleShortcut"  D:\MyGitHub\niblp\arm D:\MyGitHub\niblp\build.log

