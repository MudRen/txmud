//secrety.c ͨ���η���
#include <room.h>
inherit ROOM;
void create()
{
        set("short","����");
        set("long", @LONG
������һ��СС�����ң�ǽ���Ϲ��ŵ��ˮ�飬�ǳ��ĳ�
ʪ�������ֱ������ס�ĵط���
LONG
        );
        set("exits", ([
        "west":__DIR__"main",
        "down":__DIR__"jail/entry",
]));
        setup();
        create_door("west", "ľ��", "east", DOOR_CLOSED,LOCKED,__DIR__"obj/jail_key");
}
