// Room: /d/huanggong/xig2.c

inherit ROOM;

void create()
{
        set("short", "思宁宫");
        set("long", @LONG
这里就是贵妃娘娘的居室了。华丽的大厅富丽堂皇，尽显出
皇家的气派。一对可爱的波斯猫静静的卧在御榻之上显得十分可
爱，看到你的到来，贵妃娘娘对着你微微一笑，真是千娇百媚，
把你看的飘飘欲仙。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xig1",
 
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}