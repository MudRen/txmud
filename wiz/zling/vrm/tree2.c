
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
�����ï�����֣���ɭ�ɲ���̧ͷ�������ա�������
���ε����
LONG );
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"didao/exit",
"east" : __DIR__"tree3",
]));
//    set("no_clean_up", 0);
    set("outdoors", "gaibang");
    setup();
    replace_program(ROOM);
}
