// zoulang3.c 走廊3

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","走廊");
        set("long",@LONG
这是连接大厅和西厅的走廊，站在走廊上，你只觉得凉风习习，风窗
露槛，远处鸟语入耳，近处花香扑鼻。你不由得停下脚步，细细欣赏这个
府宅的美景。北边就是绣云房，里面传来阵阵女人们欢快的笑声。
LONG);

	set("outdoors","taxue");

	set("exits",([
		"east" : __DIR__"dating",
		"west" : __DIR__"xiting",
		"north" : __DIR__"xiuyunfang",
	]));
	setup();
	replace_program(ROOM);
}
