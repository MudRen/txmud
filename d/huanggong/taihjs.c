// Room: /d/huanggong/taihjs.c

inherit ROOM;

void create()
{
        set("short", "太湖假山");
        set("long", @LONG
放眼望去，假山顾盼生姿，湖水宁静无波，如诗如画的美景
在这里被你如痴如醉的品尝着。每一处都显示着建造者的独具匠
心与巧夺天工。假山，湖水，相映成趣，偶尔有几只水鸟贴着水
面飞过，你不禁被眼前的景色迷住了。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yuhy",
  "up" : __DIR__"yujt",
]));
        set("no_clean_up", 0);

	set("outdoors", "huanggong");
        setup();
        replace_program(ROOM);
}

