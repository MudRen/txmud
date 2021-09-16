// Room: /d/huanggong/wenyd.c

inherit ROOM;

void create()
{
        set("short", "文渊殿");
        set("long", @LONG
这里就是皇宫的藏书阁．里面并列存放了几个紫檀木的书柜
，上面摆满了各种书籍．这里可是大内的禁地，闲杂人等是不能
如内的．在大殿的外面有一队锦衣卫来回的巡查，防止不法之徒
的侵入。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"daolu5",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}