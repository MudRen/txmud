// Room: /d/huashan/lianhua_feng.c

inherit ROOM;

void create()
{
	set("short", "莲花峰");
	set("long", @LONG
你已经到达了华山的西峰顶。不时有白云向你扑面漂来，弄
得你混身湿露露的。每当四年一度的华山论剑到来时，这里也会
有一些年青的武林人士集聚进行华山小论。你要是不知武功是否
达到一流，不妨来这里一试。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"xiaolu4",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
