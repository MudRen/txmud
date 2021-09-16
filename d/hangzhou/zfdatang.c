// Room: /d/hangzhou/zfdatang.c

inherit ROOM;

void create()
{
	set("short", "大堂");
	set("long", @LONG
这是知府衙门的大堂，在门梁上最醒目的地方挂着一个金字
牌匾，上面写着“公正廉明”四个大字，门口摆着一张大鼓，正
堂上有一个红木长案，上面摆着一块惊堂木和一匣令牌。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zfyuanzi",
  "north" : __DIR__"zfpath6",
]));

	setup();
	replace_program(ROOM);
}
