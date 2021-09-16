// Room: /u/w/wangs/a/yu96.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
这是树林中的一条杂草丛生的羊肠小路，看起来平时没
什么人迹，路边开着不知名的野花，两边的松树依然高大、
挺拔。阳光透下来照的你身上是斑斑驳驳的影子。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"yu95",
  "east" : __DIR__"yu97",
  "south" : __DIR__"miaopu2",
]));
	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
