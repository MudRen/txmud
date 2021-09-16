// Room: /d/path2/ch_t30.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土小路，路的两边稀疏地长着一些杂草，看起来
这里很少有人经过，显得十分荒凉。再向西去就是天水镇了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ch_t29",
  "west" : "/d/tianshui/xiaolu4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
