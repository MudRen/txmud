// tulu3.c 黄土路 

inherit ROOM;
void create()
{
        set("short", "黄土路");
        set("long", @LONG
不太平坦的黄土路走上去感觉不是很好，不时还有武林人士
骑马从你身边飞驰而过扬起片片灰尘，你不由得加快了脚步想快
点走完这段路,好在再往南就是黄河口边的汶川镇了。
LONG
        );
       set("exits", ([
                "north"             : __DIR__"tulu2",
                "south"             : __DIR__"zhenkou",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
