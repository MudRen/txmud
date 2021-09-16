// Room: /d/huanggong/jiulb.c

inherit ROOM;

void create()
{
        set("short", "九龙壁");
        set("long", @LONG
这里就是天下闻名的大内九龙壁。九条金色巨龙盘踞在碧绿
色的画壁上。巧夺天工的手笔让人惊叹。条条金龙刹是蛟龙出海
，气势磅礴。巨大的前爪紧紧抓在龙壁之上，走近一看，正中两
条巨龙见首不见尾，充满了神秘的色彩。向北就到了皇极殿。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jingym",
  "north" : __DIR__"huangjd",
]));
        set("no_clean_up", 0);

	set("outdoors", "huanggong");
        setup();
        replace_program(ROOM);
}

