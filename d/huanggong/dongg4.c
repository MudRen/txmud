// Room: /d/huanggong/dongg4.c

inherit ROOM;

void create()
{
        set("short", "东宫花园");
        set("long", @LONG
这里是东宫花园。种植着各种奇花异草，看来令人赏心悦目。
同时声声鸟鸣时时在人耳边响起。置身此处，仿佛已和自然融为
一体，使人忘却所有的烦恼。花园中还有一个面积颇大的鱼池，
其中时时可见鱼儿，不时有鱼儿跃出水面。向东还有一个亭子。

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"dongg5",
  "west" : __DIR__"dongg3",
  "north" : __DIR__"dongg6",
]));
        set("no_clean_up", 0);
        set("outdoors", "huanggong");
        setup();
        replace_program(ROOM);
}