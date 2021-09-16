// Room: /d/huanggong/jingym.c

inherit ROOM;

void create()
{
        set("short", "景运门");
        set("long", @LONG
这里是通往西宫的必经之路。有重兵把守。闲杂人等是不许
入内的。木制的大门镶满了巨大的铜钉，一对虎头门环在不停的
摇摆，可以看出来往的人比较多，但你最好不要乱闯，小心让皇
上知道了，杀你的头，嘿嘿。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"jiulb",
  "west" : __DIR__"daolu6",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}