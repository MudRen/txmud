// Room: /d/huashan/shibi.c

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long", @LONG
你一进来，就看见三面墙壁上刻着密密麻麻的字符和文字，
不知道是什么东东。地上放着一个棉垫。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"dongtian",
]));

	set("objects", ([
		__DIR__"npc/master-yue":1,
]));

	setup();
	replace_program(ROOM);
}
