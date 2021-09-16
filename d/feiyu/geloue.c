// Room: /wiz/louth/a/geloue.c

inherit ROOM;

void create()
{
	set("short", "阁楼内屋");
	set("long", @LONG
这里是梅林阁二楼的侧屋，透过开在四面的小窗，那美丽
的梅圆尽收眼底，其景美不胜收。阁楼的一角，有一扇大屏风
(ping feng)挡住了你的视线。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yu56",
]));

	setup();
}
