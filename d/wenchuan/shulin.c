// shulin.c 树林 

inherit ROOM;
void create()
{
        set("short", "林间小路");
        set("long", @LONG
一条用小鹅卵石铺成的小路在林间延伸，树叶被微风吹拂发
出刷刷的声响，偶尔还有林间的鸟儿从头顶飞过。
LONG
        );
       set("exits", ([
                "north"             : __DIR__"shilu4",
                "east"              : __DIR__"shulin2",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
