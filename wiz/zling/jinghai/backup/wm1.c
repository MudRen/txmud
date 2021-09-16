// Room: /d/jinghai/wm1.c

inherit ROOM;

void create()
{
	set("short", "无名堡西码头");
	set("long", @LONG
此处又是一座码头，这儿的水很浅，所在在码头上往海中较
深的地方斜斜地砌了一道栈桥，栈桥尽头孤零零地停靠着一艘小
船。码头边的根枯树干上钉了一块木板，上面写着：《无名堡专
用码头》。
LONG
	);
	set("outdoors", "jinghai");
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"wm11",
]));

	setup();
	replace_program(ROOM);
}
