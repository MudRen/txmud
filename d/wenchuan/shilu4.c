// shilu4.c 石板路 

inherit ROOM;
void create()
{
        set("short", "石板路");
        set("long", @LONG
小镇的石板路就快走完了，再往前可以看到一片树林，据当
地人说，过了树林就可以到达黄河渡口，路的西面有一家小宝石
行。
LONG
        );
       set("exits", ([
                "north"             : __DIR__"shilu3",
                "south"             : __DIR__"shulin",
                //"west"              : __DIR__"baoshi",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
