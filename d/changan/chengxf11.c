// Room: chengxf11.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "密室");
        set("long", @LONG
这里是长安丞相府的密室，一进门南墙上挂着一柄古剑，西
是一个放置古玩的架子，占了整个西墙。上面摆着一些年代古远
的古玩，北壁下有一些丞相曾经用过的盔甲、兵器，却不大明白
他把这些放在这里做什么？从这里向东是后厅。
LONG
	);

	set("exits", ([
		"east" : __DIR__"chengxf9",
]));
        setup();

        create_door("east", "木门", "west", DOOR_CLOSED,LOCKED,__DIR__"obj/cxf_key");
        // LOCKED  为此房间被setup时的锁的状态是被锁着的，具体参看 /include/room.h
        // 钥匙物件用文件名唯一区分。便于钥匙物件的编写。
        // 钥匙的 name & id 可以随便编写，不会出现误识别的情况。
        // 编写 can lock door 房间时要先有 key object ,否则 load 此房间会报错.
}