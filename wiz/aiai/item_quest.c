// item_quest.c
inherit ROOM;
void create(){        
set("short", "������Է���");        
set("long", "�����ǲ�����Ʒ����ķ��䣬����ԣ�
\task man about quest/job    ������\n"+
"\task man about fangqi/����    ��������\n"+
"\t���⻹����������id������\n");        
set("exits", ([ /* sizeof() == 1 */  "west" : "/wiz/aiai/workroom",]));        
set("light_up", 1);        
set("objects", (["/wiz/aiai/item_quest/quester": 1 ]) );
setup();        
replace_program(ROOM);
} 
