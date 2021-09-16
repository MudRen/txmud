// Room: /d/huashan/qianchi.c

inherit ROOM;

void create()
{
	set("short", "千尺憧");
	set("long", @LONG
这里共有370多级石阶，山道异常狭窄，只容纳一人通过，
两侧崖壁陡峭，头顶只见一线天光，甚是危险。爬完石阶，你只
能从一个很小的石洞钻出。这石洞名叫“天井”，边上放着一块
铁板，只要用铁板把洞口盖上，上下就无路可走了。
LONG
	);

	set("NONPC", 1);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huixin",
  "eastup" : __DIR__"baichi",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
