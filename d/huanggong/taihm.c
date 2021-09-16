// Room: /d/huanggong/taihm.c

inherit ROOM;

void create()
{
        set("short", "太和门");
        set("long", @LONG
这里就是皇宫内最大的广场，每当皇上举行大典的时候．都
在这里排列仪仗队，气势宏大充分体现了帝王的气派．抬头望去
碧瓦红墙更加体现了皇宫的富丽堂皇，再往北走就是国家权利中
心的象征，太和殿。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"daolu4",
  "west" : __DIR__"daolu2",
  "south" : __DIR__"wumen",
  "north" : __DIR__"taihd",
]));
      
        set("no_clean_up", 0);
        set("outdoors", "huanggong");
        replace_program(ROOM);
}