// Room: /d/jinghai/th03.c

inherit ROOM;

void create()
{
        set("short", "桃花山庄城门");
        set("long", @LONG
桃花山庄的城门。两边长长的城墙由卵石砌就，正中是一座高耸
的城楼，设有两扇护铜甲硬木城门，铺有双行青石板大道，通向
庄内外。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southup" : __DIR__"wm5",
  "northup" : __DIR__"wm4",
  "eastdown" : __DIR__"th02",
  "west" : __DIR__"wm8",
]));
        set("objects",([
        __DIR__"npc/yong5" : 2,
        __DIR__"npc/duizhang1.c" : 1 ,
]));

        set("outdoors","jinghai");

        setup();
        replace_program(ROOM);
}
