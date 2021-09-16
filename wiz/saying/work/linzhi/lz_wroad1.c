//lz_wroad1.c 林芝村西街
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","林芝西街");
        set("long", @LONG
这里就是林芝村的西街。林芝，在藏语中是『太阳宝座』的
意思，在西藏地区，林芝确实是靠东的部分。因为群山环绕，森
林繁茂，大江经过，所以景色十分迷人。西面是一家客栈，北面
则是这里族长的家。
LONG
        );

        set("exits", ([
        "east":__DIR__"lz_cross",
        "west":__DIR__"hotel",
        "north":__DIR__"touren/gate",
]));
        if (!is_day()) {
        set("exits/south",__DIR__"lz_wroad2");}
        if (is_day()) {
        delete("exits/south");}
        set("objects",([
        __DIR__"npc/servant":1,
]));
        setup();
}
