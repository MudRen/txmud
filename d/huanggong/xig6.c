// Room: /d/huanggong/xig6.c

inherit ROOM;

void create()
{
        set("short", "道路");
        set("long", @LONG
你走在一条阴森森的路上, 浓浓的雾环绕在你的四周, 这里
是通往冷宫的必经之路。往南看去你勉强可以分辨出一个城楼的
模样，在浓雾中显得格外的诡异 。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"xig3",
  "west" : __DIR__"xig5",
]));
        set("no_clean_up", 0);
        set("outdoors", "huanggong");

        setup();
        replace_program(ROOM);
}

