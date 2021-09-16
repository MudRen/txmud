// Room: /d/huanggong/xigdm.c

inherit ROOM;

void create()
{
        set("short", "西宫大门");
        set("long", @LONG
你已经来到了小路的尽头，抬头看去，朱红的门楼上写着两
个大字西宫。这里就是贵妃娘娘的寝宫了。门口站着一队武士，
个个精神抖擞，时刻保卫娘娘的安全。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhaig",
  "north" : __DIR__"xig1",
]));
        set("no_clean_up", 0);
        set("outdoors", "huangong");
        setup();
        replace_program(ROOM);
}

