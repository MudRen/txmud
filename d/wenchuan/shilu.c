// shilu.c 石板路 

inherit ROOM;
void create()
{
        set("short", "石板路");
        set("long", @LONG
一条宽敞的石板路，街道两旁的小贩看见你走过来，不失时
机的提高了叫卖的音量，街道的东边有一家兵器铺，西边是镇上
有名的汶川武馆，听说武馆里的总教头武功很好。
LONG
        );
       set("exits", ([
                "north"             : __DIR__"zhenkou",
                "south"             : __DIR__"shilu2",
                "east"              : __DIR__"bingqi",
                "west"              : __DIR__"wuguan",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
