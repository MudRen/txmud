// Room: /wiz/louth/a/huaner_qinshi.c

inherit ROOM;

void create()
{
	set("short", "寝室");
	set("long", @LONG
走进这间房间，房间里有股淡淡的清香，好象是个小姐
个闺房，整间屋子被打扫的纤尘不染房间里的装饰，清新高
雅让人有种心旷神怡的感觉。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"fyyg",
]));

	setup();
	replace_program(ROOM);
}
