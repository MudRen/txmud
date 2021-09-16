// Room: /d/changan/shigong.c

inherit ROOM;

void create()
{
	set("short", "施工队");
	set("long", @LONG
这里是工部衙门的施工队，一走到这里一股汉臭味道扑鼻而
来，只见几个壮汉在高声的聊天说笑，右面靠墙一排放着铁锹、
镐头的各式工具。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"gongbu",
]));
	set(SAFE_ENV,1);
	set("no_sleep_room",1);

	setup();
	replace_program(ROOM);
}
