// Room: /d/path2/ch_k27.c

inherit ROOM;

void create()
{
	set("short", "土道");
	set("long", @LONG
这是一条黄土大道，过往的车马扬起阵阵尘土，你擦了擦脸
上的汗珠，抬头看了看炎炎的烈日，心中不禁暗自诅咒。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"ch_k28",
  "northwest" : __DIR__"ch_k26",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
