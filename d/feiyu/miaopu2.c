// Room: /d/feiyu/miaopu2.c

inherit __DIR__"miaopu";

void create()
{
	set("short", "草药苗圃[2]");
	set("long", @LONG
这里是绯雨阁培养草药的苗圃，可能为了怕互相影响，每一
块苗圃都用木板隔了起来。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"miaopu3",
  "south" : __DIR__"miaopu5",
  "east" : __DIR__"miaopu1",
  "north" : __DIR__"yu96",
]));

	set("outdoors","feiyu");
	setup();
}
