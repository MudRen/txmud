// Room: /open/path2/k_s11.c

inherit ROOM;

void create()
{
	set("short", "村间小路");
	set("long", @LONG
泥泞的路上到处是人和牲畜的脚印，几个小孩正牵着羊在路
边玩耍，一家农户的门前蹲着一位老头，他一边叭嗒叭嗒地抽着
旱烟，一边眯起眼睛上下打量着你。挨着路两边排着几间屋子使
这个小村庄显得整齐一些，北面是一家小小的杂货铺，南面是一
户人家。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"k_s12",
  "east" : __DIR__"k_s10",
  "south" : __DIR__"minjv01",
  "north" : __DIR__"shop",
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
