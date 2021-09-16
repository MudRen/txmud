// Room: /d/huashan/santai.c

inherit ROOM;

void create()
{
	set("short", "三息台");
	set("long", @LONG
华山上竞有这一平台，无怪人称“无限风光在险峰”，在这
里你可以驻足小息凭栏远眺，天地美景尽收眼底宛若仙境，登临
至此任何游人都会忘却尘俗杂事。向西远远就是华山派的紫霞宫。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"shanlu2",
  "southdown" : __DIR__"lvzu",
]));

	set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
