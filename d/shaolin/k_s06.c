// Room: /wiz/uudd/path2/k_s06.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
依山而行的小路在树木草丛中蜿蜒穿行，时而转过山角，时
没入树林。这条路很明显是被人用脚踏出来的，有的进方宽一点，
有的地方窄一点，被太阳烤得坚硬的黄泥地上处处印着不知是谁
踩出来的脚印。路两边的草丛里悉悉索索的似乎有什么东西要窜
出来一般。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"k_s07",
  "northeast" : __DIR__"k_s05",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
