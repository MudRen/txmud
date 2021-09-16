// shulin2.c 树林 

inherit ROOM;
void create()
{
        set("short", "林间小路");
        set("long", @LONG
一条用小鹅卵石铺成的小路在林间延伸，树叶被微风吹拂发
出刷刷的声响，偶尔还有林间的鸟儿从头顶飞过，东边的树林中
仿佛还有袅袅的炊烟升起。
LONG
        );
       set("exits", ([
                "west"              : __DIR__"shulin",
                "east"              : __DIR__"kongdi",
                  "south"             : "/d/path2/ch_k24",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
