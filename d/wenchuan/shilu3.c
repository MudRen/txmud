// shilu3.c 石板路 

inherit ROOM;
void create()
{
        set("short", "石板路");
        set("long", @LONG
一条宽敞的石板路，街道两旁的小贩看见你走过来，不失时
机的提高了叫卖的音量，街道的西边是汶川镇的民居，而东边就
是汶川镇的福来客栈了。
LONG
        );
       set("exits", ([
                "north"             : __DIR__"shilu2",
                "south"             : __DIR__"shilu4",
                "east"              : __DIR__"fulai",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
