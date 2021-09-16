// Room: /d/huanggong/shenwm.c

inherit ROOM;

void create()
{
        set("short", "神武门");
        set("long", @LONG
这里就是皇宫的的后门。每天从北门进入皇宫的人都要经过
这里，高大的城门在夕阳的照射下显得氛外妖娆。金色的琉璃瓦
、巨大的朱红色梁柱显示出帝王家的气派。城门口一队金甲武士
时刻注视着进出皇宫的人。从这里向南就到了钦安殿。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qinad",
  "north" : __DIR__"beim",
]));
        set("no_clean_up", 0);

	set("outdoors", "huanggong");
        setup();
        replace_program(ROOM);
}

