// tulu2.c 黄土路 

inherit ROOM;
void create()
{
        set("short", "黄土路");
        set("long", @LONG
不太平坦的黄土路走上去感觉不是很好，不时还有武林人士
骑马从你身边飞驰而过扬起片片灰尘，你不由得加快了脚步想快
点走完这段路。
LONG
        );
       set("exits", ([
        "north" : "/d/path2/ch_k23",
                "south"             : __DIR__"tulu3",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
