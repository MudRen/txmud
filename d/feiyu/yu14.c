// Room: /u/w/wangs/a/yu14.c

inherit ROOM;

void create()
{
	set("short", "兵器室");
	set("long", @LONG
这里是绯雨阁的兵器房，四周放这几个兵器架，上面是
绯雨阁各弟子平时常用的武器。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"yu13",
]));
        set("objects", ([
        __DIR__"obj/ssword": 5,
                        ]) );

	setup();
	replace_program(ROOM);
}
