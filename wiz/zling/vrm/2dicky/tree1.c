#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
��������֣���֦ͦ�Σ���ľ��б���ּ�С��������
��Զ�����в������֣�������ת��ʹ���ʱ���⾡����
    �������˺ܶ���֦ʯ�顣
LONG );
    set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"didao/entry",
    ]));
//    set("no_clean_up", 0);
    set("outdoors", "gaibang");
    setup();
    replace_program(ROOM);
}
