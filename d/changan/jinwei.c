// Room: /d/changan/jinwei.c

inherit ROOM;

void create()
{
	set("short", "禁卫营");
	set("long", @LONG
这里是守卫皇宫的禁卫们驻扎的地方，几队官兵正在操场上
操练，不远的地方几十间营房整齐的排列着，东面不远的地方就
是御马房了。你看到有几名禁卫面色不善地对你指指点点，看来
还是少沾此地为妙。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yuma",
  "north" : __DIR__"shroad3",
]));

	setup();
	replace_program(ROOM);
}
