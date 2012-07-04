REM Build Bat File
REM Precheck the Resource 
"C:\Program Files\MRE SDK V2.0\tools\ResEditor\CmdShell.exe" save  "C:\git\test\test\test.vcproj"
REM Copmile c file 
"C:\Program Files\ARM\ADSv1_2\Bin\armcc" -O2 -apcs /ropi/rwpi -cpu ARM7EJ-S -o "C:\git\test\test\arm\vmmain.o" -c "C:\Program Files\MRE SDK V2.0\lib\MRE20\src\vmmain.c"      -D _MINIGUI_LIB_ -D _USE_MINIGUIENTRY -D _NOUNIX_ -D _FOR_WNC -D __MRE_SDK__ -D   __MRE_VENUS_NORMAL__  -D  __MMI_MAINLCD_240X320__ -I "C:\Program Files\MRE SDK V2.0\include" -I "C:\Program Files\MRE SDK V2.0\include\service" -I "C:\git\test\test\include\MRE20" -I "C:\git\test\test\include\MRE20\service" -I "C:\git\test\test\include\MRE20\component" -I "C:\git\test\test\ResID" -I "C:\git\test\test" -errors "C:\git\test\test\test.log"
REM Copmile c file 
"C:\Program Files\ARM\ADSv1_2\Bin\armcc" -O2 -apcs /ropi/rwpi -cpu ARM7EJ-S -o "C:\git\test\test\arm\test.o" -c "c:\git\test\test\test.c"      -D _MINIGUI_LIB_ -D _USE_MINIGUIENTRY -D _NOUNIX_ -D _FOR_WNC -D __MRE_SDK__ -D   __MRE_VENUS_NORMAL__  -D  __MMI_MAINLCD_240X320__ -I "C:\Program Files\MRE SDK V2.0\include" -I "C:\Program Files\MRE SDK V2.0\include\service" -I "C:\git\test\test\include\MRE20" -I "C:\git\test\test\include\MRE20\service" -I "C:\git\test\test\include\MRE20\component" -I "C:\git\test\test\ResID" -I "C:\git\test\test" -errors "C:\git\test\test\test.log"
REM Link app 
"C:\Program Files\ARM\ADSv1_2\Bin\armlink" -o "C:\git\test\test\test.axf"  "C:\git\test\test\arm\vmmain.o"  "C:\git\test\test\arm\test.o" -info totals -rwpi -ropi -nodebug  "C:\Program Files\MRE SDK V2.0\lib\MRE20\armads\percommon.a" "C:\Program Files\MRE SDK V2.0\lib\MRE20\armads\pertcp.a" "C:\Program Files\MRE SDK V2.0\lib\MRE20\armads\persensor.a" "C:\Program Files\MRE SDK V2.0\lib\MRE20\armads\persmsper.a" "C:\Program Files\MRE SDK V2.0\lib\MRE20\armads\perbitstream.a" "C:\Program Files\MRE SDK V2.0\lib\MRE20\armads\percontact.a" "C:\Program Files\MRE SDK V2.0\lib\MRE20\armads\permms.a" "C:\Program Files\MRE SDK V2.0\lib\MRE20\armads\persmsmng.a" -errors "C:\git\test\test\test.log"
REM Pack resource to app 
"C:\Program Files\MRE SDK V2.0\tools\ResEditor\CmdShell.exe" pack -silent -resolution 240x320 -o "C:\git\test\test\test.pkd" -e AXF "C:\git\test\test\test.vcproj" "C:\git\test\test\test.axf"
REM Add tag infromation 
"C:\Program Files\MRE SDK V2.0\tools\PackDigist.exe" "C:\git\test\test\test.vcproj" "Demo" "0.1.0" "MediaTek Inc." "500" "NotSupportBg" "Not Support rotate" "Demo" "Demo" "Demo" "1234567890" "content" " TCP Sensor SMS(person) BitStream Contact MMS SMSMng" "vxp" "ADS" "PKD" "UnCompress" "NoVenus" "UnAdaptable" "15728960" "UnSysMemAble" "" "-1"  C:\git\test\test\arm C:\git\test\test\build.log

