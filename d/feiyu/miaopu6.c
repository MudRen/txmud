// Room: /d/feiyu/miaopu6.c

inherit __DIR__"miaopu";

void create()
{
	set("short", "草药苗圃[6]");
	set("long", @LONG
这里是绯雨阁培养草药的苗圃，可能为了怕互相影响，每一
块苗圃都用木板隔了起来。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"miaopu5",
  "south" : __DIR__"miaopu7",
  "north" : __DIR__"miaopu1",
]));

	set("outdoors","feiyu");
	setup();
}
