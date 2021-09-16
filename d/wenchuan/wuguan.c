// wuguan.c 武馆大门 

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "武馆大门");
        set("long", @LONG
十分气派的黑漆大门半敞着，门楣上一块红漆大匾(bian)，
院内不时传来武馆弟子们习武时的打斗声。
LONG
        );
       set("exits", ([
                "east"     : __DIR__"shilu",
          ]) );
       set("item_desc",([
       "bian" : HIY"汶川武馆\n"NOR,
          ]));

       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
