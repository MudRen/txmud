// Room: /d/feiyu/miaopu9.c

inherit __DIR__"miaopu";

void create()
{
	set("short", "草药苗圃[9]");
	set("long", @LONG
这里是绯雨阁培养草药的苗圃，可能为了怕互相影响，每一
块苗圃都用木板隔了起来。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"miaopu8",
  "north" : __DIR__"miaopu4",
]));

	set("outdoors","feiyu");
	setup();
}
