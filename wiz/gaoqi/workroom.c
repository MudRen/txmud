
inherit ROOM;

void create()
{
    set("short", "乱的工作室");
	set("long", @LONG
这是一个空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
"down" : "/wiz/gaoqi/gaibang/caochang",
]));	setup();
}
