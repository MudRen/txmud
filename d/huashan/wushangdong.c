// Room: /d/huashan/wushangdong.c

inherit ROOM;

void create()
{
	set("short", "无上洞");
	set("long", @LONG
穿过这个石洞，就可到达金锁关了。向上的山路更加陟峭，
你要是没有十分的把握，还是不要向上走了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"jinsuoguan",
  "southdown" : __DIR__"xianzhangya",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
