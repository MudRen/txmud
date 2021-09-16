// Room: /d/shaolin/puxian.c

inherit ROOM;

void create()
{
	set("short", "普贤殿");
	set("long", @LONG
这里是少林寺的普贤殿，供奉的正是普贤妙法菩萨，正见他
庄严的端坐在白象上，因为他是四大菩萨的大悲菩萨，所以这普
贤殿又被称为大悲殿。大殿里高大深邃，从这里向东是过道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lroad4",
]));

	set("objects", ([
	__DIR__"npc/huifa" : 1,
]));

	setup();
	replace_program(ROOM);
}
