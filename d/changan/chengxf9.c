// Room: chengxf9.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "后厅");
        set("long", @LONG
这里是长安丞相府的后厅，大厅很是宽阔，水磨石的地面，
墙的四周，有些名人的字画，看来这位丞相倒是一个风雅的人。
正中是主座，两边是客座，这里一般是自己家人或是很好朋友才
可以进来的地方。从西边有一个密室，北面和东面都是卧室，南
边是正厅。
LONG
	);

        set("exits", ([
  "south" : __DIR__"chengxf6",
  "north" : __DIR__"chengxf12",
  "east" : __DIR__"chengxf10",
  "west" : __DIR__"chengxf11",
]));
        setup();
        create_door("west", "木门", "east", DOOR_CLOSED,LOCKED,__DIR__"obj/cxf_key");
        // LOCKED  为此房间被setup时的锁的状态是被锁着的，具体参看 /include/room.h
        // 钥匙物件用文件名唯一区分。便于钥匙物件的编写。
        // 钥匙的 name & id 可以随便编写，不会出现误识别的情况。
        // 编写 can lock door 房间时要先有 key object ,否则 load 此房间会报错.
}