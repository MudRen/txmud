// item_quest.c
inherit ROOM;
void create(){        
set("short", "任务测试房间");        
set("long", "这里是测试物品任务的房间，你可以：
\task man about quest/job    问任务\n"+
"\task man about fangqi/放弃    放弃任务\n"+
"\t另外还可以抢其他id的任务\n");        
set("exits", ([ /* sizeof() == 1 */  "west" : "/wiz/aiai/workroom",]));        
set("light_up", 1);        
set("objects", (["/wiz/aiai/item_quest/quester": 1 ]) );
setup();        
replace_program(ROOM);
} 
