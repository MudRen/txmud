// Room: /d/hangzhou/shouse1.c

inherit ROOM;

void create()
{
	set("short", "茅屋");
	set("long", @LONG
这是一间用茅草搭成的小屋。屋里除了土灶，只有一些乱柴
堆放在屋角。灶里的火还的燃烧着，可能有人不久才离开。你四
处看了看，什么也没有找到。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"spath4",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
