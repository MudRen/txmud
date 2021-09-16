// Room: /u/w/wangs/a/yu12.c

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
你走进了一间小屋，房间很小，除了一张小床放不下别
的东西了。床上好象有几件叠得整整齐齐的粗布衫，洗的干
干净净。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"yu11",
]));
        set("objects", ([
        __DIR__"npc/master1": 1,
                        ]) );

	setup();
	replace_program(ROOM);
}
