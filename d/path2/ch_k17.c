// Room: /d/path2/ch_k17.c

inherit ROOM;

void create()
{
	set("short", "高原大道");
	set("long", @LONG
这是一条黄土铺成的高原道，轻风拂过，路两旁的高粱沙沙
做响。抬眼看去，一望无际的黄土高原与天际相连，天空则是格
外的蓝，你不禁顿感心情舒畅。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_k16",
  "south" : __DIR__"ch_k18",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
