// midao1.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "秘道");
	set("long", @LONG
这条地道一路向下。地道两旁点着几盏油灯，昏灯如豆，前面一片
阴沉沉的不知道通往那里。
LONG);
       
        set("exits", ([
		 "east" : __DIR__"midao2",
		 "west" : __DIR__"midao",
	])); 

	setup();
	replace_program(ROOM);
}
