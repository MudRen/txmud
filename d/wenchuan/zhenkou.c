// zhenkou.c 镇口 

inherit ROOM;
void create()
{
        set("short", "汶川镇");
        set("long", @LONG
这里就是黄河岸边的汶川镇入口了，来往的行人很多，有过
往客商、游人，也有身背刀剑的武林人士，笔直的石板路光滑平
坦的向镇里延伸。
LONG
        );
       set("exits", ([
                "north"             : __DIR__"tulu3",
                "south"             : __DIR__"shilu",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
