// Room: /d/huashan/xiaolu2.c

inherit ROOM;

void create()
{
        set("short", "上山小路");
        set("long", @LONG
山路越来越陡，不时有一些你也叫不出名的小动物从路边的
树林中窜出。你要是身体不太好，还是不要往上走了。路的右边
有一个小亭子。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"xiaolu1",
  "east" : __DIR__"qiting",
  "northeast" : __DIR__"lin2",
  "northwest" : __DIR__"lin1",
]));
        set("outdoors", "huashan");
        setup();
        replace_program(ROOM);
}

