// Room: /d/shaolin/shiwu.c

inherit ROOM;

void create()
{
	set("short", "清冷石屋");
	set("long", @LONG
这里是少林寺的一间清冷的石屋，是处罚一些犯戒的僧人的
地方，石屋里空空荡荡的，只有一个蒲团，在门的不远处的石碑
上刻着一幅对联(couplet)，是告诫面壁僧人好好反省自己的意，
从这里向东是戒律院。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "couplet" : "      一苇渡江启宗门法渚
      九年面壁传冷坐禅心
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jielv",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
