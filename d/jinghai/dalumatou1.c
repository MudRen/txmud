// Room: /d/jinghai/dalumatou1.c

inherit ROOM;

void create()
{
	set("short", "海边港弯");
	set("long", @LONG


LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jinghai");
	set("item_desc", ([ /* sizeof() == 1 */
  "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。
",
]));

	setup();
	replace_program(ROOM);
}
