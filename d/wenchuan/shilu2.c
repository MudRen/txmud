// shilu2.c 石板路 

inherit ROOM;
void create()
{
        set("short", "石板路");
        set("long", @LONG
一条宽敞的石板路，街道两旁的小贩看见你走过来，不失时
机的提高了叫卖的音量，街道的两边是汶川镇的民居，再往前走
就是汶川镇的客栈了，在过黄河之前很多人在这里留宿。
LONG
        );
       set("exits", ([
                "north"             : __DIR__"shilu",
                "south"             : __DIR__"shilu3",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
