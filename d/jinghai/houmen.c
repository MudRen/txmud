// Room: /d/jinghai/houmen.c

inherit ROOM;

void create()
{
	set("short", "山庄侧门");
	set("long", @LONG
没想好 呵呵

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"taohuayuan",
  "northeast" : __DIR__"shulin1",
  "west" : __DIR__"kongdi",
  "south" : __DIR__"bingqishi",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
