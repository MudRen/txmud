// Room: /d/huashan/xiaolu6.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
这是一条林间的小路，风一吹动，传来阵阵野花清香。纵横
交错的溪水时隐时现，谁也不知它们是从那里来的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"xianzhangya",
  "southdown" : __DIR__"xiaolu5",
  "northwest":"/d/huashan_zx/guange3"
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
