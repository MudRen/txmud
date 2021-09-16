// Room: /d/huashan/qunxian.c

inherit ROOM;

void create()
{
	set("short", "仙人桥");
	set("long", @LONG
这里背靠峰顶，你的左右两侧都是深壑。崎岖的山路延着绵
起伏的山势而修，白云环绕山间。再向东去，就是著名的“老君
犁沟”，向南则是华山最为险峻的百尺峡。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"baichi",
  "southeast" : __DIR__"ligou",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
