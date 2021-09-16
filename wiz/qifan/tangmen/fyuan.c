// Room: /d/tangmen/fyuan.c

inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
这里是前院的小广场，用青砖铺就的地面非常整洁，正中央
的大石墩上竖着高高的旗杆，上面的蓝绸大旗上用金线绣着斗大
的“唐”字。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gd3",
  "south" : __DIR__"gd2",
  "east" : __DIR__"yanwu",
  "west" : __DIR__"keting",
]));

	set("valid_startroom", 1);
	set(SAFE_ENV, 1);
	set("outdoors", "tangmen");
	setup();

	load_board("board_tangmen");
}
