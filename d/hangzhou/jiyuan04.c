// Room: /d/hangzhou/jiyuan04.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是后花厅的走廊，长廊的另一侧是三位姑娘的闺房所在
，长廊的顶端每隔几尺就有一盏花灯，在灯光辉映下长廊现得分
外温馨。在每位姑娘的房间门口还悬挂个一个灯球，当灯球点起
时，意味着贵客在此，请勿打扰。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"jiyuan07",
  "north" : __DIR__"jiyuan02",
]));

	setup();
	replace_program(ROOM);
}
